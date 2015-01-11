#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int pr[500000] ={};
int cv[1003][1003] ={};
int dp[1003][1003][2];
int pc[1003][1003];

int main(){
	pr[0] = 2;//erato
	int tail = 1;
	for(int x=3; x <= 1000000; x++){
		int flag = 0;
		for(int y=0; pr[y] * pr[y] <= x; y++){
			if(x % pr[y] == 0){
				flag++;
				break;
			}
		}
		if(flag == 0){
			pr[tail] = x;
			tail++;
		}
	}
	
	int nowx = 501;
	int nowy = 501;
	int kazu = 1;
	int phase=0;
	int kai = 0;
	int nowp = 0;
	for(int a = 1; a <= 1000000; a++){//cave
		cv[nowx][nowy] = a;
		if(pr[nowp] == a){
			pc[nowx][nowy] = 1;
			nowp++;
		}
		else pc[nowx][nowy] = 0;
		if(kazu % 2 == 1 && phase == 0) nowx++;
		else if(kazu % 2 == 1 && phase == 1) nowy--;
		else if(kazu % 2 == 0 && phase == 0) nowx--;
		else if(kazu % 2 == 0 && phase == 1) nowy++;
		kai++;
		if(kazu == kai && phase == 0){
			kai = 0;
			phase = 1;
		}
		if(kazu == kai && phase == 1){
			kai = 0;
			phase = 0;
			kazu++;
		}
	}
	
	int m, n;
	while(cin >> m >> n, m){
		for(nowx=0; nowx<1003; nowx++){
			dp[nowx][0][0] = -1;
			dp[nowx][0][1] = -1;
		}
		for(nowy=1; nowy<1003; nowy++){
			for(nowx=0; nowx<1003; nowx++){
				dp[nowx][nowy][0] = dp[nowx][nowy-1][0];
				dp[nowx][nowy][1] = dp[nowx][nowy-1][1];
				if(cv[nowx][nowy] == n){
					dp[nowx][nowy][0] = 0;
					dp[nowx][nowy][1] = 0;
				}
				if(nowx > 0 && 
					(dp[nowx-1][nowy-1][0] > dp[nowx][nowy][0] || 
						( dp[nowx-1][nowy-1][0] == dp[nowx][nowy][0] && dp[nowx-1][nowy-1][1] > dp[nowx][nowy][1])
					)
				){
					dp[nowx][nowy][0] = dp[nowx-1][nowy-1][0];
					dp[nowx][nowy][1] = dp[nowx-1][nowy-1][1];
				}
				if(nowx < 1002 && 
					(dp[nowx+1][nowy-1][0] > dp[nowx][nowy][0] || 
						( dp[nowx+1][nowy-1][0] == dp[nowx][nowy][0] && dp[nowx+1][nowy-1][1] > dp[nowx][nowy][1])
					)
				){
					dp[nowx][nowy][0] = dp[nowx+1][nowy-1][0];
					dp[nowx][nowy][1] = dp[nowx+1][nowy-1][1];
				}
				if(dp[nowx][nowy][0] >= 0 && cv[nowx][nowy] <= m && pc[nowx][nowy] == 1){
					dp[nowx][nowy][0]++;
					dp[nowx][nowy][1] = cv[nowx][nowy];
				}
			}
		}
		int ans = -1, last=-1;
		for(nowx=1; nowx<1002; nowx++){
			if(ans < dp[nowx][1002][0] || (ans == dp[nowx][1002][0] && last < dp[nowx][1002][1])){
				ans = dp[nowx][1002][0];
				last = dp[nowx][1002][1];
			}
		}
		cout << ans << " " << last << endl;
	}
	
	return 0;
}