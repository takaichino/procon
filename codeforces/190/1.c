#include<stdio.h>

int main(){
	int m, n, i, j=1;
	scanf("%d %d", &m, &n);
	printf("%d\n", m+n-1);
	for(i=1;i<=m;i++)
	{
		for(;;)
		{
			printf("%d %d\n", i, j);
			if(j<n) j++;
			else break;
		}
	}
	return 0;
}