Объявление:

    void rl_replace_line(const char *text, int clear_undo);

Header files:

    <stdio.h>
    <readline/readline.h>

Заменяет содержимое rl_line_buffer на значение переменной text. Указатель и пометка сохраняются, если возможно. Если clear_undo имеет не нулевое значение, undo-список асоциированный с данной строкой, очищается.