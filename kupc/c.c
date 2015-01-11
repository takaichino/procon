#include<stdio.h>
#include<math.h>

int main(){
	int n, m, cho[100], ans=0;
	int i, j, nama=0, a, b;
	scanf("%d %d", &m, &n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<n-1) scanf("%d ", &cho[j]);
			else scanf("%d", &cho[j]);
			if(i>0) cho[j] = 1 - cho[j];
			if(j>0 && j<n-1 && cho[j]==1) nama++;
		}
		if(n==1) ans += cho[0];
		if(n>=2)
		{
			if(n>2)
			{
				a = cho[0] + cho[n-1] + (n - 2 - nama);
				if(nama==0) a--;
				else a++;
			}
			else a = 0;
			b = (n - 2 - nama);
			if(cho[0] == cho[n-1])  b++;
			else b += 2;
			if(a>b) ans += a;
			else ans += b;
		}
		nama = 0;
	}
	printf("%d\n",ans);
	return 0;
}