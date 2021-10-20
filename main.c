#include<stdio.h>
void printboard(int b[9])
{
	
	printf(" ____ ____ ____ \n");
	printf("                \n");
	printf("| %c | %c | %c |\n", decode(b[0]), decode(b[1]), decode(b[2]));
	printf(" ____ ____ ____ \n");
	printf("                \n");
	printf("| %c | %c | %c |\n", decode(b[3]), decode(b[4]), decode(b[5]));
	printf(" ____ ____ ____ \n");
	printf("                \n");
	printf("| %c | %c | %c |\n", decode(b[6]), decode(b[7]), decode(b[8]));
	printf(" ____ ____ ____ \n");

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
void movmkr(int pos, int mno, int b[9])
{
	b[pos] = td(mno);
}
void legalmv(int pos )
int main()
{
	return 0;
}
