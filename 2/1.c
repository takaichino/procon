#include <stdio.h>

int main()
{
  int i, s=0, ans=0;
  for(i=0;i<10;i++)
    {
      scanf("%d", &s);
      ans = ans + s;
   }
  printf("%d\n", ans);
  return 0;
}
