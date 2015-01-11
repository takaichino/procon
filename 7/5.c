#include<stdio.h>
#include<math.h>

double kyori(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
}

int main(){
	int n, i, p, q, k=0;
	double a, b, c, sita, alpha;
	double in[100][3], rad[100][2], ans=0;
	scanf("%d", &n);
	while(n>0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf %lf", &in[i][0], &in[i][1], &in[i][2]);
			ans += M_PI * in[i][2] * 2;
		}
		for(p=0;p<n;p++)
		{
			for(q=0;q<n;q++)
			{
				a = in[p][2];
				b = in[q][2];
				c = kyori(in[p][0],in[p][1],in[q][0],in[q][1]);
				if(c < a + b && p != q)
				{
					sita = acos((a * a + c * c - b * b) / (2 * a * c));
					ans -= a * 2 * sita;
					k++;
				}
			}
		}
		printf("%f\n", ans);
		ans=0;
		k=0;
		scanf("%d", &n);
	}
	return 0;
}