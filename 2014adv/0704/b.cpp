#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int wa[51][11];

int main(){
	int M, T, P, R, m, t, p, j;
	int pt[51]; // ac2, time5, team2
	
	while( cin >> M >> T >> P >> R, M){
		for(int i=0; i<= T; i++){
			pt[i] = i + 43000 * 100;
			for(int x=0; x<=T; x++){
				wa[i][x] = 0;
			}
		}
		for(int z=0; z< R; z++){
			cin >> m >> t >> p >> j;
			if(j==0){ //ac
				pt[t] += 1 * pow(10, 7);
				pt[t] -= wa[t][p] * 20 * pow(10, 2);
				pt[t] -= m * pow(10, 2);
			}
			else{
				wa[t][p]++;
			}
		}
		sort(&pt[1], &pt[1] + T);
		/*
		for(int y=1 ; y<=T; y++)cout << pt[y] <<endl;
		*/
		
		int nex = 0, now = 0;
		for(int k=T; k>= 1 ; k--){
			now = pt[k] / 100;
			nex = pt[k-1] / 100;
			cout << pt[k] % 100;
			if(k>1){
				if(nex == now)cout << "=";
				else cout << ",";
			}
			else cout << endl;
		}
	}
	return 0;
}