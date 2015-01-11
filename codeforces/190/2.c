#include<stdio.h>

int main(){
	unsigned int r, g, b, i, pet, least, kate, most=0, ans=0;
	scanf("%d %d %d", &r, &g, &b);
	least = r;
	if(least > g) least = g;
	if(least > b) least = b;
	if(least >=3)
	{
		pet = 3;
		ans = least - 3;
	}
	else pet = least;
	for(i=0;i<=pet;i++)
	{
		kate = i;
		kate += (r-ans-i)/3;
		kate += (g-ans-i)/3;
		kate += (b-ans-i)/3;
		if(kate > most) most = kate;
	}
	ans += most;
	printf("%d\n", ans);
	return 0;
}