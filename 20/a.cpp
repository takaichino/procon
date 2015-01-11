#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 99999999

int main(){
	char input[301];
	int kupc[4] = {0,0,0,0} , ans = INF;
	
	cin >> input;
	
	int i = 0;
	while(1){
		if(input[i] == '\0'){
			break;
		}
		if(input[i] == 'K'){
			kupc[0]++;
		}
		if(input[i] == 'U'){
			kupc[1]++;
		}
		if(input[i] == 'P'){
			kupc[2]++;
		}
		if(input[i] == 'C'){
			kupc[3]++;
		}
		i++;
	}
	for(int j = 0; j<4; j++){
		if(ans > kupc[j]){
			ans = kupc[j];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}