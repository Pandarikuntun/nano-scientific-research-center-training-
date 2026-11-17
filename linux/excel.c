#include <stdio.h>
#include <unistd.h>

int main()
{
    // int ret;

    printf("I am going to execute program\n");

//     execl("/bin/ls", "ls", "-l", NULL);

//     execl("/bin/ps", "ps", "-elf", NULL);

    execl("/bin/vim", "nano", "fork.c", NULL);

    // execl("/bin/pstree", "pstree", NULL);

    // execl("/home/lenovo/Desktop/Amrita/AES_LINUX/2live_process_demo/new/a.out",
    //       "./a.out", 0);

    // OS defined pg,
    // final arg 0 indicates end of string..

    printf("1 executed ls program\n");
    printf("2 executed ls program\n");
    printf("3 executed ls program\n");
}
