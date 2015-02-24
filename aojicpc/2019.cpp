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

int main(){
	long long int ans, i, j, k, n, m, d, p, dis;
	vector<pair<int, int> >mat(10000);
	while(1){
		cin >> n >> m;
		if(!n) break;
		mat.clear();
		dis = 0;
		ans = 0;
		for(i=0;i<n;i++){
			cin >> d >> p;
			mat[i] = make_pair(p, d);
			dis += d;
		}
		sort(mat.begin(), mat.begin()+n);
		dis -= m;
		if(dis <= 0){
			cout << 0 << endl;
			continue;
		}
		int now = 0;
		while(1){
			//cout << dis << " " << ans << " " << mat[now].second << " " << mat[now].first << endl;
			if(mat[now].second <= dis){
				dis -= mat[now].second;
				ans += mat[now].second * mat[now].first;
				now++;
			}
			else{
				ans += dis * mat[now].first;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}