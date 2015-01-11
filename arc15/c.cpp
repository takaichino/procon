#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string name[256][2];
	int late[256];
	int N;
	string sta_n[4096][2];
	int sta_l[4096];
	int sta_c[4096];
	int tail=0;
	int head=-1;
	int cnt=0;
	string ans_n[2];
	int ans_l=0;
	
	cin >> N;
	for( int i =0; i<N ; i++)
	{
		cin >> name[i][0] >> late[i] >> name[i][1];
		sta_n[tail][0] = name[i][0];
		sta_n[tail][1] = name[i][1];
		sta_l[tail] = late[i];
		sta_c[tail] = 0;
		/* 
		cout << sta_n[tail][0] << " " << sta_n[tail][1] << " " << sta_l[tail] << endl;
		*/
		tail++;
		head++;
	}
	while(head > -1)
	{
		/*
		cout << sta_n[head][0] << " " << sta_n[head][1] << " " << sta_l[head] << " " << sta_c[head] << " " << ans_l << endl;
		 */
		for(int k=sta_c[head]; k<N; k++)
		{
			if(sta_n[head][1] == name[k][0])
			{
				sta_n[tail][0] = sta_n[head][0];
				sta_n[tail][1] = sta_n[k][1];
				sta_l[tail] = sta_l[head] * late[k];
				sta_c[head] = k+1;
				sta_c[tail] = 0;
				tail++;
				cnt++;
				break;
			}
		}
		if(sta_c[head] == 0 && cnt == 0)
		{
			if(sta_l[head] > ans_l)
			{
				/*
				cout << "attack!" <<endl;
				*/
				ans_l = sta_l[head];
				ans_n[0] = sta_n[head][0];
				ans_n[1] = sta_n[head][1];
			}
			head--;
			tail--;
		}
		else if(cnt == 0)
		{
			head--;
			tail--;
		}
		else
		{
			head = tail-1;
		}
		cnt = 0;
	}
	cout << "1" << ans_n[0] << "=" << ans_l << ans_n[1] << endl;
	return 0;
}