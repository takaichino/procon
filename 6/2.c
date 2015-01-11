#include<stdio.h>

int main(){
  int N, a, b, t;
  int lis[21][20], ans=0;
  int i, j, k, l, now, go, need=0, end=0;
  scanf("%d", &N);
  while(N!= 0)
    {
      for(i=0;i<21;i++)
	{
	  for(j=0;j<20;j++)
	    {
	      if(i==j) lis[i][j]=501;
	      else lis[i][j]=0;
	    }
	}
      for(k=0;k<N-1;k++)
	{
	  scanf("%d %d %d",&a,&b,&t);
	  lis[a-1][b-1]=t;
	  lis[b-1][a-1]=t;
	  lis[20][a-1]++;
	  lis[20][b-1]++;
	}
      now = 0;
      while(end == 0)
	{
	  go =now;
	  for(l=0;l<N;l++)
	    {
	      if(lis[l][now]>0 && lis[l][now]<501)
		{
		  if(lis[20][l]>=2)
		    {
		      need++;
		      if(lis[now][go] > lis[now][l])
			{
			  go = l;
			}
		    }
		}
	    }
	  if(need == 1) lis[20][now]=1;
	  if(need == 0)
	    {
	      end = 1;
	      break;
	    }
	  need = 0;
	  ans = ans + lis[now][go];
	  now = go;
	}
      printf("%d\n", ans);
      scanf("%d", &N);
      ans = 0;
      end = 0;
    }
  return 0;
}
