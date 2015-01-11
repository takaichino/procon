#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int k, count[10] = {0,0,0,0, 0,0,0,0, 0,0};
	char in[4][5];
	cin >> k;
	cin >> in[0] >> in[1] >> in[2] >> in[3];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(in[i][j] != '.') count[ in[i][j] - '1' ]++;
		}
	}
	for(int m=0;m<10; m++){
		if(count[m] > (k * 2 )){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}