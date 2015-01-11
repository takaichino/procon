#include <stdio.h>

int main()
{
  int t[10] ,x , n=0;
  while(scanf("%d", &x) != EOF)
    {
      if(x != 0)
	{
	  t[n] = x;
	  n++;
	}
      else 
	{
	  printf("%d\n", t[n-1]);
	  n--;
	}
    }
  return 0;
}
