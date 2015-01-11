
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int n, x, y, ans=0, flag=0;
	cin >> n;
	for(int i= 0; i<n; i++){
		cin >> y;
		if(i==0){}
		else if(flag == 0){
			if(x > y) flag = 1;
			else if(x < y) flag = -1;
		}
		else if(i>1){
			if(flag == 1 && x < y){
				flag = -1;
				ans++;
			}
			else if(flag == -1 && x > y){
				flag = 1;
				ans++;
			}
		}
		x = y;
	}
	if(ans > 0) ans +=2;
	cout << ans << endl;
		
	return 0;
}