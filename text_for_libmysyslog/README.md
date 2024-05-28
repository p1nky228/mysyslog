## libmysyslog-text

### libmysyslog_text.c

Этот файл содержит реализацию плагина вывода в текстовом формате для библиотеки libmysyslog.

Функция `mysyslog_text` принимает следующие параметры:
- `msg`: Строка с сообщением для записи в журнал.
- `level`: Уровень журналирования (DEBUG, INFO, WARN, ERROR, CRITICAL).
- `process`: Имя процесса.
- `path`: Путь к файлу журнала.

### libmysyslog_text.h

Этот файл содержит объявление функции `mysyslog_text`, которая используется для вывода данных в журнал в текстовом формате.

Функция `mysyslog_text` имеет те же параметры, что и функция `mysyslog`, за исключением драйвера, который всегда установлен в FILE_OUTPUT для записи в файл.

Пример использования:

```c
#include "libmysyslog_text.h"

int main()
{
    mysyslog_text("This is an informational message", INFO, "example-app", "logfile.txt");
    mysyslog_text("This is an error message", ERROR, "example-app", "logfile.txt");
    return 0;
}
```