#include<stdio.h>
#include<string.h>

int main()
{
	int n, m, k;//n個,m面ダイス
	char dic[256][10002];//10000:合計,10001:組み合わせ数
	int head=0, tail=1;
	int r, hoten = 0;
	double ans=0;
	scanf("%d %d %d", &n, &m, &k);
	while(n != 0)
	{
		memset(dic, 0, sizeof(dic));
		dic[0][0]=dic[0][10000]=n;
		dic[0][10001]=1;
		while(dic[head][10000]<k)
		{
			hoten += (k - dic[head][10000]) * dic[head][10001];
			for(r=0;r<m-1;r++)
			{
				dic[tail][r]=dic[head][r] - 1;
				dic[tail][r+1]=dic[head][r] + 1;
				dic[tail][10000]=dic[head][10000] + 1;
				dic[tail][10001]=dic[head][10001] * dic[head][r];
				if(head==255) head=0;
				else head++;
				if(tail==255) tail=0;
				else tail++;
			}
		}
		ans=hoten;
		ans = ans / (m ^ n);
		ans = ans + (m+1) * n / 2 - k;
		printf("%.8f\n", ans);
		hoten = 0;
		ans=0;
		head=0;
		tail=1;
		scanf("%d %d %d", &n, &m, &k);
	}
	return 0;
}
