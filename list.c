#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "list.h"


void append(node **head, std *s)
{
    if (*head == NULL)
    {
        push(head, s);
        printf("\nThe addition has been successfully completed !\n");
        return;
    }

    node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    node *new_node = (node *)malloc(sizeof(node));

    printf("Enter the Student ID: ");
    scanf("%d", &new_node->data.id);

    printf("enter the name: ");
    scanf(" %19[^\n]", new_node->data.name);

    printf("enter average: ");
    scanf("%f", &new_node->data.average);

    new_node->next = NULL;
    tail->next = new_node;

    *s = new_node->data;
    printf("\nThe addition has been successfully completed !\n");
}

void push(node **head, std *s)
{
    node *new_node = (node *)malloc(sizeof(node));

    printf("Enter the student ID: ");
    scanf("%d", &new_node->data.id);

    printf("enter the name: ");
    scanf(" %19[^\n]", new_node->data.name);

    printf("enter average: ");
    scanf("%f", &new_node->data.average);
    new_node->next = *head;

    *head = new_node;

    *s = new_node->data;
}

void search(node *head)
{
    int id;
    printf("\nEnter the ID: \n");
    scanf("%d", &id);
    node *curr = head;

    while (curr != NULL)
    {
        if (id == curr->data.id)
        {
            printf("\n<--- Found --->\n\n");
            printf("Name: %s\n", curr->data.name);
            printf("Average: %.2f\n", curr->data.average);

            return;
        }

        curr = curr->next;
    }
    printf("\nWrong ID!\n");

    return;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("\nNO Data Yet!\n");
        return;
    }

    node *curr = head;
    int i = 1;

    while (curr != NULL)
    {
        printf("\nStudent Number(%d):\n ID: %d\n Name: %s\n Average: %.2f\n", i, curr->data.id, curr->data.name, curr->data.average);
        i++;
        curr = curr->next;
    }
    return;
}

void edit_std(node *head, std *s)
{
    int x;
    printf("Enter the ID: ");
    scanf("%d", &x);

    node *curr = head;
    while (curr != NULL)
    {
        if (x == curr->data.id)
        {
            printf("\nFound\n");
            printf("Enter the new data: \n");

            printf("Enter the new id: \n");
            scanf("%d", &curr->data.id);

            printf("Enter the new Name: \n");
            scanf(" %19[^\n]", curr->data.name);

            printf("Enter the new Average: \n");
            scanf("%f", &curr->data.average);

            *s = curr->data;
            printf("The new data was saved !\n");
            return;
        }
        curr = curr->next;
    }

    printf("\nNO student have this id !\n");

    return;
}

void delete_node(node **head)
{

    if (*head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    int i;
    printf("Enter the ID you want to delete: \n");
    scanf("%d", &i);

    node *curr = *head;
    node *prev = NULL;

    if (curr->data.id == i)
    {
        *head = curr->next;
        free(curr);
        printf("The delete was done !\n");
        return;
    }

    while (curr != NULL)
    {
        if (curr->data.id == i)
        {
            prev->next = curr->next;
            free(curr);
            printf("The delete was done !\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }
    printf("ID not found!\n");
    return;
}