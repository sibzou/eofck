#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <err.h>

int check_file(char *path) {
    int fd = open(path, O_RDONLY);
    if(fd == -1) {
        warn("can't open %s", path);
        return EXIT_FAILURE;
    }

    struct stat stat_info;
    if(fstat(fd, &stat_info) == -1) {
        warn("can't get the size of %s", path);
        return EXIT_FAILURE;
    }

    if(stat_info.st_size == 0) {
        return 0;
    }

    if(lseek(fd, -1, SEEK_END) == -1) {
        warn("can't move at the end of %s", path);
        return EXIT_FAILURE;
    }

    char c;
    if(read(fd, &c, 1) == -1) {
        warn("can't read %s", path);
        return EXIT_FAILURE;
    }

    if(c != '\n') {
        warnx("no line feed at the end of %s", path);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        errx(EXIT_FAILURE, "need at least one file path");
    }

    int exit_status = 0;

    for(int i = 1; i < argc; i++) {
        if(check_file(argv[i]) == EXIT_FAILURE) {
            exit_status = EXIT_FAILURE;
        }
    }

    return exit_status;
}
