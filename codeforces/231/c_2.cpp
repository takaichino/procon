#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

short int xy[1000][1000];

int main(){
	int n, m;
	cin >> n >> m;
	int poyo[3] ={};
	
	int le;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> le ;
			if(le == 00){
				poyo[0]++;
			}
			else if(le == 01 || le == 10){
				poyo[1]++;
			}
			else if(le == 11){
				poyo[2]++;
			}
		}
	}
	
	int moku[2000]={};
	int sum = poyo[2] * 2 + poyo[1];
	
	for(int w=0; w < 2 * m; w++){
		if(w < sum % (2 * m)){
			moku[w] = sum / (2 * m) + 1;
		}
		else{
			moku[w] = sum / (2 * m);
		}
	}
	
	for(int v=m-1; v >= 0; v--){
		for(int u=0; u < n; u++){
			if(moku[2*v] > 0 && moku[2*v+1] > 0 && u + 1 < n && poyo[1] > 1){
				xy[u][v] = 10;
				xy[u+1][v] = 1;
				moku[2*v]--;
				moku[2*v+1]--;
				poyo[1] -= 2;
				u++;
			}
			else if(moku[2*v] > 0 && moku[2*v+1] > 0 && poyo[2] > 0){
				xy[u][v] = 11;
				moku[2*v]--;
				moku[2*v+1]--;
				poyo[2]--;
			}
			else if(moku[2*v] > 0 && moku[2*v+1] == 0 && poyo[1] > 0){
				xy[u][v] = 10;
				moku[2*v]--;
				poyo[1]--;
			}
			else if(moku[2*v] == 0 && moku[2*v+1] == 0 && poyo[0] > 0){
				xy[u][v] = 0;
				poyo[0]--;
			}
		}
	}
	
	for(int x=0; x < n; x++){
		for(int y= 0; y<m;y++){
			
			if(xy[x][y] == 11){
				cout << "11";
			}
			else if(xy[x][y] == 10){
				cout << "10";
			}
			else if(xy[x][y] == 1){
				cout << "01";
			}
			else if(xy[x][y] == 0){
				cout << "00";
			}
			
			if(y < m-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}