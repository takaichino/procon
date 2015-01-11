#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define INF 9999999

int main(){
	int n, m, a;
	vector<int> b(100000), p(100000);
	cin >> n >> m >> a;
	for(int i = 0; i < n; i++){
		b[i] = 1;
	}
	for(int i = 0; i < m; i++){
		if(i==0)p[i] = 1;
		else p[i] = 400;
	}
	sort(b.begin(), b.begin() + n);
	sort(p.begin(), p.begin() + m);
	
	int head = 0, tail = min(n, m);
	while(head < tail){
		int y = (tail + head + 1) / 2;
		int sup = 0;
		for(int j = 0; j < y; j++){
			if(p[j] > b[n-y+j]){
				sup += p[j] - b[n-y+j];
			}
		}
		if(sup > a){
			tail = y-1;
		}
		else{
			head = y;
		}
	}
	
	int sum = 0;
	if(head > 0){
		for(int k=0; k<head; k++){
			sum += p[k];
		}
	}

	cout << head << " " << max(0, sum-a) << endl;
	
	return 0;
}