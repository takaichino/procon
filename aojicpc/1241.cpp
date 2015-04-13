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

int main(){
	int n;
	int ans;
	
	while(1){
		cin >> n;
		if(!n) break;
		ans = 0;
		for(int i=0;i*i<=n;i++){
			for(int j=i;i*i+j*j<=n;j++){
				for(int k=j;i*i+j*j+k*k<=n;k++){
					for(int m=k;i*i+j*j+k*k+m*m<=n;m++){
						if(i*i+j*j+k*k+m*m==n) ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}