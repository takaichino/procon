#include<stdio.h>
#include<math.h>

int main(){
	int a[21][7], L;
	int p, s, t, now=0, zan, j, flag=0;
	scanf("%d %d", &a[0][6], &L);
	while(L!=0)
	{
		for(now=0;now<21 && flag==0;now++)
		{
			for(p=0;p<L;p++)
			{
				a[now][p] = (int)(a[now][6] / pow(10, p)) % 10;
			}
			for(s=L;s>1;s--)
			{
				for(t=0;t<s-1;t++)
				{
					zan = a[now][t];
					if(zan > a[now][t+1])
					{
						a[now][t] = a[now][t+1];
						a[now][t+1] = zan;
					}
				}
			}
			a[now+1][6] = 0;
			for(p=0;p<L;p++)
			{
				a[now+1][6] -= a[now][L-p-1] * pow(10, p);
				a[now+1][6] += a[now][p] * pow(10, p);
			}
			for(j=0;j<now+1;j++)
			{
				if(a[j][6] == a[now+1][6])
				{
					printf("%d %d %d\n", j, a[now+1][6] , now +1 -j);
					flag++;
					break;
				}
			}
		}
		flag=0;
		scanf("%d %d", &a[0][6], &L);
	}
	return 0;
}