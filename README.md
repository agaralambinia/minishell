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
* echo "$USER$USER$USER"                                     ok
* echo '$USER'"$USER"'$USER'                                 ok
* echo '"$USER"''$USER'"""$USER"                             ok
* echo " $USER  "'$PWD'                                      ok
* echo " $USER  \$ "'$PWD'                                   ok
* echo $USER=4                                               ok
* echo $USER=thallard                                        ok
* echo $USER                                                 ok
* echo $?                                                    ok
* echo $USER213                                              ok
* echo $USER$12USER$USER=4$USER12                            ok
* echo $USER $123456789USER $USER123456789                   ok
* echo $USER $9999USER $8888USER $7777USER                   ok
* echo $USER $USER9999 $USER8888 $USER7777                   ok
* echo $USER $USER9999 $USER8888 $USER7777 "$USER"           ok
* echo "$USER=12$USER"                                       ok
* echo "$9USER" "'$USER=12$SOMETHING'"                       ok
* echo $HOME/file                                            ok
* echo "$HOME/file"                                          ok
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
* echo $PWD; echo $OLDPWD; cd //; pwd; echo $PWD; echo $OLDPWD                                                ok
* echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD                                               ok
* echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD
* echo $PWD; echo $OLDPWD; cd //////////////////////////////////////////////////////; pwd; echo $PWD; echo $OLDPWD          ok
* echo $PWD; echo $OLDPWD; cd; echo $OLDPWD                                                                   ok
* echo $PWD; echo $OLDPWD; cd ' /'; pwd; echo $PWD; echo $OLDPWD                                              ok
* echo $PWD; echo $OLDPWD; cd ' / '; pwd; echo $PWD; echo $OLDPWD                                             ok
* echo $PWD; echo $OLDPWD; cd '                  /'; pwd; echo $PWD; echo $OLDPWD                             ok
* echo $PWD; echo $OLDPWD; cd '                  /              '; pwd; echo $PWD; echo $OLDPWD               ok
* echo $PWD; echo $OLDPWD; cd ' // '; pwd; echo $PWD; echo $OLDPWD                                            ok
* echo $PWD; echo $OLDPWD; cd //home; pwd; echo $PWD; echo $OLDPWD                                            ok
* echo $PWD; echo $OLDPWD; cd ' //home'; pwd; echo $PWD; echo $OLDPWD                                         ok
* echo $PWD; echo $OLDPWD; cd '     //home    '; pwd; echo $PWD; echo $OLDPWD                                 ok

блок ERROR:
* ;; test                                               ok (не обрабатываем ;)
* | test                                                ok
* echo > <                                              ok
* echo | |                                              ok
* <                                                     
* ;                                                     
* |                                                     
* | | |                                                 
* ;;;;;;;                                               
* hello world                                           
* ||||||||                                              
* cat wouaf wouaf                                       
* >                                                     
* >>>>>>>>                                              
* <<<<<<<<<                                             
* > > > >                                               
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
* export | grep "SHLVL"                         ok
* export | grep "OLDPWD"                        ok
* export | grep "PWD"                           ok
* export $? ; echo $?                           ok
* export TEST ; echo $TEST                      ok
* export TEST= ; echo $TEST                     ok
* export TEST=123 ; echo $TEST                  ok
* export ___TEST=123 ; echo $TEST               ok
* export --TEST=123 ; echo $TEST                ok (не поддерживаем опции)
* export ""=""                                  ok
* export ''=''                                  ok
* export "="="="                                ok
* export '='='='                                ok
* export TE\\\ST=100                            ok (не поддерживаем \)
* export TE-ST=100                              ok
* export -TEST=100                              ok (не поддерживаем опции)
* export TEST-=100                              ok
* export _TEST=100                              ok
* export TEST ; env | grep "TEST"               ok
* export ==========                             ok
* export 1TEST=                                 ok
* export TEST                                   ok
* export ""=""                                  ok
* export TES=T=""                               ok
* export TE+S=T=""                              ok
* export TES\\\\T=123                           ok (не поддерживаем \)
* export TES.T=123                              ok
* export TES\\\$T=123
    * не ок export: `TES\\\Apple_Terminal=123': not a valid identifier
* export TES\\\\T                               ok (не поддерживаем \)
* export TES.T=123                              ok
* export TES+T=123                              ok
* export TES=T=123                              ok
* export TES}T=123                              ok
* export TES{T=123                              ok
* export TES-T=123                              ok
* export -TEST=123                              ok (не поддерживаем опции)
* export _TEST=123                              ok
* export TES_T=123                              ok
* export TEST_=123                              ok
* export TE*ST=123                              ok
* export TES#T=123                              ok
* export TES@T=123                              ok
* export TES!T=123                              ok (не поддерживаем !)
* export TES$?T=123
    * ERROR не ок, разыменовывает $?
* export =============123                       ok
* export +++++++=123                            ok
* export ________=123                           ok
* export export                                 ok
* export echo                                   ok
* export pwd                                    ok
* export cd                                     ok
* export unset                                  ok
* export sudo                                   ok
* export TES^T=123                              ok
* export TES!T=123                              ok (не поддерживаем !)
* export TES\~T=123
* export TEST+=100 ; echo $TEST ; export TEST+=200 ; echo $TEST          ok
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST     ok
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST ; cd $TEST       ok
* export TEST=$USER ; echo $TEST ; unset PWD ; export TEST+=$PWD ; echo $TEST       ok
* export TEST=$USER ; echo $TEST ; export TEST+=$PWD ; echo $TEST ; cd $TEST       ok
* export TEST=$USER ; echo $TEST ; unset PWD ; export TEST+=$PWD ; echo $TEST ; cd $TEST ; echo $PWD         ok
* export TEST=123 0$TEST=0123 ; echo $TEST                             ok
* export TEST ; env | grep "TEST" ; unset TEST                         ok
* export TEST= ; env | grep "TEST" ; unset TEST                        ok
* export TEST="" ; env | grep "TEST" ; unset TEST                      ok
* export TEST='' ; env | grep "TEST" ; unset TEST                      ok
* export TEST=100 TEST2=100 ; env | grep "TEST" ; unset TEST TEST2     ok
* export TEST=100 TEST1=200 ; env | grep "TEST" ; unset TEST TEST1     ok
* export TEST="100" ; env | grep "TEST" ; unset TEST                   ok
* export TEST='"$USER"' ; env | grep "TEST" ; unset TEST               ok
* export TEST="$USER" ; env | grep "TEST" ; unset TEST                 ok
* export TEST="$USER$USER" ; env | grep "TEST" ; unset TEST            ok
* export TEST="'$USER'""test" ; env | grep "TEST" ; unset TEST         ok
* export TEST="$USER" TEST1=$TEST ; env | grep "TEST" ; unset TEST     ok
* export TEST=LOL ; export TEST+=LOL ; env | grep "TEST" ; unset TEST  ok
* export TEST=LOL ; export TEST-=LOL ; env | grep "TEST" ; unset TEST  ok

блок UNSET:
* unset                                                 ok
* export TEST=100 ; echo $TEST ; unset TEST             ok
* unset doesntexist                                     ok
* unset PWD                                             ok
* unset PWD ; echo $PWD                                 ok
* unset OLDPWD ; echo $PWD                              ok
* unset PATH ; ls                                       ok
* unset PATH ; echo "something"                         ok
* unset PATH ; bash                                     ok
* unset TES\\\\T                                        ok (не обрабатываем \)
* unset TES;T                                           ok (не обрабатываем ;)
* unset TES.T                                           ok
* unset TES+T                                           ok
* unset TES=T                                           ok
* unset TES}T                                           ok
* unset TES{T                                           ok
* unset TES-T                                           ok
* unset -TEST                                           ok (не обрабатываем опции)
* unset _TEST                                           ok
* unset TES_T                                           ok
* unset TEST_                                           ok
* unset TE*ST                                           ok
* unset TES#T                                           ok
* unset TES@T                                           ok
* unset TES!T                                           ok (не обрабатываем !)
* unset TES$?T
    * скорее всего ERROR и подставляется $?
* unset ============                                    ok
* unset +++++++                                         ok
* unset ________                                        ok
* unset export                                          ok
* unset echo                                            ok
* unset pwd                                             ok
* unset cd                                              ok
* unset unset                                           ok
* unset sudo                                            ok
* unset TES^T                                           ok
* unset TES!T                                           ok (не обрабатываем !)
* unset TES\~T                                          ok (не обрабатываем \)


  БЛОК PIPES - все ок

* env | grep "_="
* env | grep "SHLVL"
* echo oui | cat -e
* echo oui | echo non | echo something | grep oui
* echo oui | echo non | echo something | grep non
* echo oui | echo non | echo something | grep something
* pwd ; cd .. | echo "something"
* pwd ; cd .. | echo "something" ; pwd
* pwd ; cd / | echo "something" ; pwd
* cd .. | pwd
* ifconfig | grep ":"
* ifconfig | grep nothing
* whoami | grep $USER
* whoami | grep $USER > file; cat file
* whoami | cat -e | cat -e > file ; cat file ; echo $USER
* cat Makefile | grep "FLAGS"
* cat Makefile | cat -e | cat -e
* cat Makefile | grep "FLAGS" | grep "FLAGS" | cat -e
* export TEST=123 | cat -e | cat -e ; echo $TEST
* unset TEST | cat -e
* echo test | cat -e | cat -e | cat -e
* whereis ls | cat -e | cat -e > test
* echo test | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e
* ls -la | grep "."
* whereis grep > file ; cat file ; ls -la file | grep "grep"
* whereis grep > file ; cat file ; ls -la file
* ls -la > file ; cat < file doesntexist





БЛОК REDIRECTIONS
* ls -la > file ; cat file
* ifconfig | grep "192.168" > file ; cat file
* echo text > file text2 > file1 ; cat file file1
* echo text > file ; cat file
* echo text > file ; cat file
* echo text > $PWD/file text2 ; cat $PWD/file
* echo text$USER > file $USER ; cat file
* echo "text"$USER > file ; cat file
* echo $USER"text""'$USER'""$USER" > file >> file2 $USER ; cat file file2
* echo '$USER'"123$USER123""text" > file ; cat file
* echo "text" > file >> file1 ; cat file file1
* echo "text" > file text2 ; cat file
* echo "text" > file text ; cat file
* echo "text" > file ; cat file
* echo "text" > file ; cat file ; rm -f file
* echo text$USER > file $USER ; cat file ; rm -f file
* echo "text"$USER > file ; cat file ; rm -f file
* echo $USER"text""'$USER'""$USER" > file >> file2 $USER ; cat file file2 ; rm -f file file2
* echo '$USER'"123$USER123""text" > file ; cat file ; rm -f file
* echo "text" > file >> file1 ; cat file file1 ; rm -f file file1
* echo $USER  $USER7777"text"$USER $USER9999 > file $USER $USER9999 ; cat file ; rm -f file
* echo $USER  $USER7777"text"$USER $USER9999 > file $USER $USER9999 ; cat file
* echo something > > file ; cat < file - проблемка в лексере
* echo something > file ; cat file
* echo something > file ; >> file ls -la ; cat file
* > file echo something ; cat file
* > file cat test.sh
* cat < README.md
* cat < README.md test.sh
* cat < README.md | wc -l | xargs
* cat < README.md > file ; cat file | wc -l | xargs > file1 ; cat file1



БЛОК EXIT
* exit
* exit 0 0
* exit 42 42
* exit -42 -24
* exit 42
* exit 42 53 68
* exit 259
* exit -12030
* exit --1239312
* exit ++++1203020103
* exit +0
* exit ++++++0
* exit -----0
* exit azerty
* exit kewkwqke
* exit a
* exit z
* exit "1"
* exit "2"
* exit "+102"
* exit "1230"
* exit "+++1230"
* exit "1"23
* exit "2"32"32"
* exit "'42'"
* exit '42'"42"42
* exit +'42'"42"42
* exit -'42'"42"42
* exit 9223372036854775807
* exit 9223372036854775808 - т.к. число больше long long, там что-то в мозгах баша ломается и он не воспринимает как число. наш шелл норм обрабатывает. предлагаю забить
* exit -4
* exit wrong
* exit wrong_command
* exit something
* exit 1 ; echo if you see this message then your minishell have some troubles
* exit -1 ; echo if you see this message then your minishell have some troubles
* exit 42 ; echo if you see this message then your minishell have some troubles
* exit 0 ; echo if you see this message then your minishell have some troubles
* exit --000 ; echo if you see this message then your minishell have some troubles
* exit +++++++000 ; echo if you see this message then your minishell have some troubles
* exit ++++3193912939 ; echo if you see this message then your minishell have some troubles
* exit ---31232103012 ; echo if you see this message then your minishell have some troubles
* exit "something" ; echo if you see this message then your minishell have some troubles
* exit q ; echo if you see this message then your minishell have some troubles
* exit help ; echo if you see this message then your minishell have some troubles
* exit export ; echo if you see this message then your minishell have some troubles
* exit echo ; echo if you see this message then your minishell have some troubles
* exit cd .. ; echo if you see this message then your minishell have some troubles
* exit 0 0 ; echo if you see this message then your minishell have some troubles
* exit something somethingv2 ; echo if you see this message then your minishell have some troubles
exit 42 42 42 42 42 ; echo if you see this message then your minishell have some troubles
exit echo something ; echo if you see this message then your minishell have some troubles
exit exit ; echo if you see this message then your minishell have some troubles
-----------------------------------------------------------------
**LOG 06.07.2024**
- Dasha: found another checker, we have fuckups with exit codes https://github.com/cacharle/minishell_test/blob/master/README.md
