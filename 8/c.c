#include<stdio.h>
#include<math.h>

int main(){
	int hei[29][29], top[29][29], cnt[6];
	int j, k, l, m, ro[2], nx[2], nowx, nowy, stop;
	int n, t, f;
	int hoko[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	scanf("%d", &n);
	while(n != 0)
	{
		//init
		for(j=0;j<29;j++)
		{
			for(k=0;k<29;k++)
			{
				hei[j][k]=0;
				top[j][k]=0;
			}
		}
		for(l=0;l<6;l++)
		{
			cnt[l]=0;
		}
		//init
		for(m=0;m<n;m++)
		{
			nowx=14;
			nowy=14;
			stop=0;
			scanf("%d %d", &t, &f);
			while(stop==0)
			{
				if(t==1)
				{
					nx[0]=2;
					nx[1]=3;
					if(f==2)
					{
						ro[0]=2;
						ro[1]=3;
					}
					if(f==3)
					{
						ro[0]=1;
						ro[1]=2;
					}
					if(f==4)
					{
						ro[0]=3;
						ro[1]=0;
					}
					if(f==5)
					{
						ro[0]=0;
						ro[1]=1;
					}
				}
				if(t==2)
				{
					nx[0]=1;
					nx[1]=3;
					if(f==1)
					{
						ro[0]=2;
						ro[1]=1;
				}
					if(f==3)
					{
						ro[0]=3;
						ro[1]=2;
					}
					if(f==4)
					{
						ro[0]=1;
						ro[1]=0;
					}
					if(f==6)
					{
						ro[0]=0;
						ro[1]=3;
					}
				}
				if(t==3)
				{
					nx[0]=1;
					nx[1]=2;
					if(f==1)
					{
						ro[0]=2;
						ro[1]=3;
					}
					if(f==5)
					{
						ro[0]=3;
						ro[1]=0;
					}
					if(f==2)
					{
						ro[0]=1;
						ro[1]=2;
					}
					if(f==6)
					{
						ro[0]=0;
						ro[1]=1;
					}
				}
				if(t==4)
				{
					nx[0]=1;
					nx[1]=2;
					if(f==1)
					{
						ro[0]=2;
						ro[1]=1;
					}
					if(f==2)
					{
						ro[0]=3;
						ro[1]=2;
					}
					if(f==5)
					{
						ro[0]=1;
						ro[1]=0;
					}
					if(f==6)
					{
						ro[0]=0;
						ro[1]=3;
					}
				}
				if(t==5)
				{
					nx[0]=1;
					nx[1]=3;
					if(f==1)
					{
						ro[0]=2;
						ro[1]=3;
					}
					if(f==4)
					{
						ro[0]=3;
						ro[1]=0;
					}
					if(f==3)
					{
						ro[0]=1;
					ro[1]=2;
					}
					if(f==6)
					{
						ro[0]=0;
						ro[1]=1;
					}
				}
				if(t==6)
				{
					nx[0]=2;
					nx[1]=3;
					if(f==2)
					{
						ro[0]=2;
						ro[1]=1;
					}
					if(f==3)
					{
						ro[0]=3;
						ro[1]=2;
					}
					if(f==4)
					{
						ro[0]=1;
						ro[1]=0;
					}
					if(f==5)
					{
						ro[0]=0;
						ro[1]=3;
					}
				}
				if(hei[nowx][nowy]>hei[nowx+hoko[ro[0]][0]][nowy+hoko[ro[0]][1]])
				{
					nowx += hoko[ro[0]][0];
					nowy += hoko[ro[0]][1];
					if(ro[0]==2) f = 7 - t;
					if(ro[0]==0) f = t;
					t = nx[0];
				}
				else if(hei[nowx][nowy]>hei[nowx+hoko[ro[1]][0]][nowy+hoko[ro[1]][1]])
				{
					nowx += hoko[ro[1]][0];
					nowy += hoko[ro[1]][1];
					if(ro[1]==2) f = 7 - t;
					if(ro[1]==0) f = t;
					t = nx[1];
				}
				else
				{
					if(cnt[top[nowx][nowy]-1]>0) cnt[top[nowx][nowy]-1]--;
					top[nowx][nowy] = t;
					cnt[t-1]++;
					hei[nowx][nowy]++;
					stop++;
				}
			}
		}
		printf("%d %d %d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
		scanf("%d", &n);
	}
	return 0;
}