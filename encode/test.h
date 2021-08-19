#ifndef _TEST_H_
#define _TEST_H_

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

/// <summary>
/// ����
/// </summary>
/// <param name="person">��������</param>
/// <param name="stream">���������</param>
/// <param name="length">�������������</param>
/// <returns>����0��ʾ����ɹ�������-1��ʾʧ��</returns>
int EncodePerson(Person* person, UINT8** stream, UINT32* length);

/// <summary>
/// ����
/// </summary>
/// <param name="stream">����������</param>
/// <param name="length">��������������</param>
/// <param name="person">�������</param>
/// <returns>����0��ʾ����ɹ�������-1��ʾʧ��</returns>
int DecodePerson(UINT8* stream, UINT32 length, Person** person);

/// <summary>
/// �Ƚ��Ƿ����
/// </summary>
/// <param name="p1">����</param>
/// <param name="p2">����</param>
/// <returns>����true��ʾ��ȣ�����false��ʾ����</returns>
bool IsPersonEqual(Person* p1, Person* p2);

/// <summary>
/// ��ӡ
/// </summary>
/// <param name="person">Person</param>
void PrintPersonInfo(Person* person);

/// <summary>
/// д�ļ�
/// </summary>
/// <param name="stream">����</param>
/// <param name="length">����</param>
void WriteStreamToFile(UINT8* stream, UINT32 length);

#endif // !_TEST_H_
