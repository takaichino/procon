#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 9999999

int main(){
	int n, m, k, a, b, c, t, p, q, r, co[101][101], ti[101][101];
	while(cin >> n >> m, n){
		for(int v=1; v<=m; v++){
			for( int w=1; w<=m; w++){
				co[v][w] = INF;
				ti[v][w] = INF;
			}
		}
		for(int x=0; x<n; x++){
			cin >> a >> b >> c >> t;
			co[a][b] = c;
			co[b][a] = c;
			ti[a][b] = t;
			ti[b][a] = t;
		}
		
		for(int j=1;j<=m;j++){
			for(int h=1;h<=m;h++){
				for(int i=1;i<=m;i++){
					co[h][i] = min(co[h][i], co[h][j]+co[j][i]);
					ti[h][i] = min(ti[h][i], ti[h][j]+ti[j][i]);
				}
			}
		}
		
		cin >> k;
		for(int s=0; s<k;s++){
			cin >> p >> q >> r;
			if(!r) cout << co[p][q] << endl;
			else cout << ti[p][q] << endl;
		}
	}
	return 0;
}