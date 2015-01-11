#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

char mz[501][500];
int que[250000][2];

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n;i++){
		cin >> mz[i];
	}
	
	int dot = 1, wall=0;
	int head = 0, tail = 0;
	que[0][0] = -1;
	que[0][1] = -1;
	for(int x = 0; x < n;x++){
		for(int y = 0; y < m;y++){
			if(mz[x][y] =='.'){
				if(que[0][0] == -1){
					que[0][0]=x;
					que[0][1]=y;
					tail++;
				}
				else {
					mz[x][y] = 'X';
					wall++;
				}
			}
		}
	}
	
	
	return 0;
}