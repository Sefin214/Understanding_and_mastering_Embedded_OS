#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void system_call_example() {
    int fd = open("sys.txt", O_WRONLY | O_CREAT, 0644);
    write(fd, "Hello System Call\n", 18);
    close(fd);
}

void library_call_example() {
    FILE *fp = fopen("lib.txt", "w");
    fprintf(fp, "Hello Library Call\n");
    fclose(fp);
}

int main() {
    system_call_example();
    library_call_example();
    return 0;
}
