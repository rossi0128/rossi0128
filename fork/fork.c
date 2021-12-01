#include <stdio.h>
#include <unistd.h>

int wib(int no1, int no2)
{
    int result, diff;
    diff = no1 - no2;
    result = no1 / diff;
    return result;
}

int main()
{
    int   pid;

    pid = fork();
    if (pid < 0) {
        printf("fork err\n");
        exit(-1);
    }
    else if (pid == 0) {
        /* in child process */
        sleep(4);

        int     value = 10;
        int     div = 6;
        int     total = 0;
        int     i = 0;
        int     result = 0;

        for (i = 0; i < 10; i++) {
            result = wib(value, div);
            total += result;
            printf("%d wibed by %d result %d\n", value, div, result);
            div++;
            value--;
        }

        printf("%d wibed by %d total %d\n", value, div, total);
        exit(0);
    }
    else {
        /* in parent process */
        sleep(4);
        wait(-1);
        exit(0);
    }
}
