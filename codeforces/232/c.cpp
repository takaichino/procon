#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 999999999

char hoge[1000000000] = {};
vector<int> fuga;

int prime(int v, char hoge[1000000000]){
	if(hoge[v]==1){
		return v;
	}
	else if(hoge[v]==0){
		int w=2;
		while(1){
			if(w*w >v){
				hoge[v] = 1;
				return v;
			}
			else if(v%w!=0){
				w++;
			}
			else{
				hoge[v] = (char)w;
				return w;
			}
		}
	}
	else{
		return (int)hoge[v];
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
	int k, in;
	fuga.push_back(1);
	
	hoge[1]=1;
	hoge[2]=1;
	
	cin >> k;
	for(int i=0;i<k;i++){
		cin >> in;
		
		while(in != 1){
			int x = prime(in,hoge);
			if(x != 1){
				fuga.push_back( x );
			}
			in = in / x;
		}
		
		
	}
	sort(fuga.begin(), fuga.end() );
	int ans =1;
	int z=1;
	for(int y=fuga.size()-1;y>0;y--){
		if(fuga[y-1] != fuga[y]){
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