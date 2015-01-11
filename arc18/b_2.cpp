#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n, x[100], y[100], ans = 0;
	cin >> n;
	for( int i = 0; i < n ; i++){
		cin >> x[i] >> y[i];
	}
	int j,k,l;
	for(j=0;j<n-2;j++){
		for(k=j+1;k<n-1;k++){
			for(l=k+1;l<n;l++){
				long long int a = (long long int)y[k] - (long long int)y[j];
				long long int b = (long long int)x[j] - (long long int)x[k];
				long long int c = (long long int)x[k] * (long long int)y[j] - (long long int)x[j] * (long long int)y[k];
				long long int men = a * (long long int)x[l] + b * (long long int)y[l] + c;
				if(men < 0) men = - men;
				if(men % 2 == 0 && men != 0) ans++;
			}
		}
	}
	cout << ans << endl;
	
	
	return 0;
}