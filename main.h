#ifndef _MAIN_H
#define _MAIN_H 1

typedef struct
{
    int id;
    char name[20];
    float average;
} std;

typedef struct node
{
    std data;
    struct node *next;
} node;

#endif