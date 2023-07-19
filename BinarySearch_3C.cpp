#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[10005];
long long mindistance()
{
	long long min = -1;
	for(int i=1; i<n; i++)
		if(a[i] - a[i-1] < min)
			min = a[i] - a[i-1];
	return min;
}
bool good(int mid)
{
	long long cnt = 1;
	long long first = a[0];
	for(int i=1; i<n; i++)
	{
		if(a[i] - first >= mid)
		{
			cnt++;
			first = a[i];
		}
	}
	return cnt >= k;
	
}
int main()
{
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	long long l = mindistance() - 1;
	long long r = a[n-1] - a[0] + 1;
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
