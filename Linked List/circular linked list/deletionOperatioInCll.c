#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Deletion at the beginning of the circular linked list
struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    if (head->next == head)
    {
        // Only one node in the circular list
        free(head);
        return NULL;
    }
    temp->next = head->next;
    struct Node *newHead = head->next;
    free(head);
    return newHead;
}

// Deletion at a given index of the circular linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (index == 0)
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        if (head->next == head)
        {
            // Only one node in the circular list
            free(head);
            return NULL;
        }
        temp->next = head->next;
        struct Node *newHead = head->next;
        free(head);
        return newHead;
    }

    struct Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            // Index out of bounds, do not delete
            printf("Index out of bounds. Nothing to delete.\n");
            return head;
        }
    }
    struct Node *nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Deletion at the end of the circular linked list
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        // Only one node in the circular list
        free(head);
        return NULL;
    }
    prev->next = head;
    free(temp);
    return head;
}

int main()
{
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;
    struct Node *fourth=NULL;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;


    printf("Circular linked list before deletion\n");
    linkedListTraversal(head);

    // Delete elements at the beginning
    head = deleteAtBeginning(head);

    // Delete elements at a given index
    // head = deleteAtIndex(head, 2);

    // Delete elements at the end
    // head = deleteAtEnd(head);

    printf("Circular linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
