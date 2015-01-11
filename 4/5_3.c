#include<stdio.h>
#include<string.h>

int main()
{
	int n, m, k,s;//n個,m面ダイス
	int max;
	int p, r, i, j, t;
	double ans=0;
	scanf("%d %d %d", &n, &m, &k);
	while(n != 0)
	{
		s= m * n;
		double dic[2][s+1];//0-10000:合計がその値になる確率
		for(i=0;i<s+1;i++)
		{
			dic[1][i]=0;
			dic[0][i]=0;
		}
		dic[0][0]=1.0;
		max=0;
		for(j=0;j<n;j++)
		{
			for(p=0;p<=max+m;p++)
			{
				if(dic[0][p]>0)
				{
					for(r=1;r<=m;r++)
					{
						dic[1][p+r] += dic[0][p] * 1.0 / m;
					}
				}
				dic[0][p]=dic[1][p];
				dic[1][p]=0;
			}
			max += m;
		}
		for(t=0;t<=s;t++)
		{
			if(t<=k) ans += dic[0][t];
			else ans += (t-k) * dic[0][t];
		}
		printf("%.8f\n", ans);
		ans=0;
		scanf("%d %d %d", &n, &m, &k);
	}
	return 0;
}
