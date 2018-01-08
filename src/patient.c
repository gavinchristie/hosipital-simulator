#include "Patient.h"

Patient *createPatient ( int priority, char *patientID, char *symptom )
{
    /* Create patient and malloc space */
    Patient * p = NULL;
    p = malloc ( sizeof ( Patient ) );

    /* Allocating space for strings in patient */
    p->patientID = malloc ( sizeof ( char ) * strlen ( patientID ) );
    p->symptom = malloc ( sizeof ( char ) * strlen ( symptom ) );

    /*Set variables in the patient */
    p->priority = priority;
    p->timeFinished = -1;
    strcpy ( p->patientID, patientID );
    strcpy ( p->symptom, symptom );
    /* Return pointer to the new patient */
    return p;
}

PriorityQueue *createPatientQueue ()
{
    /* Create and return the new queue */
    PriorityQueue * newQueue = createPriorityQueue ( &printPatient, &deletePatient, &comparePatient, &comparePatientPriority );
    return newQueue;
}

void printPatient ( void *toBePrinted )
{
    /* Check that the data is valid and return if it is null */
    if ( toBePrinted == NULL ) {
        return;
    }

    /* Set the patient */
    Patient * p = ( Patient * ) toBePrinted;
    /* Print the information if they have no finish time */
    if ( p->timeFinished < 0 ) {
        printf ( "%s\t%d\t%s\n", p->patientID, p->priority, p->symptom );
    } else {
        printf ( "%s\t\t  %d\t\t%s\t\t  %d\n", p->patientID, p->priority, p->symptom, p->timeFinished );
    }
}

void deletePatient ( void *toBeDeleted )
{
    /* Check that the data is valid and return if it is null */
    if ( toBeDeleted == NULL ) {
        return;
    }

    /* Set patient */
    Patient * p = ( Patient * ) toBeDeleted;
    /* Delete data in the patient */
    free ( p->patientID );
    free ( p->symptom );
    /* Free the patient pointer */
    free ( p );
}

int comparePatient ( const void *first, const void *second )
{
    /* Casting void pointers as patient poiners */
    const Patient * p1 = ( Patient * ) first;
    const Patient * p2 = ( Patient * ) second;
    /* Return the string compare of the patient IDs */
    return strcmp ( p1->patientID, p2->patientID );
}

int comparePatientPriority ( const int first, const int second )
{
    /* Return the subraction of the two integers */
    return ( first - second );
}
