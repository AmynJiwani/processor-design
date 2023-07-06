/**
 *  Modified by: Amyn Jiwani
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

#include <stdio.h>       // Include standard input-output library
#include <stdlib.h>      // Include standard library

int size = 0;             // Global variable to store the size of the heap
int heap[100];           // Global array to store the heap elements

/**
 *  addHeap(element) adds the "element" to the Heap.
 *
 */
void addHeap(int element)
{
    heap[size] = element; // Add the value to the heap at the current size index
    size++;               // Increment the heap size
}

// sortHeap(index) sorts the heap rooted at index p
void sortHeap(int index)
{
    int temp;
    int left = (2 * index) + 1;  // Calculate the left child index
    int right = (2 * index) + 2; // Calculate the right child index
    int max = index;             // Initialize max with index

    // If the left child exists and is greater than the current max, update max
    if((left < size) && (heap[left] > heap[max]))
        max = left;

    // If the right child exists and is greater than the current max, update max
    if((right < size) && (heap[right] > heap[max]))
        max = right;

    // If max is not equal to index, swap heap[index] with heap[max] and sort the subtree rooted at max
    if(max != index) {
        temp = heap[max];
        heap[max] = heap[index];
        heap[index] = temp;
        sortHeap(max);
    }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete(){
    int temp;
    size--;                 // Decrement the heap size
    temp = heap[0];         // Store the maximum value (root) in temp
    heap[0] = heap[size];   // Replace the root with the last element in the heap
    heap[size] = temp;      // Store the maximum value at the last position
    sortHeap(0);
    printf("%d\n",heap[size]); // Print the deleted value
    return heap[size];         // Return the deleted value
}

// printTree(index) recursively prints the heap as an XML tree rooted at index p
void printTree(int index){
    int left = (2 * index) + 1;  // Calculate the left child index
    int right = (2 * index) + 2; // Calculate the right child index

    printf("<node id='%d'>", heap[index]); // Print the current node as an XML tag with the node value as its id

    if(left < size)          // If the left child exists
        printTree(left);     // Recursively print the left subtree

    if(right < size)         // If the right child exists
        printTree(right);    // Recursively print the right subtree

    printf("</node>");       // Print the closing XML tag for the current node
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
    return size;
}

