#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

struct xyt{
	int x, y, ti;
};

bool map[123][123], check[123][123];
queue <xyt> q;
int ans;

void search(int x,int y, int n, int t){
	int d[6][2] = {{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,-1}};
	xyt s;
	//cout << x-61 << " " << y-61;
	ans++;
	if(n<t){
		for(int k=0;k<6;k++){
			if(map[x+d[k][0]][y+d[k][1]]==0 && check[x+d[k][0]][y+d[k][1]]==0){
				check[x+d[k][0]][y+d[k][1]]=1;
				s.x = x+d[k][0];
				s.y = y+d[k][1];
				s.ti = n+1;
				q.push(s);
			}
		}
	}
	q.pop();
	if(!q.empty())search(q.front().x, q.front().y, q.front().ti, t);
}

int main(){
	int i, j, t, n, x, y;
	while(1){
		cin >> t >> n;
		if(t==0&&n==0) break;
		for(i=-61;i<=61;i++){
			for(j=-61;j<=61;j++){
				check[i+61][j+61] = 0;
				if(i==-61||i==61) map[i+61][j+61] = 1;
				else if(j==-61||j==61) map[i+61][j+61] = 1;
				else map[i+61][j+61] = 0;
			}
		}
		for(i=0;i<n;i++){
			cin >> x >> y;
			map[x+61][y+61] = 1;
		}
		ans = 0;
		cin >> x >> y;
		check[x+61][y+61] = 1;
		xyt a;
		a.x = x + 61;
		a.y = y +61;
		a.ti = 0;
		q.push(a);
		search(q.front().x, q.front().y, q.front().ti, t);
		cout << ans << endl;
	}
	return 0;
}