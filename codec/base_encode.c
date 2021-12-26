#define  _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "base_encode.h"
#include "log.h"

#define MemoryFree(mem) {if(mem) {free(mem); mem=NULL;}}  

#define TAG_IDENTIFIER(cTag) (cTag & SHORT_ID_MASK)

#define CREATE_ANYBUF(point) \
	    point = (AnyBuf *)malloc(sizeof(AnyBuf)); \
        if (point==NULL) return 7002; \
		memset(point,0,sizeof(AnyBuf)); \
        point->dataLen = 0; \
        point->dataType = 0; \
	    point->memoryType = MEMORY_MALLOC; \
	    point->pData = NULL; \
	    point->unusedBits = 0; \
	    point->next = NULL; \
        point->prev = NULL

#define CREATE_UINT8(point,size) \
	    point = malloc(size); \
		if (point==NULL) return 7002; \
        memset(point,0,size)

static UInt32 CountLengthBytes(UInt32 length)
{
	if (length <= 0x7F)
		return (1);
	else if (length <= 0xFF)
		return (2);
	else if (length < 0xFFFF)
		return (3);
	else if (length <= 0xFFFFFF)
		return (4);
	else if (length <= 0xFFFFFFFF)
		return (5);
	else
	{
		LOG(__FILE__, __LINE__, LogLevel[4], TLV_LENGTH_ERROR, "CountLengthBytes() error");
		return TLV_LENGTH_ERROR;
	}
}

static int EncodeTagAndLength(AnyBuf* pAnyIn, UInt8 cTag, AnyBuf** ppAnyOut, UInt8** ppUint8Value)
{
	AnyBuf* pMidAny = NULL;
	UInt8* pMidValue = NULL, cIdentifier;
	UInt32 iMidSize, iMidSizeOf, iMidLength, i;

	if ((cTag != ID_BITSTRING) && (cTag != ID_INTEGER))
		iMidSize = pAnyIn->dataLen;
	else
		if (cTag == ID_INTEGER)
			if (!(*(pAnyIn->pData) & FIRST_YES_ID_MASK))
				iMidSize = pAnyIn->dataLen;
			else
				iMidSize = pAnyIn->dataLen + 1;
		else
			iMidSize = pAnyIn->dataLen + 1;
	iMidLength = iMidSize;
	iMidSizeOf = CountLengthBytes(iMidSize);
	if (iMidSizeOf < 0 || iMidSizeOf > 5)
	{
		LOG(__FILE__, __LINE__, LogLevel[4], TLV_LENGTH_ERROR, "EncodeTagAndLength() error");
		return TLV_LENGTH_ERROR;
	}
	iMidSize += 1 + iMidSizeOf;
	CREATE_ANYBUF(pMidAny);
	CREATE_UINT8(pMidValue, iMidSize);
	if (iMidSize == 11)
	{
		iMidSize = 11;
	}
	pMidAny->pData = pMidValue;

	if (cTag & CONTEXT_SPECIFIC)
		cIdentifier = cTag;
	else
	{
		cIdentifier = TAG_IDENTIFIER(cTag);
		//if (cIdentifier != pAnyIn ->dataType)
		//    return ITDER_MemoryErr;
	}

	*(pMidValue++) = cTag;
	pMidAny->dataType = (UInt32)cIdentifier;
	pMidAny->dataLen = iMidSize;
	if (iMidSizeOf == 1)
	{
		*(pMidValue++) = (UInt8)(iMidLength);
	}
	else
	{
		*(pMidValue++) = FIRST_YES_ID_MASK | (UInt8)(iMidSizeOf - 1);
		for (i = iMidSizeOf - 1;i > 0;i--)
		{
			*(pMidValue++) = (UInt8)(iMidLength >> 8 * (i - 1));
		}
	}
	if (pMidAny->dataType == ID_BITSTRING)
	{
		pMidAny->unusedBits = pAnyIn->unusedBits;
		*(pMidValue++) = (UInt8)(pAnyIn->unusedBits);
	}
	if (pMidAny->dataType == ID_INTEGER)
	{
		if (*(pAnyIn->pData) & FIRST_YES_ID_MASK)
			*(pMidValue++) = 0x0;
	}

	*ppUint8Value = pMidValue;
	*ppAnyOut = pMidAny;

	pMidAny = NULL;
	pMidValue = NULL;

	return 0;
}

static int EncodeBmpString(BUF_BMPSTRING* pBmpString, BUF_BMPSTRING** ppBmpString)
{
	int ret;
	UInt8* pMidData = NULL;
	UInt8* pMidValue = NULL;
	UInt8 cTag = ID_STRING_BMP;
	AnyBuf* pMidBmpString = NULL;

	ret = EncodeTagAndLength(pBmpString, cTag, &pMidBmpString, &pMidValue);
	if (ret != TLV_NO_ERROR)
	{
		LOG(__FILE__, __LINE__, LogLevel[4], ret, "EncodeTagAndLength() error");
		return  ret;
	}

	pMidData = pBmpString->pData;
	memcpy(pMidValue, pMidData, pBmpString->dataLen);

	*ppBmpString = pMidBmpString;

	pMidBmpString = NULL;
	pMidData = NULL;
	pMidValue = NULL;

	return TLV_NO_ERROR;
}

int EncodePrintableString(BUF_PRINTABLESTRING* pPrintString, BUF_PRINTABLESTRING** ppDerPrintString)
{
	int ret;

	if (pPrintString->dataType == DATA_STRING_BMP)
	{
		ret = EncodeBmpString(pPrintString, ppDerPrintString);
		if (ret != TLV_NO_ERROR)
		{
			LOG(__FILE__, __LINE__, LogLevel[4], ret, "EncodeBmpString() error");
			return ret;
		}

	}
	else
	{
		// ret = DER_ItAsn1_WriteCharString(pPrintString, ppDerPrintString);
		//if (ret != TLV_NO_ERROR)
		//{
		//	LOG(__FILE__, __LINE__, LogLevel[4], ret, "DER_ItAsn1_WriteCharString() error");
		//	return ret;
		//}
	}

	return TLV_NO_ERROR;
}

int EncodeStringToAnyBuf(AnyBuf** pOriginBuf, UInt8* strOrigin, UInt32 strOriginLen)
{
	AnyBuf* pValueBuf;

	pValueBuf = malloc(sizeof(AnyBuf));
	if (pValueBuf == NULL)
	{
		LOG(__FILE__, __LINE__, LogLevel[4], TLV_MEMORY_ERROR, "malloc error");
		return TLV_MEMORY_ERROR;
	}
	memset(pValueBuf, 0, sizeof(AnyBuf));

	if (strOriginLen <= 0)
	{
		pValueBuf->pData = NULL;
		strOriginLen = 0;
	}
	else
	{
		pValueBuf->pData = (unsigned char*)malloc(strOriginLen);
		if (pValueBuf->pData == NULL)
		{
			MemoryFree(pValueBuf);
			LOG(__FILE__, __LINE__, LogLevel[4], TLV_LENGTH_ERROR, "malloc error");
			return TLV_MEMORY_ERROR;
		}
		memcpy(pValueBuf->pData, strOrigin, strOriginLen);
	}

	pValueBuf->dataLen = strOriginLen;
	pValueBuf->dataType = ID_STRING_PRINTABLE;
	pValueBuf->next = NULL;
	pValueBuf->prev = NULL;
	pValueBuf->unusedBits = (strOriginLen % 8);
	pValueBuf->memoryType = 0;
	*pOriginBuf = pValueBuf;

	return TLV_NO_ERROR;
}