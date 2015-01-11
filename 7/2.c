#include<stdio.h>

int main()
{
	double  x1, y1, x2, y2, x3, y3, x4, y4;
	int n, i;
	double d1, d2;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		if(y1 == y2 && y3 == y4) 
		{
			printf("YES\n");
		}
		else
		{
			d1 = (x1 - x2) / (y1 - y2);
			d2 = (x3 - x4) / (y3 - y4);
			if(d1 == d2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}