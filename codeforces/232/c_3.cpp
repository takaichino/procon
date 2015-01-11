#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

#define INF 999999999

vector<int> fuga;
vector<int> prime;

void sosu(int v){	//vˆÈ‰º‚Ì‘f”—ñ‚ğ¶¬‚·‚é
	prime.push_back( 2 );
	for(int i=3; i<=v;i++){
		int hunt =0;
		for(int j=0;prime[j]*prime[j]<=i;j++){
			if(i % prime[j] == 0){
				hunt = 1;
				break;
			}
		}
		if(hunt == 0){
			prime.push_back(i);
		}
	}
}

void hoge(int w){	//w‚ğ‘fˆö”•ª‰ğ‚·‚é
	if(w>1){
		for(int k = 0; k<(int)prime.size(); k++){
			if(w % prime[k] == 0){
				fuga.push_back( prime[k] );
				hoge(w / prime[k]);
				break;
			}
		}
	}
}

int poyo(int z, int k){
	if(z==1){
		return k % 1000000007;
	}
	else if(k==1){
		return 1;
	}
	else{
		return ( poyo(z-1,k) + poyo(z, k-1)) % 1000000007;
	}
}

int main(){
	int k, ci;
	vector<int> in;
	fuga.push_back(1);
	
	cin >> k;
	for(int i=0;i<k;i++){
		cin >> ci;
		in.push_back( ci );
	}
	sort(in.begin(), in.end(), greater<int>() );
	sosu(in[0]);
	for(int j=0; j<(int)in.size(); j++){
		hoge(in[j]);
	}
	sort(fuga.begin(), fuga.end());
	
	int ans =1;
	int z=1;
	for(int y=(int)fuga.size()-1;y>0;y--){
		if(fuga[y-1] != fuga[y]){
			/*
			cout << fuga[y] << z << endl;
			*/
			ans = (ans * poyo(z,k) ) % 1000000007;
			z=1;
		}
		else{
			z++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}