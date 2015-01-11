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
	
	headleng[1][0] = 7;
	headleng[1][1] = 16;
	headleng[2][0] = 6;
	headleng[2][1] = 15;
	headleng[3][0] = 0;
	headleng[3][1] = 24;
	headleng[4][0] = 0;
	headleng[4][1] = 14;
	headleng[5][0] = 9;
	headleng[5][1] = 15;
	headleng[6][0] = 0;
	headleng[6][1] = 24;
	headleng[7][0] = 3;
	headleng[7][1] = 13;
	headleng[8][0] = 9;
	headleng[8][1] = 14;
	headleng[9][0] = 0;
	headleng[9][1] = 12;
	headleng[10][0] = 9;
	headleng[10][1] = 15;
	headleng[11][0] = 5;
	headleng[11][1] = 13;
	headleng[12][0] = 9;
	headleng[12][1] = 15;
	headleng[13][0] = 7;
	headleng[13][1] = 16;
	headleng[14][0] = 3;
	headleng[14][1] = 17;
	headleng[15][0] = 7;
	headleng[15][1] = 16;
	headleng[16][0] = 1;
	headleng[16][1] = 19;
	headleng[17][0] = 0;
	headleng[17][1] = 20;
	headleng[18][0] = 0;
	headleng[18][1] = 24;
	headleng[19][0] = 7;
	headleng[19][1] = 16;
	headleng[20][0] = 1;
	headleng[20][1] = 23;
	headleng[21][0] = 0;
	headleng[21][1] = 24;
	headleng[22][0] = 1;
	headleng[22][1] = 19;
	headleng[23][0] = 0;
	headleng[23][1] = 20;
	headleng[24][0] = 3;
	headleng[24][1] = 21;
	
	for(int i = 1; i <= 24; i++){ // D % 24
		road = base.substr(headleng[i][0],headleng[i][1]);
		while(road.size() < 80) road = road + base.substr(headleng[i][0],headleng[i][1]);
		
		for(int p = 0; p < 8; p++){ //init
			for(int q = 0; q < 8; q++){
				ij[i][p][q] = 0;
			}
		}
		
		for(int j = 0; j < headleng[i][1]; j++){
			int a = 4 * (road[j+24] - '0') + 2 * (road[j+24+1] - '0') + (road[j+24+2] - '0');
			int b = 4 * (road[j+24+i] - '0') + 2 * (road[j+24+i+1] - '0') + (road[j+24+i+2] - '0');
			ij[i][a][b] = 1;
		}
		for(int m = 0; m < headleng[i][1]; m++){
			int a = 4 * (road[m+24] - '0') + 2 * (road[m+24+1] - '0') + (road[m+24+2] - '0');
			int b = 4 * (road[m+24-i] - '0') + 2 * (road[m+24-i+1] - '0') + (road[m+24-i+2] - '0');
			if(ij[i][a][b] == 1){
				cout << "error" << endl;
				break;
			}
			else{
				ij[i][a][b] = -1;
			}
		}
	}
	
	int N, D, mo, ro, re, X=0, Y=0, x, y ;
	cin >> N >> D;
	mo = D % 24;
	if(mo == 0) mo = 24;
	ro = N / headleng[mo][1];
	re = N % headleng[mo][1];
	
	for(int g=0; g<ro; g++){
		cout << base.substr(headleng[mo][0],headleng[mo][1]);
	}
	cout << base.substr(headleng[mo][0],re) << endl;
	fflush(stdout);
	scanf("%d %d", &x, &y);
	X = 2* X + x;
	Y = 2* Y + y;
	printf("Move(A,1)\n");
	fflush(stdout);
	scanf("%d %d", &x, &y);
	X = 2* X + x;
	printf("Move(A,1)\n");
	fflush(stdout);
	scanf("%d %d", &x, &y);
	X = 2* X + x;
	printf("Move(B,1)\n");
	fflush(stdout);
	scanf("%d %d", &x, &y);
	Y = 2* Y + y;
	printf("Move(B,1)\n");
	fflush(stdout);
	scanf("%d %d", &x, &y);
	Y = 2* Y + y;
	if(ij[mo][X][Y] == 1) cout << "i<j" << endl;
	if(ij[mo][X][Y] == -1) cout << "i>j" << endl;
	return 0;
}