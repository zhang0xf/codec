#define  _CRT_SECURE_NO_WARNINGS 

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif // _WIN32
#include "log.h"

// 最大Log长度
#define MAX_STRING_LEN	10240

// 日志类别
#define NO_LOG_LEVEL	0
#define DEBUG_LEVEL		1
#define INFO_LEVEL		2
#define WARNING_LEVEL	3
#define ERROR_LEVEL		4

int LogLevel[5] = 
{
	NO_LOG_LEVEL,
	DEBUG_LEVEL,
	INFO_LEVEL,
	WARNING_LEVEL,
	ERROR_LEVEL
};

// 类别名称
static char LevelName[5][10] = { "NOLOG", "DEBUG", "INFO", "WARNING", "ERROR" };

// 获取当前时间的字符串形式
static int GetCurTime(char* timeString)
{
	return strftime(timeString, 33, "%Y.%m.%d %H:%M:%S", localtime(&(time(NULL))));
}

// 打开日志文件
static int OpenLogFile(int* pf)
{
	char fileName[1024];
	memset(fileName, 0, sizeof(fileName));

#ifdef _WIN32
	sprintf(fileName, ".\\log\\%s", "log.log");
#else
	sprintf(fileName, "%s/log/%s", getenv("HOME"), "log.log");
#endif

	*pf = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (*pf < 0)
	{
		return -1;
	}

	return 0;
}

static void WriteLog(const char* file, int line, int level, int status, const char* fmt, va_list args)
{
	int pf = 0;
	int	len = 0;
	int length = 0;
	char log[MAX_STRING_LEN];
	char timeString[64];


	memset(log, 0, MAX_STRING_LEN);
	memset(timeString, 0, 64);

	//加入LOG时间
	len = GetCurTime(timeString);
	len = sprintf(log, "[%s] ", timeString);
	length = len;

	//加入LOG等级
	len = sprintf(log + length, "[%s] ", LevelName[level]);
	length += len;

	//加入LOG状态
	if (status != 0)
	{
		len = sprintf(log + length, "[ERRNO is %d] ", status);
	}
	else
	{
		len = sprintf(log + length, "[SUCCESS] ");
	}
	length += len;

	//加入LOG信息
	len = vsprintf(log + length, fmt, args);
	length += len;

	//加入LOG发生文件
	len = sprintf(log + length, " [%s]", file);
	length += len;

	//加入LOG发生行数
	len = sprintf(log + length, " [%d]\n", line);
	length += len;

	//打开LOG文件
	if (OpenLogFile(&pf))
	{
		return;
	}

	//写入LOG文件
	write(pf, log, length);

	//关闭文件
	close(pf);

	return;
}

void LOG(const char* file, int line, int level, int status, const char* fmt, ...)
{
	va_list args;

	if (level == NO_LOG_LEVEL) { return; }

	va_start(args, fmt);
	WriteLog(file, line, level, status, fmt, args);
	va_end(args);

	return;
}