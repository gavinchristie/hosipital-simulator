#include "LinkedListAPI.h"
#define TRUE 1
#define FALSE 0

List *initializeList ( void ( *printFunction ) ( void *toBePrinted ), void ( *deleteFunction ) ( void *toBeDeleted ), int ( *compareFunction ) ( const void *first,const void *second ), int ( *comparePriorityFunction ) ( const int first,const int second ) )
{
    // Initalizing list by mallocing space
    List * l = NULL;
    l = ( List * ) malloc ( sizeof ( List ) );
    l->head = NULL;
    l->tail = NULL;
    l->printNode = printFunction;
    l->deleteNode = deleteFunction;
    l->compare = compareFunction;
    l->comparePriority = comparePriorityFunction;

    return l;
}

Node *initializeNode ( void *data, int priority )
{
    if ( data == NULL ) {
        return NULL;
    }
    // Initalizing list by mallocing space
    Node * n = NULL;
    n = ( Node * ) malloc ( sizeof ( Node ) );
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    n->priority = priority;

    return n;
}

void insertFront ( List *list, void *toBeAdded, int priority )
{
    if ( list == NULL ) {
        printf ( "Empty list" );
        return;
    }

    if ( toBeAdded == NULL ) {
        return;
    }

    Node * front = initializeNode ( toBeAdded, priority );

    if ( list->head == NULL ) {
        list->head = front;
        list->tail = front;
        return;
    }
    front->next = list->head;
    list->head->previous = front;
    list->head = front;
}

void insertBack ( List *list, void *toBeAdded, int priority )
{
    if ( list == NULL ) {
        printf ( "Empty list" );
        return;
    }

    if ( toBeAdded == NULL ) {
        return;
    }

    Node * back = initializeNode ( toBeAdded, priority );

    if ( list->tail == NULL ) {
        list->tail = back;
        list->head = back;
        return;
    }
    back->previous = list->tail;
    list->tail->next = back;
    list->tail = back;
}

void deleteList ( List *list )
{
    if ( list->head == NULL ) {
        Node * temp = NULL;

        do {
            temp = list->head->next;
            list->deleteNode ( list->head->data );
            free ( list->head );
            list->head = temp;
        } while ( temp != NULL );
    }
    free ( list );
    list = NULL;
}

void insertSorted(List *list, void *toBeAdded, int priority)
{
    if ( list == NULL ) {
        printf("No list to add node to.\n");
        return;
    }

    /* If the list is empty or the priority is higher than the head */
    if ( list->head == NULL || list->comparePriority ( priority, list->head->priority ) < 0 ) {
        /* Add the new node to the end of the list */
        insertFront ( list, toBeAdded, priority );
        return;
    }
    if ( list->comparePriority ( priority, list->head->priority ) == 0 ) {
        Node * current = list->head;
        /* While the priorities are the same of the current is the same as tail */
        while ( list->comparePriority ( priority, current->priority ) == 0 && list->compare ( current->data, list->tail->data ) != 0 ) {
            /* Set current equal to the next node */
            current = current->next;
        }

        if ( list->compare ( current->data, list->tail->data ) == 0 ) {
            insertBack ( list, toBeAdded, priority );
            return;
        }
        Node * newNode = initializeNode ( toBeAdded, priority );
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous = newNode;
        newNode->previous->next = newNode;
        return;
    }

    int result = list->comparePriority ( priority, list->tail->priority );

    if ( result > 0 || result == 0 ) {
        insertBack ( list, toBeAdded, priority );
        return;
    }

    Node * newNode = NULL;
    Node * current = list->head;
    int added = FALSE;

    while ( current != list->tail && !added ) {
        result = list->comparePriority ( priority, current->priority );
        if ( result < 0 ) {
            newNode = initializeNode ( toBeAdded, priority );
            newNode->next = current;
            newNode->previous = current->previous;
            current->previous = newNode;
            newNode->previous->next = newNode;
            added = TRUE;
        } else if ( result == 0 ) {
            while ( list->comparePriority ( priority, current->priority ) == 0 && list->compare ( current->data, list->tail->data ) != 0 ) {
                /* Set current equal to the next node */
                current = current->next;
            }

            newNode = initializeNode ( toBeAdded, priority );
            newNode->next = current;
            newNode->previous = current->previous;
            current->previous = newNode;
            newNode->previous->next = newNode;
            added = TRUE;
        } else {
            current = current->next;
        }
    }

    newNode = NULL;
    current = NULL;
}

int deleteNodeFromList ( List *list, void *toBeDeleted )
{
    Node * current = list->head;
    if ( current == NULL ) {
        return 0;
    }

    while ( current != NULL ) {
        if ( list->compare ( toBeDeleted, current->data ) == 0 && current == list->head ) {
            list->head = current->next;
            list->deleteNode ( current->data );
            deleteListNode ( ( void * ) current );
            if ( list->head != NULL ) {
                list->head->previous = NULL;
            }
            free ( current );
            return 1;
        } else if ( list->compare ( toBeDeleted, current->data ) == 0 && current == list->tail ) {
            list->tail = current->previous;
            list->deleteNode ( current->data );
            deleteListNode ( ( void * ) current );
            if ( list->tail != NULL ) {
                list->tail->next = NULL;
            }
            free ( current );
            return 1;
        } else if ( list->compare ( toBeDeleted, current->data ) == 0 ) {
            list->deleteNode ( current->data );
            current->previous->next = current->next;
            current->next->previous = current->previous;
            deleteListNode ( ( void * ) current );
            free ( current );
            return 1;
        }
        current = current->next;
    }

    return ( -1 );
}

void *getFromFront ( List *list )
{
    if ( list->head == NULL ) {
        return NULL;
    }
    return list->head->data;
}

void *getFromBack ( List *list )
{
    if ( list->tail == NULL ) {
        return NULL;
    }
    return list->tail->data;
}

void printForward(List *list)
{
    if ( list->head == NULL ) {
        printf ( "Nothing in list\n" );
        return;
    }

    Node * current = list->head;
    while ( current != NULL ) {
        list->printNode ( current->data );
        current = current->next;
    }
}

void printBackwards(List *list)
{
    if ( list->tail == NULL ) {
        printf ( "Nothing in list\n" );
        return;
    }

    Node * current = list->tail;
    while ( current != NULL ) {
        list->printNode ( current->data );
        current = current->previous;
    }
}

void deleteListNode ( void *toBeDeleted )
{
    Node * tBD = ( Node * ) toBeDeleted;

    tBD->next = NULL;
    tBD->previous = NULL;
}

void *findNode ( List *list, void *data )
{
    /* Declare variables */
    Node * current = list->head;

    if ( current == NULL ) {
        return 0;
    }

    /* While there is still a current */
    while ( current != NULL ) {
        if ( list->compare ( data, current->data ) == 0 ) {
            /* If the current matches the data being looked for return the current data */
            return current->data;
        }
        /* Set the current for the next time through the loop */
        current = current->next;
    }
    return NULL;
}
