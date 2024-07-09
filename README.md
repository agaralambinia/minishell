**МОМ 09.05.2024**

Что нужно сделать:

1. изучить все разрешенные функции (составить список с описанием)
2. Что означает history? (уточнить у студентов, почитать репки) нужно ли искать по истории?
3. Search and launch the right executable (based on the PATH variable or using a relative or an absolute path) - Сережа добьет
4. Составить список с описанием всех спецсимволов shell
5. Придумать, как реализовать поддержку переменных окружения
6. Что такое builtins???
7. Разобраться в работе с библиотекой GNU Readline. Пока только принципы работы, с компиляцией и  Makefile'ом там отдельный ад.

Даша берет спецсимволы + сигналы
Сережа берет функции

-----------------------------------------------------------------
**МОМ 18.05.2024**
- Работаем втроем, со стаффом согласовано
- Следующая встреча во вторник в 21:00
- Ко встрече:
1. Даша нарисует в Миро черновик архитектуры проекта на обсуждение
2. Ваня дочитает книгу и возможно дополнит описание
3. Сережа доопишет функции и запушит в main.

-----------------------------------------------------------------
**МОМ 21.05.2024**
- Обсудили архитектуру проекта
- Работаем по канбану: сделал 1 кусок - пушишь выбираешь другой кусок
- При разработке пишем подробные комментарии в коде и коммит мессаджи для партнеров
- Обработка ошибок хоть и живет в модуле выхода, но по факту каждый для своего куска прописывает чеки и обработку
- Readline жесткий. Его нужно в Makefile обрабатывать. И делать это нужно в начале проекта
- Сейчас занимаемся компиляцией Readline - пытаемся собрать makefile который будет его компилить.
- в четверг в 21:00 встречаемся, обсуждаем результаты и разбираем тикеты из 1го блока

-----------------------------------------------------------------
**МОМ 22.05.2024**
- С readline разобрались
- К вечеру понедельника делаем верхний блок
   - Даша Вывод приглашения
   - Ваня и Сережа Чтение команды и добавление в историю
 
-----------------------------------------------------------------
**МОМ 27.05.2024**
- Обсудили сделанное
  - Вывод приглашения: Для рута обработка / TBD Даша
  - Чтение команды и добавление в историю - вмержить в рабочий каталог TBD Сережа Ваня
- Обсудили readline
  - Сережа рассказал, какие есть способы его компиляции
  - Самый надежный способ - с make install - тогда поведение cntrlD корректное
- Обсудили архитектуру слоев
  - Makefile
  - incs: Хэдеры
    - minishell.h: включает импорты всех либ, все структуры и макросы
  - libs: библиотеки (readline, libft (используем libft))
  - srcs: сишки. Общее правило: в каждом файле 1 не статик функция, одноименная файлу.
    - utils - функции общего назначения
    - wraps - обертки над функциями (декораторы)
    - Еще директории одноименные модулю проекта
- Затронули cтруктуры
  - глобальная переменная: это структура, в том числе содеращая envp
  - токен - тоже какая-то структура
- Закрепили блоки проекта
  - Даша: лексер, на выходе массив строк
  - Сережа: пайпы и парсер
  - Ваня: билдины
- Следующая встреча: Ваня и Сережа встретятся в среду/пятницу, Даша на следующей неделе

-----------------------------------------------------------------
**МОМ 03.06.2024**
- По прогрессу:
  - Лексер сегфолтит, завтра Сережа Даше скинет кейсы, где это происходит, Даша отдебажит
  - Ваня почти сделал билдины, к среде вмержит
  - Сережа в течение недели-двух доделает парсинг
- Обсудили сигналы: кажется, чо нужно реализовать 3
- Дебаг: нужно пообсуждать со старшими / посмотреть в репках и накидать тестов на прогон
- Следующая встреча 05.06, покажем доделки

-----------------------------------------------------------------
**МОМ 17.06.2024**
- Обсудили что сделали:
  - Ваня доделал билдины, до среды вмержит
  - Серега прокачал execution, теперь есть множественный редирект. Также сделал так чтоб аргументы работали с переменными окружения
  - Даша обещалась поправить кавычки и отдебажить сегфолт
- Обсудили сроки:
  - у Вани самый ранний дедлайн - 8 июля
  - Соответственно целимся в то, чтобы сдать 29-30 июня, чтобы была неделя в запасе на случай фиаско

-----------------------------------------------------------------
**МОМ 19.06.2024**
- Обсудили что сделали:
  - Толком ничего не доделали
  - Даша убрала кавычки, дебаг не дебажится
- Договорились, чо в субботу встретимся ориентироваочно в 12 поботать очно
  - К этому времени ребята доделают свои куски и найдут тесты
  - Даша напишет сигналы
 
-----------------------------------------------------------------
РУЧНОЕ ТЕСТИРОВАНИЕ ТЕСТ-КЕЙСОВ

блок CD:
* cd ; pwd                                    ok
* cd .. ; pwd                                 ok
* cd . ; pwd                                  ok
* cd /Users ; pwd                             ok
* cd ; pwd                                    ok
* cd // ; pwd
    * !ERROR! должны провалиться в //, проваливаемся в /
* cd '//' ; pwd
    * !ERROR! должны провалиться в //, проваливаемся в /
* cd ////// ; pwd                             ok
* cd ./././ ; pwd                             ok
* pwd ; cd . ; pwd
* cd / ; cd Users ; pwd ; cd .. ; pwd         ok
* cd '/etc' ; pwd
    * !ERROR! должны провалиться в /etc, проваливаемся в /private/etc
* cd '/var' ; pwd
    * !ERROR! должны провалиться в /var, проваливаемся в /private/var
* cd "$PWD/file_tests" ; pwd
    * !ERROR! должны получить ошибку -bash: cd: /Users/file_tests: No such file or directory, не получаем
* cd "doesntexist" ; pwd                      ok
* cd ../../.. ; pwd ; echo $PWD $OLDPWD       ok
* cd .. ; unset OLDPWD ; cd $OLDPWD ; pwd
    * !ERROR! Segmentation fault: 11 при unset OLDPWD
* cd .. ; unset PWD ; cd $PWD ; pwd           ok
* cd ?                                        ok
* cd +                                        ok
* cd _                                        ok
* cd woof                                     ok
* cd bark bark                                ok
* cd '/' ; pwd                                ok
* cd $PWD/file_tests ; pwd                    ok
* cd $OLDPWD/something ; pwd                  ok

блок ECHO:
* echo $PWD; echo $OLDPWD; cd .; pwd; echo $PWD; echo $OLDPWD\n                                               ok
* echo $PWD; echo $OLDPWD; cd ..; pwd; echo $PWD; echo $OLDPWD\n                                              ok
* echo $PWD; echo $OLDPWD; cd ../..; pwd; echo $PWD; echo $OLDPWD\n                                           ok
* echo $PWD; echo $OLDPWD; cd ../../..; pwd; echo $PWD; echo $OLDPWD\n                                        ok
* echo $PWD; echo $OLDPWD; cd ../../../..; pwd; echo $PWD; echo $OLDPWD\n                                     ok
* echo $PWD; echo $OLDPWD; cd ../../../../..; pwd; echo $PWD; echo $OLDPWD\n                                  ok
* echo $PWD; echo $OLDPWD; cd ../../../../../..; pwd; echo $PWD; echo $OLDPWD\n                               ok
* echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD\n                                               ok
* echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD\n                                              ok
* echo $PWD; echo $OLDPWD; cd '' ''; pwd; echo $PWD; echo $OLDPWD                                             ok
* echo $PWD; echo $OLDPWD; cd '' '' ''; pwd; echo $PWD; echo $OLDPWD                                          ok
* echo $PWD; echo $OLDPWD; cd ' '; pwd; echo $PWD; echo $OLDPWD                                               ok
* echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD                                                 ok
* echo $PWD; echo $OLDPWD; cd /.; pwd; echo $PWD; echo $OLDPWD                                                ok
* echo $PWD; echo $OLDPWD; cd /./; pwd; echo $PWD; echo $OLDPWD                                               ok
* echo $PWD; echo $OLDPWD; cd /././././; pwd; echo $PWD; echo $OLDPWD                                         ok
* echo $PWD; echo $OLDPWD; cd //; pwd; echo $PWD; echo $OLDPWD
    * !ERROR! должны провалиться в //, проваливаемся в /
* echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD                                               ok
* echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD
* echo $PWD; echo $OLDPWD; cd //////////////////////////////////////////////////////; pwd; echo $PWD; echo $OLDPWD          ok
* echo $PWD; echo $OLDPWD; cd; echo $OLDPWD                                                                   ok
* echo $PWD; echo $OLDPWD; cd ' /'; pwd; echo $PWD; echo $OLDPWD                                              ok
* echo $PWD; echo $OLDPWD; cd ' / '; pwd; echo $PWD; echo $OLDPWD                                             ok
* echo $PWD; echo $OLDPWD; cd '                  /'; pwd; echo $PWD; echo $OLDPWD                             ok
* echo $PWD; echo $OLDPWD; cd '                  /              '; pwd; echo $PWD; echo $OLDPWD               ok
* echo $PWD; echo $OLDPWD; cd ' // '; pwd; echo $PWD; echo $OLDPWD                                            ok
* echo $PWD; echo $OLDPWD; cd //home; pwd; echo $PWD; echo $OLDPWD
    * !ERROR! pwd после команды должен выдавать //home а выдает /System/Volumes/Data/home
* echo $PWD; echo $OLDPWD; cd ' //home'; pwd; echo $PWD; echo $OLDPWD                                         ok
* echo $PWD; echo $OLDPWD; cd '     //home    '; pwd; echo $PWD; echo $OLDPWD                                 ok

-----------------------------------------------------------------
 **LOG 06.07.2024**
 - Dasha: found another checker, we have fuckups with exit codes https://github.com/cacharle/minishell_test/blob/master/README.md
