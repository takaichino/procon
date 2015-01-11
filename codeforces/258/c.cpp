#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int main(){
	long long int t, n, k, a, b, v, w;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n >> k >> a >> b;
		v = k-(a+a+b);
		w = (n-k)-(a+b);
		if(v>=0 && v%3==0 && w>=0 && w%3==0){
			cout << "yes" << endl;
			continue;
		}
		if(a>b) v = k-(a+a-b);
		else v= k-(b+b-a);
		w = (n-k)-(a+b);
		if(v>=0 && v%3==0 && w>=0 && w%3==0){
			cout << "yes" << endl;
			continue;
		}
		v = k-(a+b);
		w = (n-k)-(a+abs(b-a));
		if(v>=0 && v%3==0 && w>=0 && w%3==0){
			cout << "yes" << endl;
			continue;
		}
		v = k-(a+b+b);
		w = (n-k)-(a+b);
		if(v>=0 && v%3==0 && w>=0 && w%3==0){
			cout << "yes" << endl;
			continue;
		}
		cout << "no" << endl;
	}
	return 0;
}