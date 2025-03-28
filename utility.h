#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>

/* Definition of the node structure */
typedef struct node
{
    char* data;
    struct node* next;
}node;

/* Function to add a new node at the head of the list */
void Push(node** headRef, char* newData);

/* Function to return the number of nodes in the list */
int Length(node* head);

/* Function to change the head pointer to NULL */
void ChangeToNull(node** headRef);

/* Function to demonstrate changing head pointers */
void ChangeCaller();

/* Function to print the linked list */
void PrintList(node* head);

/* Function to build a list by adding nodes at the head */
struct node* AddAtHead();

/* Function to build a list by adding nodes at the tail (Special Case + Tail Pointer) */
struct node* BuildWithSpecialCase();

/* Function to build a list using a temporary dummy node */
struct node* BuildWithDummyNode();

/* Function to build a list using a local reference pointer */
struct node* BuildWithLocalRef();

/* Function to check if a queue is full */
int isFull(node* head);

/* Function to add a patient to the appropriate queue */
void addPatient(char* name, int priority, int isEmergency);

/* Function to process the next patient */
void processNextPatient();

/* Modified upgrade function using upgradePT */
void upgradePatientPriority(char* name, int newPriority);

/* Function to clear all queues */
void clearAllQueues();

/* Display all queues */
void displayQueues();



#endif
