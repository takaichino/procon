#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

#define INF 999999999
#define REP(i,n) for(int i=0; i<(int)(n); i++)

vector<string> donut(10);
vector<string> lis(200);

int main(){
	int i, j, w, h;
	int d[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	string ans, ins;
	while(1){
		cin >> h >> w;
		if(!h) break;
		ans="0";
		lis.clear();
		donut.clear();
		REP(a,h){
			cin >> ins;
			donut.push_back(ins);
		}
		/*REP(a,h){
			cout << donut[a] << endl;
		}*/
		REP(a,h){
			REP(b,w){
				REP(c,8){
					//cout << a << "," << b << ":" << donut[a][b] << endl;
					ins = donut[a][b];
					//cout << ins << endl;
					int x = a+d[c][0], y = b+d[c][1];
					if(x<0) x = h-1;
					if(x>h-1) x = 0;
					if(y<0) y = w-1;
					if(y>w-1) y = 0;
					while(x!=a||y!=b){
						//cout<<a<<","<<b<<"("<<c<<"):"<<x<<","<<y<<"->";
						//cout<<donut[y][x]<<endl;
						ins += donut[x][y];
						x = x+d[c][0];
						y = y+d[c][1];
						if(x<0) x = h-1;
						if(x>h-1) x = 0;
						if(y<0) y = w-1;
						if(y>w-1) y = 0;
					}
					lis.push_back(ins);
				}
			}
		}
		//REP(a,lis.size()) cout << lis[a] << endl;
		REP(a,lis.size()){
			for(i=a+1;i<lis.size();i++){
				if(lis[a][0]==lis[i][0]){
					//cout << a << "-" << i << endl;
					for(j=max(2,(int)ans.size());j<=min(lis[a].size(),lis[i].size());j++){
						if(lis[a].substr(0,j)==lis[i].substr(0,j)){
							ins = lis[a].substr(0,j);
							if(ins.size() > ans.size()) ans = ins;
							else if(ins.size()==ans.size()&&ins < ans) ans = ins;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}