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

int no(char x){
	if(x=='A') return 14;
	else if(x=='T') return 10;
	else if(x=='J') return 11;
	else if(x=='Q') return 12;
	else if(x=='K') return 13;
	else return x-'0';
}

int main(){
	int i, j;
	//??? ans;
	int l, ns, ew, num;
	string play[4][13];
	char t, s, now;
	while(1){
		cin >> t;
		if(t == '#') break;
		l = 0;
		ns = 0;
		ew=0;
		REP(i,4)REP(j,13) cin >> play[i][j];
		REP(j,13){
			s = play[l][j][1];
			now = s;
			num = no(play[l][j][0]);
			REP(i,4){
				if(now!=t&&play[i][j][1]==t){
					now = t;
					num = no(play[i][j][0]);
					l = i;
				}
				if(play[i][j][1]==now && no(play[i][j][0])>num){
					num = no(play[i][j][0]);
					l = i;
				}
			}
			if(l==0||l==2)ns++;
			else ew++;
		}
		if(ew>ns)cout << "EW " << ew-6 << endl;
		else cout << "NS " << ns-6 << endl;
	}
	return 0;
}