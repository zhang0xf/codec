#include <stddef.h>
#include <string.h>
#include "test.h"
#include "log.h"
#include "encode.h"

int EncodePerson(Person* person, UInt8** stream, UInt32* length)
{
	if (NULL == person || NULL == stream || NULL == length) { return -1; }
	
	int ret;
	BUF_INTEGER* pTempBuf = NULL;
	
	// ±àÂëname
	ret = EncodeStringToAnyBuf(&pTempBuf, (unsigned char*)person->name, strlen(person->name));
	if (ret != TLV_NO_ERROR)
	{
		LOG(__FILE__, __LINE__, LogLevel[4], ret, "EncodeStringToAnyBuf() error !");
		return ret;
	}

	//ret = DER_ItAsn1_WritePrintableString(pTempBuf, &pHeader);
	//if (ret != ITDER_NoErr)
	//{
	//	DER_ITCAST_FreeQueue(pTempBuf);
	//	ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WritePrintableString() error !");
	//	return ret;
	//}
	//DER_ITCAST_FreeQueue(pTempBuf);

	return 0;
}


int DecodePerson(UInt8* stream, UInt32 length, Person** person)
{


	return 0;
}

int IsPersonEqual(Person* p1, Person* p2)
{

	return -1;
}

void PrintPersonInfo(Person* person)
{
	
}

void WriteStreamToFile(UInt8* stream, UInt32 length)
{
	
}