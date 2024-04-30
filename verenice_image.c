//Author:Verenice Acosta

#include <stdio.h>

void displayGeneralMenuOptions();
void displayEditMenuOptions();
int getGeneralMenuChoice();
int getEditMenuChoice();

int main(){
	
	int generalMenuChoice, editMenuChoice;
	
	do{
		displayGeneralMenuOptions();
		
		generalMenuChoice = getGeneralMenuChoice();
		
		if(generalMenuChoice == 1){
			printf("\n");
			printf("Enter the name of your file: ");
			// will scan name here
			printf("\n");
		}
		else if(generalMenuChoice == 2){
			printf("\n");
			printf("Here is your current image!\n");
		}
		else if(generalMenuChoice == 3){
			printf("\n");
			
			displayEditMenuOptions();
			
			editMenuChoice = getEditMenuChoice();
			
			if(editMenuChoice == 1){
				printf("\n");
				printf("Enter the width and length you would like to crop it to: ");
				printf("\n");
				// scanf the new elements of the 2D array
			}
			if(editMenuChoice == 2){
				printf("\n");
				printf("Here is your new dimmed image.");
				printf("\n");
				// display image here
			}
			if(editMenuChoice == 3){
				printf("\n");
				printf("Here is your new brightened image.");
				// display
				printf("\n");
			}
		
		
		}	
		
	}while(generalMenuChoice != 4);

	return 0;
}

void displayGeneralMenuOptions(){

	printf("\n**Image Processor**\n");
	printf("1. Load new image\n");
	printf("2. Display current image\n");
	printf("3. Edit current image\n");
	printf("4. Exit program\n");
}

int getGeneralMenuChoice(){
	int userChoice1;
	
	printf("Enter the number of your choice: ");
	scanf(" %d", &userChoice1);
	
	return userChoice1;
}

void displayEditMenuOptions(){
	
	printf("How would you like to edit your image?\n");
	printf("1. Crop image\n");
	printf("2. Dim image\n");
	printf("3. Brighten image\n");
	
}

int getEditMenuChoice(){
	int userChoice2;
	
	printf("Enter the number of your choice: ");
	scanf(" %d", &userChoice2);
	
	return userChoice2;
}


