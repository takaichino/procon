#include<stdio.h>

int main(){
	char in[12][13];
	int st[144][2], ch[12][12]={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	int inn, i, j, x, y, p, q, now=0, ans=0;
	char end[1]="0";
	//“ü—Í
	for(inn=0;inn<12;inn++)
	{
		gets(in[inn]);
	}
	st[0][0]=13;
	
	while(1)
	{
		//debug
		//for(p=0;p<12;p++) printf("input = %s\n", in[p]);
		//debug
		for(i=0;i<12;i++)
		{
			for(j=0;j<12;j++)
			{
				x = i;
				y = j;
				if(in[x][y]=='1' && ch[x][y]==0)
				{
					st[now][0]=x;
					st[now][1]=y;
					now++;
					ans++;
					ch[x][y]=1;
				}
				while(st[0][0]!=13)
				{
					x=st[now-1][0];
					y=st[now-1][1];
					if(x>0 && in[x-1][y]=='1' && ch[x-1][y]==0) 
					{
						st[now][0]=x-1;
						st[now][1]=y;
						now++;
						ch[x-1][y]=1;
					}
					else if(x<11 && in[x+1][y]=='1' && ch[x+1][y]==0) 
					{
						st[now][0]=x+1;
						st[now][1]=y;
						now++;
						ch[x+1][y]=1;
					}
					else if(y>0 && in[x][y-1]=='1' && ch[x][y-1]==0) 
					{
						st[now][0]=x;
						st[now][1]=y-1;
						now++;
						ch[x][y-1]=1;
					}
					else if(y<11 && in[x][y+1]=='1' && ch[x][y+1]==0) 
					{
						st[now][0]=x;
						st[now][1]=y+1;
						now++;
						ch[x][y+1]=1;
					}
					else
					{
						st[now-1][0]=13;
						now--;
					}
				}
			}
		}
		printf("%d\n", ans);
		now=0;
		ans=0;
		for(p=0;p<12;p++)
		{
			for(q=0;q<12;q++)
			{
				ch[p][q] = 0;
			}
		}
		
		if(gets(end)==NULL)break;
		for(inn=0;inn<12;inn++)
		{
			gets(in[inn]);
		}
		st[0][0]=13;
	}
	return 0;
}