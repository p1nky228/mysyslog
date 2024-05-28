#include "libmysyslog.h"

int mysyslog_text(const char* msg, int level, const char* process, const char* path)
{
    return mysyslog(msg, level, FILE_OUTPUT, PLAIN_TEXT, path);
}