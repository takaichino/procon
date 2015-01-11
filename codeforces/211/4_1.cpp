#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define INF 9999999

int main(){
	int n, m, t, a;
	vector<int> b, p;
	cin >> n >> m >> a;
	for(int i = 0; i < n; i++){
		cin >> t;
		b.push_back( t );
	}
	for(int i = 0; i < m; i++){
		cin >> t;
		p.push_back( t );
	}
	sort(b.begin(), b.end());
	sort(p.begin(), p.end());
	
	int head = 1;
	while(head <= min(m, n)){
		int sup = 0;
		for(int j = 0; j < head; j++){
			if(p[j] > b[n-head+j]){
				sup += p[j] - b[n-head+j];
			}
		}
		if(sup > a){
			break;
		}
		else{
			head++;
		}
	}
	
	int sum = 0;
	if(head-1 > 0){
		for(int k=0; k<head-1; k++){
			sum += p[k];
		}
	}
	
	cout << head-1 << " " << max(0, sum-a) << endl;
	
	return 0;
}