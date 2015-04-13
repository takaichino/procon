#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int pr[100001];

void erato(){
	pr[0]=0;
	pr[1]=0;
	pr[2]=1;
	for(int i=3;i<=100000;i++){
		pr[i]=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				pr[i]=0;
				break;
			}
		}
	}
}

int main(){
	long long int m, a, b, p, q;
	erato();
	while(1){
		cin >> m >> a >> b;
		if(!m)break;
		p=1;
		q=1;
		for(long long int i=2;i<=m;i++){
			for(long long int j=i;j*i<=m;j++){
				if(!pr[i]||!pr[j]) continue;
				if(i*j<=m&&a*j<=i*b&&i*j>p*q){
					p=i;
					q=j;
				}
			}
		}
		cout << p << " " << q << endl;
	}
	return 0;
}