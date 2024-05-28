# MySyslog

MySyslog - это daemon для вывода данных в журнал с различными уровнями журналирования. Daemon автоматически запускается во время старта компьютера и постоянно выводит данные в журнал с учетом настроек из конфигурационного файла.

## Установка
1.Клонируем репозиторий:
 https://github.com/MaksimAnikeev/mysyslog
  
2. Переходим в каталог mysyslog:
  `cd mysyslog`


3. Собериаем mysyslog-daemon: `gcc mysyslog-daemon.c -o mysyslog-daemon`

4. Создаем конфигурационный файл:
   * `sudo mkdir -p /etc/mysyslog`
   *  `sudo touch /etc/mysyslog/mysyslog.cfg`

5. Создаеи systemd-сервис для mysyslog-daemon: `sudo cp mysyslog-daemon.service /etc/systemd/system/`

6. Запускаем daemon и добавляем его в автозагрузку:
   * `sudo systemctl daemon-reload`
   * `sudo systemctl start mysyslog-daemon`
   * `sudo systemctl enable mysyslog-daemon`
   
  
## Вносим необходимые настройки в файл `/etc/mysyslog/mysyslog.cfg`
1. Путь к файлу журнала (path): Это путь к файлу, в который будет записываться журнал.
2. Формат вывода (format): Это формат, в котором будут записываться данные в журнал. Возможны два варианта: PLAIN_TEXT (текстовый формат) и JSON (формат JSON).
3. Драйвер вывода (driver): Это указание на то, куда будут выводиться данные: на консоль (CONSOLE) или в файл (FILE_OUTPUT).

## Путь к файлу журнала
path = /var/log/mysyslog.log

## Формат вывода (PLAIN_TEXT или JSON)
format = PLAIN_TEXT

## Драйвер вывода (CONSOLE или FILE_OUTPUT)
driver = FILE_OUTPUT

## Использование

После установки и настройки MySyslog daemon автоматически будет выводить данные в журнал в соответствии с настройками из конфигурационного файла.

* Для остановки daemon используем команду:
 `sudo systemctl stop mysyslog-daemon`
* Для перезапуска daemon используем команду:
 `sudo systemctl restart mysyslog-daemon`

## Замечание

При изменении настроек в конфигурационном файле необходимо перезапустить daemon для применения изменений.
