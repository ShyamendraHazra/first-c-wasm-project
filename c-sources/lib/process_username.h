#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct buffer Buffer;


struct buffer
{
    char* str;
    size_t length;
};

void bufferwriter(Buffer* buffer, char letter) {
    
    buffer->length++;
    buffer->str = (char*)realloc(buffer->str, buffer->length);
    buffer->str[buffer->length-1] = letter;
}

Buffer* createBuffer() {
    Buffer* buffer = (Buffer*)malloc(sizeof(Buffer));
    buffer->length = 0;
    buffer->str = NULL;
    return buffer;
}
void destroyBuffer(Buffer* buffer) {
    free(buffer->str);
    free(buffer);
    printf("Safe\n");
}

char* returnString(char* msg, int length) {
    
    char* prefix = "Hello ";
    size_t prefixLen = strlen(prefix);
    char* postfix = "\n\nThis welcome msg was generated using webassembly compiled from C language!";
    size_t postfixLen = strlen(postfix);
    char* finalString = NULL;

    Buffer* preparedString = createBuffer();

    for(int i=0; i<prefixLen; i++) {
        bufferwriter(preparedString, prefix[i]);
    }
    
    for(int i=0; i<length; i++) {
        bufferwriter(preparedString, msg[i]);
    }


    for(int i=0; i<postfixLen; i++) {
        bufferwriter(preparedString, postfix[i]);
    }

    finalString = preparedString->str;

    destroyBuffer(preparedString);

    return finalString;
}