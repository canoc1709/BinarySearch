#include<bits/stdc++.h>
using namespace std;
struct coup
{
	int x,v;
};
int n; 
coup A[100005];
bool good(double m)
{
	double left1 = A[0].x - m * A[0].v;
	double right1 = A[0].x + m * A[0].v;
	for(int i=1; i<n; i++)
	{
		double left2 = A[i].x - m * A[i].v;
		double right2 = A[i].x + m * A[i].v;
		if(left1 > right2 || left2 > right1)
			return false;
		else
		{
			left1 = max(left1,left2);
			right1 = min(right1,right2);
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> A[i].x >> A[i].v;
	
	double l = -1;
	double r = 1e10;
	for(int i=0; i<100; i++)
	{
		double m = (l + r)/2;
		if(good(m))
			r = m;
		else
			l = m;
	}
	cout << setprecision(7) << fixed << r << endl;
}

