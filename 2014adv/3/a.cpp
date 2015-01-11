#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999
int d[10][10];

int main(){
	int N, size;
	int a, b, c;
	int ans[10],ret[2];
	
	while(cin >> N, N){
		
		memset(d, INF, sizeof(d) );
		memset(ans, 0, sizeof(ans) );
		ret[0] = -1;
		ret[1] = INF;
		size = 0;
		for( int x=0; x<10; x++)d[x][x]=0;
		
		for( int i=0; i<N; i++){
			cin >> a >> b >> c;
			d[a][b] = c;
			d[b][a] = c;
			size = max( size, a+1 );
			size = max( size, b+1 );
		}
		
		int p, q, r;
		
		for(r=0; r<size; r++){
			for(p=0; p<size; p++){
				for(q=0; q<size; q++){
					d[p][q] = min( d[p][q], d[p][r] + d[r][q]);
				}
			}
		}
		
		for(int y=0;y<size; y++){
			for(int z= 0; z<size;z++){
				ans[y] += d[y][z];
			}
			if( ret[1] > ans[y]){
				ret[1] = ans[y];
				ret[0] = y;
			}
		}
		
		cout << ret[0] << " " << ret[1] << endl;
	}
	
	return 0;
}