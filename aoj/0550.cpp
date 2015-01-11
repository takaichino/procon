#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

int dp[2][5001][2];//[before/after][A‚Ì‚à‚Ì][‚¢‚ÜA‚Ì‚©]
int co[10000];

int main(){
	int ans, N, i, j;
	cin >> N;
	for(i=0;i<N-1;i++) cin >> co[i];
	for(i=0;i<2;i++){
		for(j=0;j<=5001;j++){
			dp[i][j][0] = INF;
			dp[i][j][1] = INF;
		}
	}
	dp[0][1][1] = 0;
	dp[0][1][0] = INF;
	for(i=2;i<=N;i++){//i:‚¢‚­‚Â‚ß‚Ü‚ÅŠm’è‚µ‚Ä‚¢‚é‚©
		for(j=1;j<=5000&&j<=i;j++){
			dp[1][j][0] = min(dp[0][j][0], dp[0][j][1] + co[i-2]);
			dp[1][j][1] = min(dp[0][j-1][1], dp[0][j-1][0] + co[i-2]);
			//cout << i << " " << j << endl;
			//cout << "dp[" << i << "][" << j << "][1]=" << dp[i][j][1] << endl;
		}
		for(j=1;j<=5000&&j<=i;j++){
			swap(dp[0][j][1], dp[1][j][1]);
			swap(dp[0][j][0], dp[1][j][0]);
		}
	}
	
	ans = min(dp[0][N/2][0], dp[0][N/2][1]);
	cout << ans << endl;
	return 0;
}