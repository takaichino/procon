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
		cin >> b[i];
	}
	for(int i = 0; i < m; i++){
		cin >> p[i];
	}
	sort(b.begin(), b.begin() + n);
	sort(p.begin(), p.begin() + m);
	
	int head = 0, tail = min(n, m);
	while(head < tail){
		int y = (tail + head + 1) / 2;
		long long int sup = 0;
		for(int j = 0; j < y; j++){
			if(p[j] > b[n-y+j]){
				sup += (long long int)p[j] - (long long int)b[n-y+j];
			}
		}
		if(sup > (long long int)a){
			tail = y - 1;
		}
		else{
			head = y;
		}
	}
	
	long long int sum = 0;
	if(head > 0){
		for(int k=0; k<head; k++){
			sum += (long long int)p[k];
		}
	}

	cout << head << " " << max((long long int)0, sum-(long long int)a) << endl;
	
	return 0;
}