#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

bool pr[1300000];

void erato(){
	pr[0] = 0;
	pr[1] = 0;
	pr[2] = 1;
	for(int i = 3;i<1300000;i++){
		pr[i]=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				pr[i] = 0;
				break;
			}
		}
	}
}

int main(){
	int i, j, n;
	int ans;
	erato();
	while(1){
		cin >> n;
		if(!n)break;
		if(pr[n]) cout << "0" << endl;
		else{
			int less = n-1;
			while(!pr[less]){
				less--;
			}
			int more = n+1;
			while(!pr[more]){
				more++;
			}
			cout << more - less << endl;
		}
	}
	return 0;
}