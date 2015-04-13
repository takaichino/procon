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
	int n , m , p, b[23][23][23];
	int turn;
	string win;
	int d[13][3] ={{1,0,-1},{1,1,-1},{0,1,-1},{-1,1,-1},
		{1,0,0},{1,1,0},{0,1,0},{-1,1,0},
		{1,0,1},{1,1,1},{0,1,1},{-1,1,1},{0,0,1}};
	
	while(1){
		int x,y,z;
		cin >> n >> m >> p;
		if(!n)break;
		REP(i,23) REP(j,23) REP(k,23) b[i][j][k]=0;
		turn = 0;
		REP(i,p){
			cin >> x >> y;
			REP(j,n){
				if(b[x+7][y+7][j+7]==0){
					if(i%2==0) b[x+7][y+7][j+7] = 1;
					else b[x+7][y+7][j+7] = -1;
					break;
				}
			}
			/*
			for(int j=8;j<8+n;j++){
				for(int k=8;k<8+n;k++){
					for(int l=7;l<7+n;l++){
						cout << b[k][l][j] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			*/
			int flag=0, ins;
			if(!turn){
				for(int j=8;j<8+n;j++){
					for(int k=8;k<8+n;k++){
						for(int l=7;l<7+n;l++){
							if(b[j][k][l]!=0){
								REP(s,13){
									ins = b[j][k][l];
									x = j;
									y = k;
									z = l;
									REP(q,m-1){
										x += d[s][0];
										y += d[s][1];
										z += d[s][2];
										ins += b[x][y][z];
									}
									if(abs(ins)==m){
										turn = i+1;
										if(i%2==0) win = "Black";
										else win = "White";
									}
								}
							}
						}
						//cout << endl;
					}
					//cout << endl;
				}
			}
		}
		if(!turn) cout << "Draw" << endl;
		else cout << win << " " << turn << endl;
	}
	return 0;
}