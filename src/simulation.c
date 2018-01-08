#include "Simulation.h"
#define LENGTH 100
#define TRUE 1

void commandLoop ( PriorityQueue * before, PriorityQueue * after )
{
	/* Declare variables */
	char input = ' ';

    /* While loop to get user selection */
    while ( TRUE ) {
    	/* Get character from user */
        printf("1. Add new patient\n2. Run simulation\n3. Exit\nSelect: ");
        input = getchar ( );
        switch ( input ) {
        	case '1':
        	    /* When user wants to add new patient */
        	    inputPatient ( before, after );
        	    break;
        	case '2':
        	    /* When user wants to run the simulation */
        	    hospitalSimulation ( before, after );
        	    /* Print the results afterwards */
                printf("Patient ID     Priority     Symptom Code     Time Finished\n");
                printf("__________________________________________________________\n");
        	    printQueue ( after );
                while ( getchar ( ) != '\n' ){}

        	    printf("Press any key to continue...");
        	    getchar ( );
        	    return;
        	case '3':
        	    /* Return to main on exit */
        	    return;
        	default:
        	    /* When input is anything other than integers 1 - 3 */
                /* Clear any remaing characters from the buffer */
                while ( getchar ( ) != '\n' ) {}
        	    printf("Invalid input\n");
                break;
        }
    }
}

void readFromFile ( char * path, PriorityQueue * before, PriorityQueue * after )
{
	/* Check that the queues are valid */
    if ( before == NULL || after == NULL ) {
    	printf("Please initial queues before reading from file\n");
    	return;
    }

    /* Open the file */
    FILE *fptr = NULL;
	fptr = fopen ( path, "r" );

    /* Check that the file is open */
    if ( fptr == NULL ) {
    	printf("Please add file to run command\n");
        exit ( 0 );
    }

    /* Declare new variables */
    char * input = malloc ( sizeof ( char ) * LENGTH );
    /* Get all new patients from file */
    while ( fgets ( input, LENGTH, fptr ) != NULL ) {
    	addPatientToQueues ( before, after, input );
    }

    /* Close the file */
    fclose ( fptr );
}

void addPatientToQueues ( PriorityQueue * before, PriorityQueue * after, char * input )
{
	/* Declaring variables */
    int length = 0;
	Patient * newPatient = NULL;
    Patient * newPatientCopy = NULL;
	char * newPatientID = NULL;
    char * newPatientSym = NULL;
    newPatientSym = malloc ( sizeof ( char ) * 3 );
    int newPatientPriority = 0;

    /* Find length of patient's ID */
    while ( input[length] != ' ' ) {
        length++;
    }
    /* Allocate enough space for the patient's ID */
    newPatientID = malloc ( sizeof ( char ) * ( length + 1 ) );

	/* Split the line into individual fields */
    sscanf ( input, "%s %d %s", newPatientID, &newPatientPriority, newPatientSym );
    /* Ending both strings with Null Terminator */
    newPatientSym[2] = '\0';
    newPatientID[length] = '\0';
    /* Create a new patient with the information */
    newPatient = createPatient ( newPatientPriority, newPatientID, newPatientSym );
    newPatientCopy = createPatient ( newPatientPriority, newPatientID, newPatientSym );
    /* Add the patient to both lists, the ordered one and the one for output */
    insert ( before, ( void * ) newPatient, newPatientPriority );
    insertEnd ( after, ( void * ) newPatientCopy, newPatientPriority );
}

void inputPatient ( PriorityQueue * before, PriorityQueue * after )
{
	/* Declare variable */
	char * input = malloc ( ( sizeof ( char ) ) * ( LENGTH + 1 ) );
    /* Clear the buffer */
    while ( getchar ( ) != '\n' ) {}
    /* Get patient information from the user */
	printf ( "Enter new Patient, please write all infomation on one line separated by spaces following this format:\n" );
	printf ( "\"Patient ID\" \"Patient Priority\" \"PatientSymptoms\"\n" );
	fgets ( input, LENGTH, stdin );
	/* Add patient to the queues */
	addPatientToQueues ( before, after, input );
}

void hospitalSimulation ( PriorityQueue * before, PriorityQueue * after )
{
	/*Declare any variables needed */
	int currentTime = 1, timeRemaining = 0;

    /* Setting the timeRemaing for first patient */
    timeRemaining = getServeLength ( peek ( before ) );

	/* Continue while before queue is not empty */
	while ( !isEmpty ( before ) ) {
        /* Add one to the current time and subtract one from the time remaining to serve current patient */
        currentTime++;
        timeRemaining--;
	    /* If the time remaining is zero move on to next patient */
	    if ( timeRemaining == 0 ) {
	        /* Set the finish time for current patient and remove them from the queue */
	        setFinishTime ( after, peek ( before ), currentTime );
	        pop ( before );
            /* If there is another patient, get their service time */
            if ( !isEmpty ( before ) ) {
            	currentTime++; // Add one second because doctor cannot see next patient until paper work is done
            	timeRemaining = getServeLength ( peek ( before ) );
            }
        }
    }
}

void setFinishTime ( PriorityQueue * after, void * finishedPatient, int currentTime )
{
	/* Declare variables */
	Patient * p = NULL;
	/* Find the patient in the after queue */
	p = ( Patient * ) findData ( after, finishedPatient );
	/* Set the finish time */
	p->timeFinished = currentTime;
}

int getServeLength ( void * newData )
{
	/* Cast data as a patient */
	Patient * newPatient = ( Patient * ) newData;
	/* Check the symptom and return the time represented by that code */
    if ( strcmp ( newPatient->symptom, "CV" ) == 0 ) {
    	return 5;
    } else if ( strcmp ( newPatient->symptom, "HN" ) == 0 ) {
    	return 3;
    } else if ( strcmp ( newPatient->symptom, "EV" ) == 0 ) {
        return 10;
    } else if ( strcmp ( newPatient->symptom, "GI" ) == 0 ) {
    	return 2;
    } else if ( strcmp ( newPatient->symptom, "MH" ) == 0 ) {
    	return 5;
    } else if ( strcmp ( newPatient->symptom, "NC" ) == 0 ) {
    	return 5;
    } else if ( strcmp ( newPatient->symptom, "EC" ) == 0 ) {
    	return 1;
    } else if ( strcmp ( newPatient->symptom, "RC" ) == 0 ) {
    	return 1;
    } else if ( strcmp ( newPatient->symptom, "SK" ) == 0 ) {
    	return 2;
    } else if ( strcmp ( newPatient->symptom, "SA" ) == 0 ) {
    	return 7;
    } else if ( strcmp ( newPatient->symptom, "TR" ) == 0 ) {
    	return 4;
    } else {
    	return 0;
    }
}
