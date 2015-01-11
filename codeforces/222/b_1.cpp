#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n;
	int a[100000], b[100000];
	int pa[100000]={}, pb[100000]={};
	cin >> n;
	for(int i = 0; i<n;i++){
		cin >> a[i] >> b[i];
		if( (i+1) * 2 <= n ){
			pa[i] = 1;
			pb[i] = 1;
		}
	}
	int ah=0, bh=0;
	while(ah + bh < n){
		if(a[ah] < b[bh]){
			pa[ah]=1;
			ah++;
		}
		else if(a[ah] > b[bh]){
			pb[bh]=1;
			bh++;
		}
	}
	
	for(int j = 0; j < n; j++){
		cout << pa[j];
	}
	cout << endl;
	for(int k = 0; k < n; k++){
		cout << pb[k];
	}
	cout << endl;
	
	
	return 0;
}