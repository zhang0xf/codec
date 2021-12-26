#ifndef _DEFINE_H_
#define _DEFINE_H_

typedef unsigned char UInt8;
typedef unsigned short UInt16;
typedef unsigned int Int32;
typedef unsigned long UInt32;

#define TRUE 1
#define FALSE 0

#define MEMORY_STATIC 1
#define MEMORY_MALLOC 2

#define TLV_NO_ERROR 0	
#define TLV_MEMORY_ERROR 200
#define TLV_LENGTH_ERROR 201
#define TLV_LENGTH_NOT_EQUAL_ERROR 202
#define TLV_DATA_RANGE_ERROR 203
#define TLV_INVALID_TAG_ERROR 204

enum {
	ID_RESERVED,
	ID_BOOLEAN,
	ID_INTEGER,
	ID_BITSTRING,
	ID_OCTETSTRING,
	ID_NULL,
	ID_OBJECT_IDENTIFIER,
	ID_OBJECT_DESCRIPTOR,
	ID_EXTERNAL,
	ID_REAL,
	ID_ENUMERATED,
	ID_EMBEDDED_PDV,
	ID_STRING_UTF8,
	ID_13,
	ID_14,
	ID_15,
	ID_SEQUENCE,
	ID_SET,
	ID_STRING_NUMERIC,
	ID_STRING_PRINTABLE,
	ID_STRING_T61,
	ID_STRING_VIDEOTEX,
	ID_STRING_IA5,
	ID_TIME_UTC,
	ID_TIME_GENERALIZED,
	ID_STRING_GRAPHIC,
	ID_STRING_ISO646,
	ID_STRING_GENERAL,
	ID_STRING_UNIVERSAL,
	ID_29,
	ID_STRING_BMP
};

// 掩码
#define CLASS_MASK 0xC0
#define CONSTRUCTED_MASK 0x20
#define SHORT_ID_MASK 0x1F
#define FIRST_NOT_ID_MASK 0x7F
#define FIRST_YES_ID_MASK 0x80
#define ALL_YES_ID_MASK 0xFF

#define UNIVERSAL 0x00
#define APPLICATION 0x40
#define CONTEXT_SPECIFIC 0x80
#define PRIVATE 0xC0

#define CONSTRUCTED 0x20
#define PRIMITIVE 0x00

#define DATA_RESERVED ( UNIVERSAL | PRIMITIVE | ID_RESERVED )
#define DATA_BOOLEAN ( UNIVERSAL | PRIMITIVE | ID_BOOLEAN )
#define DATA_INTEGER ( UNIVERSAL | PRIMITIVE | ID_INTEGER )
#define DATA_BITSTRING ( UNIVERSAL | PRIMITIVE | ID_BITSTRING )
#define DATA_OCTETSTRING ( UNIVERSAL | PRIMITIVE | ID_OCTETSTRING )
#define DATA_NULL ( UNIVERSAL | PRIMITIVE | ID_NULL )
#define DATA_OBJECT_IDENTIFIER ( UNIVERSAL | PRIMITIVE | ID_OBJECT_IDENTIFIER )
#define DATA_OBJECT_DESCRIPTOR ( UNIVERSAL | PRIMITIVE | ID_OBJECT_DESCRIPTOR )
#define DATA_EXTERNAL ( UNIVERSAL | PRIMITIVE | ID_EXTERNAL )
#define DATA_REAL ( UNIVERSAL | PRIMITIVE | ID_REAL )
#define DATA_ENUMERATED ( UNIVERSAL | PRIMITIVE | ID_ENUMERATED )
#define DATA_EMBEDDED_PDV ( UNIVERSAL | PRIMITIVE | ID_EMBEDDED_PDV )
#define DATA_STRING_UTF8 ( UNIVERSAL | PRIMITIVE | ID_STRING_UTF8 )
#define DATA_13 ( UNIVERSAL | PRIMITIVE | ID_13 )
#define DATA_14 ( UNIVERSAL | PRIMITIVE | ID_14 )
#define DATA_15 ( UNIVERSAL | PRIMITIVE | ID_15 )
#define DATA_SEQUENCE ( UNIVERSAL | CONSTRUCTED | ID_SEQUENCE )
#define DATA_SET ( UNIVERSAL | CONSTRUCTED | ID_SET )
#define DATA_STRING_NUMERIC ( UNIVERSAL | PRIMITIVE | ID_STRING_NUMERIC )
#define DATA_STRING_PRINTABLE ( UNIVERSAL | PRIMITIVE | ID_STRING_PRINTABLE )
#define DATA_STRING_T61 ( UNIVERSAL | PRIMITIVE | ID_STRING_T61 )
#define DATA_STRING_VIDEOTEX ( UNIVERSAL | PRIMITIVE | ID_STRING_VIDEOTEX )
#define DATA_STRING_IA5 ( UNIVERSAL | PRIMITIVE | ID_STRING_IA5 )
#define DATA_TIME_UTC ( UNIVERSAL | PRIMITIVE | ID_TIME_UTC )
#define DATA_TIME_GENERALIZED ( UNIVERSAL | PRIMITIVE | ID_TIME_GENERALIZED )
#define DATA_STRING_GRAPHIC ( UNIVERSAL | PRIMITIVE | ID_STRING_GRAPHIC )
#define DATA_STRING_ISO646 ( UNIVERSAL | PRIMITIVE | ID_STRING_ISO646 )
#define DATA_STRING_GENERAL ( UNIVERSAL | PRIMITIVE | ID_STRING_GENERAL )
#define DATA_STRING_UNIVERSAL ( UNIVERSAL | PRIMITIVE | ID_STRING_UNIVERSAL )
#define DATA_29 ( UNIVERSAL | PRIMITIVE | ID_29 )
#define DATA_STRING_BMP ( UNIVERSAL | PRIMITIVE | ID_STRING_BMP )

#endif // !_DEFINE_H_