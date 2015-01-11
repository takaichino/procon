#include <stdio.h>

int main()
{
  int x, i=1;
  scanf("%d", &x);
  while(x != 0)
    {
      printf("Case %d: %d\n", i, x);
      i++;
      scanf("%d", &x);
    }
  return 0;
}
