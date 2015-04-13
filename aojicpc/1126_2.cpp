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

vector<string> in(72);
string dp[72][72];
string ans;

bool com(string a, string b){
	if(a.size() > b.size()) return true;
	else if(a.size() == b.size()){
		REP(i, a.size()){
			if(a[i] > b[i]) return true;
			else if(a[i] < b[i]) return false;
		}
		return true;
	}
	else return false;
}

int main(){
	int i, j, w, h;
	string p;
	while(1){
		cin >> w >> h;
		if(!w) break;
		REP(a,h){
			cin >> in[a+1];
			in[a+1].insert(in[a+1].begin(),'A');
			in[a+1].insert(in[a+1].end(),'A');
		}
		in[h+1] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		in[0] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		REP(a,h+2) dp[a][0]="";
		REP(a,w+2) dp[0][a]="";
		dp[1][1] = "";
		ans ="";
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				if(in[i][j]-'0'>=0&&in[i][j]-'0'<=9){
					dp[i][j] = "";
					if(dp[i-1][j]!=""){
						dp[i][j] = dp[i-1][j];
					}
					if(dp[i][j-1]!=""){
						if(com(dp[i][j-1],dp[i][j])) dp[i][j] = dp[i][j-1];
					}
					if(!(dp[i][j]==""&&in[i][j]=='0'))dp[i][j].insert(dp[i][j].end(), in[i][j]);
				}
				else dp[i][j] ="";
			}
		}
		ans = "";
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				if(com(dp[i][j],ans)) ans = dp[i][j];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}