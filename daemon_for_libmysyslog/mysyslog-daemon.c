#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>

// Функция для обработки сигнала SIGTERM
void sigterm_handler(int signum)
{
    syslog(LOG_INFO, "Received SIGTERM. Exiting...");
    exit(EXIT_SUCCESS);
}

int main()
{
    // Открываем системный лог
    openlog("mysyslog-daemon", LOG_PID, LOG_DAEMON);

    // Устанавливаем обработчик сигнала SIGTERM
    signal(SIGTERM, sigterm_handler);

    /**/

    // Бесконечный цикл для вывода сообщений в журнал
    while (1)
    {
        // Ваш код для вывода сообщений в журнал с учетом настроек из конфигурационного файла
        syslog(LOG_INFO, "This is an informational message");
        syslog(LOG_ERR, "This is an error message");
        // Пауза на 5 секунд
        sleep(5);
    }

    // Закрываем системный лог
    closelog();

    return EXIT_SUCCESS;
}
