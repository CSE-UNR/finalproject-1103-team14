//Author: Verenice Acosta 
//Menu selections for image project 

#include <stdio.h> 

#define ROWS 100 
#define COLUMNS 100
int getGeneralMenuOptions(); 
int getEditMenuOptions(); 
int dimImage(int width, int height, int image[][height]); 
char saveFileImageChoice();

int main(){ 

	int generalMenuChoice, editMenuChoice, image[ROWS][COLUMNS]; 
	char saveYesNo; 

	do{ 

		generalMenuChoice = getGeneralMenuOptions(); 

		if(generalMenuChoice == 1){ 
			printf("What is the name of the image file? "); 
			//add the file scanning part here 
			//if file exists will give a success message if fails gives error message and sends to main menu and all the other options will print
			printf("\n");
		} 

		else if(generalMenuChoice == 2){ 
			printf("\n"); 
			//add display image 
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
