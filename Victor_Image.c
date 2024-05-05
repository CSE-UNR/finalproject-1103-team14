// Victor Dang
// Image Processing 

#include <stdio.h>
#include <stdbool.h>

#define ROWS 1000
#define COLUMNS 1000
#define FILENAMECAP 75

int getGeneralMenuOptions(); 
int getEditMenuOptions();  


void dimImage(char copiedImage[ROWS][COLUMNS], int width, int height);

void grabImageDimensions(int* widthPointer, int* heightPointer,FILE* inputFilePointer, char fileName[]);

void displayFileImage(FILE* inputFilePointer, char fileName[]);

void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]);


int main() {
	int generalMenuChoice, editMenuChoice, widthIndex, heightIndex, originalWidth = 0, originalHeight = 0, endIndex; 
	char saveYesNo;
	char copiedImage[COLUMNS][ROWS];
	char inputFileName[FILENAMECAP];
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
				printf("Sorry, no image to display\n");
				printf("Returning back to first menu.\n");
			} 
			
			fclose(userFilePointer);
			printf("\nImage loaded successfully.\n");
			
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
 				
			} 

			else if(editMenuChoice == 2){ //DIM IMAGE
				dimImage(copiedImage, originalWidth, originalHeight);
			}
			
      			else if(editMenuChoice == 3){ //BRIGHTEN IMAGE
        
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

/*
void cropImage(char array[ROWS][COLUMNS], int width, int height){
	int leftCol, rightCol, topRow, bottomRow, rowI = width, colI = height;
	
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("\nWhich column do you want to be the new left side? ");
	scanf(" %d", &leftCol);
	printf("\n\nWhich column do you want to be the right left side? ");
	scanf(" %d", &rightCol);
	printf("\n\nWhich row do you want to be the new top? ");
	scanf(" %d", &topRow);
	printf("\n\nWhich row do you want to be the new bottom? ");
	scanf(" %d", &bottomRow);
	
	for(rowI = 0; rowI < topRow; rowI++){
		for(columnI = 0; columnI < leftCol; columnI++){
			for(rowI = 0; rowI < bottomRow; rowI++){
				for(columnI = 0; columnI < rightCol; columnI++){
					bottomRow - topRow = newRows;
					rightCol - leftCol = newCols;
					array[newRows][newCols];
				}
			}
		}
	}
					
	//display new image
	printf("\n");
}*/




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

void copyFileImage(int width, int height, char array[COLUMNS][ROWS], FILE* inputFilePointer, char fileName[]) {
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
