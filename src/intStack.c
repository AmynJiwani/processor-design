/**
 *  The functions in this module implement a Stack data structure
 *  of integers.  (Note that chars are also integers so this
 *  integer Stack can be used for chars as well.)
 *
 *  NOTE: the stack is implemented as a fixed size array (size = 100).
 *  Consequently, no more than 100 integers can be pushed onto
 *  the Stack at any given time.
 */

// Implementation hints:
//   The 3 functions--push, pop and isEmpty--share information
//   about the array used to implement the stack and the index
//   of the "top" of the stack.
//
//   You may want to make these variables global...
//   ...but that would
//   be a mistake (because anyone using the module would have
//   to ensure that they did not use global variables with the
//   same names).
//
//   An alternative in C is a "static global".
//   If a global variable is qualified as "static", it is global only
//   within the source code file where it is declared.
//   In parituclar, it cannot conflict with any other global variable.
//
//  RECOMMENDATION:
//   Uncomment the following 2 lines and use these static globals!
//static int top = 0;
//static int stack[100];


//Modified by: Amyn Jiwani



#include <stdio.h>       // Include standard input-output library
#include <stdlib.h>      // Include standard library

static int top = 0;           // Declare the top index of the stack and initialize it to 0
static int stack[100];        // Declare the stack array of size 100

/**
 * pop() removes the top integer on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value -1 (minus one) is returned.
 */
int pop()
{
    int temp = stack[top]; // Store the value at the top of the stack in a temporary variable
    top--;                 // Decrement the top index
    return temp;           // Return the value stored in the temporary variable
}

/**
 *  push(element) adds the "element" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int element)
{
    if(top == 99){           // Check if the stack is full
        printf("The Stack is full!"); // Print an error message
        exit(1);              // Exit the program with an error status
    }
    stack[top+1] = element; // Add the value to the top of the stack
    top++;                  // Increment the top index
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
    if(top == 0)            // Check if the stack is empty
        return 1;
    return 0;
}

// printStack() iterates through the stack and prints each value
void printStack(){
    int i;
    for(i = 0; i < top; i++)   // Iterate through the stack elements
        printf("%d\n", stack[i]); // Print the value at the current index followed by a newline
}

