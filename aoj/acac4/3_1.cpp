#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 9999999999

int lca(int P[100001], int G[100001], int U, int V){
	while (G[U] < G[V]) V = P[V];
	while (G[U] > G[V]) U = P[U];
	
	while(U != V){
		U = P[U];
		V = P[V];
	}
	
	return U;
}

int main(){
	int n,k,m;
	int p[100001], g[100001];
	cin >> n;
	
	p[0]=0;
	g[0]=0;
	for(int i=0; i<n; i++){
		cin >> k;
		for(int j=0; j<k; j++){
			cin >> m;
			p[m] = i;
			g[m] = g[i]+1;
		}
	}
	
	int q,u,v;
	cin >> q;
	for(int x=0; x < q; x++){
		cin >> u >> v;
		cout << lca(p, g, u, v) << endl;
	}
	
	return 0;
}