#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libmysyslog.h"

int main(int argc, char *argv[])
{
    int opt;
    int level = INFO;
    int driver = CONSOLE;
    int format = PLAIN_TEXT;
    const char* path = NULL;
    const char* message = NULL;

    // Обработка аргументов командной строки с помощью getopt
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) 
    {
        switch (opt) {
            case 'm':
                message = optarg;
                break;
            case 'l':
                level = atoi(optarg);
                break;
            case 'd':
                driver = atoi(optarg);
                break;
            case 'f':
                format = atoi(optarg);
                break;
            case 'p':
                path = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s -m message -l level -d driver -f format -p path\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Проверка, было ли задано сообщение
    if (!message)
    {
        fprintf(stderr, "Необходимо указать сообщение с помощью опции -m.\n");
        exit(EXIT_FAILURE);
    }

    // Вывод сообщения в журнал с заданными параметрами
    int res = mysyslog(message, level, driver, format, path);
    if (res == -1)
    {
        fprintf(stderr, "Ошибка при записи в журнал.\n");
        exit(EXIT_FAILURE);
    }

    printf("Сообщение успешно записано в журнал.\n");

    return EXIT_SUCCESS;
}
