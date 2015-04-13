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

struct nu{
	int x, y; string s;
};

vector<string> in(72);
string ans;
stack< nu > q;

void search(nu v){
	cout << v.x <<"~"<< v.y << "~" << ans << "~" << q.size() << endl;
	nu ins;
	int fla =0;
	q.pop();
	if(in[v.x+1][v.y]-'0'>=0&&in[v.x+1][v.y]-'0'<=9){
		fla++;
		ins.s = v.s + in[v.x+1][v.y];
		ins.x = v.x+1;
		ins.y = v.y;
		q.push(ins);
	}
	if(in[v.x][v.y+1]-'0'>=0&&in[v.x][v.y+1]-'0'<=9){
		fla ++;
		ins.s = v.s + in[v.x][v.y +1];
		ins.x = v.x;
		ins.y = v.y+1;
		q.push(ins);
	}
	if(!fla){
		if(v.s.size() > ans.size()) ans = v.s;
		else if(v.s.size() == ans.size()){
			REP(a, v.s.size()){
				if(v.s[a] > ans[a]) ans = v.s;
				else if(v.s[a] < ans[a]) break;
			}
		}
	}
	if(!q.empty()) search(q.top());
}

int main(){
	int i, j, w, h;
	string p;
	while(1){
		cin >> w >> h;
		if(!w) break;
		REP(a,h){
			cin >> in[a+1];
			in[a+1].insert(in[a+1].begin(),'A');
			in[a+1].insert(in[a+1].end(),'A');
		}
		in[h+1] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		in[0] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		ans = "0";
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				if((in[i-1][j]-'0'<1||in[i-1][j]-'0'>9)&&(in[i][j-1]-'0'<1||in[i][j-1]-'0'>9)&&(in[i][j]-'0'>=1&&in[i][j]-'0'<=9)){
					nu v;
					v.x = i;
					v.y = j;
					v.s = in[i][j];
					q.push(v);
					search(v);
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}