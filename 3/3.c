#include <stdio.h>

int main(){
  int n, s, ans = 0, min=0, k;

  int back(int x, int z, int max);

  scanf("%d %d", &n, &s);
  while(n != 0 || s != 0)
    {
      for(k=0; k<n; k++) min = min + k;
      if(s < min) printf("0\n");
      else
	{
	  ans = back(n, s - min, n-1);
	  printf("%d\n", ans);
	}
      ans = 0;
      min = 0;
      scanf("%d %d", &n, &s);
    }
  return 0;
}

int back(int x, int z, int max){
  int kaeri=0, l;
  if(max > 9) return 0;
  if(z < 0) return 0;
  if(z == 0) return 1;
  for(l=1; l<=x; l++)
    {
      kaeri = kaeri + back(l, z-l, max+1);
    }
  return kaeri;
}

