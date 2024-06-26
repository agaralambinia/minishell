Объявление:

    pid_t fork(void);

Header files:

    <unistd.h>

fork() вызывает создание нового процесса.  Новый процесс (дочерний процесс) является точной копией вызывающего процесса (родительского процесса), за исключением следующих моментов:
    - Дочерний процесс имеет уникальный идентификатор процесса.
    - Дочерний процесс имеет другой идентификатор родительского процесса (т. е. идентификатор процесса родительского процесса).
    - У дочернего процесса есть своя собственная копия дескрипторов родительского процесса.  Эти дескрипторы ссылаются на на одни и те же базовые объекты, так что, например, указатели на файлы в файловых объектах используются совместно дочерним и родительским процессами, так что выполнение команды lseek(2) на дескрипторе в дочернем процессе может повлиять на последующее чтение или запись в родительском процессе.  Такое копирование дескрипторов также используется оболочкой для создания стандартного ввода и вывода для вновь созданных процессов, а также для настройки каналов связи.
    - Использование ресурсов дочерних процессов устанавливается на 0; см. setrlimit(2).

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ

После успешного завершения fork() возвращает дочернему процессу значение 0 и возвращает идентификатор процесса дочернего процесса родительскому процессу.  В противном случае родительскому процессу возвращается значение -1, дочерний процесс не создается, а глобальный дочерний процесс не будет создан, а глобальная переменная errno будет установлена для указания ошибки.