#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 9999999999

int main(){
	int n, ans;
	cin >> n;
	
	ans = n;
	int x = n;
	
	for(int i=2; i <= n; i++){
		if(x % i==0){
			while(x % i == 0){
				x = x / i;
			}
			ans = ans / i * (i - 1) ;
		}
		if(x==1)break;
	}
	
	cout << ans << endl;
	
	return 0;
}