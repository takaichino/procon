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

vector<int> guy, sas;
int dp[101][1<<17];

int main(){
	int i, j, n, m, l, s, e, ins;
	int ans;
	while(1){
		cin >> n;
		if(!n)break;
		ans = 0;
		guy.clear();
		sas.clear();
		REP(i,n)REP(j,1<<17) dp[i][j]=0;
		REP(i,n){
			cin >> m >> l;
			sas.push_back(l);
			ins=0;
			REP(j,m){
				cin >> s >> e;
				for(int k=s;k<e;k++){
					ins+=1<<(k-6);
				}
			}
			//cout << ins << endl;
			guy.push_back(ins);
		}
		REP(i,n){
			REP(j,1<<17){
				dp[i+1][j] = dp[i][j];
			}
			REP(j,1<<17){
				if(!(guy[i]&j) && dp[i+1][j+guy[i]]<dp[i][j]+sas[i]){
					dp[i+1][j+guy[i]]=dp[i][j]+sas[i];
				}
			}
		}
		REP(j,1<<17) if(ans<dp[n][j])ans = dp[n][j];
		cout << ans << endl;
	}
	return 0;
}