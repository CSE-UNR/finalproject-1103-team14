// Victor Dang
// Image Processing 

#include <stdio.h>
#include <stdbool.h>

#define STR_CAP 75

void grabImageDimensions(int* widthPointer, int* heightPointer,FILE* inputFilePointer, char fileName[]);
void displayFileImage(FILE* inputFilePointer, char fileName[]);

void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]);


int main() {
	//Image to load for testing: TestImage.txt

	char inputFileName[STR_CAP];
	char originalImage[STR_CAP][STR_CAP];
	int originalWidth = 0;
	int originalHeight = 0; 
	
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
	
	userFilePointer = fopen(inputFileName, "r");
	
	if (userFilePointer == NULL) {
		printf("Image couldn't be loaded succesfully. Goodbye. \n");
		return 0;
	}
	
	fclose(userFilePointer);
	
	//Grab File Dimensions, Display File to Screen 
	grabImageDimensions(&originalWidth, &originalHeight, userFilePointer, inputFileName);
	char copiedImage[originalWidth][originalHeight];
	
	displayFileImage(userFilePointer, inputFileName);
	
	return 0;
}

void grabImageDimensions(int* widthPointer, int* heightPointer, FILE* inputFilePointer, char fileName[]) {
	char letter;
	
	int height;
	int width;
	
	int total = 0;
	
	int BrightnessZero = 0;
	int BrightnessOne = 0;
	int BrightnessTwo = 0;
	int BrightnessThree = 0;
	int BrightnessFour = 0;
	
	inputFilePointer = fopen(fileName, "r");
	
	if (inputFilePointer == NULL) {
		printf("File couldn't be loaded successfully. Goodbye. \n");
	}
	
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		if (letter == ' ') {
			BrightnessZero++;
		} else if (letter == '.') {
			BrightnessOne++;
		} else if (letter == 'o') {
			BrightnessTwo++;
		} else if (letter == 'O') {
			BrightnessThree++;
		} else if (letter == '0') {
			BrightnessFour++;
		}
	
		total++;	
	} 
	
	height = total - (BrightnessZero + BrightnessOne + BrightnessTwo + BrightnessThree + BrightnessFour);
	width = (total-height) / height;
	
	*heightPointer = height;
	*widthPointer = width; 
	
	/*
	printf("\nThe height of the image is %d. ", height);
	printf("\nThe width of the image is %d. ", width);
	
	printf("\nRead %d Brightness 0(  ) characters in image.", BrightnessZero);
	printf("\nRead %d Brightness 1( . ) characters in image.", BrightnessOne);
	printf("\nRead %d Brightness 2( o ) characters in image.", BrightnessTwo);
	printf("\nRead %d Brightness 3( O ) characters in image.", BrightnessThree);
	printf("\nRead %d Brightness 4( 0 ) characters in image.", BrightnessFour);
	printf("\nRead %d total letters in image including endlines and %d without.", total, (total-height)); */
	
	fclose(inputFilePointer);
	
	printf("Successfully Loaded Image\n");
}

void displayFileImage(FILE* inputFilePointer, char fileName[]) {
	char letter;
	inputFilePointer = fopen(fileName, "r");
	
	if (inputFilePointer == NULL) {
		printf("File couldn't be loaded successfully. Goodbye. \n");
	}
	
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		printf("%c", letter);
	}
	
	fclose(inputFilePointer);
}

void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]) {


	


}







