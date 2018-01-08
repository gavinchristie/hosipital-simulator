#include "PriorityQueueAPI.h"

PriorityQueue *createPriorityQueue ( void ( *printFunction )( void *toBePrinted ), void ( *deleteFunction ) ( void *toBeDeleted ), int ( *compareFunction ) ( const void *first,const void *second ), int ( *comparePriorityFunction ) ( const int first,const int second ) )
{
	if ( printFunction == NULL || deleteFunction == NULL || compareFunction == NULL || comparePriorityFunction == NULL ) {
		printf("At least one function not found, please try again.\n");
		return NULL;
	}
    PriorityQueue * q = NULL;

    /* Allocate memory then initialize variables */
    q = malloc ( sizeof ( PriorityQueue ) );
    q->list = initializeList ( printFunction, deleteFunction, compareFunction, comparePriorityFunction );
    q->count = 0;
    return q;
}

void *destroyPriorityQueue ( PriorityQueue * q )
{
    /* Check if the queue is null, return null if it is */
    if ( q == NULL ) {
    	printf("No queue to delete.\n");
    	return NULL;
    }
    /* Check if the queue is not empty */
    if ( !isEmpty ( q ) ) {
    	deleteList ( q->list );
    }

    /* Free the pointer to the queue and set to null */
    free ( q );
    q = NULL;

    return q;
}

void insert ( PriorityQueue * q, void *toBeAdded, int priority )
{
    if ( q == NULL || q->list == NULL ) {
    	/* If the queue or list is null just return */
    	printf("Cannot insert data, please initialize the queue.\n");
    	return;
    }
    if ( toBeAdded == NULL ) {
    	/* If the user is trying to add a value of null to the queue return */
    	printf("Cannot insert NULL into queue\n");
    	return;
    }
    /* Add data to list */
    insertSorted ( q->list, toBeAdded, priority );
    q->count++; // Increase count because item added
}

void insertEnd ( PriorityQueue * q, void *toBeAdded, int priority )
{
    if ( q == NULL || q->list == NULL ) {
        /* If the queue or list is null just return */
        printf("Cannot insert data, please initialize the queue.\n");
        return;
    }
    if ( toBeAdded == NULL ) {
        /* If the user is trying to add a value of null to the queue return */
        printf("Cannot insert NULL into queue\n");
        return;
    }
    /* Add data to list */
    insertBack ( q->list, toBeAdded, priority );
    q->count++; // Increase count because item added
}

void pop ( PriorityQueue * q)
{
	if ( q == NULL || q->list == NULL || isEmpty ( q ) ) {
		/* If the queue or list is null just return */
		printf("Cannot pop data, please initialize queue or insert data into list first.\n");
		return;
	}
	/* Delete the node from the list */
    int result = deleteNodeFromList ( q->list, peek ( q ) );
    if ( result == 1 ) {
    	q->count--; // Decrease count if delete is successful
    }
}

void *peek ( PriorityQueue * q )
{
    /* Check that the queue exists anf contains information */
    if ( q == NULL || q->list == NULL || isEmpty ( q ) ) {
        /* Return NULL if it doesn't */
    	return NULL;
    }
    /* Return the first element */
    return getFromFront ( q->list );
}

void removeFromQueue ( PriorityQueue * q, void *toBeRemoved )
{
    if ( q == NULL || q->list == NULL || isEmpty ( q ) ) {
		/* If the queue or list is null just return */
		printf("Cannot remove if list doesn't exist, please initialize queue or insert data into list first.\n");
		return;
	}
	if ( toBeRemoved == NULL ) {
		/* Cannot remove for NULL in list */
        printf("Cannot remove NULL from list. Please try again\n");
        return;
	}
	/* Delete the node from the list */
    int result = deleteNodeFromList ( q->list, toBeRemoved );
    if ( result == 1 ) {
    	q->count--; // Decrease count if delete is successful
    }
}

int isEmpty ( PriorityQueue * q )
{
    /* Check that the queue actually exists */
	if ( q == NULL ) {
		printf("Please initialize the queue\n");
		return -1;
	}
    if ( count ( q ) == 0 /*&& getFromFront ( q->list ) == NULL*/ ) {
    	/* If the count is zero and the front of queue is empty return 1 */ 
    	return 1;
    }
    return 0; // Otherwise, return 0
}

int count ( PriorityQueue * q )
{
	if ( q == NULL ) {
		/* When the queue is null */
		printf("Please initialize the queue\n");
		return -1;
	}
    return q->count; // Return the count
}

void *findData ( PriorityQueue * q, void * data )
{
    return findNode ( q->list, data );
}

void printQueue ( PriorityQueue * q )
{
    printForward ( q->list );
}
