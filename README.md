The purpose of this document is to explain the conditions of use of our program, which is designed to simulate a wind farm over a given time period, with a pre-selected number of wind turbines. The program has been designed to enable an operator to simulate and understand the data from his wind farm.
 
To generate the executable, first run the following two commands: 

make projet_1_v7_main

./ projet_1_v7_main
 
Execution of the program returns a menu allowing the user to choose between 6 functions:
 
	1: total wind farm production and intervention costs
	2: detailed day-by-day description of wind progression and daily production of all wind turbines
	3: maximum wind farm production over a defined period
	4: minimum wind farm output over a given period	
	5: daily production for a user-selectable day
	6: Quit 
 
The first 5 functions return precise data to the terminal. The last choice allows the user to quit the program at any time.
 
The program uses a Makefile to make it easier to run and understand.
The module contains two files: 
The first is an interface entitled projet_1_v7.h. This is a header file specifying the functionalities offered by the program.
The second is an implementation of the functionalities specified by the program, entitled projet_1_v7.c, i.e. all the program's functions.
 
Finally, the project_1_v7_main file contains the user menu. 

It is also necessary to detail here the various technical choices imposed by the program. The program has been designed to be as simple and easy to use and understand as possible. It uses classic C language elements such as arrays, matrices (to manage wind transition) and dynamic allocation (necessary as arrays can be very large depending on the number of days chosen by the user).
