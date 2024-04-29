// Victor Dang
// Image Processing 

#include <stdio.h>

#define STR_CAP 75

void copyFileImage(FILE* inputFilePointer, char fileName[]);

int main () {
	//Image to load for testing: TestImage.txt

	char inputFileName[STR_CAP];
	char originalImage[STR_CAP][STR_CAP];
	int endIndex;
	FILE* userFilePointer;
	
	//Load User Image 
	printf("Enter file to load (without .txt at): ");
	fgets(inputFileName, STR_CAP, stdin);
	
	for (int letter=0; inputFileName[letter] != '\0'; letter++) {
		endIndex = letter;
	}
	
	inputFileName[endIndex] = '.';
	inputFileName[endIndex+1] = 't';
	inputFileName[endIndex+2] = 'x';
	inputFileName[endIndex+3] = 't';
	
	copyFileImage(userFilePointer, inputFileName);
	
	
	
	
	return 0;
}


void copyFileImage(FILE* inputFilePointer, char fileName[]) {

	inputFilePointer = fopen(fileName, "r");
	
	if (inputFilePointer == NULL) {
		printf("File couldn't be loaded succesfully. Goodbye. \n");
	}
	
	printf("Successful Load");
	
	fclose(inputFilePointer);
}








