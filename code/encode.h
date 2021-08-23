#ifndef _ENCODE_H_
#define _ENCODE_H_

#include "define.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _AnyBuf
{
	unsigned char* pData;
	UInt32 dataLen;
	UInt32 unusedBits;
	UInt32 memoryType;
	UInt32 dataType;
	struct _AnyBuf* next;
	struct _AnyBuf* prev;
}AnyBuf;

typedef UInt8  BUF_BOOLEAN;
typedef AnyBuf BUF_INTEGER;
typedef AnyBuf BUF_OCTETSTRING;
typedef AnyBuf BUF_BITSTRING;
typedef AnyBuf BUF_PRINTABLESTRING;
typedef AnyBuf BUF_BMPSTRING;
typedef AnyBuf BUF_ENUMERATED;
typedef AnyBuf BUF_IA5STRING;
typedef AnyBuf BUF_SEQUENCE;
typedef AnyBuf BUF_SET;

/// <summary>
/// ����PrintableStringΪ�ṹ��
/// </summary>
/// <param name="pPrintString">����buf</param>
/// <param name="ppDerPrintString">���buf</param>
/// <returns>����TLV_NO_ERROR��ʾ�ɹ��������������ʾʧ��</returns>
int EncodePrintableString(BUF_PRINTABLESTRING* pPrintString, BUF_PRINTABLESTRING** ppDerPrintString);

/// <summary>
/// ����StringΪ�ṹ��
/// </summary>
/// <param name="pOriginBuf">����ṹ��</param>
/// <param name="strOrigin">��������</param>
/// <param name="strOriginLen">�������ݳ���</param>
/// <returns>����TLV_NO_ERROR��ʾ�ɹ��������������ʾʧ��</returns>
int EncodeStringToAnyBuf(AnyBuf** pOriginBuf, UInt8* strOrigin, UInt32 strOriginLen);


#ifdef __cplusplus
}
#endif

#endif // !_ENCODE_H_
