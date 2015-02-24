#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

vector<pair<int, int> > rin[32][32];
int d[32][32];

queue<pair<int, int> > qu;

void search(pair<int, int> a){
	//cout << a.first << " " << a.second << " " << d[a.first][a.second] << endl;
	pair<int, int> b;
	for(int i=0;i<rin[a.first][a.second].size();i++){
		b.first = rin[a.first][a.second][i].first;
		b.second = rin[a.first][a.second][i].second;
		if(!d[b.first][b.second]){
			qu.push(b);
			d[b.first][b.second] = d[a.first][a.second] + 1;
		}
	}
	qu.pop();
	if(!qu.empty()) search(qu.front());
}

int main(){
	int i, j, k, l, w, h, ins;
	pair<int, int> s;
	while(1){
		cin >> w >> h;
		if(!w)break;
		for(i=0;i<=h+1;i++){
			for(j=0;j<=w+1;j++){
				d[i][j] = 0;
				rin[i][j].clear();
			}
		}
		
		for(i=1;i<=h-1;i++){
			for(j=1;j<=w-1;j++){
				cin >> ins;
				if(!ins){
					rin[i][j].push_back(make_pair(i,j+1));
					rin[i][j+1].push_back(make_pair(i,j));
				}
			}
			for(j=1;j<=w;j++){
				cin >> ins;
				if(!ins){
					rin[i+1][j].push_back(make_pair(i,j));
					rin[i][j].push_back(make_pair(i+1,j));
				}
			}
		}
		for(j=1;j<=w-1;j++){
			cin >> ins;
			if(!ins){
				rin[i][j].push_back(make_pair(i,j+1));
				rin[i][j+1].push_back(make_pair(i,j));
			}
		}
		/*
		for(i=0;i<=h+1;i++){
			for(j=0;j<=w+1;j++){
				cout << i << "," << j << ":";
				for(int z=0;z<rin[i][j].size();z++){
					 cout << rin[i][j][z].first << "," << rin[i][j][z].second << " ";
				}
				cout << endl;
			}
		}
		*/
		//cout << "OK" << endl;
		s.first = 1;
		s.second = 1;
		d[1][1] = 1;
		qu.push(s);
		search(s);
		cout << d[h][w] << endl;
	}
	return 0;
}