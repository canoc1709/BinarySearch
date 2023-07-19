#include<iostream>
using namespace std;
#define maxn 100005
int n,d;
int a[maxn];
double kq;
int Left,Right;
bool CanFind(int r, double mid)
{
	double prefix[maxn];
	prefix[1] = a[1] - mid;
	for(int i=2; i<=n; i++)
		prefix[i] = a[i] - mid + prefix[i-1];
		
	double minPre = 99999;
	for(int i=1; i <= r-d; i++)
		if(prefix[i] < minPre)
			minPre = prefix[i];
	return minPre <= prefix[r];
}
bool good(double mid)
{
	bool ok = false;
	for(int i=n; i>=d; i--)
		if(CanFind(i,mid))
		{
			Right = i;
			kq = mid;
			ok = true;
		}
	return ok == true;
	
}
double tbc(int l, int r)
{
	double sum = 0;
	for(int i=l; i<=r; i++)
		sum += a[i];
	return sum / ( r - l + 1);
}
int main()
{
	cin >> n >> d;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	if(n == d)
		cout << 1 << " " << n << endl;
	else
	{
		double l = 0;
		double r = 1e9;
		for(int i=0; i<100; i++)
		{
			double m = (l + r)/2;
			if(good(m))
				l = m;
			else
				r = m;
		}
		double prefix[maxn];
		prefix[1] = a[1] - kq;
		for(int i=2; i<=n; i++)
			prefix[i] = a[i] - kq + prefix[i-1];
		prefix[0] = 0;
			
		for(int i=1; i<=n; i++)
			if(prefix[Right] - prefix[i - 1] >= 0)
			{
				Left = i;
			}
		cout << Left << " " << Right << endl;
	}
	
}
