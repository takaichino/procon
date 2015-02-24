#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

vector<int> in[10001], out[10001];

int main(){
	int i, j, k, t, N, M, r, q, n, m, s, ts, te, ans;
	while(1){
		cin >> N >> M;
		if(!N) break;
		for(i=1;i<=M;i++){
			in[i].clear();
			out[i].clear();
		}
		cin >> r;
		for(i=0;i<r;i++){
			cin >> t >> n >> m >> s;
			if(s) in[m].push_back(t);
			else out[m].push_back(t);
		}
		for(i=1;i<=M;i++){
			for(j=0;j<in[i].size();j++){
				for(k=j+1;k<in[i].size();k++){
					if(in[i][j] <= in[i][k] && out[i][k] <= out[i][j]){
						in[i][k] = 0;
						out[i][k] = 0;
					}
					else if(in[i][j] <= in[i][k] && in[i][k] <= out[i][j]){
						out[i][j] = out[i][k];
						in[i][k] = 0;
						out[i][k] = 0;
					}
					else if(in[i][j] <= out[i][k] && out[i][k] <= out[i][j]){
						in[i][k] = in[i][j];
						in[i][j] = 0;
						out[i][j] = 0;
					}
					else if(in[i][k] <= in[i][j] && out[i][j] <= out[i][k]){
						in[i][j] = 0;
						out[i][j] = 0;
					}
				}
			}
		}
		cin >> q;
		for(i=0;i<q;i++){
			ans = 0;
			cin >> ts >> te >> m;
			for(j=0;j<in[m].size();j++){
				if(in[m][j] <= ts && te <= out[m][j]){
					ans += te - ts;
				}
				else if(in[m][j] <= ts && ts <= out[m][j]){
					ans += out[m][j] - ts;
				}
				else if(in[m][j] <= te && te <= out[m][j]){
					ans += te - in[m][j];
				}
				else if(ts <= in[m][j] && out[m][j] <= te){
					ans += out[m][j] - in[m][j];
				}
			}
			//cout << "a:";
			cout << ans << endl;
		}
	}
	return 0;
}