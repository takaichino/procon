#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

bool pr[200000];

void erato(){
	pr[0] = false;
	pr[1] = false;
	pr[2] = true;
	for(int i=3;i<200000;i++){
		pr[i] = true;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				pr[i] = false;
				continue;
			}
		}
	}
}

int main(){
	int i, j, n, p, now;
	erato();
	while(1){
		cin >> n >> p;
		if(n==-1) break;
		now = n*2+2;
		i=0;
		while(1){
			for(j=n+1;now-j>=j;j++){
				if(pr[j]&&pr[now-j]){
					//cout << j << " " << now-j << endl;
					i++;
				}
			}
			if(i>=p)break;
			now++;
		}
		cout << now << endl;
	}
	return 0;
}