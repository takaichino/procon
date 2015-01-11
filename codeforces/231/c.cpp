#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

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
	
	int see[2001] ={};
	i
	for(int x=0; x < n; x++){
		for(int y= 0; y<m;y++){
			if(see[2*y] == see[2*y+1] && poyo[2] > 0){
				cout << "11";
				see[2*y]++;
				see[2*y+1]++;
				poyo[2]--;
			}
			else if(see[2*y] == see[2*y+1] && poyo[1] > 0){
				cout << "01";
				see[2*y+1]++;
				poyo[1]--;
			}
			else if(see[2*y] == see[2*y+1] && poyo[0] > 0){
				cout << "00";
				poyo[0]--;
			}
			else if(see[2*y] == see[2*y+1] - 1 && poyo[1] > 0){
				cout << "10";
				see[2*y]++;
				poyo[1]--;
			}
			else if(see[2*y] == see[2*y+1] - 1 && poyo[2] > 0){
				cout << "11";
				see[2*y]++;
				see[2*y+1]++;
				poyo[2]--;
			}
			else if(see[2*y] == see[2*y+1] - 1 && poyo[0] > 0){
				cout << "00";
				poyo[0]--;
			}
			
			if(y < m-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}