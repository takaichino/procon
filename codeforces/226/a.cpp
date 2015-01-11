#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, c, x[100];
	cin >> n >> c;
	for(int i = 0; i<n;i++){
		cin >> x[i];
	}
	int ans = 0;
	for(int j = 0; j<n-1;j++){
		if(x[j] - c - x[j+1] > ans){
			ans = x[j] - c - x[j+1];
		}
	}
	cout << ans << endl;
	
	return 0;
}