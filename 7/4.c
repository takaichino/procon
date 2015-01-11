#include<stdio.h>

int main()
{
	double  x1, y1, x2, y2, x3, y3, xp, yp;
	double d1, d2, d3, xa, xb, xc, ya, yb, yc;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp)!=EOF)
	{
		xa = x1 - xp;
		xb = x2 - xp;
		xc = x3 - xp;
		ya = y1 - yp;
		yb = y2 - yp;
		yc = y3 - yp;
		d1 = xa * yb - ya * xb;
		d2 = xb * yc - yb * xc;
		d3 = xc * ya - yc * xa;
		if(d1 * d2 > 0 && d3 * d2 > 0 && d1 * d3 > 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}