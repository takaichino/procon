#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n,l,r,lr[100]={};
	
	cin >> n;
	cin >> l >> r;
	for(int j=l; j<r; j++){
		lr[j] = 1;
	}
	for(int i=0; i<n-1; i++){
		cin >> l >> r;
		for(int m=l; m<r; m++){
			lr[m]=0;
		}
	}
	int m = 0;
	for(int v = 0;v<100;v++){
		if(lr[v] == 1){
			m++;
		}
	}
	
	cout << m << endl;
	
	return 0;
}