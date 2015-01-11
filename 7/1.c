#include<stdio.h>

int main()
{
	int n, a, b, c, i;
	int d1, d2, d3;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		d1 = a*a + b*b - c*c;
		d2 = a*a + c*c - b*b;
		d3 = c*c + b*b - a*a;
		if(d1 * d2 * d3 ==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}