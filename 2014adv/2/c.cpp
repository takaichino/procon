#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int in[1001][1001], sum[1001][1001];
char sen[1001];

int main(){
	int n;
	while(cin >> n,n){
		memset(sum, 0, sizeof(sum) );
		
		for(int i=1; i<=n;i++){
			cin >> sen;
			for(int j=1; j<=n; j++){
				if(sen[j-1] == '.')in[i][j]=0;
				else if(sen[j-1] == '*')in[i][j]=1;
			}
		}
		for(int x=1; x<=n; x++){
			for(int y=1; y<=n; y++){
				sum[x][y] = sum[x][y-1] + in[x][y];
			}
		}
		for(int a=1; a<=n; a++){
			for(int b=1; b<=n; b++){
				sum[b][a] += sum[b-1][a];
			}
		}
		
		
		int head = 0;
		int tail = n;
		int now = 0;
		int poyo;
		
		while(head<tail){
			now = (head + tail + 1) / 2;
			for(int c=1; c+now-1<=n; c++){
				for(int d=1; d+now-1<=n; d++){
					poyo = sum[c+now-1][d+now-1] - sum[c-1][d+now-1] - sum[c+now-1][d-1] + sum[c-1][d-1];
					if(poyo == 0){
						head = now;
						break;
					}
				}
				if(poyo == 0) break;
			}
			if(poyo > 0) tail = now - 1;
		}
		
		cout << tail << endl;
	}
	
	return 0;
}