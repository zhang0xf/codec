#define _CRT_SECURE_NO_WARNINGS	// �������ȫ����strcpy()�����ľ���

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(int argc, char* argv[])
{
	printf("���Ա����ӿ�...\n");

	Person person;
	strcpy(person.name, "zhangfei");
	person.age = 18;
	person.sex = Sex.MALE;
	strcpy(person.introduction, "this is introduction");

	UINT8* stream = NULL:
	UINT32 len = 0;

	// ����
	EncodePerson(person, &stream, &len);

	// д�ļ�
	WriteStreamToFile(stream, len);

	Person* pPerson = NULL:

	// ����
	DecodePerson(stream, len, &pPerson);

	// �Ƚ�
	if (IsPersonEqual(&person, pPerson))
	{
		printf("�������ԣ��ɹ�...\n");
	}
	else
	{
		printf("�������ԣ�ʧ��...\n");
	}

	return 0;
}