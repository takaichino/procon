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

int dp[10][10][2][2];

int main(){
	int i, j, k, l;
	int ans;
	string in;
	int di[2][2] = {{1,0},{0,1}};
	//cout << in.max_size();
	while(1){
		cin >> in;
		if(in[0]=='#') break;
		REP(a,10)REP(b,10)REP(c,2)REP(d,2)dp[a][b][c][d]=INF;
		dp[5][5][0][0] = 0;
		dp[5][5][1][0] = 0;
		REP(e,in.size()){
			/*
			for(i=1;i<=9;i++){
				for(j=1;j<=9;j++){
					if(dp[i][j][0][0]==INF) cout << "-1 ";
					else cout << dp[i][j][0][0] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for(i=1;i<=9;i++){
				for(j=1;j<=9;j++){
					if(dp[i][j][1][0]==INF) cout << "-1 ";
					else cout << dp[i][j][1][0] << " ";
				}
				cout << endl;
			}
			cout << endl;
			*/
			int s = in[e] - '0';
			for(i=1;i<=9;i++)for(j=1;j<=9;j++)REP(c,2){
				if(dp[i][j][c][0]!=INF){
					if(i==s)
					dp[s][j][0][1] = min(dp[s][j][0][1],dp[i][j][c][0]+di[c][0]);
					if(j==s)
					dp[i][s][1][1] = min(dp[i][s][1][1],dp[i][j][c][0]+di[c][1]);
					if(i==5)
					dp[i][s][1][1] = min(dp[i][s][1][1],dp[i][j][c][0]+di[c][1]);
					if(j==5)
					dp[s][j][0][1] = min(dp[s][j][0][1],dp[i][j][c][0]+di[c][0]);
					if(i!=s&&i!=5&&(i-1)%3<=(s-1)%3)
					dp[i][s][1][1] = min(dp[i][s][1][1],dp[i][j][c][0]+di[c][1]);
					if(j!=s&&j!=5&&(s-1)%3<=(j-1)%3)
					dp[s][j][0][1] = min(dp[s][j][0][1],dp[i][j][c][0]+di[c][0]);
				}
			}
			REP(a,10)REP(b,10)REP(c,2){
				dp[a][b][c][0]=dp[a][b][c][1];
				dp[a][b][c][1]=INF;
			}
		}
		ans = INF;
		for(i=1;i<=9;i++)for(j=1;j<=9;j++)REP(c,2){
			if(dp[i][j][c][0] < ans)ans = dp[i][j][c][0];
		}
		cout << ans << endl;
	}
	return 0;
}