#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 9999999999


int gcd( int x, int y){
	if(x<y)swap(x,y);
	if(x%y == 0){
		return y;
	}
	else
	{
		return gcd(y, x%y);
	}
}

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
			ans = ans * (i - 1) / i;
		}
	}
	
	cout << "1: " << ans << endl;
	
	int anan = 0;
	
	for(int j=1; j <= n; j++){
		if(gcd(j, n) == 1){
			anan++;
		}
	}
	
	cout << "2: " <<ans << endl;
	
	return 0;
}