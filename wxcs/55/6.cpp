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

int root[100][100];
int dp[100][100];

int main(){
	int i, j, N, M, L, K, A, H, X, Y, T;
	long long int ans;
	while(1){
		cin >> N >> M >> L >> K >> A >> H;
		if(!N) break;
		REP(i,N)REP(j,N){
			dp[i][j]=INF;
			root[i][j]=INF;
		}
		ans = INF;
		REP(i,L){
			cin >> 
		}
		REP(i,K){
			cin >> X >> Y >> T;
			
		
	cout << ans << endl;
	return 0;
}