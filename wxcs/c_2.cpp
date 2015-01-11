#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int josephus(int n, int k){
	if(n==1){
		return 0;
	}
	else{
		return ( josephus(n-1, k) + k ) % (n-1);
	}
}
		

int main(){
	int n=2,k,m;
	int ans;
	while(1){
		cin >> n >> k >> m;
		if(n==0) break;
		
		ans = (josephus(n,k) + m) % n + 1;
		
		cout << ans << endl;
	}
	return 0;
}