#include <stdio.h> 
#include <string.h> 
#include <cstdio>


#define LABEL_MAX_LEN 50
#define MAX_LINE_LEN 500
#define MAX_LABELS 4096 //Max Labels
#define MAX_PROGRAM_LINES 4096 //Max Lines
#define MAX_DATA_MEMORY 4096 //Max Lines


// ----- dict of labels -------
int size = 0; // Current number of elements in the map 
char labels[MAX_LABELS][LABEL_MAX_LEN]; // Array to store the labels 
int addresses[MAX_LABELS]; // Array to store the addresses 

// Function to get the index of a label in the labels array 
int getIndex(char label[])
{
	for (int i = 0; i < size; i++) {
		if (strcmp(labels[i], label) == 0) {
			return i;
		}
	}
	return -1; // label not found 
}

// Function to insert a label-address pair into the map 
void insert(char label[], int address)
{
	int index = getIndex(label);
	if (index == -1) { // label not found 
		strcpy(labels[size], label);
		addresses[size] = address;
		size++;
	}
	else { // label found 
		err_msg("this label already appeared");
	}
}

// Function to get the address of a label in the map 
int getAddress(char label[])
{
	int index = getIndex(label);
	if (index == -1) { // label not found 
		return -1;
	}
	else { // label found 
		return addresses[index];
	}
}

// Function to print the map 
void printMap()
{
	for (int i = 0; i < size; i++) {
		printf("%s: %d\n", labels[i], addresses[i]);
	}
}

