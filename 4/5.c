#include<stdio.h>

int combi(int x, int y)
{
	int z, atai = 1;
	for(z=y;z>=1;z--)
	{
		atai = atai * (x-z+1);
	}
	for(z=y;z>=1;z--)
	{
		atai = atai / z;
	}
	return atai;
}

int main()
{
	int n, m, k;//n個,m面ダイス
	int i, j, hoten = 0;
	double ans=0;
	scanf("%d %d %d", &n, &m, &k);
	while(n != 0)
	{
		if(n<k)
		{
			for(i=n;i<=k;i++)
			{
				hoten = hoten + (k-i+1) * combi(i-1, n-1);
			}
		}
		ans = hoten;
		for(j=0;j<n;j++)
		{
			ans = ans / m;
		}
		ans = ans + (m+1) * n / 2 - k;
		printf("%.8f\n", ans);
		hoten = 0;
		ans=0;
		scanf("%d %d %d", &n, &m, &k);
	}
	return 0;
}
