#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char position[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


/*
This function detects if someone wins.As we know a Tic Tac board has nine
positions. I have numbered them as they are ordered on a standard numerical
keypad. A win is detected by seeing if one player's symbol is on the following
series of combinations:
123, 456, 789, 357, 159.
A value of 1 is returned when any of the combinations is made.
*/

int winDetector()
{
	if(position[1] == position[2] && position[2] == position[3]) 
	{
		return 1;
	}
	else if(position[4] == position[5] && position[5] == position[8]) 
	{
		return 1;
	}
	else if(position[4] == position[5] && position[5] == position[6]) 
	{
		return 1;
	}
	else if(position[7] == position[8] && position[8] == position[9]) 
	{
		return 1;
	}
	else if(position[1] == position[4] && position[4] == position[7]) 
	{
		return 1;
	}
	else if(position[2] == position[5] && position[5] == position[8]) 
	{
		return 1;
	}
	else if(position[3] == position[6] && position[6] == position[9]) 
	{
		return 1;
	}
	else if(position[1] == position[5] && position[5] == position[9]) 
	{
		return 1;
	}
	else if(position[7] == position[5] && position[5] == position[3]) 
	{
		return 1;
	}
	else if (position[1] != '1' && position[2] != '2' && position[3] != '3' && position[4] != '4' && position[5] != '5' && position[6] != '6' && position[7] != '7' && position[8] != '8' && position[9] != '9')
	{
	    return 0;
	}
	else 
	{
		return -1;
	}
	
	
}

//This just draws the board. Just drawing the lines and stuff by printing characters.

void Board() 
{
	system("cls");
	printf("\n\n\t Tic Tac Toe \n\n");
	printf("Player1 (x) - Player2 (0) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |   %c  \n", position[1], position[2], position[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |   %c  \n", position[4], position[5], position[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |   %c  \n", position[7], position[8], position[9]);
	printf("     |     |     \n");
}




int main()
{
	int player = 1, i, choice;
	char symbol; //X,O
	do 
	{
		Board();
		player = (player %2) ? 1:2;
		printf("Player %d, choose position: ",player);
		scanf("%d",&choice);//Get user input implying the position s/he wants to put marker at.
		
		if (player == 1) //Declare the type of symbol every player will put in his/her selected position
		{
			symbol = 'X';
		}
		else 
		{
			symbol = 'O';
		}
		
		if(choice == 1 && position[1] == '1') //This second and seen everywhere accepts to place the player's symbol there if it is unoccupied, meaning having its original value)
		{
			position[1]=symbol;
		}
		else if(choice == 2 && position[2]=='2') 
		{
			position[2] = symbol;
		}
		else if(choice == 3 && position[3]=='3') 
		{
			position[3] = symbol;
	    }
		else if(choice == 4 && position[4]=='4') 
		{
			position[4] = symbol;
	    }
		else if(choice == 5 && position[5]=='5') 
		{
			position[5] = symbol;
	    }
		else if(choice == 6 && position[6]=='6') 
		{
			position[6] = symbol;
	    }
		else if(choice == 7 && position[7]=='7') 
		{
			position[7] = symbol;
	    }
		else if(choice == 8 && position[8]=='8') 
		{
			position[8] = symbol;
	    }
		else if(choice == 9 && position[9]=='9') 
		{
			position[9] = symbol; 
		}
		else
		{
	    	printf("Invalid option !");
	    	player--;
	    	getch();
		}
		i = winDetector(); //Remember the return value of winDetector function.
		player++;
		
	}
	while(i == -1);
	
	Board();
	if(i==1)
	{
		printf("==>Player %d won", --player);
	}
	else
	{
		printf("==>Game draw");
	}
	getch();
	return 0;
}






