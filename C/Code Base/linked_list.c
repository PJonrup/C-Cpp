#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// ------------ Linked List ------------
// drops the continous memory requirements as arrays have.
// no need to pre-allocated the space (just add new node).
// Easier implementation of Queu and Deque data structures.
// Circular linked list like in Round Robin.
// [data][pointer] --> [data][pointer] --> [data][NULL]

// Last in, Last out

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void printList()
{
    struct node *ptr = head;
    
    while(ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("null\n");
}

//insert at beginning
void insert(int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int main()
{
    insert(10);
    insert(5);
    insert(15);
    insert(20);
    
    printList();
    return 0;
}



// ------------ Doubly Linked List ------------
// Has both Next and Previous address.


// ------------ Doubly vs Singly (Linked Lists) ------------

// Doubly:
// + You know.
// - Extra space for prev.
// - Code becomes more complex.