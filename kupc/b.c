#include<stdio.h>
#include<math.h>

int main(){
	int n, x, m;
	int l[10], r[10], s[10];
	int poss[7];
	int i, a, b, c, d, e, f, j, k, flag=0;
	scanf("%d %d %d", &n, &x, &m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d", &l[i], &r[i], &s[i]);
	}
	poss[0]=0;
	for(a=x;a>=0;a--)
	{
		poss[1]=a;
		for(b=x;b>=0;b--)
		{
			poss[2]=a+b;
			for(c=x;c>=0;c--)
			{
				poss[3]=a+b+c;
				for(d=x;d>=0;d--)
				{
					poss[4]=a+b+c+d;
					for(e=x;e>=0;e--)
					{
						poss[5]=a+b+c+d+e;
						for(f=x;f>=0;f--)
						{
							poss[6]=a+b+c+d+e+f;
							for(j=0;j<m;j++)
							{
								if(poss[r[j]] - poss[l[j]-1] == s[j])
								{
									flag++;
								}
							}
							if(flag==m) break;
							else flag=0;
						}
						if(flag==m) break;
					}
					if(flag==m) break;
				}
				if(flag==m) break;
			}
			if(flag==m) break;
		}
		if(flag==m) break;
	}
	if(flag==m)
	{
		for(k=0;k<n;k++)
		{
			printf("%d", poss[k+1]-poss[k]);
			if(k<n-1) printf(" ");
			else printf("\n");
		}
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}