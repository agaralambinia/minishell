#include <signal.h> - Либа

Измененяет действие процесса при получении соответствующего сигнала.
Более новая функция чем signal. позволяет лучше контролировать процесс.
Рекомендуют использовать sigaction а не signal

Прототип:
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

Параметры:
	- sig: Номер сигнала, который функция будет обрабатывать (один из сигналов ОС Linux (смотри картинку))
	- sigaction *restrict act: новый обработчик сигнала
	- sigaction *restrict oact: через него возвращается старый обработчик

Возвращаемое значение
	- 0 в случае успеха
	- -1 в случае ошибки


struct sigaction
{
void (*sa_handler)(int); /* адрес функции-обработчика сигнала, SIG_IGN, или SIG_DFL */
sigset_t sa_mask; 
/*  маска сигналов который будут блокированы пока выполняется наш обработчик. + по дефолту блокируется и сам полученный сигнал */
int sa_flags; /* флаги, смотри картинку sa_flags */
/* альтернативный обработчик сигнала */
void (*sa_sigaction)(int, siginfo_t *, void *);
};
