#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	
	double ans[100001], dp[2][12], p[2][12];
	memset( ans, 0, sizeof(ans) );
	
	for(int i=0; i<=10; i++){
		p[1][i] = 1.0 / pow( 2, i );
		p[0][i] = 1.0 - p[1][i];
	}
	
	memset( dp, 0, sizeof(dp) );
	dp[1][1] = 1.0;
	
	for(int j = 1; j <= 100000; j++){
		//calc. ans
		ans[j] = ans[j-1];
		for(int z = 1; z <= 11; z++){
			ans[j] += dp[1][z];
		}
		//swap
		for(int x = 0; x <= 11; x++){
			dp[0][x] = dp[1][x];
			dp[1][x] = 0.0;
		}
		//dp
		for(int y = 0; y <= 10; y++){
			dp[1][0] += dp[0][y] * p[0][y];
			dp[1][y+1]+=dp[0][y] * p[1][y];
		}
		
	}
	
	int n;
	while(cin >> n, n){
		printf("%.3f\n", ans[n]);
	}
	
	return 0;
}