#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512
#define MAX_PACKET_SIZE 256

char mainBuffer[BUFFER_SIZE];
int bufferLen = 0;

const char *DELIM = "zzaa";
const int DELIM_LEN = 4;

				// Mock functions (replace with actual)
int readFromBuffer(char *dest);
void sendToConsumer(char *data, int len);
					// Function to find delimiter index
int findDelimiter(char *buf, int len) {
    for (int i = 0; i <= len - DELIM_LEN; i++) {
        if (memcmp(&buf[i], DELIM, DELIM_LEN) == 0) {
            return i;
        }
    }
    return -1;
}

void processBuffer() {
    while (1) {
        int index = findDelimiter(mainBuffer, bufferLen);

        if (index == -1)
            break; 				// No complete packet yet

       				 // Extract packet
        if (index > MAX_PACKET_SIZE) {
            				// Invalid packet (too large)
            printf("Error: Packet too large\n");
            				// Remove invalid data including delimiter

            memmove(mainBuffer, mainBuffer + index + DELIM_LEN, bufferLen - (index + DELIM_LEN));
            bufferLen -= (index + DELIM_LEN);
            continue;
        }

       				 // Valid packet
        sendToConsumer(mainBuffer, index);

       				 // Remove processed packet + delimiter
        memmove(mainBuffer, mainBuffer + index + DELIM_LEN,
                bufferLen - (index + DELIM_LEN));
        bufferLen -= (index + DELIM_LEN);
    }
}
void uartTask() {
    char temp[64];

    while (1) {
        int bytesRead = readFromBuffer(temp);

        if (bytesRead <= 0)
            continue;
        					// Check overflow
        if (bufferLen + bytesRead > BUFFER_SIZE) {
            printf("Buffer Overflow! Resetting buffer\n");
            bufferLen = 0;
            continue;
        }
        					// Append new data
        memcpy(mainBuffer + bufferLen, temp, bytesRead);
        bufferLen += bytesRead;
      					 // Process packets
        processBuffer();
    }
}

