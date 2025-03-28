/* Utility Functions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

/* Function to add a new node at the head of the list */

/*
void Push(node** headRef, char* newData)
{
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = newData;
        newNode->next = *headRef;
        *headRef = newNode;
}
*/
void Push(node** head, char* data)
{
        // Allocate a new node
        node* newNode = (node*)malloc(sizeof(node));
        if (!newNode)
        {
                printf("Memory allocation failed.\n");
                return;
        }

        // Assign data to the new node
        newNode->data = strdup(data); // Duplicate the string to ensure independent memory
        newNode->next = NULL;

        // Add the new node at the end of the queue
        if (*head == NULL)
        {
                *head = newNode;
        } else {
                node* temp = *head;
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                temp->next = newNode;
        }
}

/* Function to return the number of nodes in the list */
int Length(node* head)
{
        int count = 0;
        node* current = head;
        while (current != NULL)
        {
                printf("%s -> ", current->data);
                //count++;
                current = current->next;
        }
        //printf("NULL\n");
        return count;
}

/* Function to change the head pointer to NULL */
void ChangeToNull(node** headRef)
{
        *headRef = NULL;
}

/* Function to demonstrate changing head pointers */
void ChangeCaller()
{
        node* head1;
        node* head2;
        ChangeToNull(&head1);
        ChangeToNull(&head2);
        // head1 and head2 are NULL at this point
}

/* Function to print the linked list */
void PrintList(node* head)
{
        node* current = head;
        while (current != NULL)
        {
                printf("%s -> ", current->data);
                current = current->next;
        }
        printf("NULL\n");
}

/* Function to build a list by adding nodes at the head
struct node* AddAtHead()
{
        node* head = NULL;
        int i;
        for (i = 1; i < 6; i++)
        {
                Push(&head, i); // (utility function defined above)
        }
        // head == {5, 4, 3, 2, 1};
        return head;
}

// Function to build a list by adding nodes at the tail (Special Case + Tail Pointer)
struct node* BuildWithSpecialCase()
{
        node* head = NULL;
        node* tail;

        // Deal with the head node here, and set the tail pointer
        Push(&head, 1);
        tail = head;

        // Do all the other nodes using 'tail'
        for (int i = 2; i < 6; i++)
        {
                Push(&(tail->next), i);
                tail = tail->next;
        }
        return head; // head == {1, 2, 3, 4, 5}
}

// Function to build a list using a temporary dummy node
struct node* BuildWithDummyNode()
{
        node dummy;
        node* tail = &dummy;
        dummy.next = NULL;

        for (int i = 1; i < 6; i++)
        {
                Push(&(tail->next), i);
                tail = tail->next;
        }
        return dummy.next; // head == {1, 2, 3, 4, 5}
}

// Function to build a list using a local reference pointer
struct node* BuildWithLocalRef()
{
        node* head = NULL;
        node** lastPtrRef = &head; // Start out pointing to the head pointer
        int i;
        for (i = 1; i < 6; i++)
        {
                Push(lastPtrRef, i); // Add node at the last pointer in the list
                lastPtrRef = &((*lastPtrRef)->next); // Advance to point to the new last pointer
        }
        return head; // head == {1, 2, 3, 4, 5}
}

// Main function to test the linked list functions
int main()
{
        node* head = AddAtHead();
        printf("Linked List (AddAtHead): ");
        PrintList(head);
        printf("Length: %d\n", Length(head));
        printf("\n");

        node* head2 = BuildWithSpecialCase();
        printf("Linked List (BuildWithSpecialCase): ");
        PrintList(head2);
        printf("\n");

        node* head3 = BuildWithDummyNode();
        printf("Linked List (BuildWithDummyNode): ");
        PrintList(head3);
        printf("\n");

        node* head4 = BuildWithLocalRef();
        printf("Linked List (BuildWithLocalRef): ");
        PrintList(head4);
        printf("\n");

        ChangeToNull(&head);
        printf("After ChangeToNull: ");
        PrintList(head);
        printf("\n");

        return 0;
}
*/
                                                                                                
