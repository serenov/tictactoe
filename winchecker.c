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
