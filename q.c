#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
//#include<conio.h> /*for clrscr()*/	
#include <unistd.h> // for using sleep

#include<readline/history.h> // to use function add_history

void at_start() {
	system("clear"); 
	printf(" \n \n ************* Kissa's Shell *************\n \n");
    sleep(2);
    system("clear");
}

void type_prompt(){
	//Printing current working directory
	char cwd[1000]; 
	getcwd(cwd, sizeof(cwd)); 
	printf("\nCurrent Directory: %s\n", cwd); 

	printf("cmdp@ubuntu: " );
}

int take_input(char* input){

	char input_buffer[50];
	memset(input_buffer,'\0',sizeof(input_buffer));

	// Taking command from the user through fgets
	fgets (input_buffer, 49, stdin);
	// removing the enter character from the input
	int i = 0;
	while(1){
	   	if (input_buffer[i] == '\n'){
	   		input_buffer[i] = '\0';
	   		break;
	   	}
	   	i++;
	}
	printf("Buffer : %s\n", input_buffer);

	
	if (strlen(input_buffer) != 0){ //Buffer contains an input

		add_history(input_buffer); // Add the input value into history
		strcpy(input,input_buffer);// Now input will point to input_buffer[0]
		return 1;
	}
	else{ // Got no proper input 
		return 0;
	}
}

void loop(){

	while(1){

		type_prompt();

		char* input; // stores the input typed by the user 

		// Taking the right input
		int j;
		while (1){
			j = take_input(input);
			if (j == 1){
				printf("j = 1\n");
				break;
			}			
		}

		
		
	}// end of outer most while(1)
}

int main()
{
    at_start();
    loop();
	return 0;
}