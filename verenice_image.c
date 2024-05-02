//Author: Verenice Acosta 
//Menu selections for image project 

#include <stdio.h> 

#define ROWS 100 
#define COLUMNS 100
#define FILENAMECAP 75

int getGeneralMenuOptions(); 
int getEditMenuOptions(); 

int dimImage(int width, int height, int image[][height]); 
char saveFileImageChoice();

void grabImageDimensions(int* widthPointer, int* heightPointer,FILE* inputFilePointer, char fileName[]);
void displayFileImage(FILE* inputFilePointer, char fileName[]);
void copyFileImage(int width, int height, char array[width][height], FILE* inputFilePointer, char fileName[]);


int main(){ 

	int generalMenuChoice, editMenuChoice, image[ROWS][COLUMNS], originalWidth = 0, originalHeight = 0, endIndex; 
	char saveYesNo;
	char copiedImage[ROWS][COLUMNS];
	char inputFileName[FILENAMECAP];
	FILE* userFilePointer;
	
	do{ 

		generalMenuChoice = getGeneralMenuOptions(); 

		if(generalMenuChoice == 1){ 
		
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
				printf("Image couldn't be loaded succesfully.\n");
				printf("Returning back to first menu.\n");
			
			}
	
			printf("\nImage loaded successfully.\n");
			
			fclose(userFilePointer);
			
			
			//Copy contents of file into copiedImage array after calculating image dimensions
			grabImageDimensions(&originalWidth, &originalHeight, userFilePointer, inputFileName);
			
	
			copyFileImage(originalWidth, originalHeight, copiedImage, userFilePointer, inputFileName);
			
			printf("\n");
		} 

		else if(generalMenuChoice == 2){ 
			printf("\n"); 
			displayFileImage(userFilePointer, inputFileName);
			printf("%c", copiedImage[1][4]);
			printf("%c", copiedImage[1][25]);
			
		}

		else if(generalMenuChoice == 3){ 
			editMenuChoice = getEditMenuOptions(); 

			if(editMenuChoice == 1){ 
				printf("\n"); 
				printf("The image you want to crop is \n"); 
				// add the 2D array values here
				printf("The row and column values start in the upper lefthand corner.\n");
				printf("\nWhich column do you want to be the new left side? ");
				//scanf(" %d", &leftCol);
				printf("\n\nWhich column do you want to be the right left side? ");
				//scanf 2D array value here
				printf("\n\nWhich row do you want to be the new top? ");
				//scanf
				printf("\n\nWhich row do you want to be the new bottom? ");
				//scanf
				//display new image
				printf("\n");
				saveYesNo = saveFileImageChoice();
 				
			} 

			else if(editMenuChoice == 2){ 
				//display image 
        saveYesNo = saveFileImageChoice();

			} 

      else if(editMenuChoice == 3){
        //display image
        saveYesNo = saveFileImageChoice();
        
      }
		} 
		else if(editMenuChoice == 0){ 
			printf("\nGoodbye!\n\n"); 
		} 
	}while(generalMenuChoice != 0); 

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
	scanf(" %d", &userChoice1);

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
	scanf(" %d", &userChoice2);

	return userChoice2;
} 


char saveFileImageChoice(){
  	char saveOption;

	printf("Would you like to save the file? (y/n) "); 
	scanf(" %c", &saveOption); 
	printf("\n"); 
	switch(saveOption){ 
		case 'Y': 
		case 'y': 
			printf("What do you want to name the image file? (include the extension) "); 
			//scanf of the new file name 
			printf("\nImage successfully loaded!\n\n"); 
			break; 
		case 'N': 
		case 'n': 
		break; 
	} 
        
        return saveOption;
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
	char letter;
	inputFilePointer = fopen(fileName, "r");

	//Copies the file's contents into array pointer.
	// +1 in for loop accounts for endlines
	for (int widthIndex=0; widthIndex<width+1; widthIndex++) {
		for (int heightIndex=0; heightIndex<height; heightIndex++) {
			count++; //Debugging
			fscanf(inputFilePointer, "%c", &array[widthIndex][heightIndex]);
			
			
			printf("%c", array[widthIndex][heightIndex]); //Debugging 
		}
	}
	
	
	
	
	printf("COPIED IMAGE DISPLAY FROM ARRAY DONE ^^^^ \n"); //Debugging 
	printf("Total Characters: %d\n", count); //Debugging 
	
	fclose(inputFilePointer);

}

void saveFileImage(FILE* outputFilePointer, char fileName[]) {
	
}
