#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n;
	cin >> n;
	int ans = (n*n+1) / 2;
	cout << ans << endl;
	for(int i=0; i < n; i++){
		for(int j=0; j < n;j++){
			if( i%2==0 && j%2 == 0){
				cout << "C";
			}
			else if( i%2==1 && j%2 == 1){
				cout << "C";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
	
	return 0;
}