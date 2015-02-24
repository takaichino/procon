#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int i, j, n, m, k, v;
	bool know[101][101], l[101];
	int ans, sus;
	while(1){
		cin >> n;
		if(!n) break;
		ans = -1;
		sus = 0;
		for(i=0;i<=100;i++){
			l[i] = false;
			for(j=0;j<=100;j++){
				know[i][j]=false;
			}
		}
		for(i=1;i<=n;i++){
			cin >> m;
			for(j=0;j<m;j++){
				cin >> v;
				know[i][v] = true;
			}
		}
		cin >> k;
		for(i=0;i<k;i++){
			cin >> v;
			l[v] = true;
		}
		for(i=1;i<=n;i++){
			bool white = false;
			for(j=1;j<=n;j++){
				if(l[j] && !know[i][j]){
					white = true;
					break;
				}
			}
			if(!white){
				if(!sus){
					ans = i;
					sus++;
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}