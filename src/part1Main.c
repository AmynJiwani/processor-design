//Written by: Amyn Jiwani
//Program used to run XML Validation Algorithm.

#include <stdio.h> // include standard input-output library
#include <stdlib.h> // include standard library
#include <ctype.h> // include library to handle character types
#include <string.h> // include string manipulation library

extern char *pop(); // declare function to remove an element from the stack
extern void push(char *); // declare function to add an element to the stack
extern int isEmpty(); // declare function to check if stack is empty

int main(int argc, char *argv[]) {
    int ch; // Declare an integer variable to store each character of input
    char tag[100]; // Declare a char array to store tag names
    int i = 0; // Initialize a counter variable i to 0
    int is_valid = 1; // Initialize a validity check variable to true (1)

    // Loop through input until the end of file (EOF) is reached
    while ((ch = getchar()) != EOF) {
        //checks if num is placed first as the start of the tag
        if (isdigit(ch)) {
              printf("Invalid Input Type - not a correct XML tag start!\n");
              exit(1);
        }
        

        // Skip the current iteration if the character is not an alphabetic letter, >, <, or /
        if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
            continue;
        
        
         
        // Check if the character is '<'
        if (ch == '<') {
            i = 0; // Reset the counter variable i to 0
            ch = getchar(); // Read the next character
        
          // Check if the character is a digit 
          

            // Check if the next character is '/'
            if (ch == '/') {
                // End tag
                // Loop through the input until '>' is encountered
                while ((ch = getchar()) != '>') {
                    // Check if the character is not an alphabetic letter
                    if (!isalpha(ch)) {
                        printf("Invalid Tag name!\n"); // Print an error message
                        is_valid = 0; // Set the validity check variable to false (0)
                        break; // Break out of the loop
                    }
                    tag[i++] = ch; // Add the character to the tag name and increment the counter variable i
                }
                tag[i] = '\0'; // Add a null terminator to the end of the tag name
                if (!is_valid)
                    break; // Break out of the loop if the validity check variable is false (0)
                char *popped_tag = pop(); // Remove the tag from the stack
                if (popped_tag == NULL) { // Check if the stack is empty
                    printf("Tag Stack Underflow (not enough)!\n"); // Print an error message
                    is_valid = 0; // Set the validity check variable to false (0)
                    break; // Break out of the loop
                }
                // Compare the popped tag with the tag just read
                if (strcmp(tag, popped_tag) != 0) {
                    printf("Invalid Tag Sequence!\n"); // Print an error message
                    is_valid = 0; // Set the validity check variable to false (0)
                    break; // Break out of the loop
                }
                free(popped_tag); // Free the memory allocated by strdup()
            } 

			else {
                // Start tag
                // Loop through the input until the character is not an alphabetic letter
                while (isalpha(ch)) {
                    tag[i++] = ch; // Add the character to the tag name and increment the counter variable i
                    ch = getchar(); // Read the next character
                }
                tag[i] = '\0'; // Add a null terminator to the end of the tag name
                push(strdup(tag)); // Add the tag to the stack after duplicating the string
            }
        }
    }

    // Check if the stack is not empty
    if (!isEmpty()) {
        printf("Tag Stack not empty!\n"); // Print an error message
        is_valid = 0; // Set the validity check variable to false (0)
    }

    


    if (is_valid) { // checks whether the is_valid variable is true or not. When pressing "Ctrl+D"; this is the defacto default.
        printf("Valid XML.\n");
    } else {
        printf("Invalid XML!\n");
        exit(1);
    }

    // Free remaining memory allocated by strdup()
    while (!isEmpty()) {
        free(pop()); //frees the memory allocated to the top element of the stack using "free()"
    }

    return 0; //program compiled successfully
}

