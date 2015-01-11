#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int answer[5000][2] = {};

int main(){
	int n, m, k, in[1000][100];
	cin >> n >> m >> k;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> in[i][j];
		}
	}
	int ind, max;
	int ans = 0;
	
	if(k == 0){
		for(int v = m-1; v>= 0; v--){
			for(int x = 0; x < n; x++){
				max = in[x][v];
				ind = v;
				for(int w = 0; w < v; w++){
					if(in[x][w] > max){
						max = in[x][w];
						ind = w;
					}
				}
				if(ind != v){
					answer[ans][0] = ind;
					answer[ans][1] = v;
					ans++;
				}
				for(int u = 0; u < n; u++){
					if(in[u][v] < in[u][ind]){
						swap(in[u][v], in[u][ind]);
					}
				}
			}
		}
	}
	if(k == 1){
		for(int v = 0; v < m-1; v++){
			for(int x = 0; x < n; x++){
				max = in[x][v];
				ind = v;
				for(int w = v+1; w < m; w++){
					if(in[x][w] > max){
						max = in[x][w];
						ind = w;
					}
				}
				if(ind != v){
					answer[ans][0] = ind;
					answer[ans][1] = v;
					ans++;
				}
				for(int u = 0; u < n; u++){
					if(in[u][v] < in[u][ind]){
						swap(in[u][v], in[u][ind]);
					}
				}
			}
		}
	}
	
	cout << ans << endl;
	for(int y = 0; y < ans; y++){
		cout << answer[y][0] + 1 << " " << answer[y][1] + 1 << endl;
	}
	
	
	return 0;
}