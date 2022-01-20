#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
Stack Data Structure: (Linear)
Last in, first out.

push()  - add element to top,
pop()   - remove element from top
peek()  - returns the top item.
size()  - returns the size of stack

Underflow: when pop() or peek() called on empt stack
Overflow:  when push called on a full stack (not common if dynamic arrays are used)


*/


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void push(struct Stack* stack, int item)
{
    if(isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}
 
//Function to remove an item from top of the stack.
int pop(struct Stack* stack)
{
    //if stack is empty, we return -1 else we return the top element.
    if (isEmpty(stack))
        return -INT_MIN;
    return stack->array[stack->top--];
}


int main(void)
{

    struct Stack* stack = createStack(1000);
    
    push(stack,10);
    push(stack,20);
    push(stack,30);
    
    printf("%d\n",peek(stack));
    
    pop(stack);
    
    printf("%d\n",peek(stack));
    
    push(stack,40);
    
    printf("%d\n",peek(stack));
    
    return 0;
}



