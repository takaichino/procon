#include<stdio.h>

int main(){
	int m, n, i, j;
	while(scanf("%d %d", &m, &n)!=EOF)
	{
		printf("%d\n", m+n-1);
		if(m>=2)
		{
			for(j=1;j<=m;j++)
			{
				printf("1 %d\n",j);
			}
			if(n>=2)
			{
				for(i=2;i<=n;i++)
				{
					printf("%d 2\n", i);
				}
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				printf("%d 1\n", i);
			}
		}
	}
	return 0;
}