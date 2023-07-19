#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int m,n,d;
vector<int> adj[maxn];
vector<int> weight[maxn];
int minC = 9999999;
int maxC = -9999999;
vector<int> FinalPath;
int ok = 0;
void bfs(int mid, int u, int parent[], int visited[])
{
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0; i < adj[v].size(); i++)
			if(visited[adj[v][i]] == 0 && weight[v][i] <= mid)
			{
				q.push(adj[v][i]);
				visited[adj[v][i]] = 1;
				parent[adj[v][i]] = v;
			}
	}
}
bool good(int mid, int u)
{
	int parent[maxn]= {0};
	int visited[maxn] = {0}; //0 is false, 1 is true
	bfs(mid,u,parent,visited);
	if(parent[m] == 0)
		return false;
	int t = m;
	vector<int> path;
	while(t != 1)
	{
		path.push_back(t);
		t = parent[t];
	}
	path.push_back(1);
	if(path.size() - 1 <= d)
	{
		ok = 1;
		FinalPath.clear();
		for(int i=0; i<path.size(); i++)
			FinalPath.push_back(path[i]);
		reverse(FinalPath.begin(), FinalPath.end());
		return true;
	}
	else
		return false;
	
}

int main()
{
	cin >> m >> n >> d;
	for(int i=0; i<n; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		adj[x].push_back(y);
		weight[x].push_back(z);
		if(z > maxC)
			maxC = z;
		if(z < minC)
			minC = z;
	}
	int l = minC - 1;
	int r = maxC + 1;
	while(r > l + 1)
	{
		int mid = (l + r)/2;
		if(good(mid,1))
			r = mid;
		else
			l = mid;
	}
	if(ok == 0)
		cout << -1 << endl;
	else
	{
		cout << FinalPath.size() - 1 << endl;
		for(int i=0; i<FinalPath.size(); i++)
			cout << FinalPath[i] << " ";
		cout << endl;
	}
	return 0;
}

