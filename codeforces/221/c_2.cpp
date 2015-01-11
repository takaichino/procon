#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define INF 999999999

int main(){
	string in;
	
	cin >> in;
		
	int age = (int)in.size() - 4;
	int mod = 0;
	int haihan[4] = {};
	
	for(int i = 0; i < (int)in.size(); i++){
		if(in[i] == '1' && haihan[0] == 0){
			haihan[0]++;
			in[i] = '#';
		}
		else if(in[i] == '6' && haihan[1] == 0){
			haihan[1]++;
			in[i] = '#';
		}
		else if(in[i] == '8' && haihan[2] == 0){
			haihan[2]++;
			in[i] = '#';
		}
		else if(in[i] == '9' && haihan[3] == 0){
			haihan[3]++;
			in[i] = '#';
		}
		else{
			mod = ( (in[i] - '0') + 10 * mod) % 7;
		}
	}
	
	int modod = 1;
	for(int j=0; j < age; j++){
		modod = (10 * modod) % 7;
	}
	
	if( (0 * modod + mod) % 7 == 0){
		cout << "1869";
	}
	if( (1 * modod + mod) % 7 == 0){
		cout << "1968";
	}
	if( (2 * modod + mod) % 7 == 0){
		cout << "1689";
	}
	if( (3 * modod + mod) % 7 == 0){
		cout << "6198";
	}
	if( (4 * modod + mod) % 7 == 0){
		cout << "1698";
	}
	if( (5* modod + mod) % 7 == 0){
		cout << "1986";
	}
	if( (6 * modod + mod) % 7 == 0){
		cout << "1896";
	}
	
	for(int y = 0; y < (int)in.size(); y++){
		if(in[y] != '#'){
			cout << in[y];
		}
	}
	cout <<endl;
	
	return 0;
}