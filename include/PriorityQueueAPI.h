
/**
 * @author Gavin Christie
 * @data October 22nd 2017
 * @brief File containing all the functions to implement a priority queue
 */

#ifndef _PRIORITY_QUEUE_API_
#define _PRIORITY_QUEUE_API_

#include <stdlib.h>
#include <stdio.h>
#include "LinkedListAPI.h"

typedef struct priorityQueue {
    int count;
    List * list;

} PriorityQueue;

/**
 * This function creates a new priority queue. Allocates memeory to the queue struct.
 * @param printFunction User defined function to print stored information
 * @param deleteFunction User defined function to delete individual instances of the information stored
 * @param compareFunction User defined function to compare stored data
 * @param comparePriority User defined function to compare the priority of each node in the list
 * @return Pointer to the newly created priority queue struct
 */
PriorityQueue *createPriorityQueue ( void ( *printFunction )( void *toBePrinted ), void ( *deleteFunction ) ( void *toBeDeleted ), int ( *compareFunction ) ( const void *first,const void *second ), int ( *comparePriorityFunction ) ( const int first,const int second ) );

/**
 * Function deletes remaining information from list and then deletes the queue itself
 * @param q The queue to be deleted
 */
void *destroyPriorityQueue ( PriorityQueue * q );

/**
 * Function to insert data into the list stored based on it priority
 * @param q The queue the data is being added to
 * @param toBeAdded Struct containing the data being added to the list
 * @param priority Integer that represents the priority of the data in the queue
 */
void insert ( PriorityQueue * q, void *toBeAdded, int priority );

/**
 * Function to insert data at the back of the list no matter what its priority value is
 * @param q The queue the data is being added to
 * @param toBeAdded Struct containing the data being added to the list
 * @param priority Integer that represents the priority of the data in the queue
 */
void insertEnd ( PriorityQueue * q, void *toBeAdded, int priority );

/**
 * Function removes the next item in the queue and returns the information that was stored
 * @param q The queue whose next item is to be popped
 */
void pop ( PriorityQueue * q);

/**
 * Function to get the data being stored at the head of the queue without affecting order of queue
 * @param q The queue being peeked at
 * @return Returns pointer to the data stored at that location
 */
void *peek ( PriorityQueue * q );

/**
 * Function to remove node that stores the data being passed into the function from the list
 * @param q The queue that the information is being remove from
 * @param toBeRemoved Pointer to the information being removed
 */
void removeFromQueue ( PriorityQueue * q, void *toBeRemoved );

/**
 * Function to return whether the queue is empty, ruturns 1 if empty and 0 when not empty
 * @param q The queue being check if it is empty
 * @return Returns 1 if empty, 0 is contains at least one item, and -1 if the queue is not initialized
 */
int isEmpty ( PriorityQueue * q );

/**
 * Function that returns the number of items in the queue, returns -1 if the queue is NULL
 * @param q The queue being checked for its length
 * @return Returns an integer representing the number of items in the list
 */
int count ( PriorityQueue * q );

/**
 * Function is used to find the data in a queue and return pointer to the data
 * @param q The queue being searched
 * @param data The data being searched for
 * @return Void pointer to the data, or NULL if nothing is found
 */
void *findData ( PriorityQueue * q, void * data );

/**
 * Function to print the remaining elements of a queue without affecting the data inside
 * @param q The queue being printed
 */
void printQueue ( PriorityQueue * q );

#endif
