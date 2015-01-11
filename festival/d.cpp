#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define INF 999999999

int a[100000];

class RMQ{//by http://taku-k.hatenablog.com/entry/2014/01/09/040348
	private:
	static const int MAX_N = 1 << 17;
	int n, dat[2*MAX_N -1];
	//[a,b)の最小値を返す
	//kは節点の番号l,rはその節点が[l,r)を保持している
	int rec(int a,int b,int k,int l,int r){
		if(b <= l || r <= a){
			return INF;
		}
		
		if(a<=l && r<=b){
			return dat[k];
		}else{
			int rl = rec(a,b,2*k+1,l,(l+r)/2);
			int rr = rec(a,b,2*k+2,(l+r)/2,r);
			return min(rl,rr);
		}
	}
	
	public:
	void init(int n_){
		n=1;
		while(n < n_) n*=2;
		
		for(int i=0;i<2*n-1;i++){
			dat[i] = INF;
		}
	}
	
	//kをaに変更
	void update(int k, int a){
		int reaf = k+n-1;
		dat[reaf]=a;
		while(reaf>0){
			reaf = (reaf-1)/2;
			dat[reaf]=min(dat[reaf*2+1],dat[2*reaf+2]);
		}
	}

    //query[a,b]の範囲内の最小値を返す
    int query(int a,int b){
    	return rec(a,b+1,0,0,n);
    }
};

int main(){
	int n, ans;
	cin >> n;
	
	RMQ r;
	r.init(n);
	for(int j=0;j<n;j++){
		cin >> a[j];
		r.update(j,-a[j]);
	}
	
	for(int x=0;x<n;x++){
		int head = 0,tail = x,now;
		ans = 0;
		while(head != tail && x > 0){
			now = (head + tail)/2;
			//cout << x << "-L:" << head << " " << tail << " " << now << " " << r.query(now,x) << endl;//
			if(r.query(now,x)>=-a[x])tail=now;
			else head=now+1;
		}
		ans += x - head;
		
		head = x,tail = n-1;
		while(head != tail && x < n-1){
			now = (head + tail+1)/2;
			//cout << x << "-R:" << head << " " << tail << " " << now << " " << r.query(x,now) << endl;//
			if(r.query(x,now)>=-a[x])head=now;
			else tail=now-1;
		}
		ans += head - x;
		cout << ans << endl;
	}
	
	return 0;
}
