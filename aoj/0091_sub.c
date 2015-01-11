#include<stdio.h>

int correct(int nx[10][10])
{
  int x, y;
  for(x=0; x<10; x++)
    {
      for(y=0; y<10; y++)
	{
	  if(nx[x][y]>0 && nx[x][y] != 4)
	    {
	      if(nx[x][y-1] < 3 && nx[x-1][y] < 3 && nx[x+1][y] < 3 && nx[x][y+1] < 3) return 0;
	    }
	}
    }
  return 1;
}

int main()
{
  int n;
  int in[10][10];
  int kr[10][10], krnx[10][10] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
  int nx[10][10] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
  int x, y, i=0;
  int xg, yg, zg;
  scanf("%d", &n);
  int ans[3][n], zantei = 0;
  ans[0][0]=0;
  ans[1][0]=0;
  ans[2][0]=3;

  for(y=0; y<10; y++)
    {
      scanf("%d %d %d %d %d %d %d %d %d %d", &in[0][y], &in[1][y], &in[2][y], &in[3][y], &in[4][y], &in[5][y], &in[6][y], &in[7][y], &in[8][y], &in[9][y]);
    }
  //input完了

  for(x=0; x<10; x++)
    {
      for(y=0; y<10; y++)
        {
	  kr[x][y] = in[x][y];
	}
    }

  //next_to
  for(x=0; x<10; x++)
    {
      for(y=0; y<10; y++)
        {
	  if(in[x][y]>0)
	    {
	      if(y>0 && in[x][y-1]>0) nx[x][y]++;
	      if(x>0 && in[x-1][y]>0) nx[x][y]++;
	      if(x<9 && in[x+1][y]>0) nx[x][y]++;
	      if(y<9 && in[x][y+1]>0) nx[x][y]++;
	    }
        }
    }
  //next_to

  for(xg=0; xg<10; xg++)
    {
      for(yg=0; yg<10; yg++)
        {
	  for(zg=3;zg>0;zg--)
	    {
	      if(nx[xg][yg] == 4)
		{
		  if(zg==3)
		    {
		      if(nx[xg][yg-1]==4 && nx[xg-1][yg]==4 && nx[xg+1][yg]==4 && nx[xg][yg+1]==4)
			{
			  kr[xg][yg-2] = kr[xg][yg-2] -1;
			  kr[xg-1][yg-1] = kr[xg-1][yg-1] -1;
			  kr[xg][yg-1] = kr[xg][yg-1] -1;
			  kr[xg+1][yg-1] = kr[xg+1][yg-1] -1;
			  kr[xg-2][yg] = kr[xg-2][yg] -1;
			  kr[xg-1][yg] = kr[xg-1][yg] -1;
			  kr[xg][yg] = kr[xg][yg] -1;
			  kr[xg+1][yg] = kr[xg+1][yg] -1;
			  kr[xg+2][yg] = kr[xg+2][yg] -1;
			  kr[xg-1][yg+1] = kr[xg-1][yg+1] -1;
			  kr[xg][yg+1] = kr[xg][yg+1] -1;
			  kr[xg+1][yg+1] = kr[xg+1][yg+1] -1;
			  kr[xg][yg+2] = kr[xg][yg+2] -1;
			  
			  for(x=0; x<10; x++)
			    {
			      for(y=0; y<10; y++)
				{
				  krnx[x][y]=0;
				  if(kr[x][y]>0)
				    {
				      if(y>0 && kr[x][y-1]>0) krnx[x][y]++;
				      if(x>0 && kr[x-1][y]>0) krnx[x][y]++;
				      if(x<9 && kr[x+1][y]>0) krnx[x][y]++;
				      if(y<9 && kr[x][y+1]>0) krnx[x][y]++;
				    }
				}
			    }
			  if(correct(krnx)==1)
			    {
			      ans[0][zantei] = xg;
			      ans[1][zantei] = yg;
			      ans[2][zantei] = zg;
			      zantei++;
			      for(x=0; x<10; x++)
				{
				  for(y=0; y<10; y++)
				    {
				      in[x][y] = kr[x][y];
				      nx[x][y] = krnx[x][y];
				    }
				}
			    }
			  else
			    {
			      for(x=0; x<10; x++)
				{
				  for(y=0; y<10; y++)
				    {
				      kr[x][y] = in[x][y];
				      krnx[x][y] = nx[x][y];
				    }
				}
			    }
			}
		    }
		  
		  if(zg==2)
		    {
		      if(nx[xg][yg-1]>=3 && nx[xg-1][yg]>=3 && nx[xg+1][yg]>=3 && nx[xg][yg+1]>=3)
			{
			  kr[xg-1][yg-1] = kr[xg-1][yg-1] -1;
			  kr[xg][yg-1] = kr[xg][yg-1] -1;
			  kr[xg+1][yg-1] = kr[xg+1][yg-1] -1;
			  kr[xg-1][yg] = kr[xg-1][yg] -1;
			  kr[xg][yg] = kr[xg][yg] -1;
			  kr[xg+1][yg] = kr[xg+1][yg] -1;
			  kr[xg-1][yg+1] = kr[xg-1][yg+1] -1;
			  kr[xg][yg+1] = kr[xg][yg+1] -1;
			  kr[xg+1][yg+1] = kr[xg+1][yg+1] -1;
			  
			  for(x=0; x<10; x++)
			    {
			      for(y=0; y<10; y++)
				{
				  krnx[x][y]=0;
				  if(kr[x][y]>0)
				    {
				      if(y>0 && kr[x][y-1]>0) krnx[x][y]++;
				      if(x>0 && kr[x-1][y]>0) krnx[x][y]++;
				      if(x<9 && kr[x+1][y]>0) krnx[x][y]++;
				      if(y<9 && kr[x][y+1]>0) krnx[x][y]++;
				    }
				}
			    }
			  if(correct(krnx)==1)
			    {
			      ans[0][zantei] = xg;
			      ans[1][zantei] = yg;
			      ans[2][zantei] = zg;
			      zantei++;
			      for(x=0; x<10; x++)
                                {
                                  for(y=0; y<10; y++)
                                    {
                                      in[x][y] = kr[x][y];
                                      nx[x][y] = krnx[x][y];
                                    }
                                }
			    }
			  else
			    {
			      for(x=0; x<10; x++)
				{
				  for(y=0; y<10; y++)
				    {
				      kr[x][y] = in[x][y];
				      krnx[x][y] = nx[x][y];
				    }
				}
			    }
			}
		    }
		  if(zg==1)
		    {
		      kr[xg][yg-1] = kr[xg][yg-1] -1;
		      kr[xg-1][yg] = kr[xg-1][yg] -1;
		      kr[xg][yg] = kr[xg][yg] -1;
		      kr[xg+1][yg] = kr[xg+1][yg] -1;
		      kr[xg][yg+1] = kr[xg][yg+1] -1;
		      
		      for(x=0; x<10; x++)
			{
			  for(y=0; y<10; y++)
			    {
			      krnx[x][y]=0;
			      if(kr[x][y]>0)
				{
				  krnx[x][y]=0;
				  if(y>0 && kr[x][y-1]>0) krnx[x][y]++;
				  if(x>0 && kr[x-1][y]>0) krnx[x][y]++;
				  if(x<9 && kr[x+1][y]>0) krnx[x][y]++;
				  if(y<9 && kr[x][y+1]>0) krnx[x][y]++;
				}
			    }
			}
		      if(correct(krnx)==1)
			{
			  ans[0][zantei] = xg;
			  ans[1][zantei] = yg;
			  ans[2][zantei] = zg;
			  zantei++;
			  for(x=0; x<10; x++)
			    {
			      for(y=0; y<10; y++)
				{
				  in[x][y] = kr[x][y];
				  nx[x][y] = krnx[x][y];
				}
			    }
			}
		      else
			{
			  for(x=0; x<10; x++)
			    {
			      for(y=0; y<10; y++)
				{
				  kr[x][y] = in[x][y];
				  krnx[x][y] = nx[x][y];
				}
			    }
			}
		    }
		}
	    }
	}
    }

  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n",ans[0][i], ans[1][i], ans[2][i]);
    }
  return 0;
}
