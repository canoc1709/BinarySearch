#include<iostream>
#include<iomanip>
using namespace std;
int n,k;
int a[10005];
bool good(double x)
{
	int pieces = 0;
	for(int i=0; i<n; i++)
		pieces += a[i]/x;
	return pieces >= k;
}
int main()
{
	
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	double l = 0; //can cut k pieces of l length
	double r = 1e9; //can't ______________
	
	for(int i=0; i<100; i++)
	{
		double m = (l+r)/2;
		if(good(m))
			l = m;
		else
			r = m;
		
	}
	cout << setprecision(20) << fixed << l << endl;
}
