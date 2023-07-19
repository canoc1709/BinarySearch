#include<iostream>
using namespace std;

long long n,k;
long long a[100005];
int max()
{
	long long max = 0;
	for(int i=0; i<n; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}
long long sum()
{
	long long sum = 0;
	for(int i=0; i<n; i++)
		sum += a[i];
	return sum;
}
bool good(long long m)
{
	long long cnt = 1;
	long long sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += a[i];
		if(sum > m)
		{
			sum = a[i];
			cnt++;
		}
	}
	return cnt <= k;
}
int main()
{
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	long long l = max() - 1;
	long long r = sum() + 1;
	while(r > l + 1)
	{
		long long m = (l + r)/2;
		if(good(m))
			r = m;
		else
			l = m;
	}
	cout << r << endl;
}
