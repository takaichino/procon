#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int w, h,c[50][50],s[50][50],que[2501][2];
	while(1){
		cin >> w >> h;
		if(w==0)break;
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> c[i][j];
				s[i][j] = 0;
			}
		}
		int ans=0;
		
		for(int x=0;x<h;x++){
			for(int y=0;y<w;y++){
				if(s[x][y]==0 && c[x][y]==1){
					int head = 0;
					int tail = 0;
					que[tail][0]=x;
					que[tail][1]=y;
					s[x][y]=1;
					tail++;
					ans++;
					while(head<tail){
						int xn = que[head][0];
						int yn = que[head][1];
						
						if(xn>0 && yn>0 && s[xn-1][yn-1]==0 && c[xn-1][yn-1]==1){
							que[tail][0]=xn-1;
							que[tail][1]=yn-1;
							s[xn-1][yn-1]=1;
							tail++;
						}
						if(yn>0 && s[xn][yn-1]==0 && c[xn][yn-1]==1){
							que[tail][0]=xn;
							que[tail][1]=yn-1;
							s[xn][yn-1]=1;
							tail++;
						}
						if(xn<h-1 && yn>0 && s[xn+1][yn-1]==0 && c[xn+1][yn-1]==1){
							que[tail][0]=xn+1;
							que[tail][1]=yn-1;
							s[xn+1][yn-1]=1;
							tail++;
						}
						if(xn>0 && s[xn-1][yn]==0 && c[xn-1][yn]==1){
							que[tail][0]=xn-1;
							que[tail][1]=yn;
							s[xn-1][yn]=1;
							tail++;
						}
						if(xn<h-1 && s[xn+1][yn]==0 && c[xn+1][yn]==1){
							que[tail][0]=xn+1;
							que[tail][1]=yn;
							s[xn+1][yn]=1;
							tail++;
						}
						if(xn>0 && yn<w-1 && s[xn-1][yn+1]==0 && c[xn-1][yn+1]==1){
							que[tail][0]=xn-1;
							que[tail][1]=yn+1;
							s[xn-1][yn+1]=1;
							tail++;
						}
						if(yn<w-1 && s[xn][yn+1]==0 && c[xn][yn+1]==1){
							que[tail][0]=xn;
							que[tail][1]=yn+1;
							s[xn][yn+1]=1;
							tail++;
						}
						if(xn<h-1 && yn<w-1 && s[xn+1][yn+1]==0 && c[xn+1][yn+1]==1){
							que[tail][0]=xn+1;
							que[tail][1]=yn+1;
							s[xn+1][yn+1]=1;
							tail++;
						}
						head++;
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}