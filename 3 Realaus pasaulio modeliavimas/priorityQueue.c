#include "priorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

priorityQueue* pq_Create(int capacity)
{
    if (capacity <= 0)
        return NULL;

    priorityQueue *queue = malloc(sizeof(priorityQueue));
    if (queue == NULL)
        return NULL;

    queue->data = malloc(sizeof(queueElement) * capacity);
    if (queue->data == NULL)
    {
        free(queue);
        return NULL;
    }

    queue->size = 0;
    queue->capacity = capacity;
    queue->nextOrder = 0;
    return queue;
}

int pq_IsEmpty(priorityQueue *queue)
{
    if (queue == NULL || queue->size == 0)
        return 1;
    else return 0;
}

void pq_Insert (priorityQueue *queue, int value, int priority)
{
    if (queue == NULL)
        return;

    ///jei truksta vietos, padidinam masyva dvigubai
    if (queue->size == queue->capacity)
    {
        int newCapacity = queue->capacity * 2;
        queueElement *tempElement = realloc(queue->data, sizeof(queueElement) * newCapacity);

        if (tempElement == NULL)
            return;

        queue->data = tempElement;
        queue->capacity = newCapacity;
    }

    ///pridedame nauja elementa i gala
    queue->data[queue->size].value = value;
    queue->data[queue->size].priority = priority;
    queue->data[queue->size].order = queue->nextOrder++;

    queue->size++;
}

int pq_Remove(priorityQueue *queue)
{
    if (pq_IsEmpty(queue))
        return 0;

    int highestPriorityIndex = 0;

    for (int i = 1; i < queue->size; ++i)
    {
        if (queue->data[i].priority > queue->data[highestPriorityIndex].priority)
            highestPriorityIndex = i;
        else if (queue->data[i].priority == queue->data[highestPriorityIndex].priority)
            if (queue->data[i].order < queue->data[highestPriorityIndex].order)
            highestPriorityIndex = i;
    }

    int removedElement = queue->data[highestPriorityIndex].value;

    ///paslenkame likusius elementus
    for (int i = highestPriorityIndex; i < queue->size - 1; ++i)
        queue->data[i] = queue->data[i+1];
    queue->size--;

    return removedElement;
}

void pq_Join (priorityQueue *queue1, priorityQueue *queue2)
{
    if (queue1 == NULL || queue2 == NULL)
        return;

    ///visus queue2 elementus sudedam i queue1
    for (int i = 0; i < queue2->size; ++i)
    {
        pq_Insert(queue1, queue2->data[i].value, queue2->data[i].priority);
    }
}

int pq_Peek(priorityQueue *queue)
{
    if (pq_IsEmpty(queue))
        return -1;

    int highestPriorityIndex = 0;

    ///surandame elementa su didziausiu prioritetu
    for (int i = 1; i < queue->size; ++i)
    {
        if (queue->data[i].priority > queue->data[highestPriorityIndex].priority)
        {
            highestPriorityIndex = i;
        }
        else if (queue->data[i].priority == queue->data[highestPriorityIndex].priority)
        {
            if (queue->data[i].order < queue->data[highestPriorityIndex].order)
            {
                highestPriorityIndex = i;
            }
        }
    }

    return queue->data[highestPriorityIndex].value;
}

void pq_Destroy(priorityQueue *queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}
