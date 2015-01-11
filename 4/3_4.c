#include<stdio.h>
#include<string.h>

int main()
{
	int now=0, wri=1, sta[65536][5], X, Y, tx, ty, kx, ky, in[52][52];
	static char ch[51][51][51][51];
	int i, j, k, dtx, dty, dkx, dky;
	scanf("%d %d", &X, &Y);
	while(X!=0 && Y!=0)
	{
		scanf("%d %d", &tx, &ty);
		scanf("%d %d", &kx, &ky);
		for(i=0;i<=Y+1;i++)
		{
			for(j=0;j<=X+1;j++)
			{
				if(i==0 || i==Y+1 || j==0 || j==X+1) in[i][j]=1;
				else scanf("%d", &in[i][j]);
			}
		}
		sta[0][0] = ty;
		sta[0][1] = tx;
		sta[0][2] = ky;
		sta[0][3] = kx;
		sta[0][4] = 0;
		ch[ty][tx][ky][kx] = '1';
		
		while(1)
		{
			ty = sta[now][0];
			tx = sta[now][1];
			ky = sta[now][2];
			kx = sta[now][3];

			if(sta[now][4]>100 || now == wri)
			{
				printf("NA\n");
				break;
			}
			
			if(ty == ky && tx == kx)
				{
					printf("%d\n", sta[now][4]);
					break;
				}
			
			for(k=0;k<4;k++)
			{
				dty = 0;
				dtx = 0;
				dky = 0;
				dkx = 0;
				
				if(k==0)
				{
					if(in[ty-1][tx] == 0) dty = -1;
					if(in[ky+1][kx] == 0) dky = 1;
				}
				if(k==1)
				{
					if(in[ty+1][tx] == 0) dty = 1;
					if(in[ky-1][kx] == 0) dky = -1;
				}
				if(k==2)
				{
					if(in[ty][tx-1] == 0) dtx = -1;
					if(in[ky][kx+1] == 0) dkx = 1;
				}
				if(k==3)
				{
					if(in[ty][tx+1] == 0) dtx = 1;
					if(in[ky][kx-1] == 0) dkx = -1;
				}
				if(ch[ty + dty][tx + dtx][ky+dky][kx+dkx] != '1')
				{
					ch[ty + dty][tx + dtx][ky+dky][kx+dkx] = '1';
					sta[wri][0] = ty + dty;
					sta[wri][1] = tx + dtx;
					sta[wri][2] = ky + dky;
					sta[wri][3] = kx + dkx;
					sta[wri][4] = sta[now][4] + 1;
					if(wri==65535) wri=0;
					else wri++;
				}
			}
			if(now==65535) now=0;
			else now++;
		}
		now=0;
		wri=1;
		memset(ch, '0', sizeof(ch));
		scanf("%d %d", &X, &Y);
	}
	return 0;
}
