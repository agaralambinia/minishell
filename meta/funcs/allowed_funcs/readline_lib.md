Библиотека readline не является стандартной частью  MacOS и должна компилироваться отдельно вместе с программой.

Компиляция согласно файлу README:

To build the library, try typing `./configure', then `make'.  The
configuration process is automated, so no further intervention should
be necessary.  Readline builds with `gcc' by default if it is
available.  If you want to use `cc' instead, type

        CC=cc ./configure

if you are using a Bourne-style shell.  If you are not, the following
may work:

        env CC=cc ./configure

Подробности по установку в файле  INSTALL

Man файл находится в поддиректориии doc.
