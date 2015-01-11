#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int a[100000];

int main(){
	int n,k=100,ans=0;
	cin >> n >> k;
	for(int j=0;j<n;j++){
		cin >> a[j];
	}
	for(int i=0;i<n&&k>0;i++){
		k -= a[i];
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}