#include<stdio.h>

int main(){
	int n, y, m, d, ans=0;
	int i, eto, mody, sho, modm;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d", &y, &m, &d);
		eto = (y - 1) / 3;
		mody = (y - 1) % 3;
		ans += eto * 590;
		ans += mody * 195;
		if(y%3 == 0)
		{
			ans += (m-1) * 20 + d;
		}
		else
		{
			sho = (m-1) / 2;
			modm = (m-1) % 2;
			ans += sho * 39;
			ans += modm * 20;
			ans += d;
		}
		printf("%d\n", 196471-ans);
		ans = 0;
	}
	return 0;
}