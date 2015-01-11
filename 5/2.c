#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, k, i, j, s[100000],max=-99999;
	scanf("%d %d", &n, &k);
	while(n!=0)
	{
		s[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d", &s[i]);
			s[i] += s[i-1];
		}
		for(j=k;j<=n;j++)
		{
			if(max < s[j] - s[j-k]) max = s[j] - s[j-k];
		}
		printf("%d\n", max);
		scanf("%d %d", &n, &k);
	}
	return 0;
}