#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define INF 999999999

int main(){
	string in;
	cin >> in;
	int st[2] = {0, 1};
	char now[1];
	
	now[0] = in[0];
	cout << in[0];
	for(int i = 1; i < (int)in.size(); i++){
		if(in[i] == now[0]){
			st[1]++;
			if(st[1] == 3){
				in[i] = '#';
				st[1]--;
			}
			if(st[0] == 2 && st[1] == 2){
				in[i] = '#';
				st[1]--;
			}
		}
		else{
			now[0] = in[i];
			st[0] = st[1];
			st[1] = 1;
		}
		if(in[i] != '#') cout << in[i];
	}
	
	cout << endl;
	return 0;
}