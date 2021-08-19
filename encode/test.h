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
/// 编码
/// </summary>
/// <param name="person">输入数据</param>
/// <param name="stream">输出数据流</param>
/// <param name="length">输出数据流长度</param>
/// <returns>返回0表示编码成功，返回-1表示失败</returns>
int EncodePerson(Person* person, UINT8** stream, UINT32* length);

/// <summary>
/// 解码
/// </summary>
/// <param name="stream">输入数据流</param>
/// <param name="length">输入数据流长度</param>
/// <param name="person">输出数据</param>
/// <returns>返回0表示解码成功，返回-1表示失败</returns>
int DecodePerson(UINT8* stream, UINT32 length, Person** person);

/// <summary>
/// 比较是否相等
/// </summary>
/// <param name="p1">输入</param>
/// <param name="p2">输入</param>
/// <returns>返回true表示相等，返回false表示不等</returns>
bool IsPersonEqual(Person* p1, Person* p2);

/// <summary>
/// 打印
/// </summary>
/// <param name="person">Person</param>
void PrintPersonInfo(Person* person);

/// <summary>
/// 写文件
/// </summary>
/// <param name="stream">输入</param>
/// <param name="length">输入</param>
void WriteStreamToFile(UINT8* stream, UINT32 length);

#endif // !_TEST_H_
