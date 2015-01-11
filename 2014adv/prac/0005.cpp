#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 9999999

int main(){
	int n, s[1000];
	double m,a;
	while(cin >> n,n){
		m=0;
		for(int i=0;i<n;i++){
			cin >> s[i];
			m += (double)s[i];
		}
		m = m / (double)n;
		a=0;
		for(int j=0;j<n;j++){
			a += ((double)s[j] - m) * ((double)s[j] - m);
		}
		a = a/(double)n;
		a = sqrt(a);
		printf("%.6f\n", a);
	}
	return 0;
}