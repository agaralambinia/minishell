Объявление:

    int stat(const char *restrict path, struct stat *restrict buf);

    int lstat(const char *restrict path, struct stat *restrict buf);

    int fstat(int fildes, struct stat *buf);
    
Header files:

    <unistd.h>
    
ОПИСАНИЕ
Функция stat() получает информацию о файле, на который указывает путь.  Разрешение на чтение, запись или выполнение именованного файла не требуется, но все каталоги, перечисленные в имени пути, ведущего к файлу, должны быть доступны для поиска.

Функция lstat() похожа на stat(), за исключением случая, когда именованный файл является символической ссылкой; lstat() возвращает информацию информацию о ссылке, в то время как stat() возвращает информацию о файле, на который ссылается ссылка.  Для символических ссылок член st_mode содержит значимую информацию при использовании макросов типа файла, а член st_size содержит длину имени пути, содержащегося в символической ссылке. Биты режима файла и содержимое остальных членов stat-структуры не определены. Значение, возвращаемое в члене st_size, представляет собой длину содержимого символической ссылки и не считает идущие следом нули.

Команда fstat() получает ту же информацию об открытом файле, известном по файловому дескриптору fildes.

Аргумент buf - это указатель на структуру stat, определенную в <sys/stat.h>, в которую помещается информация, касающаяся файла.  Если не определен макрос _DARWIN_FEATURE_64_BIT_INODE (подробнее об этом макросе см. ниже), то структура stat определяется как макрос), структура stat определяется как:

struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is NOT defined */
         dev_t    st_dev;    /* device inode resides on */
         ino_t    st_ino;    /* inode's number */
         mode_t   st_mode;   /* inode protection mode */
         nlink_t  st_nlink;  /* number of hard links to the file */
         uid_t    st_uid;    /* user-id of owner */
         gid_t    st_gid;    /* group-id of owner */
         dev_t    st_rdev;   /* device type, for special file inode */
         struct timespec st_atimespec;  /* time of last access */
         struct timespec st_mtimespec;  /* time of last data modification */
         struct timespec st_ctimespec;  /* time of last file status change */
         off_t    st_size;   /* file size, in bytes */
         quad_t   st_blocks; /* blocks allocated for file */
         u_long   st_blksize;/* optimal file sys I/O ops blocksize */
         u_long   st_flags;  /* user defined flags for file */
         u_long   st_gen;    /* file generation number */
     };

Поля struct stat, связанные со временем, следующие:

st_atime 
Время последнего обращения к файловым данным.  Изменяется системными вызовами mknod(2), utimes(2) и read(2).

st_mtime 
Время последнего изменения данных файла.  Изменяется системными вызовами mknod(2), utimes(2) и write(2).

st_ctime 
Время последнего изменения статуса файла (модификация данных inode).  Изменяется системными вызовами chmod(2), chown(2), link(2), mknod(2), rename(2), unlink(2), utimes(2) и write(2).

st_birthtime 
Время создания файла. Устанавливается только один раз при создании файла. Это поле доступно только в 64-битных вариантах инодов. В файловых системах, где время рождения недоступно, это поле устанавливается в 0 (т. е. в эпоху).

Поля структур, связанные с размером, выглядят следующим образом:

st_blksize 
Оптимальный размер блока ввода-вывода для файла.

st_blocks 
Фактическое количество блоков, выделенных для файла, в 512-байтовых единицах.  Поскольку короткие символические ссылки хранятся в inodes, это число может быть равно нулю.

Cлово информации о состоянии st_mode имеет следующие биты:

     #define S_IFMT 0170000 /* тип файла */
     #define S_IFIFO 0010000 /* именованный канал (fifo) */
     #define S_IFCHR 0020000 /* специальный символ */
     #define S_IFDIR 0040000 /* директория */
     #define S_IFBLK 0060000 /* специальный блок */
     #define S_IFREG 0100000 /* обычный */
     #define S_IFLNK 0120000 /* символическая ссылка */
     #define S_IFSOCK 0140000 /* сокет */
     #define S_IFWHT 0160000 /* белое пятно */
     #define S_ISUID 0004000 /* установка идентификатора пользователя при выполнении */
     #define S_ISGID 0002000 /* установить идентификатор группы при выполнении */
     #define S_ISVTX 0001000 /* сохранять замененный текст даже после использования */
     #define S_IRUSR 0000400 /* разрешение на чтение, владелец */
     #define S_IWUSR 0000200 /* разрешение на запись, владелец */
     #define S_IXUSR 0000100 /* разрешение на выполнение/поиск, владелец */

     Список режимов доступа см. в <sys/stat.h>, access(2) и chmod(2).

     Список файловых флагов в поле st_flags см. в <sys/stat.h> и chflags(2).

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ
При успешном завершении возвращается значение 0.  В противном случае возвращается значение -1 и устанавливается значение errno, указывающее на ошибку.
