#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueueAPI.h"
#include "Simulation.h"

int main( int argc, char **argv)
{
	/* Create two new priority queues to hold the patients */
	PriorityQueue * before = createPatientQueue ();
	PriorityQueue * after = createPatientQueue ();

    /* Check that correct number of arguments are entering through terminal */
	if ( argc < 2 || argc > 2 ) {
        printf( "Please try again with only file name.\n" );
    } else {
    	/* Read all the information from the file provided */
    	readFromFile ( argv[1], before, after );
    	/* Enter the command loop */
    	commandLoop ( before, after );
    }

    /* Delete anything remaining in either list */
    destroyPriorityQueue ( before );
    destroyPriorityQueue ( after );

    /* Set pointer to null */
    before = NULL;
    after = NULL;

    return 0;
}