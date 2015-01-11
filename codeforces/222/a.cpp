#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	int a,b;
	cin >> a >> b;
	int w=0,d=0,l=0;
	for(int i = 1; i<6; i++){
		if( abs(a-i) < abs(b-i) ){
			w++;
		}
		if( abs(a-i) == abs(b-i) ){
			d++;
		}
		if( abs(a-i) > abs(b-i) ){
			l++;
		}
	}
	cout << w << " " << d << " " << l << endl;
	
	return 0;
}