#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<bitset>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

struct megaman{
	int s, t;
	bool operator<(const megaman& a) const{
		if(t!=a.t) return t > a.t;
		if(s!=a.s) return s > a.s;
	}
};

int dp[1<<17];
bool ch[1<<17];
queue <int> q;
int t[17][17];

int count(int k,int n){
	int ans =0;
	REP(i,n)if(k&(1<<n))ans++;
	return ans;
}

void search(int n,int x){
	//cout << "s:"<< static_cast<bitset<17> >(z) <<"-" <<dp[z]<<endl;
	REP(z,1<<n){
		if(count(z,n)==x){
			REP(a,n){
				if(!(z&(1<<a))){
					if(t[a][0]+dp[z]<dp[z+(1<<a)]){
						dp[z+(1<<a)] = t[a][0]+dp[z];
					}
					REP(b,n){
						if(z&(1<<b)){
							if(t[a][b+1]+dp[z]<dp[z+(1<<a)]){
								dp[z+(1<<a)] = t[a][b+1]+dp[z];
							}
						}
					}
					if(!ch[z+(1<<a)]){
						ch[z+(1<<a)]=1;
					}
					//cout << "p:"<< static_cast<bitset<17> >(z+(1<<a)) << "-" <<dp[z+(1<<a)]<<endl;
				}
			}
		}
	}
	if(x<n)search(n,x+1);
}

int main(){
	int i, j, n;
	int ans;
	while(1){
		cin >> n;
		if(!n) break;
		REP(a,1<<n){
			dp[a]=99999999;
			ch[a]=0;
		}
		dp[0]=0;
		REP(a,n)REP(b,n+1) cin >> t[a][b];
		ch[0]=1;
		//cout << "ok" << endl;
		search(n,0);
		cout << dp[(1<<n)-1] <<endl;
	}
	
	return 0;
}