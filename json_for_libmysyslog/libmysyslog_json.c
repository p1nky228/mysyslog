#include "libmysyslog.h"

int mysyslog_json(const char* msg, int level, const char* process, const char* path) 
{
    return mysyslog(msg, level, FILE_OUTPUT, JSON, path);
}