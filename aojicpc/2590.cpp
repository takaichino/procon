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
	int n, m, q;
	string s;
	vector <string> b(2);
	bool ans[36][1000];
	while(1){
		cin >> n >> m >> q;
		if(!n) break;
		b[1]= "";
		REP(i,m)b[1] = b[1] + "0";
		REP(i,n){
			REP(j,m){
				ans[i][j]=1;
			}
		}
		//cout << b[1] <<endl;
		REP(i,q){
			cin >> s >> b[0];
			REP(j,n){
				if(s[j]=='1'){
					REP(k,m){
						if(b[0][k]==b[1][k]) ans[j][k]=0;
					}
				}
				else if(s[j]=='0'){
					REP(k,m){
						if(b[0][k]!=b[1][k]) ans[j][k]=0;
					}
				}
			}
			/*
			REP(j,n){
				REP(k,m) cout << ans[j][k];
				cout << endl;
			}
			*/
			b[1] = b[0];
		}
		REP(i,m){
			int flag=0;
			REP(j,n){
				if(ans[j][i]){
					if(!flag)flag = j+1;
					else{
						flag = -1;
						break;
					}
				}
			}
			if(flag>=1&&flag<=10) cout << flag-1;
			else if(flag==-1) cout << "?";
			else printf("%c",'A'+flag-11);
		}
		cout << endl;
	}
	return 0;
}