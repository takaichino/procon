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

double dp[3][106];
int ma[106];

int main(){
	int i, j, n, t, l, b,ins;
	while(1){
		cin >> n >> t >> l >> b;
		if(!n) break;
		REP(a,n+7){
			dp[0][a]=0;
			dp[1][a]=0;
			dp[2][a]=0;
			ma[a]=0;
		}
		dp[0][0] = 1;
		REP(a,l){
			cin >> ins;
			ma[ins] = 1;
			if(n-ins<=5) ma[n+(n-ins)]=1;
		}
		REP(a,b){
			cin >> ins;
			ma[ins] = -1;
			if(n-ins<=5) ma[n+(n-ins)]=-1;
		}
		
		REP(a,t){
			/*REP(b, 3){
				REP(a,n+1) printf("%.5f ",dp[b][a]);
				cout << endl;
			}*/
			REP(b,n){
				REP(c,6){
					if(ma[b+c+1]==-1) dp[1][0] += dp[0][b] / 6;
					else if(ma[b+c+1]==1) dp[2][b+c+1]+=dp[0][b]/6;
					else dp[1][b+c+1] += dp[0][b] / 6;
				}
			}
			dp[1][n]+=dp[0][n];
			REP(b,5){
				dp[1][n-b-1] += dp[1][n+b+1];
				dp[1][n+b+1] = 0;
				dp[2][n-b-1] += dp[2][n+b+1];
				dp[2][n+b+1] = 0;
			}
			REP(b,n+1){
				dp[0][b] = dp[1][b];
				dp[1][b] = 0;
				dp[1][b] += dp[2][b];
				dp[2][b] = 0;
			}
		}
		printf("%.13f\n", dp[0][n]);
	}
	return 0;
}