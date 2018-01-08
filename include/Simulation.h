
/**
 * @author Gavin Christie
 * @date October 22nd 2017
 * @brief File containing all the functions to run the hospital simulaiton for assignment 2
 */

#ifndef _SIM_API_
#define _SIM_API_

#include <string.h>
#include "PriorityQueueAPI.h"
#include "Patient.h"

/**
 * The command loop that allows the user to select what they want the program to do 
 * @param before The queue being used for the simulation
 * @param after The queue being used to print the results after the simulation is run
 */
void commandLoop ( PriorityQueue * before, PriorityQueue * after );

/**
 * Function that reads all the patient information from a file
 * @param path The path to the file being read from
 * @param before The queue being used for the simulation
 * @param after The queue being used to print the results after the simulation is run
 */
void readFromFile ( char * path, PriorityQueue * before, PriorityQueue * after );

/**
 * Function that adds the information it is given as a patient to two queues
 * @param before The queue being used for the simulation
 * @param after The queue being used to print the results after the simulation is run
 * @param input The information of the patient being added
 */
void addPatientToQueues ( PriorityQueue * before, PriorityQueue * after, char * input );

/**
 * Function used to added a patient from the command loop after the file is already read in
 * @param before The queue being used for the simulation
 * @param after The queue being used to print the results after the simulation is run
 */
void inputPatient ( PriorityQueue * before, PriorityQueue * after );

/**
 * Function that is used to simulate the hospital.  Works by cycling one second at a time
 * and advancing the queue when needed.
 * @param before The queue being used for the simulation
 * @param after The queue being used to print the results after the simulation is run
 */
void hospitalSimulation ( PriorityQueue * before, PriorityQueue * after );

/**
 * Function that finds the patient in the other queue and sets the time the patient finished
 * @param after The queue being used to print the results after the simulation is run
 * @param finishedPatient Void pointer to the patient whose finish time needs to be set
 * @param currentTime The time the patient finished at
 */
void setFinishTime ( PriorityQueue * after, void * finishedPatient, int currentTime );

/**
 * Function that returns the time require to serve a patient
 * @param newData A void pointer to the patient information
 */
int getServeLength ( void * newData );

#endif
