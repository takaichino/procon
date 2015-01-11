#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N;
	double max, min;
	int ans[6]={0,0,0,0,0,0};
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> max >> min;
		if(max >= 35.0) ans[0]++;
		if(max >= 30.0 && max < 35.0) ans[1]++;
		if(max >= 25.0 && max < 30.0) ans[2]++;
		if(min >= 25.0) ans[3]++;
		if(min < 0.0 && max >= 0.0) ans[4]++;
		if(max < 0.0) ans[5]++;
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << endl;
	return 0;
}