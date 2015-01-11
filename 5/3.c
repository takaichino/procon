#include<stdio.h>
#include<stdlib.h>

int main(){
	int c, n, m, s, d, fee[500][3], ch[100], su, st[65536][14];
	int i, j, k, p, head, tail, ans=99999;
	scanf("%d %d %d %d %d", &c, &n, &m, &s, &d);
	while(n!=0)
	{
		//init
		su = 1;
		head =0;
		tail =1;
		st[0] = {s, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for(p=0;p<100;p++)
		{
			ch[p]=0;
		}
		//init
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d", &fee[i][0], &fee[i][1], &fee[i][2]);
		}
		while(su <= n)
		{
			for(i=0;i<m;i++)
			{
				if(fee[i][0] == st[head][0]) st[tail][0] = fee[i][1];
				if(fee[i][1] == st[head][0]) st[tail][0] = fee[i][0];
				if(fee[i][0] == st[head][0] || fee[i][1] == st[head][0])
				{
					st[tail][1] = st[head][1] + 1;
					st[tail][2] = st[head][2] + fee[i][2];
					for(j=0;j<10;j++)
					{
						if(fee[i][2]>st[head][4+j])
						{
							st[tail][3+j] = st[head][4+j];
						}
						else
						{
							st[tail][4+j] = fee[i][2];
							break;
						}
					}
					tail++;
				}
			}
			head++;
			su++;
			
		}
	return 0;
}