#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

int pr[250000];

void erato(int A[250000]){
	A[0]=0;
	A[1]=0;
	int flag, i, j;
	for(j=2; j<250000; j++){
		flag = 1;
		for(i=2; i*i<=j;i++){
			if(j % i == 0){
				flag = 0;
				break;
			}
		}
		if(flag) A[j] = A[j-1]+1;
		else A[j] = A[j-1];
	}
}

int main(){
	erato(pr);
	int n;
	while(1){
		cin >> n;
		if(!n) break;
		cout << pr[2*n]-pr[n] << endl;
	}
	return 0;
}