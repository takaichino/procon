#include<stdio.h>
#include<math.h>

int main(){
	unsigned int n, he[200002], i, ch[200000] = {0}, now=0, ans=0, k;
	scanf("%d", &n);
	he[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d", &he[i]);
		if(he[i] > he[i-1])
		{
			ans++;
			ch[now] = he[i];
			now++;
		}
		else if(he[i] < he[i-1])
		{
			ch[now] = he[i];
			for(k=now-1;k>=0;k--)
			{
				if(ch[k] > he[i])
				{
					ch[k] = he[i];
					now = k + 1;
				}
				else if(ch[k] == he[i])
				{
					now = k + 1;
					break;
				}
				else if(ch[k] < he[i])
				{
					ans++;
					now = k + 2;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}