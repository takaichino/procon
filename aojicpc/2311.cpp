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

vector<string> bo(10);
int f;

void cookie(int t){
	int d[8][2]={{-1,-1},{-1,0},{-1,1},
		{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	int x=9, y=9, ma=0, nx, ny, ins, sum, i ,j;
	string co="ox";
	for(int ii=1;ii<=8;ii++){
		if(t==0) i = ii;
		else i = 9 - ii;
		for(int jj=1;jj<=8;jj++){
			if(t==0) j = jj;
			else j = 9 - jj;
			sum = 0;
			if(bo[i][j]=='.'){
				REP(a,8){
					ins = 0;
					nx = i;
					ny = j;
					while(bo[nx+d[a][0]][ny+d[a][1]]==co[1-t]){
						ins++;
						nx += d[a][0];
						ny += d[a][1];
					}
					//cout << nx <<"=" << ny <<endl ;
					if(ins && bo[nx+d[a][0]][ny+d[a][1]]==co[t]) sum += ins;
				}
				if(ma < sum){
					x = i;
					y = j;
					ma = sum;
				}
				//cout << ma << endl;
			}
		}
	}
	if(ma){
		f++;
		//cout << co[t] << ":" << x << "," << y << endl;
		REP(a,8){
			bo[x][y] = co[t];
			nx = x;
			ny = y;
			while(bo[nx+d[a][0]][ny+d[a][1]]==co[1-t]){
				nx += d[a][0];
				ny += d[a][1];
			}
			if(bo[nx+d[a][0]][ny+d[a][1]] == co[t]){
				while(nx!=x||ny!=y){
					bo[nx][ny] = co[t];
					nx -= d[a][0];
					ny -= d[a][1];
				}
			}
		}
	}
}

int main(){
	int i, j;
	string ins;
	REP(a,8){
		cin >> ins;
		bo[a+1] = "z" + ins + "z";
	}
	bo[0] = "zzzzzzzzzz";
	bo[9] = "zzzzzzzzzz";
	f = 1;
	while(f>0){
		f = 0;
		//mami
		cookie(0);
		//charl
		cookie(1);
	}
	//cout << "ok" << endl;
	REP(a,8) cout << bo[a+1].substr(1,8) << endl;
	return 0;
}