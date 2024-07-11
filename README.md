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
* cd // ; pwd                                 ok
* cd '//' ; pwd                               ok
* cd ////// ; pwd                             ok
* cd ./././ ; pwd                             ok
* pwd ; cd . ; pwd
* cd / ; cd Users ; pwd ; cd .. ; pwd         ok
* cd '/etc' ; pwd                             ok - bash тоже проваливается в private, просто маскирует это
* cd '/var' ; pwd                             ok - bash тоже проваливается в private, просто маскирует это
* cd "$PWD/file_tests" ; pwd                  ok
* cd "doesntexist" ; pwd                      ok
* cd ../../.. ; pwd ; echo $PWD $OLDPWD       ok
* cd .. ; unset OLDPWD ; cd $OLDPWD ; pwd     ok
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
* echo                                        ok
* echo echo                                   ok
* eCho                                        ok
* eChO                                        ok
* eCHO                                        ok
* ECHO                                        ok
* echo rhobebou                               ok
* echo stop barking                           ok
* echo "bonjour"                              ok
* echo bonjour                                ok
* echo 'bonjour'                              ok
* echo -n bonjour                             ok
* echo -nn bonjour                            ok
* echo -n -n -n bonjour                       ok
* echo -n -n -n bonjour                       ok
* echo "-n" bonjour                           ok
* echo -n"-n" bonjour                         ok
* echo "-nnnn" bonjour                        ok
* echo "-n -n -n"-n bonjour                   ok
* echo "-n '-n'" bonjour                      ok
* echo ~                                      ok
* echo "~"                                    ok
* echo '~'                                    ok
* echo ~123                                   ok
* echo 123~                                   ok
* echo ~/123                                  ok
* echo ~/123/456                              ok
* echo $USER                                  ok
* echo "$USER"                                ok
* echo "'$USER'"                              ok
* echo " '$USER' "                            ok
* echo text"$USER"                            ok
* echo text"'$USER'" ' $USER '                ok
* echo "text"   "$USER"    "$USER"            ok
* echo '              $USER          '        ok
* echo               text "$USER"            "$USER"text    ok
* echo ''''''''''$USER''''''''''                            ok
* echo """"""""$USER""""""""                                ok
* echo $USER'$USER'text oui oui     oui  oui $USER oui      $USER '' ok
* echo $USER '' $USER $USER '' $USER '' $USER -n $USER       ok
* echo ' \' ' \'                                             ok
* echo ' \' ' \'                                             ok
* echo \\\" \\\" \\\" \\\"\\\"\\\" \\\'\\\'\\\'              ok - вывод отличается, но мы не должны обрабатывать \
* echo "$USER""$USER""$USER"                                 ok
* echo text"$USER"test                                       ok
* echo '$USER' "$USER" "text \' text"                        ok
* echo '$USER'                                               ok
* echo $USER " "                                             ok
* echo "$USER""Users/$USER/file""'$USER'"'$USER'             ok
* echo "$USER$USER$USER"                                      ok
* echo '$USER'"$USER"'$USER'
    * !ERROR! должно быть $USERagaralambinia$USER
    * получаем ничего
* echo '"$USER"''$USER'"""$USER"
    * !ERROR! должно быть "$USER"$USERagaralambinia
    * получаем "$USER"agaralambinia"""$USER"
* echo " $USER  "'$PWD'
    * !ERROR! должно быть  agaralambinia  $PWD
    * получаем ничего
* echo " $USER  \$ "'$PWD'
    * !ERROR! должно быть  agaralambinia  $ $PWD
    * получаем ничего
* echo $USER=4
    * !ERROR! должно быть $USER=4
    * получаем ничего
* echo $USER=thallard
    * !ERROR! должно быть agaralambinia=thallard
    * получаем ничего
* echo $USER                                                 ok
* echo $?
* echo $USER213
    * !ERROR! должно быть 0
    * получаем ничего
* echo $USER$12USER$USER=4$USER12
    * !ERROR! должно быть agaralambinia2USERagaralambinia=4
    * получаем ничего
* echo $USER $123456789USER $USER123456789
    * !ERROR! должно быть agaralambinia 23456789USER
    * получаем ничего
* echo $USER $9999USER $8888USER $7777USER
    * !ERROR! должно быть agaralambinia 999USER 888USER 777USER
    * получаем ничего
* echo $USER $USER9999 $USER8888 $USER7777
    * !ERROR! должно быть agaralambinia
    * получаем ничего
* echo $USER $USER9999 $USER8888 $USER7777 "$USER"
    * !ERROR! должно быть agaralambinia agaralambinia
    * получаем ничего
* echo "$USER=12$USER"
    * !ERROR! должно быть agaralambinia=12agaralambinia
    * получаем ничего
* echo "$9USER" "'$USER=12$SOMETHING'"
    * !ERROR! должно быть USER 'agaralambinia=12'
    * получаем ничего
* echo $HOME/file
    * !ERROR! должно быть /Users/agaralambinia/file
    * получаем ничего
* echo "$HOME/file"
    * !ERROR! должно быть /Users/agaralambinia/file
    * получаем ничего
* echo "text" "text$USER" ... "$USER"                                                                         ok
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

блок ERROR:
* ;; test
    * !ERROR! должно быть -bash: syntax error near unexpected token `;;'
    * получаем ;;: No such file or directory
* | test
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address
* echo > <
    * !ERROR! должно быть -bash: syntax error near unexpected token `<'
    * получаем пустую строку
* echo | |
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address\nBad address
* <
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* ;
    * !ERROR! должно быть -bash: syntax error near unexpected token `;'
    * получаем ;: No such file or directory
* |
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address\nBad address
* | | |
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address\nBad address\nBad address\nBad address
* ;;;;;;;
    * !ERROR! должно быть -bash: syntax error near unexpected token `;;'
    * получаем ;;;;;;;: No such file or directory
* hello world
    * !ERROR! должно быть -bash: hello: command not found
    * получаем hello: No such file or directory
* ||||||||
    * !ERROR! должно быть -bash: syntax error near unexpected token `||'
    * получаем Bad address\nBad address\nBad address\nBad address\nBad address\nBad address\nBad address\nBad address\nBad address
* cat wouaf wouaf                               ok
* >
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* >>>>>>>>
    * !ERROR! должно быть -bash: syntax error near unexpected token `>>'
    * получаем Bad address
* <<<<<<<<<
    * !ERROR! должно быть -bash: syntax error near unexpected token `<<<'
    * получаем Bad address
* > > > >
    * !ERROR! должно быть -bash: syntax error near unexpected token `>'
    * получаем Bad address
* >> >> >> >>
    * !ERROR! должно быть -bash: syntax error near unexpected token `>>'
    * получаем Bad address
* ~
    * !ERROR! должно быть -bash: /Users/agaralambinia: is a directory
    * получаем ~: No such file or directory
* <<
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* /Users
    * !ERROR! должно быть -bash: /Users: is a directory
    * получаем agaralambinia
* .
    * !ERROR! должно быть .: usage: . filename [arguments]
    * получаем .: Permission denied
* ..
    * !ERROR! должно быть -bash: ..: command not found
    * получаем ..: Permission denied
* /
    * !ERROR! должно быть -bash: /: is a directory
    * получаем /: Permission denied
* \\\
    * !ERROR! должно быть -bash: \: command not found
    * получаем \\\: No such file or directory
* EechoE
    * !ERROR! должно быть -bash: EechoE: command not found
    * получаем EechoE: No such file or directory
* .echo.
    * !ERROR! должно быть -bash: .echo.: command not found
    * получаем .echo.: No such file or directory
* >echo>
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* <echo<
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* >>echo>>
    * !ERROR! должно быть -bash: syntax error near unexpected token `newline'
    * получаем Bad address
* ;echo;
    * !ERROR! должно быть -bash: syntax error near unexpected token `;'
    * получаем Bad address
* |echo|
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address\nBad address
* echo -n                                                          ok
* echo -n ;                                                        ok
* echo ;                                                           ok
* echo something ;                                                 ok
* rm -f something                                                  ok
* cat something                                                    ok
* | echo -n oui 
    * !ERROR! должно быть -bash: syntax error near unexpected token `|'
    * получаем Bad address
* ; echo -n oui
    * !ERROR! должно быть -bash: syntax error near unexpected token `;'
    * получаем ;: No such file or directory
* trying to destroy your minishell ; echo hello
    * !ERROR! должно быть -bash: trying: command not found
    * получаем trying: No such file or directory
* trying something again echo if you see this message thats not a good new
    * !ERROR! должно быть -bash: trying: command not found
    * получаем trying: No such file or directory
* qewew
    * !ERROR! должно быть -bash: qewew: command not found
    * получаем qewew: No such file or directory
* wtf
    * !ERROR! должно быть -bash: wtf: command not found
    * получаем wtf: No such file or directory
* hi im thallard
    * !ERROR! должно быть -bash: hi: command not found
    * получаем hi: No such file or directory
* nice to meet you if these tests are green                                  ok
* your minishell is perfect
    * !ERROR! должно быть -bash: your: command not found
    * получаем your: No such file or directory

блок EXPORT
* export | grep "SHLVL"
    * !ERROR! должно быть declare -x SHLVL="1"
    * получаем пустоту
* export | grep "OLDPWD"            ok
* export | grep "PWD"               ok
* export $? ; echo $?
    * !ERROR! должно быть -bash: export: `0': not a valid identifier\n1
    * получаем пустоту
* export TEST ; echo $TEST
    * !ERROR! должна быть пустая строка
    * получаем пустоту
* export TEST= ; echo $TEST
    * !ERROR! должна быть пустая строка
    * получаем Segmentation fault: 11
* export TEST=123 ; echo $TEST
    * !ERROR! должно быть 123
    * получаем Segmentation fault: 11
* export ___TEST=123 ; echo $TEST
    * !ERROR! должно быть 123
    * получаем Segmentation fault: 11
* export --TEST=123 ; echo $TEST
    * !ERROR! должно быть -bash: export: --: invalid option
export: usage: export [-nf] [name[=value] ...] or export -p
123
    * получаем minishell: --TEST=123: not a valid identifier
    123
* export ""=""
    * !ERROR! должно быть -bash: export: `=': not a valid identifier
    * получаем minishell: =: not a valid identifier
* export ''=''
    * !ERROR! должно быть -bash: export: `=': not a valid identifier
    * получаем minishell: =: not a valid identifier
* export "="="="
    * !ERROR! должно быть -bash: export: `===': not a valid identifier
    * получаем minishell: ===: not a valid identifier
* export '='='='
    * !ERROR! должно быть -bash: export: `===': not a valid identifier
    * получаем minishell: ===: not a valid identifier
* export TE\\\ST=100
    * !ERROR! должно быть -bash: export: `TE\ST=100': not a valid identifier
    * получаем minishell: TE\\\ST=100: not a valid identifier
* export TE-ST=100
    * !ERROR! должно быть -bash: export: `TE-ST=100': not a valid identifier
    * получаем minishell: TE-ST=100: not a valid identifier
* export -TEST=100
* export TEST-=100
* export _TEST=100
* export TEST ; env | grep "TEST"
* export ==========
* export 1TEST=
* export TEST
* export ""=""
* export TES=T=""
* export TE+S=T=""
* export TES\\\\T=123
* export TES.T=123
* export TES\\\$T=123
* export TES\\\\T
* export TES.T=123
* export TES+T=123
* export TES=T=123
* export TES}T=123
* export TES{T=123
* export TES-T=123
* export -TEST=123
* export _TEST=123
* export TES_T=123
* export TEST_=123
* export TE*ST=123
* export TES#T=123
* export TES@T=123
* export TES!T=123
* export TES$?T=123
* export =============123
* export +++++++=123
* export ________=123
* export export
* export echo
* export pwd
* export cd
* export export
* export unset
* export sudo
* export TES^T=123
* export TES!T=123
* export TES\~T=123
* export TEST+=100 ; echo $TEST ; export TEST+=200 ; echo $TEST
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST ; cd $TEST
* export TEST=$USER ; echo $TEST ; unset PWD ; export TEST+=$PWD ; echo $TEST
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST ; cd $TEST
* export TEST=$USER ; echo $TEST ; unset PWD ; export TEST+=$PWD ; echo $TEST ; cd $TEST ; echo $PWD
* export TEST=123 0$TEST=0123 ; echo $TEST
* export TEST ; env | grep "TEST" ; unset TEST
* export TEST= ; env | grep "TEST" ; unset TEST
* export TEST="" ; env | grep "TEST" ; unset TEST
* export TEST='' ; env | grep "TEST" ; unset TEST
* export TEST=100 TEST2=100 ; env | grep "TEST" ; unset TEST TEST2
* export TEST=100 TEST1=200 ; env | grep "TEST" ; unset TEST TEST1
* export TEST="100" ; env | grep "TEST" ; unset TEST
* export TEST='"$USER"' ; env | grep "TEST" ; unset TEST
* export TEST="$USER" ; env | grep "TEST" ; unset TEST
* export TEST="$USER$USER" ; env | grep "TEST" ; unset TEST
* export TEST="'$USER'""test" ; env | grep "TEST" ; unset TEST
* export TEST="$USER" TEST1=$TEST ; env | grep "TEST" ; unset TEST
* export TEST=LOL ; export TEST+=LOL ; env | grep "TEST" ; unset TEST
* export TEST=LOL ; export TEST-=LOL ; env | grep "TEST" ; unset TEST
-----------------------------------------------------------------
**LOG 06.07.2024**
- Dasha: found another checker, we have fuckups with exit codes https://github.com/cacharle/minishell_test/blob/master/README.md
