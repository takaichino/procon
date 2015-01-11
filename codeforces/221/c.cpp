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
	
	for(int i= (int)in.size() - 1; i >= 4; i--){
		int phase = 0;
		if(in[i] == '1' && in[0] != '1'){
			swap(in[0], in[i]);
			i++;
			phase = 1;
		}
		else if(in[i] == '6' && in[1] != '6'){
			swap(in[1], in[i]);
			i++;
			phase = 1;
		}
		else if(in[i] == '8' && in[2] != '8'){
			swap(in[2], in[i]);
			i++;
			phase = 1;
		}
		else if(in[i] == '9' && in[3] != '9'){
			swap(in[3], in[i]);
			i++;
			phase = 1;
		}
		
		if(phase == 0){
			mod = ( (in[i] - '0') + 10 * mod) % 7;
		}
	}
	
	int modod = 1;
	for(int j=0; j < age; j++){
		modod = (10 * modod) % 7;
	}
	
	cout << modod << " " << mod << endl;//
	
	
	
	if( (0 * modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '8';
		in[2] = '6';
		in[3] = '9';
	}
	if( (1 * modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '9';
		in[2] = '6';
		in[3] = '8';
	}
	if( (2 * modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '6';
		in[2] = '8';
		in[3] = '9';
	}
	if( (3 * modod + mod) % 7 == 0){
		in[0] = '6';
		in[1] = '1';
		in[2] = '9';
		in[3] = '8';
	}
	if( (4 * modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '6';
		in[2] = '9';
		in[3] = '8';
	}
	if( (5* modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '9';
		in[2] = '8';
		in[3] = '6';
	}
	if( (6 * modod + mod) % 7 == 0){
		in[0] = '1';
		in[1] = '8';
		in[2] = '9';
		in[3] = '6';
	}
	
	for(int y = 0; y < (int)in.size(); y++){
		cout << in[y];
	}
	cout <<endl;
	
	return 0;
}