#include<stdio.h>
#include<stdlib.h>
char decode(int n);
int legalmv(int pos, int b[9]);
void printboard(int b[9])
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
int movmkr(int pos, int mno, int b[9])
{
	if(legalmv(pos, b)){
		b[pos] = td(mno);
		return 1;
	}
	printf("Invalid input.\n");
	return 0;
}
int legalmv(int pos, int b[9])
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
void initar(int b[9])
{
	for(int i = 0; i < 9; i++)
		b[i] = 0;
}
int dgt(char a[8])
{
	if(a[0] > 48 && a[0] < 58)
	{
		if(a[1] == '\0')
			return (a[0] - 48);
	}
	return 10;
}
int checker(int b[], int p, int s, int lim)
{
	if(s + p > lim)
		return b[s - 1]; 
	int t = checker(b, p, s + p, lim);
	if(t == b[s - 1])
		return b[s - 1]; 
	return 0;
}
int winchecker(int b[])
{
	return checker(b, 1, 1, 3)||checker(b, 1, 4, 6)||checker(b, 1, 7, 9)||checker(b, 4, 1, 9)||checker(b, 2, 3, 7)||checker(b, 3, 1, 9)||checker(b, 3, 2, 9)||checker(b, 3, 3, 9);
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
int main()
{
	int b[9]; 
	char plrin[8];
	initar(b);
	int win = 0, mov;
	system("clear");
	for(mov = 1; mov < 10; mov++)
	{
		printboard(b);
		printf("It's player %c's turn, choose a position b/t 1-9: ", decode(td(mov)));
		scanf("%s", plrin);
		system("clear");
		if(movmkr(dgt(plrin) - 1, mov, b) == 0)
			mov--;
		win = winchecker(b);
		if(win != 0)
			break;
	}
	terminal(b, td(mov), win);
	return 0;
}
