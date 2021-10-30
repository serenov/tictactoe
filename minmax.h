int dwckr(int b[])
{
	for(int i = 0; i < 9; i++)
	{
		if(b[i] == 0)
			return 0;
	}
	return 1;
}
int minimax(int b[], int turn, int depth
{
	if(winchecker() == 1)
		return -1*turn;
	else if(dwckr(b) == 1)
		return 0;
	int i = 1, r = 0, rtemp, mov;
	for(;i < 10; i++)
	{
		if(b[i] == 0)
		{
			b[i] = turn;
			rtemp = minimax(b, -1*turn)
			if((turn * rtemp) > (turn * r))
			{
				r = rtemp;
				if(depth == 0)
					mov = i;
			}
			b[i] = 0;
		}
	}
	if(depth != 0)
		return r;
	return i;
}
