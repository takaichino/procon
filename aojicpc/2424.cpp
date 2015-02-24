#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int i, j, q, n;
	int ans;
	
	cin >> q; 
	for(i=0;i<q;i++){
		ans = 0;
		cin >> n;
		while(n>=10){
			ans++;
			int mo=0;
			//cout << n << endl;
			for(j=1;n/pow(10,j)>0;j++){
				if(mo<(n/(int)pow(10,j))*(n%(int)(pow(10,j)))){
					mo = (n/(int)pow(10,j))*(n%(int)(pow(10,j)));
				}
			}
			n = mo;
		}
		cout << ans << endl;
	}
	return 0;
}