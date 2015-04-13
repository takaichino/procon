#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

vector<int> a;

void tori(int n, int k, int m){
	if(n > 1){
		//for(int i=0;i<=n;i++)
		//cout << a[i] << " ";
		//cout << endl;
		int z=(m + k - 1) % n;
		if(z == 0) z = n;
		a.erase(a.begin()+z);
		tori(n-1,k,z);
	}
}

int main(){
	int i, j, n, k, m, z;
	while(1){
		cin >> n >> k >> m;
		if(!n)break;
		a.clear();
		for(i=0;i<=n;i++) a.push_back(i);
		a.erase(a.begin()+m);
		tori(n-1, k, m);
		cout << a[1] <<endl;
	}
	return 0;
}