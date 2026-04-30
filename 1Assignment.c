#include <stdio.h>
#include <string.h>
#define SIZE 15 // to just easly changing the size of the buffer
// defining the buffer
typedef struct {
    char buffer[SIZE]; //buffer size 
    int head;//buffer head
    int tail;// buffer tail
    int count;
} CircularBuffer;

//intilizing the buffer
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// function to check if the buffer is full
int isFull(CircularBuffer *cb) {
    if (cb->count == SIZE) {
        return 1;
    }
    return 0;
}
// function to check if the buffer is empty
int isEmpty(CircularBuffer *cb) {
    if (cb->count == 0) {
        return 1;
    }
    return 0;
}

// to write a charecter in the buffer
void writeChar(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

//to read charecter from the buffer
char readChar(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;

    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    int len = strlen(name);
    if (name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    strcat(name, "CE-ESY");

    printf("String to store: %s\n", name);

    // wrtining each letter in the buffer
    for (int i = 0; i < strlen(name); i++) {
        writeChar(&cb, name[i]);
    }

    // to read and write
    printf("Reading from buffer: ");
    while (!isEmpty(&cb)) {
        char c = readChar(&cb);
        if (c != '\0') {
            printf("%c", c);
        }
    }

    printf("\n");

   // to recheck if the buffer is empty
    if (isEmpty(&cb)) {
        printf("Buffer is empty now.\n");
    } else {
        printf("Buffer still has data.\n");
    }

    return 0;
}
