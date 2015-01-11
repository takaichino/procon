#include<stdio.h>

int main(){
	int i, j, sta[1024][2], head=0, tail=1, ans=0;
	for(i=10;i<30;i++)
	{
		printf("%d : ", i);
		for(j=1;j<i;j++)
		{
			sta[0][0] = j;
			sta[0][1] = 0;
			while(sta[head][1]<6)
			{
				if(sta[head][0] == i)
				{
					ans++;
				}
				sta[tail][0] = sta[head][0] * 2;
				sta[tail][1] = sta[head][1] + 1;
				if(tail==1023) tail=0;
				else tail++;
				sta[tail][0] = sta[head][0] - 1;
				sta[tail][1] = sta[head][1] + 1;
				if(tail==1023) tail=0;
				else tail++;
				if(head==1023) head=0;
				else head++;
			}
			if(ans>0) printf("O ");
			else printf("X ");
			head=0;
			tail=1;
			ans=0;
		}
		printf("\n");
	}
	return 0;
}