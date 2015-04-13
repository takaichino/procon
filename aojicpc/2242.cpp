#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define INF 999999999

struct ye{
	string ge;
	long long int nu, ad;
	
	bool operator<(const ye& a) const{
		if(ad != a.ad) return ad < a.ad;
	}
};

int main(){
	long long int i, j, n ,q, x;
	ye ans;
	ye s;
	vector<ye> a;
	while(1){
		cin >> n >> q;
		if(!n) break;
		a.clear();
		for(i=0;i<n;i++){
			cin >> s.ge >> s.nu >> s.ad;
			a.push_back(s);
		}
		sort(a.begin(),a.end());
		/*for(i=0;i<a.size();i++){
			cout << a[i].ad << " ";
		}
		cout << endl;*/
		
		for(i=0;i<q;i++){
			cin >> x;
			int z = 0;
			for(j=a.size()-1;j>=0;j--){
				if(x <= a[j].ad){
					if(a[j].nu - (a[j].ad - x) > 0){
						ans.ad=x;
						ans.nu=a[j].nu - (a[j].ad - x);
						ans.ge=a[j].ge;
						z++;
					}
				}
			}
			if(z==1) cout << ans.ge << " " << ans.nu << endl;
			else cout << "Unknown" << endl;
		}
	}
	return 0;
}