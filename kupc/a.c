#include<stdio.h>

int main(){
	int n, q, year, near=0;
	char name[30], ans[30]="kogakubu10gokan";
	int i, j;
	scanf("%d %d", &n, &q);
	for(i=0;i<n;i++)
	{
		scanf("%d %s", &year, name);
		if(year > near && year <= q)
		{
			for(j=0;j<30;j++)
			{
				ans[j] = name[j];
			}
		}
	}
	printf("%s\n", ans);
	return 0;
}