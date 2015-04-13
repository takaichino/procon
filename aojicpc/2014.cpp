#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

vector <string> a(52);
queue<pair <int, int> > q[2];
bool c[2][52][52];
int f[2];

void search(int x, int y, int z){
	pair<int, int> r;
	if(a[x][y] == '.')f[z]++;
	if(a[x+1][y]=='.'&&c[z][x+1][y]==0){
		c[z][x+1][y] = 1;
		r.first = x+1;
		r.second = y;
		q[z].push(r);
	}
	if(a[x-1][y]=='.'&&c[z][x-1][y]==0){
		c[z][x-1][y] = 1;
		r.first = x-1;
		r.second = y;
		q[z].push(r);
	}
	if(a[x][y-1]=='.'&&c[z][x][y-1]==0){
		c[z][x][y-1] = 1;
		r.first = x;
		r.second = y-1;
		q[z].push(r);
	}
	if(a[x][y+1]=='.'&&c[z][x][y+1]==0){
		c[z][x][y+1] = 1;
		r.first = x;
		r.second = y+1;
		q[z].push(r);
	}
	q[z].pop();
	if(!q[z].empty()) search(q[z].front().first, q[z].front().second, z);
}

int main(){
	int i, j, w, h;
	string s;
	pair<int, int> d;
	while(1){
		cin >> w >> h;
		if(!w)break;
		for(i=0;i<=h+1;i++){
			for(j=0;j<=w;j++){
				c[0][i][j] = 0;
				c[1][i][j] = 0;
				if(i==0||i==h+1) a[i] = "####################################################";
			}
		}
		for(i=1;i<=h;i++){
			cin >> s;
			a[i] = "#" + s + "#";
		}
		
		int common = 0;
		f[0]=0;
		f[1]=0;
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				d.first = i;
				d.second = j;
				if(a[i][j]=='B'){
					c[0][i][j] = 1;
					q[0].push(d);
				}
				else if(a[i][j]=='W'){
					c[1][i][j] = 1;
					q[1].push(d);
				}
				else common++;
			}
		}
		if(q[0].empty() && q[1].empty()){
			cout << "0 0" << endl;
		}
		else{
			if(!q[0].empty()) search(q[0].front().first, q[0].front().second, 0);
			if(!q[1].empty()) search(q[1].front().first, q[1].front().second, 1);
			//cout << common << " " << f[0] << " " << f[1] << endl;
			cout << common-f[1] << " " << common-f[0] << endl;
		}
	}
	return 0;
}