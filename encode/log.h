#ifndef _LOG_H_
#define _LOG_H_

// 日志类别
extern int  LogLevel[5];

// 日志
void LOG(const char* file, int line, int level, int status, const char* fmt, ...);


#endif // !_LOG_H_


