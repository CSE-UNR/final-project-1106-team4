// Authors: James Dye & Vennethe Y. Valenzuela 
// Date: 12/02/20
// Purpose: To create a Madlib game that a user can play within the terminal.

#include <stdio.h>

// MACROS
#define MAX_STRING_SIZE 1000

// FILES
#define INPUT_FILE_1 madlib1.txt
#define INPUT_FILE_2 madlib2.txt

// FUNCTION PROTOTYPES BELOW
int getStringLength(char str[]); 
int getNumLinesFromFile(FILE* fileToRead, int maxColSize);

void requestUserInput(int size, char madlibChars[], char madlibResponses[][MAX_STRING_SIZE]);
void removeEndlineChar (int size, char string[]);
void removeEndlineChar2 (char str[]);
void handleReplacable(int rows, int cols, char thing[][cols]);
void storeText(FILE* fileToRead, int rows, int cols, char str[][cols]);

// MAIN FUNCTION BELOW
int main(){	
	FILE inputFile = fopen(INPUT_FILE_1, "r"); // Open a madlib.txt file
	
	// Verify connection is made to a madlib.txt file
	if (inputFile == NULL){
		printf("Could not open a file for reading!\n");
		return 0;
	}
	
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

void handleReplacable(int rows, int cols, char thing[][cols]){
    for (int i = 0; i < rows; i++){
        // Do checking and prompting logic here
        if (getStringLength(thing[i]) == 1){
            switch (thing[i][0]){
                case 'A'://Adjective
                    printf("Please enter an adjective: ");
                    fgets(thing[i], cols, stdin);
                    thing[i][getStringLength(thing[i])-1] = '\0';
                    break;
                case 'N'://Noun
                    printf("Please enter a noun: ");
                    fgets(thing[i], cols, stdin);
                    thing[i][getStringLength(thing[i])-1] = '\0';
                    break;
                case 'V': //Verb
                    printf("Please enter a verb: ");
                    fgets(thing[i], cols, stdin);
                    thing[i][getStringLength(thing[i])-1] = '\0';
                    break;
            }
        }
    }
}

/*
// PURPOSE: Creates a char var holder and interates through a char array to display to the screen requests and waits for a response before reasking.	
void requestUserInput(int size, char madlibChars[]){
	char holder = madlibChars[0];
	char response[MAX_STRING_SIZE];
	
	for (int i = 0; i < size; i++){
		holder = madlibChars[i];
		if (holder == 'A'){
			printf("Please enter an adjective: ");	
		} else {
			printf("Please enter a ");
			if (holder == 'N'){
				printf("noun: ");
			} else if (holder == 'V'){
				printf("verb: ");
			} // End of nested if/else if statement
		} // End of if/else statement
		
		fgets(responses, size, stdin);
		
	} // End of for loop	

}// END of requestUserInput

void removeEndlineChar (int size, char string[]){
// PURPOSE: Interates through a string and once a null character is detected, makes the character a space (' ')	
	for (int i = 0; i < size; i++){
		if (string[i] == '\0'){
			string[i] = ' ';
		}
	}
	
}// END of removeEndLineChar

// Another way to write removeEndlineChar
void removeEndlineChar2 (char str[]){
	int endlineIndex = getStringLength(str); 
	str[endlineIndex] = ' '; //Sets the endline character of the string as a space 
	
} // END of removeEndLineChar2
*/
