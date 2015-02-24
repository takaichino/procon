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

struct yoko{
	int h, p, q;
	
	bool operator<(const yoko& a) const{
		return h > a.h;
	}
};

int main(){
	int ans, i, j, k, n, m, a;
	vector<yoko> mat(1000);
	while(1){
		cin >> n >> m >> a;
		if(!n) break;
		mat.clear();
		ans = a;
		for(i=0; i<m; i++){
			cin >> mat[i].h >> mat[i].p >> mat[i].q;
		}
		sort(mat.begin(), mat.begin()+m);
		for(j=0; j<m; j++){
			//cout << mat[j].h << " " << mat[j].p << " " << mat[j].q << endl;
			if(ans == mat[j].p){
				ans = mat[j].q;
			}
			else if(ans == mat[j].q){
				ans = mat[j].p;
			}
			//cout << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}