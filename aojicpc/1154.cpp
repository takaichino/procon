#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

int so[100000];

int hen(int i){
	if(i%2==0) return ((int)(i/2))*7 + 1;
	else return ((int)(i/2))*7 + 6;
}

void erato(){
	so[0] = 0;
	so[1] = 1;
	for(int j=2;j<100000;j++){
		so[j] = 1;
		int m = hen(j);
		//cout << m << endl;
		for(int k=1;hen(k)*hen(k)<=m;k++){
			if(m%hen(k)==0){
				so[j] = 0;
				break;
			}
		}
	}
}

int main(){
	int i, j, n;
	erato();
	while(1){
		cin >> n;
		if(n==1) break;
		cout << n << ":";
		for(j=0;hen(j)<=n;j++){
			if(so[j]==1 && n%hen(j)==0){
				cout << " " << hen(j);
			}
		}
		cout << endl;
	}
	return 0;
}