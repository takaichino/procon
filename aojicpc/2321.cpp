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


struct bitdp{
	int time, bi;
	bool operator<(const bitdp& a) const{
		if(a.bi != bi) return bi > a.bi;
		else return true;
	}
};

vector<int> guy, sas;
int dp[1<<17];
bool ch[1<<17];
priority_queue<bitdp> q;

int count(int x){
	int ans=0;
	REP(i,17)if(x&(1<<i)) ans++;
	return ans;
}

void search(bitdp t){
	bitdp hoge;
	//cout << t.time << " " << t.bi << endl;
	REP(i,guy.size()){
		if(!(t.time & guy[i])){
			if(dp[t.time]+sas[i] > dp[t.time+guy[i]]){
				dp[t.time+guy[i]]=dp[t.time]+sas[i];
				if(!ch[t.time+guy[i]]){
					ch[t.time+guy[i]] = true;
					hoge.time = t.time+guy[i];
					hoge.bi = count(t.time+guy[i]);
					q.push(hoge);
				}
			}
		}
	}
	q.pop();
	//cout << q.size() << ",";
	if(!q.empty()) search(q.top());
}


int main(){
	int i, j, n, m, l, s, e, ins;
	bitdp first;
	int ans;
	while(1){
		cin >> n;
		if(!n)break;
		ans = 0;
		guy.clear();
		sas.clear();
		REP(j,1<<17) dp[j] = 0;
		REP(j,1<<17) ch[j] = 0;
		REP(j,n){
			cin >> m >> l;
			sas.push_back(l);
			ins=0;
			REP(i,m){
				cin >> s >> e;
				for(int k=s;k<e;k++){
					ins+=1<<(k-6);
				}
			}
			//cout << ins << endl;
			guy.push_back(ins);
		}
		first.time = 0;
		first.bi = 0;
		q.push(first);
		search(q.top());
		//cout << "dp" << endl;
		REP(j,1<<17) if(ans<dp[j])ans = dp[j];
		cout << ans << endl;
	}
	return 0;
}