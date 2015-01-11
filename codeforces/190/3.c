#include<stdio.h>
#include<string.h>

int main(){
	double a, b, wx, wy;
	int i, j, ans=0, k;
	char s[101];
	double wa[101][2];
	scanf("%lf %lf", &a, &b);
	scanf("%s", s);
	wa[0][0] = 0;
	wa[0][1] = 0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='U')
		{
			wa[i+1][0]=wa[i][0];
			wa[i+1][1]=wa[i][1]+1;
			wa[i][0] = a - wa[i][0];
			wa[i][1] = b - wa[i][1];
		}
		if(s[i]=='D')
		{
			wa[i+1][0]=wa[i][0];
			wa[i+1][1]=wa[i][1]-1;
			wa[i][0] = a - wa[i][0];
			wa[i][1] = b - wa[i][1];
		}
		if(s[i]=='L')
		{
			wa[i+1][0]=wa[i][0]-1;
			wa[i+1][1]=wa[i][1];
			wa[i][0] = a - wa[i][0];
			wa[i][1] = b - wa[i][1];
		}
		if(s[i]=='R')
		{
			wa[i+1][0]=wa[i][0]+1;
			wa[i+1][1]=wa[i][1];
			wa[i][0] = a - wa[i][0];
			wa[i][1] = b - wa[i][1];
		}
	}
	wx = wa[strlen(s)][0];
	wy = wa[strlen(s)][1];
	if(a == 0 && b == 0)
	{
		ans++;
	}
	if(wx != 0 && wy != 0)
	{
		for(j=0;j<strlen(s);j++)
		{
			k = wa[j][0] / wx;
			if(wa[j][0] / wx == wa[j][1] / wy && wa[j][1] / wy >= 0 && wa[j][0] / wx == k)
			{
				ans++;
			}
		}
	}
	if(wx == 0 && wy != 0)
	{
		for(j=0;j<strlen(s);j++)
		{
			k = wa[j][1] / wy;
			if(wa[j][0] == 0 && wa[j][1] / wy == k && k > 0)
			{
				ans++;
			}
		}
	}
	if(wx != 0 && wy == 0)
	{
		for(j=0;j<strlen(s);j++)
		{
			k = wa[j][0] / wx;
			if(wa[j][1] == 0 && wa[j][0] / wx == k && k > 0)
			{
				ans++;
			}
		}
	}
	if(wx == 0 && wy == 0)
	{
		for(j=0;j<strlen(s);j++)
		{
			if(wa[j][0] == 0 && wa[j][1] == 0)
			{
				ans++;
			}
		}
	}
	if(ans>0) printf("Yes\n");
	else printf("No\n");
	return 0;
}
