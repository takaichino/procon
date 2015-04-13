#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

struct pac{
	int t, s, d;
	bool operator<(const pac& a) const{
		if(a.t != t) return t < a.t;
	}
};

int main(){
	int n, m, v[20001], t,s,d;
	int ans;
	vector<pac> rec;
	pac in;
	while(1){
		cin >> n >> m;
		if(!n) break;
		REP(i,n+1) v[i] = 0;
		v[1] = 1;
		rec.clear();
		REP(i,m){
			cin >> in.t >> in.s >> in.d;
			rec.push_back(in);
		}
		sort(rec.begin(), rec.begin()+m);
		REP(i,m){
			if(v[rec[i].s]) v[rec[i].d] = 1;
		}
		ans =0;
		REP(i,n+1){
			if(v[i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}