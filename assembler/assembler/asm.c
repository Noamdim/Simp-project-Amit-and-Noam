#include "asm.h"
#define LABEL_MAX_LEN 50
#define MAX_LINE_LEN 500
#define MAX_LABELS 4096 //Max Labels
#define MAX_PROGRAM_LINES 4096 //Max Lines
#define MAX_DATA_MEMORY 4096 //Max Lines

int imemin_file[MAX_PROGRAM_LINES][7];
int dmemin_file[MAX_DATA_MEMORY];
char* opcodes[] = { "add", "sub", "mac", "and", "or", "xor", "sll", "sra", "srl", "beq", "bne", "blt", "bgt", "ble", "bge", "jal", "lw", "sw", "reti", "in", "out", "halt" };


// Function to get the index of a key in the keys array 
int getOpIndex(char key[])
{
	for (int i = 0; i < 22; i++) {
		if (strcmp(opcodes[i], key) == 0) {
			return i;
		}
	}
	return -1; // Key not found 
}
/**
 * sets the imemin array to be all zeros
 */
void init_imemin_array()
{
	int i;
	for (i = 0; i < MAX_PROGRAM_LINES; i++)
	{
		for (int j = 0; j < 7; ++j)
		{
			imemin_file[i][j] = 0;
		}
	}
}

/**
 * sets the dmemin array to be all zeros
 */
void init_dmemin_array()
{
	for (int i = 0; i < MAX_DATA_MEMORY; ++i)
	{
		dmemin_file[i] = 0;
	}
}
/**
 * given filepath, reads asm code from filePath
 * checks path validation
 * return: a File pointer
 */
FILE* get_file(const char* filePath)
{
	FILE* in_file;
	in_file = fopen(filePath, "r");

	//check validation
	if (in_file == NULL)
	{
		err_msg("open file");
		exit(1);
	}
	return in_file;
}
// ----------- first run func -------
int get_labels(FILE* file)
{
	int line_index = 0;
	int inst_pc = 0;
	char line_str[MAX_LINE_LEN];

	while (line_index < MAX_PROGRAM_LINES)
	{
		if (!feof(file))
		{
			fgets(line_str, MAX_LINE_LEN, file); // save line content in line_str
			printf(line_str);
		}
	}

}


// -------------- main -------------- //

	int main()
	{
		// ----- Initializing ----
		init_imemin_array();
		init_dmemin_array();

		//Creates 2 output files
		FILE* Imemin;
		FILE* dmemin;

		// Create a file
		Imemin = fopen("Imemin.txt", "w");
		dmemin = fopen("dmemin.txt", "w");

		//create empty labels map
		int size = 0; // Current number of elements in the map 
		char labels[MAX_LABELS][LABEL_MAX_LEN]; // Array to store the labels 
		int addresses[MAX_LABELS]; // Array to store the addresses 
		
		//Reads the text file and return array of lines

		//A function that goes through the code for the first time and saves the labels

		//A function that passes a second time and converts the lines


		// Close the file
		fclose(Imemin);
		fclose(dmemin);
		return 1;
	}