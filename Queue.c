/* Updated Queue Takeaway with Multi-Priority Queues */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

/* Maximum size for high and second-high priority queues */
#define MAX_SIZE 5

/* Queues for different priorities */
node* highPriorityQueue = NULL;
node* secondHighPriorityQueue = NULL;
node* noPriorityQueue = NULL;

/* Function to check if a queue is full */
int isFull(node* head)
{
        return Length(head) >= MAX_SIZE;
}

/* Function to add a patient to the appropriate queue */
void addPatient(char* name, int priority, int isEmergency)
{
        if (isEmergency)
        {
                printf("Emergency patient processed immediately: %s\n", name);
                return;
        }

        // Ensure the patient is added to only one queue
        if (priority == 1)
        {
                if (isFull(highPriorityQueue))
                {
                        printf("High Priority Queue is full. Cannot add patient: %s\n", name);
                } else {
                        Push(&highPriorityQueue, name);
                }
        } else if (priority == 2)
        {
                if (isFull(secondHighPriorityQueue))
                {
                        printf("Second High Priority Queue is full. Cannot add patient: %s\n", name);
                } else {
                        Push(&secondHighPriorityQueue, name);
                }
        } else if (priority > 2)
        {
                Push(&noPriorityQueue, name);
        } else {
                printf("Invalid priority: %d. Patient not added.\n", priority);
        }
}

/* Function to process the next patient */
void processNextPatient()
{
        if (highPriorityQueue)
        {
                char* patient = (char*)highPriorityQueue->data;
                highPriorityQueue = highPriorityQueue->next;
                printf("Processing High Priority Patient: %s\n", patient);
        } else if (secondHighPriorityQueue)
        {
                char* patient = (char*)secondHighPriorityQueue->data;
                secondHighPriorityQueue = secondHighPriorityQueue->next;
                printf("Processing Second High Priority Patient: %s\n", patient);
        } else if (noPriorityQueue)
        {
                char* patient = (char*)noPriorityQueue->data;
                noPriorityQueue = noPriorityQueue->next;
                printf("Processing No Priority Patient: %s\n", patient);
        } else {
                printf("No patients in queue to process.\n");
        }
}

/* Function to fetch the topmost patient */
void fetchTopPatient()
{
        if (highPriorityQueue)
        {
                printf("Topmost patient is from High Priority Queue: %s\n", (char*)highPriorityQueue->data);
        } else if (secondHighPriorityQueue)
        {
                printf("Topmost patient is from Second High Priority Queue: %s\n", (char*)secondHighPriorityQueue->data);
        } else if (noPriorityQueue)
        {
                printf("Topmost patient is from No Priority Queue: %s\n", (char*)noPriorityQueue->data);
        } else {
                printf("No patients in any queue.\n");
        }
}

/* Function to upgrade a patient's priority */
void upgradePatientPriority(char* name, int newPriority)
{
        node **sourceQueue = NULL;
        node *temp = NULL, *prev = NULL;

        // Search for the patient in all queues
        node **queues[] = {&highPriorityQueue, &secondHighPriorityQueue, &noPriorityQueue};
        for (int i = 0; i < 3; i++)
        {
                sourceQueue = queues[i];
                prev = NULL;
                temp = *sourceQueue;

                // Traverse the queue to find the patient
                while (temp && strcmp((char*)temp->data, name) != 0)
                {
                        prev = temp;
                        temp = temp->next;
                }

                // If the patient is found, stop searching
                if (temp)
                {
                        break;
                }
        }

        if (!temp)
        {
                printf("Patient not found for upgrade: %s\n", name);
                return;
        }

        // Check for emergency case
        char isEmergency;
        printf("Is this an emergency case? (Y/N): ");
        scanf(" %c", &isEmergency);

        if (isEmergency == 'Y' || isEmergency == 'y')
        {
                printf("Emergency upgrade identified for patient: %s\n", name);
                printf("Emergency patient processed immediately: %s\n", name);

                // Remove the patient from the source queue
                if (prev)
                {
                        prev->next = temp->next;
                } else
                {
                        *sourceQueue = temp->next;
                }
                free(temp);
                return;
        }

        // Remove the patient from the source queue (non-emergency case)
        if (prev)
        {
                prev->next = temp->next;
        } else
        {
                *sourceQueue = temp->next;
        }

        // Add the patient to the correct queue based on new priority
        printf("Upgrading patient %s to new priority %d.\n", name, newPriority);
        addPatient(name, newPriority, 0);
        free(temp);
}

/* Display all queues */
void displayQueues()
{
        printf("High Priority Queue: ");
        PrintList(highPriorityQueue);
        printf("Second High Priority Queue: ");
        PrintList(secondHighPriorityQueue);
        printf("No Priority Queue: ");
        PrintList(noPriorityQueue);
}

/* Function to clear all queues */
void clearAllQueues()
{
        while (highPriorityQueue)
        {
                node* temp = highPriorityQueue;
                highPriorityQueue = highPriorityQueue->next;
                free(temp);
        }

        while (secondHighPriorityQueue)
        {
                node* temp = secondHighPriorityQueue;
                secondHighPriorityQueue = secondHighPriorityQueue->next;
                free(temp);
        }

        while (noPriorityQueue)
        {
                node* temp = noPriorityQueue;
                noPriorityQueue = noPriorityQueue->next;
                free(temp);
        }
        printf("All queues have been cleared.\n");
}

/* Main Function */
int main()
{
        char choice;
        char name[50];
        int priority;

        do
        {
                printf("\nCurrent Queues:\n");
                displayQueues();
                printf("\n(A) Add Patient, (U) Upgrade Patient, (P) Process Next, (T) Fetch Top Patient, (C) Clear All Queues, (Q) Quit: ");
                scanf(" %c", &choice);

                switch (choice)
                {
                        case 'A':
                        case 'a':
                                printf("Enter Patient Name: ");
                                scanf("%s", name);

                                printf("Enter Priority (1-High, 2-Second High, Others-No Priority): ");
                                scanf("%d", &priority);
                                printf("Is this an emergency case? (Y/N): ");
                                char isEmergency;
                                scanf(" %c", &isEmergency);

                                if (isEmergency == 'Y' || isEmergency == 'y')
                                {
                                        // Emergency case
                                        addPatient(name, priority, 1);
                                } else {
                                        addPatient(name, priority, 0);
                                }
                                break;

                        case 'U':
                        case 'u':
                                printf("Enter Patient Name: ");
                                scanf("%s", name);
                                printf("Enter New Priority (1-High, 2-Second High): ");
                                scanf("%d", &priority);
                                upgradePatientPriority(name, priority);
                                break;

                        case 'P':
                        case 'p':
                                processNextPatient();
                                break;

                        case 'T':
                        case 't':
                                fetchTopPatient();
                                break;

                        case 'C':
                        case 'c':
                                clearAllQueues();
                                break;

                        case 'Q':
                        case 'q':
                                printf("Exiting.\n");
                                break;

                        default:
                                printf("Invalid choice.\n");
                }
        } while (choice != 'Q' && choice != 'q');

        return 0;


}
