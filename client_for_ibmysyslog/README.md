# Описание для клиента
## mysyslog-client
`mysyslog-client` - это тестовое приложение на языке C, которое использует библиотеку `libmysyslog` для записи сообщений в журнал с различными параметрами. Пользователь может указать текст сообщения, уровень журналирования, драйвер вывода, формат и путь к файлу журнала через аргументы командной строки.

## Установка
1. Клонируем репозиторий: `git clone https://github.com/MaksimAnikeev/mysyslog`
2. Переходим в каталог mysyslog: `cd mysyslog`
3. Собираем приложение mysyslog-client: `gcc mysyslog-client.c -o mysyslog-client -lmysyslog`
4. Устанавливаем mysyslog-client в систему: `sudo cp mysyslog-client /usr/local/bin/`

## Использование

Приложение `mysyslog-client` позволяет отправлять сообщения в журнал с помощью различных опций командной строки. Вот список доступных опций:

* `-m <message>`: Устанавливает текст сообщения.
* `-l <level>`: Устанавливает уровень журналирования (0 - DEBUG, 1 - INFO, 2 - WARN, 3 - ERROR, 4 - CRITICAL). По умолчанию: INFO.
* `-d <driver>`: Устанавливает драйвер вывода (0 - CONSOLE, 1 - FILE_OUTPUT). По умолчанию: CONSOLE.
* `-f <format>`: Устанавливает формат вывода (0 - PLAIN_TEXT, 1 - JSON). По умолчанию: PLAIN_TEXT.
* `-p <path>`: Устанавливает путь к файлу журнала.


## Пример использования

```bash
mysyslog-client -m "This is an informational message" -l 1 -d 1 -f 0 -p "/var/log/mysyslog.log"
```
## Замечание

При использовании `mysyslog-client` необходимо убедиться, что daemon `mysyslog-daemon` запущен и настроен корректно для записи в журнал.
