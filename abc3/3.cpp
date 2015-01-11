#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, k, r[101];
	double ans=0;
	cin >> n >> k ;
	for(int i = 0; i < n ; i++){
		cin >> r[i];
	}
	sort(&r[0], &r[n], greater<int>());
	for(int j =0; j<k;j++){
		ans += (double) r[j] / pow(2.0 , (double) j + 1.0);
	}
	printf("%.15f\n", ans);
	return 0;
}