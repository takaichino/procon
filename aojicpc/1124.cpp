#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int ans, n, q, po[101], ins, i,j, m;
	
	while(1){
		cin >> n >> q;
		if(!n) break;
		for(i=0; i<=100; i++) po[i] = 0;
		ans = 0;
		for(i=0; i<n; i++){
			cin >> m;
			for(j=0; j<m; j++){
				cin >> ins;
				po[ins]++;
			}
		}
		ans = 0;
		for(i=1;i<=100;i++){
			if(po[i] >= q && po[i] > po[ans]){
				ans = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}