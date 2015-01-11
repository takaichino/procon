#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

char mz[501][501];
short que[250000][2];

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n;i++){
		cin >> mz[i];
	}
	
	int wall=0;
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
	
	while(wall != k){
		int a = que[head][0];
		int b = que[head][1];
		if( a > 0 && mz[a-1][b]=='X'){
			mz[a-1][b]='.';
			que[tail][0] = a-1;
			que[tail][1] = b;
			tail++;
			wall--;
			if(wall == k) break;
		}
		if( a < n-1 && mz[a+1][b]=='X'){
			mz[a+1][b]='.';
			que[tail][0] = a+1;
			que[tail][1] = b;
			if(tail <229999){tail++;}
			tail++;
			wall--;
			if(wall == k) break;
		}
		if( b > 0 && mz[a][b-1]=='X'){
			mz[a][b-1]='.';
			que[tail][0] = a;
			que[tail][1] = b-1;
			tail++;
			wall--;
			if(wall == k) break;
		}
		if( b < m-1 && mz[a][b+1]=='X'){
			mz[a][b+1]='.';
			que[tail][0] = a;
			que[tail][1] = b+1;
			tail++;
			wall--;
			if(wall == k) break;
		}
		head++;
	}
	
	for(int p=0; p<n;p++){
		for(int q=0; q<m; q++){
			cout << mz[p][q];
		}
		cout << endl;
	}
	return 0;
}