#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int pr[200];

int main(){
	pr[0]=2;//erato
	int tail = 1;
	for(int a=3;a<=1050;a++){
		int flag = 0;
		for(int b=0; pr[b]*pr[b]<=a;b++){
			if(a % pr[b] == 0){
				flag++;
				break;
			}
		}
		if(flag==0){
			pr[tail] = a;
			tail++;
		}
	}
	
	int nowp = 0;
	int ans = 1;
	char judge[2] = "Y";
	while(nowp < 168){
		judge[0] = 'Y';
		while(judge[0] == 'Y' && ans * pr[nowp] <= 1000){
			ans = ans * pr[nowp];
			printf("? %d\n", ans);
			fflush(stdout);
			scanf("%s", judge);
		}
		if(judge[0] == 'N') ans = ans / pr[nowp];
		nowp++;
		if(ans * pr[nowp] > 1000){
			break;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}