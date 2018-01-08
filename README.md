Name: Gavin Christie
Email: gchristi@uoguelph.ca
Date: October 22th 2017

Assignment 2 - Hospital Simulation

********** Description **********
Implement and use a priority queue to simulate a hospital's queueing system. Patients will be added with a unique ID,
their priority, and a symptom code.  A patient will be ordered in the list based on their priority level. Once the 
simulation is run it will save the time that each patient left the hospital and output the results with patients in the
same order in which they were entered.

********** How to build **********
Run make to compile both the main program and the testMain program.  Run "make program" without quotes to make the
main program, and run "make test" without quotes to make the test file. The testing for both the linked list and the 
priority queue will be compiled by the "make test" command.

********** How to run **********
To run the main program use the command ./program followed by the path to a text file which will be used as input.
To run the queue test program use the command ./testQueue in the /bin folder.
To run the linked list test program use the command ./testList in the /bin folder

********** Assumptions **********
1. The user should implement the priority compare function, this way the API could be used to implement priorities of
different value, for example, this assignment uses 1-5 with 5 being least priority and 1 being highest priority, however
different application might require priority assignment of 1-10. In this implementation the comparePriority function is for
insertSorted to determine order based on node priority and other functions that want to compare data can use the standard
comapre function. (Note: Not sure if this is what is expected for the assignment)
