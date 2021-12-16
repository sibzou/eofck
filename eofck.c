#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void syscall_error(int ret, char *syscall_name, char *proc_name) {
    if(ret == -1) {
        fprintf(stderr, "%s: ", proc_name);
        perror(syscall_name);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int ret;

    if(argc != 2) {
        fprintf(stderr, "%s: need a single file path argument\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    syscall_error(fd, "open", argv[0]);

    struct stat stat_info;
    ret = fstat(fd, &stat_info);
    syscall_error(ret, "fstat", argv[0]);

    if(stat_info.st_size == 0) {
        exit(0);
    }

    ret = lseek(fd, -1, SEEK_END);
    syscall_error(ret, "lseek", argv[0]);

    char c;
    ret = read(fd, &c, 1);
    syscall_error(ret, "read", argv[0]);

    if(c != '\n') {
        fprintf(stderr, "%s: no line feed at the end of %s\n", argv[0], argv[1]);
        exit(1);
    }
}
