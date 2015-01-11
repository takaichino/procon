#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int N;
	string h;
	
	cin >> N;
	cin >> h;
	
	int tod[8] = {};
	int asu[8] = {};
	tod[1] = 1;
	int sek;
	
	for(int i=0; i<N; i++){
		if(h[i] == 'J') sek = 1 << 0;
		if(h[i] == 'O') sek = 1 << 1;
		if(h[i] == 'I') sek = 1 << 2;
		for(int j=0; j<8; j++){
			for(int k=0; k<8; k++){
				if((j & k) && (k & sek)){
					asu[k] = (asu[k] + tod[j]) % 10007;
				}
			}
		}
		for(int v=0; v<8;v++){
			tod[v] = asu[v];
			asu[v] = 0;
		}
	}
	int ans =0;
	for(int w = 0; w < 8; w++){
		ans = (ans + tod[w]) % 10007;
	}
	cout << ans << endl;
			
	return 0;
}