#! /bin/sh

#cat cases.txt | xargs project/minishell -c > mini_out.txt

echo ==================CD==================
echo ==================CD================== > mini_out.txt
echo ==================CD================== > bash_out.txt
< cases/cd_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/cd_cases.txt bash | grep bash: -v >> bash_out.txt

echo =================ECHO=================
echo =================ECHO================= >> mini_out.txt
echo =================ECHO================= >> bash_out.txt
< cases/echo_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/echo_cases.txt bash | grep bash: -v >> bash_out.txt

echo ================EXPORT================
echo ================EXPORT================ >> mini_out.txt
echo ================EXPORT================ >> bash_out.txt
< cases/export_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/export_cases.txt bash | grep bash: -v >> bash_out.txt

echo ================PARSE=================
echo ================PARSE================= >> mini_out.txt
echo ================PARSE================= >> bash_out.txt
< cases/parse_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/parse_cases.txt bash | grep bash: -v >> bash_out.txt

echo ================UNSET=================
echo ================UNSET================= >> mini_out.txt
echo ================UNSET================= >> bash_out.txt
< cases/unset_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/unset_cases.txt bash | grep bash: -v >> bash_out.txt

echo ================PIPES=================
echo ================PIPES================= >> mini_out.txt
echo ================PIPES================= >> bash_out.txt
< cases/pipes_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/pipes_cases.txt bash | grep bash: -v >> bash_out.txt

echo =================MORE=================
echo =================MORE================= >> mini_out.txt
echo =================MORE================= >> bash_out.txt
< cases/more_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
< cases/more_cases.txt bash | grep bash: -v >> bash_out.txt

#echo ================BONUS=================
#echo ================BONUS================= >> mini_out.txt
#echo ================BONUS================= >> bash_out.txt
#< cases/bonus_cases.txt project/minishell | grep minishell: -v >> mini_out.txt
#< cases/bonus_cases.txt bash | grep bash: -v >> bash_out.txt

echo ERRORS:
diff bash_out.txt mini_out.txt
