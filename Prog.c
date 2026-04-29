#include <stdio.h>
#include <string.h>
#define SIZE 10 

typedef struct {
    char buffer[SIZE];
    int head;   
    int tail;
    int count;  
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}


void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow!\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE; 
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow!\n");
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

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    strcat(name, "CE-ESY");
    
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    printf("\n");
   return 0;
}
