#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	string base, road;
	base = "000001010011100101110111";
	int ij[25][8][8];
	int headleng[25][2];
	int flag = 0;
	
	for(int i = 1; i <= 24; i++){ // D % 24
		int metaflag =0;
		for(int k = 24; k >= 1; k--){ // |base|
			for(int v = 0; v+k <= 24; v++){
				road = base.substr(v,k);
				while(road.size() < 80) road = road + base.substr(v,k);
				cout << v << " " <<  k << " " << road.substr(0, 80) << endl;
				headleng[i][0] = v;
				headleng[i][1] = k;
				
				for(int p = 0; p < 8; p++){ //init
					for(int q = 0; q < 8; q++){
						ij[i][p][q] = 0;
					}
				}
				flag = 0;
				
				for(int j = 0; j < k; j++){
					int a = 4 * (road[j+24] - '0') + 2 * (road[j+24+1] - '0') + (road[j+24+2] - '0');
					int b = 4 * (road[j+24+i] - '0') + 2 * (road[j+24+i+1] - '0') + (road[j+24+i+2] - '0');
					ij[i][a][b] = 1;
				}
				for(int m = 0; m < k; m++){
					int a = 4 * (road[m+24] - '0') + 2 * (road[m+24+1] - '0') + (road[m+24+2] - '0');
					int b = 4 * (road[m+24-i] - '0') + 2 * (road[m+24-i+1] - '0') + (road[m+24-i+2] - '0');
					if(ij[i][a][b] == 1){
						flag++;
						break;
					}
					else{
						ij[i][a][b] = -1;
					}
				}
				if(flag == 0){//OK
					metaflag++;
					break;
				}
			}
			if(flag == 0){//OK
				break;
			}
		}
		if(metaflag == 0){
			cout << i << ":failed!" << endl;
			break;
		}
		else{
			cout << i  << ":clear! (" << headleng[i][0] << "," << headleng[i][1] << ")" << endl;
			for(int p = 0; p < 8; p++){
				for(int q = 0; q < 8; q++){
					cout << ij[i][p][q] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}