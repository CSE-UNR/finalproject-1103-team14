// Verenice Acosta
// Final Project

#include <stdio.h>
#include <stdbool.h>

#define ROWS 1000
#define COLUMNS 1000
#define FILENAMECAP 75

int getGeneralMenuOptions(); 
int getEditMenuOptions();  

void cropImage(char array[ROWS][COLUMNS], int width, int height);
void brightenImage(char array[ROWS][COLUMNS], int width, int height);
void dimImage(char array[ROWS][COLUMNS], int width, int height);
void grabImageDimensions(int* widthPointer, int* heightPointer,FILE* inputFilePointer, char fileName[]);
void displayFileImage(FILE* inputFilePointer, char fileName[]);
void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]);


int main() {
	int generalMenuChoice, editMenuChoice, widthIndex, heightIndex, originalWidth = 0, originalHeight = 0, endIndex; 
	char saveYesNo, copiedImage[ROWS][COLUMNS], inputFileName[FILENAMECAP];
	
	FILE* userFilePointer;
	
	do{ 
		
		generalMenuChoice = getGeneralMenuOptions(); 

		if(generalMenuChoice == 1){ //LOADING IMAGE
			char buffer;
			scanf("%c", &buffer);
			
			printf("What is the name of the image file? "); 
			fgets(inputFileName, FILENAMECAP, stdin);
			
			
			for (int letter=0; inputFileName[letter] != '\0'; letter++) {
				endIndex = letter;
			}
			
			inputFileName[endIndex] = inputFileName[endIndex+1];
			userFilePointer = fopen(inputFileName, "r");
	
			if (userFilePointer == NULL) {
				printf("Could not find an image with that file name.\n");
			} 
			
			fclose(userFilePointer);
			printf("\nImage loaded successfully!\n");
			
			//Copy contents of file into copiedImage array after calculating image dimensions
			grabImageDimensions(&originalWidth, &originalHeight, userFilePointer, inputFileName);

			copyFileImage(originalWidth, originalHeight, copiedImage, userFilePointer, inputFileName);
			printf("\nBegin printing from array\n");
			
			for (int i =0; i<originalHeight; i++) {
				for (int j=0; j<originalWidth+1;j++) {
					printf("%c", copiedImage[i][j]);
				}
			}
			
			printf("end\n\n");
			
			
		} else if(generalMenuChoice == 2){ //DISPLAYING IMAGE
			displayFileImage(userFilePointer, inputFileName);
			
			
		} else if(generalMenuChoice == 3){ //EDITING IMAGE
			editMenuChoice = getEditMenuOptions(); 

			if(editMenuChoice == 1){ //CROPPING IMAGE
 				cropImage(copiedImage, originalWidth, originalHeight);	
			} 

			else if(editMenuChoice == 2){ //DIM IMAGE
				dimImage(copiedImage, originalWidth, originalHeight);
			}
			
      			else if(editMenuChoice == 3){ //BRIGHTEN IMAGE
        			brightenImage(copiedImage, originalWidth, originalHeight);
      			}
      			
		} else if(editMenuChoice == 0){ 
			printf("\nGoodbye!\n\n"); 
			return 0;
		} 
	} while(generalMenuChoice != 0); 

	return 0; 
} 


int getGeneralMenuOptions(){ 
	int userChoice1;
	printf("**ERINSTAGRAM**\n"); 
	printf("1. Load image\n"); 
	printf("2. Display image\n"); 
	printf("3. Edit image\n"); 
	printf("0. Exit\n"); 
	printf("\nChoose from one of the options above: ");
	scanf("%d", &userChoice1);

	return userChoice1;
} 

int getEditMenuOptions(){ 
  	int userChoice2;
  	
	printf("\n\n");
  	printf("**EDITING**\n"); 
	printf("1. Crop image\n"); 
	printf("2. Dim image\n"); 
	printf("3. Brighten image\n"); 
	printf("0. Return to main menu\n"); 
	printf("\nChoose from one of the options above: ");
	scanf("%d", &userChoice2);

	return userChoice2;
} 

void cropImage(char array[ROWS][COLUMNS], int width, int height){
	int leftCol, rightCol, topRow, bottomRow, newRow, newCols;
	
	//for(int heightIndex = 0; heightIndex < height; heightIndex++){
		//for(int widthIndex = 0; widthIndex < width + 1; widthIndex++){
			//array[0][1] = '1';
			//printf("%c", array[heightIndex][widthIndex]);
		//}
	//}Displaying the image with # of rows and columns 
	
	printf("The image you want to crop is %d x %d.\n", height, width);
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("\n\nWhich column do you want to be the new left side? ");
	scanf("%d", &leftCol);
	printf("\n\nWhich column do you want to be the new right side? ");
	scanf("%d", &rightCol);
		if(rightCol <= leftCol){
			printf("Invalid column. Choose a value between %d and %d: ", leftCol, width - 1);
			scanf("%d", &rightCol);
		}
	printf("Which row do you want to be the new top? ");
	scanf("%d", &topRow);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &bottomRow);
		if(rightCol <= leftCol){
			printf("Invalid row. Choose a value between %d and %d: ", leftCol, width - 1);
			scanf("%d", &rightCol);
		}
	
	for(int heightIndex = topRow; heightIndex <= bottomRow; heightIndex++){
		for(int widthIndex = leftCol; widthIndex <= rightCol; widthIndex++){
			for(heightIndex = topRow; heightIndex < height; heightIndex++){
				for(widthIndex = leftCol; widthIndex < width; widthIndex++){
					printf("%c", array[heightIndex][widthIndex]);
				}
			}
		}
	}
}

void brightenImage(char array[ROWS][COLUMNS], int width, int height){
	
	for (int heightIndex=0; heightIndex<height; heightIndex++) {
		for (int widthIndex=0; widthIndex<width+1; widthIndex++) {
			if (array[heightIndex][widthIndex] == '0') {
				array[heightIndex][widthIndex] = '0';
			} else if (array[heightIndex][widthIndex] == 'O') {
				array[heightIndex][widthIndex] = '0';
			} else if (array[heightIndex][widthIndex] == 'o') {
				array[heightIndex][widthIndex] = 'O';
			} else if (array[heightIndex][widthIndex] == '.') {
				array[heightIndex][widthIndex] = 'o';
			} else if (array[heightIndex][widthIndex] == ' ') {
				array[heightIndex][widthIndex] = '.';
			}
			printf("%c", array[heightIndex][widthIndex]);
		}
	}
}

void dimImage(char array[ROWS][COLUMNS], int width, int height){
	
	for (int heightIndex=0; heightIndex<height; heightIndex++) {
		for (int widthIndex=0; widthIndex<width+1; widthIndex++) {
			if (array[heightIndex][widthIndex] == ' ') {
				array[heightIndex][widthIndex] = ' ';
			} else if (array[heightIndex][widthIndex] == '.') {
				array[heightIndex][widthIndex] = ' ';
			} else if (array[heightIndex][widthIndex] == 'o') {
				array[heightIndex][widthIndex] = '.';
			} else if (array[heightIndex][widthIndex] == 'O') {
				array[heightIndex][widthIndex] = 'o';
			} else if (array[heightIndex][widthIndex] == '0') {
				array[heightIndex][widthIndex] = 'O';
			}
			printf("%c", array[heightIndex][widthIndex]);
		}
	}
}

void grabImageDimensions(int* widthPointer, int* heightPointer, FILE* inputFilePointer, char fileName[]) {
	char letter;
	
	int height;
	int width;
	
	int total = 0; // Stores all possible characters in file's contents INCLUDING lines
	int allValidPixels = 0; // Stores all possible characters in file's contents EXCLUDING endlines
	
	inputFilePointer = fopen(fileName, "r");
	
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		if (letter == ' ' || letter == '.' || letter == 'o' || letter == 'O' || letter == '0') {
			allValidPixels++;
		}
		total++;	
	} 
	
	fclose(inputFilePointer);
	
	//Calculates width and height and assigned to their respective pointers to declare copiedImage[] in main
	height = total - allValidPixels;
	width = (total-height) / height;

	*heightPointer = height;
	*widthPointer = width; 

}

void displayFileImage(FILE* inputFilePointer, char fileName[]) {
	char letter;

	inputFilePointer = fopen(fileName, "r");

	//Displays each letter in file's contents
	while (fscanf(inputFilePointer, "%c", &letter) == 1) {
		printf("%c", letter);
	}

	fclose(inputFilePointer);
	
}

void copyFileImage(int width, int height, char array[ROWS][COLUMNS], FILE* inputFilePointer, char fileName[]) {
	int count = 0; //Debugging
	
	inputFilePointer = fopen(fileName, "r");

	//Copies the file's contents into array pointer.
	// +1 in for loop accounts for endlines
	for (int heightIndex=0; heightIndex<height; heightIndex++) {
		for (int widthIndex=0; widthIndex<width+1; widthIndex++) {
			count++; //Debugging
			fscanf(inputFilePointer, "%c", &array[heightIndex][widthIndex]);

			//printf("%c", array[heightIndex][widthIndex]);
		}
		
	}
	
	fclose(inputFilePointer);
	
	//printf("COPIED IMAGE DISPLAY FROM ARRAY DONE ^^^^ \n"); Debugging 
	//printf("Total Characters: %d\n", count); Debugging 
}
