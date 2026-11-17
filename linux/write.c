#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h> 						// For file permissions

int main() {
    int fd, res;
    char buf[1000] = "ram technology";
    
   							 // Open the file with proper permissions
    fd = open("/home/pandari/Desktop/ram/ram_txt/write.txt", O_CREAT | O_WRONLY, 0644);  						// Corrected permissions to 0644
    printf("File fd = %d\n", fd);

    if (fd < 0) {
        printf("File not opened or bad credentials\n");
    } else {
       							 // Write to the file
        res = write(fd, buf, strlen(buf));
        
        if (res < 0) {
            printf("Error writing to the file\n");
        } else {
            printf("Bytes written: %d\n", res);
        }

        						// Close the file
        close(fd);
    }

    return 0;
}

