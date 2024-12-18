// Authors: James Dye & Vennethe Y. Valenzuela 
// Date: 12/02/2024
// Purpose: To create a Madlib game that a user can play within the terminal.

#include <stdio.h>

// MACROS
#define MAX_ROWS 50
#define MAX_STRING_SIZE 1000

// FILES
#define INPUT_FILE_1 "madlib1.txt"
#define INPUT_FILE_2 "madlib2.txt"

// FUNCTION PROTOTYPES BELOW
int getStringLength(char str[]);
 
_Bool isPunctuation(char compare);
 
void removeEndlineChar (char str[]);
void handleReplacable(int rows, int cols, char thing[][cols]);
void storeText(FILE* fileToRead, int rows, int cols, char str[][cols]);
void displayFullMadlib(int rows, int cols, char stringArray[][cols]);

// MAIN FUNCTION BELOW
int main(int argc, char* argv[]){	
	char madlibStory[MAX_ROWS][MAX_STRING_SIZE];

	FILE* inputFile = fopen(argv[1], "r"); // Open a madlib.txt file
	
	// Verify connection is made to a madlib.txt file
	if (inputFile == NULL){
		printf("Could not open a file for reading!\n");
		return 0;
	}
	
	storeText(inputFile, MAX_ROWS, MAX_STRING_SIZE, madlibStory);
	handleReplacable(MAX_ROWS, MAX_STRING_SIZE, madlibStory);
	displayFullMadlib(MAX_ROWS, MAX_STRING_SIZE, madlibStory);
	
	fclose(inputFile); // Close the madlib.txt file 
	
	return 0;
	
}// END of main

// FUNCTION DEFINITIONS BELOW

void displayFullMadlib(int rows, int cols, char stringArray[][cols]){
// PURPOSE: displays the Madlib with all user input and proper spacing. 	
	for (int r = 0; stringArray[r][0] != '\0'; r++){
		removeEndlineChar(stringArray[r]);
		if (r == 0 || isPunctuation(stringArray[r][0])) {
			printf("%s", stringArray[r]); //Prints string without a space if it's the first string or starts with punctation (i.e. '.').
		} else {
			printf(" %s", stringArray[r]); //Prints string starting with a space in all other cases. 
		}
	}
	printf("\n");
}
_Bool isPunctuation(char compare){
// PURPOSE: returns a boolean value for proper spacing with Madlib output. 	
	switch(compare){
		case '.':
			return 1;
			break;
		case ',':
			return 1;
			break;
		case '?':
			return 1;
			break;
		case '!':
			return 1;
			break;
		//Could expand...
		default:
			return 0;
			break;	
	}	
} // END of isPunctutation

void storeText(FILE* fileToRead, int rows, int cols, char str[][cols]){
// PURPOSE: stores strings from file into a 2D array
	for (int i = 0; i < rows; i++){
		fgets(str[i], cols, fileToRead); // At the "i"th row of str, of size cols, appends from fileToRead
	}
} // END of storeText

int getStringLength(char str[]){
// PURPOSE: gets the length of a string using a for loop to count through how many indexes it takes until a null character ('\0') is reached.
	int counter = 0;
	while (str[counter] != '\0'){
		counter++;
	}
	return counter;
	
} // END of getStringLength

void handleReplacable(int rows, int cols, char str[][cols]){ 
// PURPOSE: prompts user with proper prompt and gets user input    
    for (int i = 0; i < rows; i++){
        // Do checking and prompting logic here
        
        if (getStringLength(str[i]) - 1 <= 1){ // - 1 because the newline character adds to lines of size 1
            switch (str[i][0]){ // Pass in values of first column of str
                case 'A':// Adjective
                    printf("Please enter an adjective: ");
                    fgets(str[i], cols, stdin);
                    str[i][getStringLength(str[i]) - 1] = ' '; // Adds a space at the end of user input
                    break;
                case 'N':// Noun
                    printf("Please enter a noun: ");
                    fgets(str[i], cols, stdin);
                    str[i][getStringLength(str[i]) - 1] = ' '; // Adds a space at the end of user input
                    break;
                case 'V': // Verb
                    printf("Please enter a verb: ");
                    fgets(str[i], cols, stdin);
                    str[i][getStringLength(str[i]) - 1] = ' '; // Adds a space at the end of user input
                    break;
            }
        }
    }
} // END of handleReplacable

void removeEndlineChar (char str[]){
 // PURPOSE: gets the index of the endline character and converts it to a space. 	
	int endlineIndex = getStringLength(str) - 1; // Gets the index of the endline character (\n)
	str[endlineIndex] = '\0'; // Changes the endline to a space ( )
} // END Of removeEndlineChar	

