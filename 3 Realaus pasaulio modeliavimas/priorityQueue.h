#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct queueElement
{
    int value;
    int priority;
    int order;
}queueElement;

typedef struct priorityQueue
{
    queueElement *data; /// dinaminis masyvas
    int size; ///kiek elementu yra
    int capacity; ///masyvo talpa
    int nextOrder; /// sekantis idejimo numeris
} priorityQueue;

///sukuria tuscia eile su pradine talpa
priorityQueue* pq_Create(int capacity);

///patikrina, ar eileje yra elementu
int pq_IsEmpty(priorityQueue *queue);


///iterpia nauja elementa (didina talpa, jei reikia)
void pq_Insert (priorityQueue *queue, int value, int priority);

///suranda, grazina ir pasalina auksciausio prioriteto elementa
int pq_Remove(priorityQueue *queue);

///sujungia dvi eiles i viena
void pq_Join (priorityQueue *queue1, priorityQueue *queue2);

///grazina auksciausio prioriteto elementa jo nepasalinant
int pq_Peek(priorityQueue *queue);

///atlaisvina atminti
void pq_Destroy(priorityQueue *queue);

#endif // PRIORITYQUEUE_H_INCLUDED
