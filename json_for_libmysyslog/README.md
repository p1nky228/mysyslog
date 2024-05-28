# Описание

Этот репозиторий содержит два подключаемых плагина для библиотеки libmysyslog на языке Си:

1. **libmysyslog-text** - плагин для вывода данных в журнал в текстовом формате с заданным разделителем.
2. **libmysyslog-json** - плагин для вывода данных в журнал в формате JSON.

## libmysyslog-json

### libmysyslog_json.c

Этот файл содержит реализацию плагина вывода в формате JSON для библиотеки libmysyslog.

Функция `mysyslog_json` принимает следующие параметры:
- `msg`: Строка с сообщением для записи в журнал.
- `level`: Уровень журналирования (DEBUG, INFO, WARN, ERROR, CRITICAL).
- `process`: Имя процесса.
- `path`: Путь к файлу журнала.


### libmysyslog_json.h

Этот файл содержит объявление функции `mysyslog_json`, которая используется для вывода данных в журнал в формате JSON.

Функция `mysyslog_json` имеет те же параметры, что и функция `mysyslog`, за исключением драйвера, который всегда установлен в FILE_OUTPUT для записи в файл.

Пример использования:

```c
#include "libmysyslog_json.h"

int main() 
{
    mysyslog_json("This is an informational message", INFO, "example-app", "logfile.json");
    mysyslog_json("This is an error message", ERROR, "example-app", "logfile.json");
    return 0;
}
```