#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int who[200000], room[200000], yaba[200000]={}, yabap[200000] = {};
double ex[200000];

int main(){
	int n, k, max = 0, min = 0, write=1,r=0;
	string s;
	cin >> n >> k >> s;
	if(k>1){
		for(int i=0;i<n;i++){
			if(s[i] =='1'){
				who[i] = max;
				room[0]++;
				max++;
			}
			else{
				who[i] = min;
				if(write==1 && room[0] ==room[1]){
					room[0]++;
					yabap[max]=1;
					max++;
					write = 0;
					yaba[i]=1;
				}
				else if(k>1){
					room[write]++;
				}
				
				if(write == k-1){
					write = 1;
					min++;
				}
				else	write++;
			}
		}
		
		for(int z=0; z<n;z++){
			cout << who[z] << endl;
		}
		for(int y=0; y<k;y++){
			cout << room[y] << endl;
		}
		
		for(int p=0;p <max;p++){
			ex[p]=0.0;
			
			for(int v=0;room[v] >= p+1;v++){
				ex[p] += (double)room[v];
				r = v+1;
			}
			ex[p] = ex[p] / (double)r;
		}
		for(int w=0;w<n;w++){
			if(yaba[w]==0)printf("%.8f\n", ex[ who[w] ]);
			else cout << max << endl;
		}
	}
	else {
		for(int x=0; x<n;x++){
			cout << n << endl;
		}
	}
	return 0;
}