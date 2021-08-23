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
/// 编码PrintableString为结构体
/// </summary>
/// <param name="pPrintString">输入buf</param>
/// <param name="ppDerPrintString">输出buf</param>
/// <returns>返回TLV_NO_ERROR表示成功，返回其他宏表示失败</returns>
int EncodePrintableString(BUF_PRINTABLESTRING* pPrintString, BUF_PRINTABLESTRING** ppDerPrintString);

/// <summary>
/// 编码String为结构体
/// </summary>
/// <param name="pOriginBuf">输出结构体</param>
/// <param name="strOrigin">输入数据</param>
/// <param name="strOriginLen">输入数据长度</param>
/// <returns>返回TLV_NO_ERROR表示成功，返回其他宏表示失败</returns>
int EncodeStringToAnyBuf(AnyBuf** pOriginBuf, UInt8* strOrigin, UInt32 strOriginLen);


#ifdef __cplusplus
}
#endif

#endif // !_ENCODE_H_
