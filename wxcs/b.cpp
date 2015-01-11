#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int k,ans=1;
	cin >> k;
	while(k>3){
		ans++;
		if(k%3==0){
			k=k/3;
		}
		else if(k%3==1){
			k=(k+2)/3;
		}
		else{
			k=(k+1)/3;
		}
	}
	
	cout << ans << endl;
	return 0;
}