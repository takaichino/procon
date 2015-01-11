#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int t, l, r, n;
	cin >> t;
	for(int i = 0; i<t;i++){
		cin >> n >> l >> r;
		int roop;
		if(n % r == 0){
			roop = n / r;
		}
		else {
			roop = (n - (n % r)) / r + 1 ; 
		}
		int most = roop * r;
		int least = roop * l;
		if(most >= n && least <= n){
			cout << "Yes" << endl;
		}
		else cout << "No" <<endl;
	}
	return 0;
}