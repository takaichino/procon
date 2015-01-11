#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, m, a, i, j, now=0, ans=0;
	int s[100000];
	scanf("%d %d", &n, &m);
	s[0] = 0;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d", &s[i]);
		s[i] += s[i-1];
		/*
		printf("%d ", s[i]);
		*/
	}
	for(j=0;j<m;j++)
	{
		scanf("%d", &a);
		if(a>0) ans += (s[now+a] - s[now]) % 100000;
		else ans += (s[now] - s[now+a]) % 100000;
		if(ans>100000) ans = ans % 100000;
		/*
		printf("%d ", s[now+a] - s[now]);
		*/
		now += a;
	}
	printf("%d\n", ans);
	return 0;
}