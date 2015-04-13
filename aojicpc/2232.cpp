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

char in[30][30], sw[30][30], bo[30][30];
int d, w, h, s;

void tate(){
	REP(a,h){
		for(int i=0;i+s<=w;i++){
			int e = 1;
			for(int j=0;j<s;j++){
				if(bo[a][i]!=bo[a][i+j]||bo[a][i]=='.'){
					e=0;
					break;
				}
			}
			if(e){
				REP(b,s){
					sw[a][i+b]='.';
					d = 1;
				}
			}
		}
	}
}
void yoko(){
	REP(a,w){
		for(int i=0;i+s<=h;i++){
			int e = 1;
			for(int j=0;j<s;j++){
				if(bo[i][a]!=bo[i+j][a]||bo[i][a]=='.'){
					e=0;
					break;
				}
			}
			if(e){
				REP(b,s){
					sw[i+b][a]='.';
					d = 1;
				}
			}
		}
	}
}

int main(){
	int i, j, k, f, e, ch;
	string ans="NO";
	cin >> h >> w >> s;
	REP(a,h) cin >> in[a];
	REP(x,h){
		REP(y,w-1){
			REP(q,h)REP(z,w)bo[q][z] = in[q][z];
			swap(bo[x][y], bo[x][y+1]);
			d=1;
			while(d){
				d=0;
				REP(a,h)REP(b,w)sw[a][b] = '#';
				f=1;
				while(f){
					f=0;
					for(i=1;i<h;i++){
						REP(a,w){
							if(bo[i-1][a]!='.'&&bo[i][a]=='.'){
								swap(bo[i-1][a],bo[i][a]);
								f=1;
							}
						}
					}
				}
				tate();
				yoko();
				//REP(a,h)cout << sw[a] << endl;
				REP(a,h)REP(b,w)if(sw[a][b] == '.') bo[a][b] = '.';
			}
			//cout << x << "," << y << endl;
			//REP(a,h) cout << bo[a] << endl;
			ch = 1;
			REP(a,h)REP(b,w)if(bo[a][b]!='.') ch=0;
			if(ch) ans = "YES";
		}
	}
	cout << ans << endl;
	return 0;
}