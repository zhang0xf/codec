#define _CRT_SECURE_NO_WARNINGS	// strcpy() warning

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "person_codec.h"

int main(int argc, char* argv[])
{
	printf("测试编解码接口...\n");

	// 构建数据
	Person person;
	strcpy(person.name, "zhangfei");
	person.age = 18;
	person.sex = MALE;
	strcpy(person.introduction, "this is introduction");

	UInt8* stream = NULL;
	UInt32 len = 0;

	// 编码
	EncodePerson(&person, &stream, &len);

	// 写文件
	WriteStreamToFile(stream, len);

	Person* pPerson = NULL;

	// 解码
	DecodePerson(stream, len, &pPerson);

	// 比较差异
	if (IsPersonEqual(&person, pPerson))
	{
		printf("编解码测试: 成功...\n");
	}
	else
	{
		printf("编解码测试: 失败...\n");
	}

	return 0;
}