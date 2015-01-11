#include <stdio.h>
#include <math.h>

double round(double cl)
{
  double re;
  re = cl * pow(10, 3);
  if (cl >= 0)
    {
      re = (double)(int)(re + 0.5);
    }
  else
    {
      re = (double)(int)(re - 0.5);
    }
  return re * pow(10, -3);
}

int main()
{
  double a, b, c, d, e, f;
  double x, y;
  while(scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f)!= EOF)
    {
      y = (c * d - f * a) / ( b * d - e * a );
      x = (c * e - f * b) / ( a * e - d * b );
      y = round(y);
      x = round(x);
      printf("%5.3lf %5.3lf\n", x, y);
    }
  return 0;
}
      
