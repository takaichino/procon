#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int n=2,k,m;
	int ans;
	int state[10001]={};
	while(1){
		cin >> n >> k >> m;
		
		if(n==0){
			break;
		}
		state[0]=1;
		for(int v=1;v<=10000;v++){
			state[v]=0;
		}
		
		int now = m;
		for(int i=0; i<n-1;i++){
			/*
			cout << "removed " << now << endl;
			*/
			state[now]=1;
			
			for(int r=0; r<k; r++){
				if(now==n){
					now=1;
				}
				else{
					now++;
				}
				while(state[now] != 0){
					if(now==n){
						now=1;
					}
					else{
						now++;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(state[j] == 0){
				ans = j;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}