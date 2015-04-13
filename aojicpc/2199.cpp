#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

long long int dp[2][256];

int main(){
	int i, j, m, n, c[16], x;
	long long int ans;
	while(1){
		cin >> n >> m;
		if(!n) break;
		ans = INF;
		REP(a,2)REP(b,256) dp[a][b] = INF;
		dp[0][128]=0;
		REP(a,m) cin >> c[a];
		REP(a,n){
			cin >> x;
			REP(y,256){
				if(dp[0][y]!=INF){
					REP(z,m){
						if(y+c[z]<=0){
							if(dp[1][0]>=dp[0][y]+pow(x-0,2)){
								dp[1][0]=dp[0][y]+pow(x-0,2);
							}
						}
						else if(y+c[z]>=255){
							if(dp[1][255]>=dp[0][y]+pow(x-255,2)){
								dp[1][255]=dp[0][y]+pow(x-255,2);
							}
						}
						else{
							if(dp[1][y+c[z]]>=dp[0][y]+pow(x-y-c[z],2)){
								dp[1][y+c[z]]=dp[0][y]+pow(x-y-c[z],2);
							}
						}
					}
				}
			}
			REP(b,256){
				dp[0][b]=dp[1][b];
				dp[1][b]=INF;
			}
		}
		REP(a,256)if(dp[0][a]<ans) ans = dp[0][a];
		cout << ans << endl;
	}
	return 0;
}