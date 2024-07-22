#! /bin/sh

echo ==================CD==================
echo ==================CD================== > mini_out.txt
echo ==================CD================== > bash_out.txt
echo ==================CD================== > errors.diff
echo > cd_mini_out.txt
echo > cd_bash_out.txt
< cases/cd_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep 'minishell:' -v >> cd_mini_out.txt
< cases/cd_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> cd_bash_out.txt
diff cd_bash_out.txt cd_mini_out.txt >> errors.diff
< cd_mini_out.txt cat >> mini_out.txt
< cd_bash_out.txt cat >> bash_out.txt

echo =================ECHO=================
echo =================ECHO================= >> mini_out.txt
echo =================ECHO================= >> bash_out.txt
echo =================ECHO================= >> errors.diff
echo > echo_mini_out.txt
echo > echo_bash_out.txt
< cases/echo_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep 'minishell:' -v >> echo_mini_out.txt
< cases/echo_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> echo_bash_out.txt
diff echo_bash_out.txt echo_mini_out.txt >> errors.diff
< echo_mini_out.txt cat >> mini_out.txt
< echo_bash_out.txt cat >> bash_out.txt

echo ================EXPORT================
echo ================EXPORT================ >> mini_out.txt
echo ================EXPORT================ >> bash_out.txt
echo ================EXPORT================ >> errors.diff
echo > export_mini_out.txt
echo > export_bash_out.txt
< cases/export_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep 'minishell:' -v >> export_mini_out.txt
< cases/export_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> export_bash_out.txt
diff export_bash_out.txt export_mini_out.txt >> errors.diff
< export_mini_out.txt cat >> mini_out.txt
< export_bash_out.txt cat >> bash_out.txt

echo ================PARSE=================
echo ================PARSE================= >> mini_out.txt
echo ================PARSE================= >> bash_out.txt
echo ================PARSE================= >> errors.diff
echo > parse_mini_out.txt
echo > parse_bash_out.txt
< cases/parse_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> parse_mini_out.txt
< cases/parse_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> parse_bash_out.txt
diff parse_bash_out.txt parse_mini_out.txt >> errors.diff
< parse_mini_out.txt cat >> mini_out.txt
< parse_bash_out.txt cat >> bash_out.txt

echo ================UNSET=================
echo ================UNSET================= >> mini_out.txt
echo ================UNSET================= >> bash_out.txt
echo ================UNSET================= >> errors.diff
echo > unset_mini_out.txt
echo > unset_bash_out.txt
< cases/unset_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> unset_mini_out.txt
< cases/unset_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> unset_bash_out.txt
diff unset_bash_out.txt unset_mini_out.txt >> errors.diff
< unset_mini_out.txt cat >> mini_out.txt
< unset_bash_out.txt cat >> bash_out.txt

echo ================PIPES=================
echo ================PIPES================= >> mini_out.txt
echo ================PIPES================= >> bash_out.txt
echo ================PIPES================= >> errors.diff
echo > pipes_mini_out.txt
echo > pipes_bash_out.txt
< cases/pipes_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> pipes_mini_out.txt
< cases/pipes_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' | sed 's/bash: //'>> pipes_bash_out.txt
diff pipes_bash_out.txt pipes_mini_out.txt >> errors.diff
< pipes_mini_out.txt cat >> mini_out.txt
< pipes_bash_out.txt cat >> bash_out.txt

echo =============REDIRECTIONS=============
echo =============REDIRECTIONS============= >> mini_out.txt
echo =============REDIRECTIONS============= >> bash_out.txt
echo =============REDIRECTIONS============= >> errors.diff
echo > redir_mini_out.txt
echo > redir_bash_out.txt
< cases/redirections.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> redir_mini_out.txt
< cases/redirections.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' | sed 's/bash: //'>> redir_bash_out.txt
diff redir_bash_out.txt redir_mini_out.txt >> errors.diff
< redir_mini_out.txt cat >> mini_out.txt
< redir_bash_out.txt cat >> bash_out.txt

echo =================MORE=================
echo =================MORE================= >> mini_out.txt
echo =================MORE================= >> bash_out.txt
echo =================MORE================= >> errors.diff
echo > more_mini_out.txt
echo > more_bash_out.txt 
< cases/more_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> more_mini_out.txt
< cases/more_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> more_bash_out.txt
diff more_bash_out.txt more_mini_out.txt >> errors.diff
< more_mini_out.txt cat >> mini_out.txt
< more_bash_out.txt cat >> bash_out.txt

echo ================BONUS=================
echo ================BONUS================= >> mini_out.txt
echo ================BONUS================= >> bash_out.txt
echo ================BONUS================= >> errors.diff
echo > bonus_mini_out.txt
echo > bonus_bash_out.txt 
< cases/bonus_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> bonus_mini_out.txt
< cases/bonus_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> bonus_bash_out.txt
diff bonus_bash_out.txt bonus_mini_out.txt >> errors.diff
< bonus_mini_out.txt cat >> mini_out.txt
< bonus_bash_out.txt cat >> bash_out.txt

echo ================ERROR=================
echo ================ERROR================= >> mini_out.txt
echo ================ERROR================= >> bash_out.txt
echo ================ERROR================= >> errors.diff
echo > error_mini_out.txt
echo > error_bash_out.txt 
< cases/error_cases.txt project/minishell 2>&1 | sed 's/minishell: //' | grep minishell: -v >> error_mini_out.txt
< cases/error_cases.txt bash 2>&1 | sed 's/bash: line [0-9]*: //' >> error_bash_out.txt
diff error_bash_out.txt error_mini_out.txt >> errors.diff
< error_mini_out.txt cat >> mini_out.txt
< error_bash_out.txt cat >> bash_out.txt

echo Look into errors.diff
#diff bash_out.txt mini_out.txt > errors.diff

