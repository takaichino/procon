#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, k, sh=0, h[200000];
	int ans, best = INF;
	
	cin >> n >> k;
	for( int i = 0; i < n; i++){
		cin >> h[i];
	}
	for( int j = 0; j < k; j++){
		sh += h[j];
	}
	for( int x = 0; x < n-k+1; x++){
		if(sh < best){
			best = sh;
			ans = x + 1;
		}
		sh = sh - h[x] + h[x + k];
	}
	cout << ans << endl;
	return 0;
	
}