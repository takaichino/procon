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

int c[100001], dpt[100001];
vector< vector <int> > e( 100001 );

int dfs(int d, int s, int f, bool v[100001]){
	for(int k=0;k < e[s].size(); k++){
		dpt[s] = d;
		if(!v[ e[s][k] ] && e[s][k] != f){
			v[e[s][k]]++;
			dpt[e[s][k]] = d+1;
			int W = dfs(d+1, e[s][k], s, v);
			if(W>0) return W;
		}
		else if(dpt[ e[s][k] ] != -1 && e[s][k] != f){
			return d + 1 - dpt[ e[s][k] ];
		}
	}
	return 0;
}

int main(){
	int ans, n, x, y ,i;
	
	bool v[100001] = {};
	cin >> n;
	e.resize(n+7);
	for(i=0; i<n;i++){
		dpt[i+1]=-1;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
		c[x]++;
		c[y]++;
	}
	v[1]++;
	dpt[1]=0;
	ans = dfs(0, 1, 1, v);
	
	cout << ans << endl;
	return 0;
}