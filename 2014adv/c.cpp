#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	long long int ans;
	int N,in[100];
	long long int dp[100][21];
	
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> in[i];
	}
	
	memset(dp,0,sizeof(dp));
	dp[0][ in[0] ] = 1;
	
	for(int j=0; j < N-1; j++){
		for(int k=0; k <= 20; k++){
			if(dp[j][k]>0){
				int now = in[j+1];
				if(k+now<=20) dp[j+1][k+now]+=dp[j][k];
				if(k-now>=0) dp[j+1][k-now]+=dp[j][k];
			}
		}
	}
	ans = dp[N-2][in[N-1]];
	/*
	for(int x=0;x<N;x++){
		for(int y=0;y<=20;y++){
			cout << dp[x][y] << " ";
		}
		cout << endl;
	}
	*/
	
	cout << ans << endl;
	
	return 0;
}