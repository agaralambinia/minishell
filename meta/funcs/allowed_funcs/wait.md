Объявление:

    pid_t wait(int *stat_loc);

    pid_t wait3(int *stat_loc, int options, struct rusage *rusage);

    pid_t wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);

    pid_t waitpid(pid_t pid, int *stat_loc, int options);

Header files:

    <sys/wait.h>

Функция wait() приостанавливает выполнение вызывающего ее процесса до тех пор, пока не будет доступна информация stat_loc для завершенного дочернего процесса или получения сигнала.  По возвращении из успешного вызова wait() область stat_loc содержит информацию о завершенном процессе.

Вызов wait4() предоставляет более общий интерфейс для программ, которым требуется ожидание определенных дочерних процессов, которым нужна статистика использования ресурсов, накопленная дочерними процессами, или которым требуются опции. Остальные функции ожидания реализуются с помощью wait4().

Параметр pid задает набор дочерних процессов, для которых нужно ждать.  Если pid равен -1, вызов ожидает любой дочерний процесс.  Если pid равен 0, вызов ожидает любой дочерний процесс в группе процессов вызывающей стороны.
Если pid больше нуля, вызов ожидает процесс с идентификатором процесса pid.  Если pid меньше -1, вызов ожидает любой процесс, чей идентификатор группы процессов равен абсолютному значению pid.

Параметр stat_loc определен ниже.  Параметр options содержит побитовое ИЛИ любого из перечисленных ниже параметров. Параметр WNOHANG используется для указания, что вызов не должен блокироваться, если нет процессов, желающих сообщить о состоянии.  Если установлена опция WUNTRACED, дочерние процессы текущего процесса, которые были остановлены по сигналу SIGTTIN, SIGTTOU, SIGTSTP или SIGSTOP, также сообщают о своем состоянии.

Если rusage ненулевое, то возвращается сводка ресурсов, использованных завершенным процессом и всеми его дочерними процессами (в настоящее время эта информация недоступна для остановленных процессов).

Если указана опция WNOHANG и ни один процесс не желает сообщать о состоянии, функция wait4() возвращает идентификатор процесса 0.

Вызов waitpid() идентичен wait4() со значением rusage, равным нулю. Более старый вызов wait3() аналогичен как wait4() со значением pid, равным -1.

Для проверки способа завершения процесса можно использовать следующие макросы.  Один из первых трех макросов будет иметь ненулевое (истинное) значение:

    WIFEXITED(status)
    Истина, если процесс завершился нормально в результате вызова _exit(2) или exit(3).

    WIFSIGNALED(status)
    Истина, если процесс завершился из-за получения сигнала.

    WIFSTOPPED(status)
    Истина, если процесс не завершился, а остановился и может быть перезапущен.  Этот макрос может быть истинным только в том случае, если в вызове wait была указана опция WUNTRACED или если дочерний процесс отслеживается (см. ptrace(2)).

В зависимости от значений этих макросов, следующие макросы выдают остальную информацию о состоянии дочернего процесса:

    WEXITSTATUS(status)
    Если WIFEXITED(status) равен true, то оценивается в младшие 8 бит аргумента, переданного в _exit(2) или exit(3) дочерним процессом.

    WTERMSIG(status)
    Если WIFSIGNALED(status) равен true, оценивается в номер сигнала, вызвавшего завершение процесса.

    WCOREDUMP(status)
    Если WIFSIGNALED(status) равен true, оценивается как true, если завершение процесса сопровождалось созданием файла ядра, содержащего изображение процесса в момент получения сигнала.

    WSTOPSIG(status)
    Если WIFSTOPPED(status) равен true, вычисляется номер сигнала, который вызвал остановку процесса остановка.

ПРИМЕЧАНИЯ
Список сигналов завершения см. в sigaction(2).  Статус 0 означает нормальное завершение.

Если родительский процесс завершается, не дождавшись завершения всех своих дочерних процессов, оставшимся дочерним процессам присваивается идентификатор родительского процесса 1 (идентификатор начального процесса).

Если во время выполнения любого из вызовов wait() пойман сигнал, вызов может быть прерван или перезапущен когда вернется процедура перехвата сигнала, в зависимости от опций, действующих для сигнала; см. intro(2), System call restart.

ВОЗВРАТНЫЕ ЗНАЧЕНИЯ
Если wait() возвращается из-за остановленного или завершенного дочернего процесса, он возвращает идентификатор дочернего процесса. В противном случае возвращается значение -1 и устанавливается значение errno, указывающее на ошибку.

Если wait3(), wait4() или waitpid() возвращается из-за остановленного или завершенного дочернего процесса, они возвращают идентификатор дочернего процесса.  Если нет дочерних процессов, не ожидавших ранее, возвращается -1 с ошибкой errno, установленной в [ECHILD].  В противном случае, если указано WNOHANG и нет остановленных или завершенных детей, возвращается 0. Если обнаружена ошибка или пойманный сигнал прерывает вызов, возвращается значение -1, и устанавливается значение errno, указывающее на ошибку.