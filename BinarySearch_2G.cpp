#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long k,n;
long long a[51];

bool good(long long mid)
{
	long long cnt = 0;
	for(int i=1; i<=n; i++)
	{
		cnt += min(a[i], mid);
	}
		
	return cnt >= mid*k; // tong so hoc sinh co the vao mid hoi dong voi mid nhat dinh
}
int main()
{
	cin >> k >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
		
	long long l = 1; // l is good 
	long long r = 26 * 1e9; //r is bad, gia tri ma chac chan khong the tao duoc "r" council
	while(r > l + 1)
	{
		long long m = (l + r)/2;
		if(good(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;
		
}
