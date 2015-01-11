#include<stdio.h>
#include<math.h>

int main(){
	unsigned int n, he[200002], i, ch[200000], now=0, ans=0, k;
	scanf("%d", &n);
	he[0]=0;
	for(i=1;i<=n;i++)
	{
		if(i<n) scanf("%d ", &he[i]);
		else scanf("%d", &he[i]);
		if(he[i] > he[i-1])
		{
			ans++;
			ch[now] = he[i];
			now++;
		}
		if(he[i] < he[i-1])
		{
			ch[now] = he[i];
			for(k=0;k<now;k++)
			{
				if(ch[k] > ch[now])
				{
					ch[k] = ch[now];
					now = k + 1;
					ans++;
					break;
				}
				if(ch[k] == ch[now])
				{
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}