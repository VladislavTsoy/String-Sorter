#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int myCompare (const void* a, const void* b) {
    return strcmp (*(const char **) a, *(const char **) b);
}
 
void sort(char *arr[], int n) {
    qsort(arr, n, sizeof (const char *), myCompare);
}

int main(int argc, char** argv) {
    
    if(argc != 2 ){
        fprintf(stderr, "ERROR: invalid number of arguments (USAGE: ./stringsorter \"aaaa bbb cc\") \n");
        return 0;
    }
    
    //gets rid of all non alpha chars and replaces them with spaces
    int stringSize = strlen(argv[1]);
    char* string= argv[1];
    int i = 0;
    
    for(i = 0; i < stringSize; i ++) {
        if(!isalpha(string[i])){
            string[i] = ' ';
        }
    }
    
    
    
    //separates strings and adds them to an array;
    char* token;
    const char delim[2] = " ";
    char* sortedList[20];
    int index = 0;
    token = strtok(string, delim);
    
    while(token != NULL) {
        sortedList[index] = token;
        token = strtok(NULL, delim);
        index++;
    }
    
    
    //sorts list and prints
    sort(sortedList, index);
    int j;
    for(j= 0; j < index; j++){
        printf("%s \n", sortedList[j]);
    }
    return 0;
 
}