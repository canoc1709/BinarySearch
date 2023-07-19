#include<bits/stdc++.h>
using namespace std;

struct asst
{
	int t,z,y;
};

bool goodBalloons(int t, int z, int y, int balloons, int mid)
{
	int cycle = t*z + y; //time of one batch
	int batches = balloons / z; 
	bool ok = (balloons%z == 0) ? 1 : 0;
	int currTime = 0;
	if(ok)
	{
		batches -= 1;
		currTime = (cycle*batches) + (t*z);
	}	
	else
		currTime = (batches * cycle) + ((balloons%z)*t);
	return currTime <= mid;
}
bool good(int mid, asst a[], int m, int n)
{
	int totalBalloons = 0;
	for(int i=0; i<n; i++)
	{
		int t = a[i].t;
		int z = a[i].z;
		int y = a[i].y;
		int low = 0;
		int high = 1e9;
		while(high > low + 1)
		{
			int balloons = (low + high)/2;
			if(goodBalloons(t,z,y,balloons,mid))
				low = balloons;
			else
				high = balloons;
		}
		totalBalloons += low;
	}
	return totalBalloons >= m;
}
int countMaxBalloons(int t, int z, int y, int r)
{
	int cycle = t*z + y;
	int batches = r/cycle;
	int remTime = r%cycle; 
	int totalBalloons = 0;
	totalBalloons += batches*z;
	if(remTime != 0)
	{
		if(remTime / t >= z)	
			totalBalloons += z;
		else
			totalBalloons += remTime / t;
	}
	return totalBalloons;
}
int main()
{
	int m,n;
	cin >> m >> n;
	asst a[n];
	for(int i=0; i<n; i++)
		cin >> a[i].t >> a[i].z >> a[i].y;
		
		
	int l = -1;
	int r = 1e9;
	while(r > l + 1) 
	{
		int mid = (l + r)/2;
		if(good(mid,a,m,n))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	int cnt[1005];
	memset(cnt, 0, sizeof cnt);
	
	for(int i=0; i<n; i++)
	{
		int t = a[i].t;
		int z = a[i].z;
		int y = a[i].y;
		cnt[i] = countMaxBalloons(t,z,y,r);
	}
	int totalBalloons = 0;
	for(int i=0; i<n; i++)
	{
		if(totalBalloons + cnt[i] <= m)
		{
			cout << cnt[i] << " ";
			totalBalloons += cnt[i];
		}
		else
		{
			if(totalBalloons == m)
				cout << 0 << " ";
			else
			{
				cout << (m - totalBalloons) << " ";
				totalBalloons = m;	
			}
		}
	}
	cout << endl;
	return 0;
}
