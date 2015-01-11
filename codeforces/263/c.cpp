#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int a[300000];

int main(){
	int n;
	long long int ans = 0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		ans += a[i];
	}
	sort( &a[0], &a[0]+n);
	
	ans = ans * n;
	for(int j=0; j<n-2; j++){
		ans -= a[j] * (n-2-j);
	}
	
	cout << ans << endl;
	return 0;
}