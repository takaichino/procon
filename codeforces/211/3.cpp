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
	
	for(int i = 0; i < (int)in.size() - 1 ; i++){
		if(in[i] == in[i + 1]){
			if(i < (int)in.size() - 2 && in[i] == in[i+2]){
				in.erase(i, 1);
				i--;
			}
			else if(i < (int)in.size() - 3 && in[i] == in[i+1] && in[i+2] == in[i+3]){
				in.erase(i + 2, 1);
				i--;
			}
		}
	}
	cout << in <<endl;
	return 0;
}