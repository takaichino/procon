#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 99999999

long long int f[10001];

int n;
int dist[1001][1001];
int cost[1001][2];
char used[1001][2];

void dijkstra(int g,int v, int n) //http://www.ss.cs.meiji.ac.jp/CCP024.html
{
	int x, y, min;
	for(x = 0; x <= n; x++){
		cost[x][v] = INF;
		used[x][v] = 0;
	}
	cost[g][v] = 0;
	while(1){
		min = INF;
		for(x = 1; x <= n; x++){
			if(!used[x][v] && min > cost[x][v])min = cost[x][v];
		}
		/*
		for(int Z1=1;Z1<=n;Z1++){
			cout << cost[Z1][v] << " ";
		}
		cout << endl;
		*/
		if(min == INF)break;
		
		for(y = 1; y <= n; y++){
			if(cost[y][v] == min){
				used[y][v]++;
				/*
				cout << y << " ";
				for(int Z=1;Z<=n;Z++){
					cout << cost[Z][v] << " ";
				}
				cout << endl;
				*/
				for(x = 1; x <= n; x++){
					if(cost[x][v] > dist[x][y] + cost[y][v]){
						cost[x][v] = dist[x][y] + cost[y][v];
					}
				}
			}
		}
	}
} //http://www.ss.cs.meiji.ac.jp/CCP024.html

int main(){
	int m, s, t, ans = -1, xi, yi, di;
	cin >> n >> m >> s >> t;
	for(int P=0;P<=n;P++){
		for(int Q=0;Q<=n;Q++){
			dist[P][Q] = INF;
		}
	}
	
	for(int i=0; i<m;i++){
		cin >> xi >> yi >> di;
		dist[xi][yi] = di;
		dist[yi][xi] = di;
	}
	
	dijkstra(s, 0, n);
	dijkstra(t, 1, n);
	/*
	for(int P1=1;P1<=n;P1++)cout << cost[P1][0] << " " << cost[P1][1] << endl;
	*/
	for(int j=1;j<=n;j++){
		if(cost[j][0] == cost[j][1] && cost[j][0] != INF){
			ans = j;
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}