#include<stdio.h>
#include<string.h>

int mat[20][11680];
char in[20001];

int main(){
	int n, m, v, ph, cal, i, j, k, hohho,hoge;
	scanf("%d\n", &n);
	for(m=0;m<n;m++)
	{
		ph = 0;
		mat[0][0]=1;
		cal=0;
		fgets(in, 20001, stdin);
		for(v=0;v<strlen(in)-1;v++)
		{
			if(in[v]=='[')
			{
				if(in[v+1]=='[')
				{
					ph++;
					mat[ph][0]=1;
				}
				else
				{
					cal=0;
				}
			}
			else if(in[v] == ']')
			{
				if(in[v-1]!=']')
				{
					mat[ph][mat[ph][0]]= (cal+1)/2;
					mat[ph][0]++;
					cal=0;
				}
				else
				{
					for(i=1;i<mat[ph][0]-1;i++)
					{
						for(j=1;j<mat[ph][0]-i;j++)
						{
							if(mat[ph][j]>mat[ph][j+1])
							{
								hohho=mat[ph][j];
								mat[ph][j]=mat[ph][j+1];
								mat[ph][j+1]=hohho;
							}
						}
					}
					cal=0;
					hoge = mat[ph][0]/2;
					for(k=1;k<=hoge;k++)
					{
						cal += mat[ph][k];
					}
					ph--;
					mat[ph][mat[ph][0]]=cal;
					mat[ph][0]++;
				}
			}
			else
			{
				if(in[v]=='0') cal = cal * 10 + 0;
				if(in[v]=='1') cal = cal * 10 + 1;
				if(in[v]=='2') cal = cal * 10 + 2;
				if(in[v]=='3') cal = cal * 10 + 3;
				if(in[v]=='4') cal = cal * 10 + 4;
				if(in[v]=='5') cal = cal * 10 + 5;
				if(in[v]=='6') cal = cal * 10 + 6;
				if(in[v]=='7') cal = cal * 10 + 7;
				if(in[v]=='8') cal = cal * 10 + 8;
				if(in[v]=='9') cal = cal * 10 + 9;
			}
		}
		printf("%d\n", mat[0][1]);
	}
	return 0;
}
