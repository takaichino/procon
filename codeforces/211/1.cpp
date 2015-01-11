#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 9999999999

int main(){
	int in;
	int r, v;
	cin >> in;
	if(in==0){
		cout << "O-|-OOOO" << endl;
	}
	else{
		while(in > 0){
			r = in % 10;
			v = in % 5;
			if(r >= 5 )cout << "-O|";
			else cout << "O-|";
			if(v == 0 )cout << "-OOOO" << endl;
			if(v == 1 )cout << "O-OOO" << endl;
			if(v == 2 )cout << "OO-OO" << endl;
			if(v == 3 )cout << "OOO-O" << endl;
			if(v == 4 )cout << "OOOO-" << endl;
			in = in /10;
		}
	}
	return 0;
}