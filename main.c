#include<stdio.h>
#include<stdlib.h>
#include"include.h"
#include"winchecker.c"
#include"minmax.c"
void printboard(int b[])
{
	printf("\n");
	printf("____ ____ ____ \n");
	printf("                \n");
	printf(" | %c | %c | %c |\n", decode(b[0]), decode(b[1]), decode(b[2]));
	printf("____ ____ ____ \n");
	printf("                \n");
	printf(" | %c | %c | %c |\n", decode(b[3]), decode(b[4]), decode(b[5]));
	printf("____ ____ ____ \n");
	printf("                \n");
	printf(" | %c | %c | %c |\n", decode(b[6]), decode(b[7]), decode(b[8]));
	printf("____ ____ ____ \n");
	printf("\n");

}
char decode(int n)
{
	if(n == 0)
		return ' ';
	else if(n == 1)
		return 'X';
	return 'O';	
}
int td(int mno)
{
	if(mno % 2 == 1)
	       return 1;
	return -1;	
}
int movmkr(int pos, int mno, int b[])
{
	
	if(legalmv(pos, b)){
		b[pos] = td(mno);
		return 1;
	}
	printf("Invalid input.\n");
	return 0;
}
int legalmv(int pos, int b[])
{
	if(pos < 9)
	{
		if(b[pos] != 0)
		{
			return 0;
		}
		return 1;
	}
	return 0;
}
void initar(int b[])
{
	for(int i = 0; i < 9; i++)
		b[i] = 0;
}
int dgt(char a)
{
	if(a > 48 && a < 58)
	{
		return (a[0] - 48);
	}
	return 10;
}
void terminal(int b[], int turn, int win)
{
	printboard(b);
	if(win == 0){
		printf("Game is a draw.\n");
	}
	else{
		printf("%c is the winner!\n", decode(turn));
	}
}
int cmplr(int b[], int mov, int cmp)
{
	char plrin;
	if(mov % 2 == cmp){
	printboard(b);
	printf("It's player %c's turn, choose a position b/t 1-9: ", decode(td(mov)));
	plrin = getchar();
	system("clear");
	if(movmkr(dgt(plrin) - 1, mov, b) == 0)
		return 0;
	}
	else
		b[minimax(b, td(mov), 0) - 1] = td(mov);
	return 1;
}
void twoplr(int b[])
{
	int mov, win = 0;
	for(mov = 1; mov < 10; mov++)
	{
		if(cmplr(b, mov, 1) == 0)
			mov--;
		win = winchecker(b);
		if(win != 0)
			break;

	}
	terminal(b, td(mov), win);
}
int main()
{
	int b[9]; 
	initar(b);
	system("clear");
	twoplr(b);
	return 0;
}
