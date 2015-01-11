#include<stdio.h>

int main()
{
  int c1, c2, c3, m4=4;
  while(scanf("%d %d %d", &c1, &c2, &c3) != EOF)
    {
      if(c1 <= m4) m4++;
      if(c2 <= m4) m4++;
      if(c3 <= m4) m4++;
      if(c1 + c2 + m4 <= 20) printf("YES\n");
      else printf("NO\n");
      m4 = 4;
    }
  return 0;
}
