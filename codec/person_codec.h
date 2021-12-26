#ifndef _PERSON_CODEC_H_
#define _PERSON_CODEC_H_

#include "define.h"

typedef enum _Sex
{
	MALE,
	FRMALE
}Sex;

typedef struct _Person
{
	char name[64];
	int age;
	Sex sex;
	char introduction[64];
}Person;

// 编码person
int EncodePerson(Person* person, UInt8** stream, UInt32* length);

// 解码person
int DecodePerson(UInt8* stream, UInt32 length, Person** person);

// 相等测试
int IsPersonEqual(Person* p1, Person* p2);

// 打印person
void PrintPersonInfo(Person* person);

// 写文件
void WriteStreamToFile(UInt8* stream, UInt32 length);

#endif // !_TEST_H_
