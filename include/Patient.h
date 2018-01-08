
/**
 * @author Gavin Christie
 * @date October 22nd 2017
 * @brief File containing all the function to implement a patient as defined in the assignment 2 outline
 */

#ifndef _PATIENT_API_
#define _PATIENT_API_

#include <string.h>
#include "PriorityQueueAPI.h"

typedef struct patient {
    int priority;
    int timeFinished;
    char *patientID;
    char *symptom;
} Patient;

/**
 * Function used to create a new patient at the hospital.  Each patient must have a unique 
 * patient ID.
 * @param priority The priority level of the patient in the queue
 * @param patientID The unique ID representing the patient
 * @param symptom The two character symptom code representing the symptoms the patient is experiencing
 * @return Returns the newly created patient
 */
Patient *createPatient ( int priority, char *patientID, char *symptom );

/**
 * Function used to create a new queue for patients
 * @return Returns the pointer to the new queue
 */
PriorityQueue *createPatientQueue ();

/**
 * Function to print patient's information to the terminal.
 * @param toBePrinted Void pointer to the patient being printed
 */
void printPatient ( void *toBePrinted );

/**
 * Function that deletes the information inside of a patient
 * @param toBeDeleted Void pointer to the patient being deleted
 */
void deletePatient ( void *toBeDeleted );

/**
 * Function that compares the values of a patient based on the patient ID
 * @param first The first of the two patients being compared
 * @param second The second patient in the comparison
 * @return Returns an integer that is >0 if first is bigger, <0 if second is bigger, and 0 if they are the same
 */
int comparePatient ( const void *first, const void *second );

/**
 * Function that compares the priority of two nodes in the queue
 * @param first Integer representing the priority of the first node
 * @param second Integer representing the priority of the second node
 * @return Returns an integer that is >0 if first is higher priority, <0 if second is higher priority, and 0 if they are the same priority
 */
int comparePatientPriority ( const int first, const int second );

#endif
