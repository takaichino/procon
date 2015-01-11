#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int x[32], k, ans=0;
  while(n != 0)
    {
      x[0] = 1, x[1] = 1;
      for(k=1;k<=n;k++)
	{
	  if(k==2) x[k] = 2;
	  if(k>=3) x[k] = x[k-1] + x[k-2] + x[k-3];
	}
      ans = x[n] / 3650;
      if(x[n] % 3650  > 0) ans++; 
      printf("%d\n", ans);
      scanf("%d", &n);
    }
  return 0;
}
