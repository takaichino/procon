#include <stdio.h>

int main(){
  int a[3];
  int x, i;
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  x = a[0];
  for(i=1; i<3; i++)
    {
      if(x > a[i])
	{
	  a[0] = a[i];
	  a[i] = x;
	  x = a[0];
	}
    }
  if(a[1] > a[2])
    {
      x = a[1];
      a[1] = a[2];
      a[2] = x;
    }
  printf("%d %d %d\n", a[0], a[1], a[2]);
  return 0;
}
