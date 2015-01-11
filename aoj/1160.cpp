#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>

using namespace std;

#define INF 999999999

int ch[52][52], in[52][52];
void dfs(int ma[52][52], int x, int y, int fl[52][52]){
	fl[x][y]=1;
	if(ma[x-1][y+0]&&!fl[x-1][y+0]) dfs(ma, x-1, y+0, fl);
	if(ma[x-1][y-1]&&!fl[x-1][y-1]) dfs(ma, x-1, y-1, fl);
	if(ma[x+0][y-1]&&!fl[x+0][y-1]) dfs(ma, x+0, y-1, fl);
	if(ma[x+1][y-1]&&!fl[x+1][y-1]) dfs(ma, x+1, y-1, fl);
	if(ma[x+1][y+0]&&!fl[x+1][y+0]) dfs(ma, x+1, y+0, fl);
	if(ma[x+1][y+1]&&!fl[x+1][y+1]) dfs(ma, x+1, y+1, fl);
	if(ma[x+0][y+1]&&!fl[x+0][y+1]) dfs(ma, x+0, y+1, fl);
	if(ma[x-1][y+1]&&!fl[x-1][y+1]) dfs(ma, x-1, y+1, fl);
}

int main(){
	int w,h,i,j,ans;
	while(1){
		ans = 0;
		cin >> w >> h;
		if(!w) break;
		for(i=0;i<=h+1;i++){
			for(j=0;j<=w+1;j++){
				if(i==0||j==0||i==h+1||j==w+1){
					in[i][j] = 0;
					ch[i][j] = 0;
				}
				else{
					cin >> in[i][j];
					ch[i][j] = 0;
				}
			}
		}
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				if(in[i][j]&&!ch[i][j]){
					dfs(in, i, j, ch);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}