#include<stdio.h>

int main()
{
	int n, ans=1, i;
	while(scanf("%d", &n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			ans += i;
		}
		printf("%d\n", ans);
		ans= 1;
	}
	return 0;
}
