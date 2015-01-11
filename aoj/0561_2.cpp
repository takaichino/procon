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

vector< vector<int> > in( 10 );
int dp[10][2001]; //[genre x ‚Ü‚Å‚Å][yû”„‚Á‚½]‚Æ‚«‚ÌÅ‘å’l

int main(){
	long long int ans=0;
	int N, K, C, G, i, j, k;
	cin >> N >> K;
	for(j=0;j<10;j++) in[j].push_back(INF);
	for(i=0;i<N;i++){
		cin >> C >> G;
		in[G-1].push_back(C);
	}
	for(j=0;j<10;j++) sort(in[j].begin(),in[j].end(),greater<int>());
	for(j=0;j<10;j++) in[j][0] = 0;
	for(j=0;j<10;j++){
		for(i=1;i<(int)in[j].size();i++){
			in[j][i] += 2*(i-1) + in[j][i-1];
			//cout << in[j][i] << " ";
		}
		//cout << endl;
	}
	for(i=0;i<N;i++){
		if(i >= in[0].size()) dp[0][i] = 0;
		else dp[0][i] = in[0][i];
	}
	for(j=1;j<10;j++){
		for(i=0;i<=K;i++){
			dp[j][i] = 0;
			for(k=0;k<in[j].size();k++){
				if(i-k>=0) dp[j][i] = max(dp[j-1][i-k] + in[j][k], dp[j][i]);
			}
			//cout << dp[j][i] << " ";
		}
		//cout << endl;
	}
	ans = dp[9][K];
	cout << ans << endl;
	return 0;
}