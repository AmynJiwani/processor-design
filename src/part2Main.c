//Written by: Amyn Jiwani
//Program used to run heap/heapSort Algorithm.
//Note: "end" is used to terminate the program.

#include <stdio.h>       // Include standard input-output library
#include <stdlib.h>      // Include standard library
#include <ctype.h>       // Include library to handle character types
#include <string.h>      // Include string manipulation library

extern int pop();         // Declare function to remove an element from the stack
extern void push(int);    // Declare function to add an element to the stack
extern void addHeap(int); // Declare function to add an element to the heap
extern int heapSize();    // Declare function to get the size of the heap
extern void printTree(int); // Declare function to print the heap as a tree
extern int heapDelete();  // Declare function to delete the maximum element from the heap
extern void printStack(); // Declare function to print the stack
extern void sortHeap(int); // Declare function to sort a part of the heap

int main(int argc, char * argv[]) {
    char inputLine[100];                 // Declare a char array to store input lines
    int startIndex, iterator, numInputs = 0; // Declare variables to store the start index, iterator, and number of inputs
    fgets(inputLine, 100, stdin);        // Read input line of up to 100 characters (including newline)

    while (strcmp(inputLine , "end\n") != 0) { // Loop until the input value is "end\n"
        addHeap(atoi(inputLine));        // Convert the input value to an integer and add it to the heap
        numInputs++;                      // Increment the number of inputs
        fgets(inputLine, 100, stdin);     // Read the next input line
    }

    startIndex = (heapSize() - 1) / 2; // Calculate the start index for sorting the heap
    //Reasoning: The nodes are stored in an array in such a way that the parent of a node at index i is at index (i-1)/2, and the left and right children of a node at index i are at indices (2*i)+1 and (2*i)+2, respectively.
    //To sort the heap, we want to start from the middle of the heap and work our way down to the root. The middle of the heap is the parent of the last element in the heap, which can be calculated as (heapSize() - 1) / 2. This is because the last element in the heap is at index heapSize() - 1, and its parent is at index (heapSize() - 2) / 2. The parent of the last element is the last internal node in the heap, and all the nodes after it are leaves, so we do need not sort them.

    for (iterator = startIndex; iterator >= 0; iterator--) // Iterate through the heap elements from start index to 0
        sortHeap(iterator);            // Sort the part of the heap rooted at index iterator

    printf("\n");                      // Print a newline character
    printTree(0);                      // Print the heap as a tree starting from the root (index 0)
    printf("\n");                      // Print a newline character

    for (iterator = 0; iterator < numInputs; iterator++) { // Iterate through the number of inputs
        int deletedValue = heapDelete(); // Delete the maximum element from the heap and store it in deletedValue
        push(deletedValue);             // Push the deleted value onto the stack
    }
    printf("\n");                      // Print a newline character

    for(iterator = 0; iterator < numInputs; iterator++)    // Iterate through the number of inputs
        printf("%d\n", pop());          // Pop an element from the stack and print it with a newline
    printf("\n");                      // Print a newline character

    printStack();                      // Print the stack
    exit(0);                           // Exit the program with a success status
}

