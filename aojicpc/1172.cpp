#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int pr[250000];

void elato(int pr[250000]){
	for(int k = 0;k<250000;k++){
		if(k==0||k==1){
			pr[k] = 0;
		}
		else{
			int flag = 1;
			for(int m=2;m*m<=k;m++){
				if(k%m==0){
					flag=0;
					break;
				}
			}
			if(flag){
				pr[k] = pr[k-1] + 1;
			}
			else{
				pr[k] = pr[k-1];
			}
		}
	}
}

int main(){
	int n;
	elato(pr);
	while(1){
		cin >> n;
		if(!n) break;
		cout << pr[2*n]-pr[n] << endl;
	}
	return 0;
}