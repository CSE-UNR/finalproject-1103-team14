// Victor Dang
// Image Processing 

#include <stdio.h>
#include <stdbool.h>

#define FILENAMECAP 75

void grabImageDimensions(int* widthPointer, int* heightPointer,FILE* inputFilePointer, char fileName[]);
void displayFileImage(FILE* inputFilePointer, char fileName[]);
void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]);

int main() {
	//Image to load for testing: TestImage.txt or TestImage2.txt

	char inputFileName[FILENAMECAP];
	int originalWidth = 0;
	int originalHeight = 0; 
	
	int endIndex;
	
	FILE* userFilePointer;
	
	//Load User Image 
	
	printf("Enter file to load: ");
	fgets(inputFileName, FILENAMECAP, stdin);
	
	for (int letter=0; inputFileName[letter] != '\0'; letter++) {
		endIndex = letter;
	}
	inputFileName[endIndex] = inputFileName[endIndex+1];
	
	userFilePointer = fopen(inputFileName, "r");
	
	//Exit program if file couldn't be loaded in. 
	if (userFilePointer == NULL) {
		printf("Image couldn't be loaded succesfully.\n");
		printf("Returning back to first menu.\n");
		return 0;
	}
	
	printf("\nImage loaded successfully.\n");
	fclose(userFilePointer);
	
	displayFileImage(userFilePointer, inputFileName);
	
	//Copy contents of file into copiedImage array after calculating image dimensions
	grabImageDimensions(&originalWidth, &originalHeight, userFilePointer, inputFileName);
	char copiedImage[originalWidth][originalHeight];
	
	copyFileImage(originalWidth, originalHeight, copiedImage, userFilePointer, inputFileName);
	
	
	return 0;
}

void grabImageDimensions(int* widthPointer, int* heightPointer, FILE* inputFilePointer, char fileName[]) {
	char letter;
	
	int height;
	int width;
	
	int total = 0; // Stores all possible characters in file's contents INCLUDING endlines
	int allValidPixels = 0; // Stores all possible characters in file's contents EXCLUDING endlines
	
	inputFilePointer = fopen(fileName, "r");
	
	
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		if (letter == ' ' || letter == '.' || letter == 'o' || letter == 'O' || letter == '0') {
			allValidPixels++;
		}
		total++;	
	} 
	
	//Calculates width and height and assigned to their respective pointers to declare copiedImage[] in main
	height = total - allValidPixels;
	width = (total-height) / height;
	
	*heightPointer = height;
	*widthPointer = width; 
	 
	//Debugging printf("\nTotal: %d", total); 
	//Debugging printf("\nWidth: %d", width); 
	//Debugging printf("\nHeight: %d\n", height); 
	
	fclose(inputFilePointer);
	
}

void displayFileImage(FILE* inputFilePointer, char fileName[]) {
	char letter;
	int count = 0; //Debugging
	
	inputFilePointer = fopen(fileName, "r");
	
	//Displays each letter in file's contents
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		count++;
		printf("%c", letter);
	}
	
	printf("ORIGINAL IMAGE DISPLAY DONE. ^^^^ \n"); //Debugging
	printf("Total Characters: %d\n", count); //Debugging
	
	fclose(inputFilePointer);
}

void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]) {
	int count = 0; //Debugging
	
	inputFilePointer = fopen(fileName, "r");

	//Copies the file's contents into array pointer.
	// +1 in for loop accounts for endlines
	for (int widthIndex=0; widthIndex<width+1; widthIndex++) {
		for (int heightIndex=0; heightIndex<height; heightIndex++) {
			count++; //Debugging
			fscanf(inputFilePointer, "%c", &array[widthIndex][heightIndex]);
			
			//Debugging printf("%c", array[widthIndex][heightIndex]); 
		}
	}
	
	//Debugging printf("COPIED IMAGE DISPLAY FROM ARRAY DONE ^^^^ \n"); 
	//Debugging printf("Total Characters: %d\n", count); 
	
	fclose(inputFilePointer);

}

void saveFileImage(FILE* outputFilePointer, char fileName[]) {
	
}

//need edited image to allow for functionality of the save 
//need invalid check for invalid file that doesn't exist > return to first menu
//need invalid check for invalid rows and columns for cropping > reprompt for valid rows and columns
//need invalid check for invalid option > exit program entirely 




