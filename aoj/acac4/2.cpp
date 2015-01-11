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
	int n, ans=0;
	cin >> n;
	
	for(int i=1; i <= n; i++){
		if(gcd(i, n) == 1){
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}