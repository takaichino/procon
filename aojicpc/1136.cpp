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

int main(){
	vector< pair<int, int> > a[51], b[8];
	pair<int, int> ins;
	int n, m;
	
	while(1){
		cin >> n;
		if(!n) break;
		REP(i,51)a[i].clear();
		REP(i,8)b[i].clear();
		REP(i,n+1){
			cin >> m;
			REP(j,m){
				cin >> ins.first >> ins.second;
				a[i].push_back(ins);
			}
		}
		REP(i,a[0].size()){
			ins.first = a[0][i].first;
			ins.second = a[0][i].second;
			b[0].push_back(ins);
			b[1].insert(b[1].begin(), ins);
		}
		for(int i=2;i<8;i++){
			REP(j,b[0].size()){
				ins.first = -b[i-2][j].second;
				ins.second = b[i-2][j].first;
				b[i].push_back(ins);
			}
		}
		for(int i=1;i<=n;i++){
			if(b[0].size()==a[i].size()){
				int flag;
				REP(j,8){
					flag=1;
					REP(k,b[0].size()-1){
						int x1 = a[i][k+1].first - a[i][k].first;
						int y1 = a[i][k+1].second - a[i][k].second;
						int x2 = b[j][k+1].first - b[j][k].first;
						int y2 = b[j][k+1].second - b[j][k].second;
						if(x1 != x2 || y1 != y2) flag = 0;
					}
					if(flag){
						cout << i << endl;
						break;
					}
				}
			}
		}
		cout << "+++++" << endl;
	}
	return 0;
}