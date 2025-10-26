// Date: September 29th, 2025
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// does not account for incorrect input
int main(){
        //starting with the height of box
        int height;
        //char** pointer
        char* string = NULL;
        size_t length;
        int longest = 0;
        
        //this reads the height and sets the height variable to the input
        scanf("%d", &height);
        //consumes the newline
        getchar();
        //Need to use malloc because heap memory. Not stack. * 8 because size of pointer.
        char **collection_of_strings = malloc(height * 8);
        
        for(int i = 0; i < height; i++){
                //read it
                ssize_t read_strings = getline(&string, &length, stdin);
                //get rid of the newline. Use strlen so it works. Length is just the size of the pointer
                string[strlen(string)-1] = '\0'; 
                //copy string so it doesn't duplicate. It is secretly a char*
                //malloc gives non-stack memory
                char *copy_of_string = malloc(length);
                strcpy(copy_of_string, string);
                //add to collection
                collection_of_strings[i] = copy_of_string;
                //figure out if longest
                if(strlen(string) > longest){
                        longest = strlen(string);
                } 
        }
        //print the first line of '+'s
        //plus 4 to account for the edges of the box
        for(int i = 0; i < longest + 4; i++){
                printf("+");
        }
        printf("\n");

        for(int i = 0; i < height; i++){
                printf("+ ");
                printf("%s", collection_of_strings[i]);
                // Adds padding
                for(int j = 0; j < (longest - strlen(collection_of_strings[i])); j++){
                        printf(" ");
                }
                printf(" +\n");
        }
        for(int i = 0; i < longest + 4; i++){
                printf("+");
        }
        printf("\n");
        free(collection_of_strings);
        return 0;
}
