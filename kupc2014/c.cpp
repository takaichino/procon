#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

long long gcd(long long a, long long b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

int gr[400][400];

int main(){
	int N, M, Q, c[200], d[200];
	cin >> N >> M >> Q;
	for(int k = 0; k<Q; k++){
		cin >> c[k] >> d[k];
	}
		
	int head = 0;
	int tail = max(N,M) / gcd(max(M,N), min(M,N)) * min(N,M) + 1;
	
	while(head < tail-1){
		int now = (head + tail) / 2;
		for(int x = 0 ; x< N+M; x++){
			for(int y = 0; y< N+M; y++){
				gr[x][y] = 9999999;
			}
		}
		for(int i = 0; i < now-1 ; i++){
			gr[i % N][i % M + N] = 1;
			gr[i % M + N][i % N] = 1;
		}
		for(int z = 0; z<Q; z++){
			gr[c[z]-1][d[z]-1+N] = 1;
			gr[d[z]-1+N][c[z]-1] = 1;
		}
		for(int r=0; r<N+M; r++){
			for(int p=0; p<N+M; p++){
				for(int q=0; q<N+M;q++){
					if(gr[p][q] > gr[p][r] + gr[r][q]){
						gr[p][q] = gr[p][r] + gr[r][q];
					}
				}
			}
		}
		
		if(gr[(now-1)%N][(now-1)%M + N] < 9999999){
			tail = now;
		}
		else{
			head = now;
		}
	}
	cout << head << endl;
	
	return 0;
}