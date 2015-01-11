#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

short int ans[1000000] ={};

int main(){
	int p, x;
	cin >> p >> x;
	int hikae, ten=0, sikato,ichi;
	
	for(ichi = x; ichi <=9; ichi++){
		ten = 0;
		ans[p-1] = ichi;
		sikato = (ans[p-1] - ( ans[p-1] % x) ) / x;
		
		/*
		cout << sikato << " " << ichi << endl;
		*/
		
		for(int a = p-1; a > 0; a--){
			hikae = ans[a] * x + ten;
			ans[a-1] = hikae % 10;
			ten = (hikae - ans[a-1]) / 10;
		}
		/*
		for(int z = 0; z < p; z++){
			cout << ans[z];
		}
		cout << endl;
		*/
		if(ans[0] == sikato && ans[0] * x + ten == ans[p-1]){
			for(int z = 0; z < p; z++){
				cout << ans[z];
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << "Impossible" <<endl;
	return 0;
}