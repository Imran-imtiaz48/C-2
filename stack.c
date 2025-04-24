// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of elements in the stack

// Global variable to track the number of elements in the stack
int count = 0;

// Structure for the stack
typedef struct {
  int items[MAX]; // Array to store stack elements
  int top;        // Index of the top element
} Stack;

// Function to initialize an empty stack
void createEmptyStack(Stack *s) {
  s->top = -1; // Set the top index to -1 (indicating an empty stack)
}

// Function to check if the stack is full
int isFull(Stack *s) {
  return s->top == MAX - 1; // Returns 1 (true) if the stack is full, otherwise 0
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
  return s->top == -1; // Returns 1 (true) if the stack is empty, otherwise 0
}

// Function to add an element to the stack
void push(Stack *s, int newItem) {
  if (isFull(s)) {
    printf("STACK FULL\n");
  } else {
    s->top++; // Increment the top index
    s->items[s->top] = newItem; // Add the new item to the top of the stack
    count++; // Increment the count of elements
  }
}

// Function to remove an element from the stack
void pop(Stack *s) {
  if (isEmpty(s)) {
    printf("\nSTACK EMPTY\n");
  } else {
    printf("Item popped = %d\n", s->items[s->top]); // Print the popped item
    s->top--; // Decrement the top index
    count--; // Decrement the count of elements
  }
}

// Function to print all elements of the stack
void printStack(Stack *s) {
  printf("Stack: ");
  for (int i = 0; i <= s->top; i++) { // Loop through all elements in the stack
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  // Allocate memory for the stack
  Stack *s = (Stack *)malloc(sizeof(Stack));

  // Initialize the stack
  createEmptyStack(s);

  // Push elements into the stack
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  // Print the stack
  printStack(s);

  // Pop an element from the stack
  pop(s);

  // Print the stack after popping
  printf("\nAfter popping out\n");
  printStack(s);

  // Free the allocated memory
  free(s);

  return 0;
}
