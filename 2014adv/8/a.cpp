#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

struct edge { int to, cap, rev; };
vector <edge> G[1002];
bool used[1002]; 


void add_edge(int from, int to, int cap) {
	G[from].push_back( (edge) {to, cap, (int)G[to].size()});
	G[to].push_back( (edge) {from, 0, (int)G[from].size() -1});
}

int dfs(int v, int t, int f) {
	if (v == t) return f;
	used[v] = true;
	for (int i=0; i < (int)G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

int main(){
	int m, n, card[1002] = {0};
	card[1] = 1;
	while(cin >> m >> n, n){
		for(int i=0; i<m; i++) cin >> card[i+2];
		for(int j=0; j<n; j++) cin >> card[j+m+2];
		
		for(int k=0; k<m; k++) add_edge(0, k+2, 1);
		for(int x=0; x<n; x++) add_edge(x+m+2, 1, 1);
		for(int y=0; y<m; y++){
			for(int z=0; z<n; z++){
				if(card[y+2] > card[z+m+2]){
					if(gcd(card[y+2], card[z+m+2]) >= 2){
						add_edge(y+2, z+m+2, 1);
					}
				}
				else{
					if(gcd(card[z+m+2], card[y+2]) >= 2){
						add_edge(y+2, z+m+2, 1);
					}
				}
			}
		}
		
		cout <<  max_flow(0, 1) << endl;
		G[0].clear();
		G[1].clear();
		for(int xx=0; xx<m; xx++) G[xx+2].clear();
		for(int xy=0; xy<n; xy++) G[xy+m+2].clear();
	}
	
	return 0;
}
