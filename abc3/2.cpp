#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

int main(){
	char in[2][11];
	cin >> in[0] >> in[1];
	int i=0, ans=1;
	while(in[1][i] != '\0' && in[0][i] != '\0'){
		if(in[0][i] != in[1][i]){
			if((in[0][i] == '@') && (in[1][i] == 'a' || in[1][i] == 't' || in[1][i] == 'c' || in[1][i] == 'o' || in[1][i] == 'd' || in[1][i] == 'e' || in[1][i] == 'r') ){
					i++;
			}
			else if((in[1][i] == '@') && (in[0][i] == 'a' || in[0][i] == 't' || in[0][i] == 'c' || in[0][i] == 'o' || in[0][i] == 'd' || in[0][i] == 'e' || in[0][i] == 'r') ){
					i++;
			}
			else {
				ans = 0;
				break;
			}
		}
		else i++;
	}
	if(ans == 1) cout << "You can win" << endl;
	else cout << "You will lose" << endl;
	
	return 0;
}