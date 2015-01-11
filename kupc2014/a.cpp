#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	int a[3], b[3],ch,ans =INF;
	for(int i =0 ; i<3;i++)cin >> a[i];
	for(int j =0 ; j<3;j++)cin >> b[j];
	
	ch = abs(a[0]-b[0]) + abs(a[1]-b[1]) + abs(a[2]-b[2]);
	if(ans > ch) ans = ch;
	ch = abs(a[0]-b[0]) + abs(a[1]-b[2]) + abs(a[2]-b[1]);
	if(ans > ch) ans = ch;
	ch = abs(a[0]-b[1]) + abs(a[1]-b[2]) + abs(a[2]-b[0]);
	if(ans > ch) ans = ch;
	ch = abs(a[0]-b[1]) + abs(a[1]-b[0]) + abs(a[2]-b[2]);
	if(ans > ch) ans = ch;
	ch = abs(a[0]-b[2]) + abs(a[1]-b[0]) + abs(a[2]-b[1]);
	if(ans > ch) ans = ch;
	ch = abs(a[0]-b[2]) + abs(a[1]-b[1]) + abs(a[2]-b[0]);
	if(ans > ch) ans = ch;
	
	cout << ans << endl;
	
	return 0;
}