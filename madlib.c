// Authors: James Dye & Vennethe Y. Valenzuela 
// Date: 12/02/20
// Purpose: To create a Madlib game that a user can play within the terminal.

//TO-DO: Remove newlines if present

#include <stdio.h>

// MACROS
#define MAX_STRING_SIZE 1000

// FILES
#define INPUT_FILE_1 "madlib1.txt"
#define INPUT_FILE_2 "madlib2.txt"

// FUNCTION PROTOTYPES BELOW
int getStringLength(char str[]); 
int getNumLinesFromFile(FILE* fileToRead, int maxColSize);

void requestUserInput(int size, char madlibChars[], char madlibResponses[][MAX_STRING_SIZE]);
void removeEndlineChar (char str[]);
void handleReplacable(int rows, int cols, char thing[][cols]);
void storeText(FILE* fileToRead, int rows, int cols, char str[][cols]);

// MAIN FUNCTION BELOW
int main(){	
	FILE* inputFile = fopen(INPUT_FILE_2, "r"); // Open a madlib.txt file
	
	// Verify connection is made to a madlib.txt file
	if (inputFile == NULL){
		printf("Could not open a file for reading!\n");
		return 0;
	}
	int numRows = getNumLinesFromFile(inputFile, MAX_STRING_SIZE); // Forces reopening of file 
	fclose(inputFile); // Close the madlib.txt file
	
	char madlibStory[numRows][MAX_STRING_SIZE];
	
	inputFile = fopen(INPUT_FILE_2, "r");
	
	// Verify connection is made to a madlib.txt file
	if (inputFile == NULL){
		printf("Could not open a file for reading!\n");
		return 0;
	}
	storeText(inputFile, numRows, MAX_STRING_SIZE, madlibStory);
	handleReplacable(numRows, MAX_STRING_SIZE, madlibStory);
	
	for (int r = 0; r < numRows; r++){
		removeEndlineChar(madlibStory[r]);
		if (r == 0 || madlibStory[r][1] == ' '){
			printf("%s", madlibStory[r]); //Prints string without a space if it's the first string or starts with punctation (i.e. '.').
		} else {
			printf(" %s", madlibStory[r]); //Prints string starting with a space in all other cases. 
		}
	}
	printf("\n");
	fclose(inputFile); // Close the madlib.txt file 
	
	return 0;
	
}// END of main

void storeText(FILE* fileToRead, int rows, int cols, char str[][cols]){
	for (int i = 0; i < rows; i++){
		fgets(str[i], cols, fileToRead); // At the "i"th row of str, of size cols, appends from fileToRead
	}
}

int getNumLinesFromFile(FILE* fileToRead, int maxColSize){
	int counter = 0;
	char temp[maxColSize];
	while (fgets(temp, maxColSize, fileToRead) != NULL){
		counter++;
	}
	return counter;
}

// FUNCTION DEFINITIONS BELOW
int getStringLength(char str[]){
// PURPOSE: gets the length of a string using a for loop to count through how many indexes it takes until a null character ('\0') is reached.
	int counter = 0;
	while (str[counter] != '\0'){
		counter++;
	}
	return counter;
	
}// END of getStringLength

void handleReplacable(int rows, int cols, char str[][cols]){
    for (int i = 0; i < rows; i++){
        // Do checking and prompting logic here
        
        /*Debugging
        int temp = getStringLength(str[i]);
        printf("%d| %s", temp, str[i]);
        */
        
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
} //END of handleReplacable

void removeEndlineChar (char str[]){
 // PURPOSE: gets the index of the endline character and converts it to a space. 	
	int endlineIndex = getStringLength(str) - 1; // Gets the index of the endline character (\n)
	str[endlineIndex] = '\0'; // Changes the endline to a space ( )
} // END Of removeEndlineChar	




