#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int a[100002], b[100002], c[100002];

int gcd(int a, int b){
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}

int main(){
	int n,ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	b[0] = b[n];
	b[n+1] = b[1];
	for(int j=1;j<=n;j++){
		a[j] = max(b[j-1],b[j]) / gcd( max(b[j-1],b[j]) , min(b[j-1],b[j]) ) * min(b[j-1],b[j]);
	}
	a[0]=a[n];
	a[n+1] = a[1];
	for(int k=1;k<=n;k++){
		c[k] = gcd( max(a[k],a[k+1]) , min(a[k],a[k+1]) );
	}
	c[0] = c[n];
	c[n+1] = c[1];
	
	for(int z=1;z<=n;z++){
		if(b[z] != c[z]) ans++;
		else if(b[z-1] != c[z-1] && b[z+1] != c[z+1]) ans--;
	}
	
	cout << ans << endl;
	return 0;
}