#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define maxn 100005
int m,n;
vector<int> A[maxn]; //luu dinh ke
vector<int> B[maxn]; //luu trong so
int visited[maxn] = {0};
stack<int> st;
int parent[maxn];
void inp()
{
	cin >> m >> n;
	for(int i=0; i<n; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		A[x].push_back(y);
		B[x].push_back(z);
	}
}
void topoSort(int u)
{
	visited[u] = 1;
	for(int i=0; i<A[u].size(); i++)
		if(visited[ A[u][i] ] == 0)
			topoSort( A[u][i] );
	st.push(u); 
}
bool good(double mid)
{
	vector<double> d(m+1);
	for(int i=0; i<=m; i++)
		d[i] = 1e5;
	d[1] = 0;
	int cnt = 0;
	while(!st.empty())
	{
		int u = st.top();
		st.pop();
		cnt++;
		for(int i=0; i<A[u].size(); i++)
		{
			int v = A[u][i];
			int wt = B[u][i];
			if(v != m && d[v] > d[u] + wt)
			{
				d[v] = d[u] + wt;
				parent[v] = u;
			}
			else
				if(v == m && ((d[u] + wt) / cnt) < d[v] )
				{
					d[m] = (d[u] + wt)/cnt;
					cnt = 1;
					parent[m] = u;
				}
		}
	}
	if(d[m] - mid <= 0)
		return true;
	else
		return false;
}
int main()
{
	inp();
	for(int i=1; i<=m; i++)
		if(visited[i] == 0)
			topoSort(i);
			
	double l = 0;
	double r = 200;
	for(int i=0; i<200; i++)
	{
		double mid = (l + r)/2;
		if(good(mid))
			r = mid; // update mid to be minimum
		else
			l = mid;
	}
	vector<int> path;
	while(m != 1)
	{
		path.push_back(m);
		m = parent[m];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	cout << path.size() - 1 << endl;
	for(int i=0; i<path.size(); i++)
		cout << path[i] << " ";
	
} 
