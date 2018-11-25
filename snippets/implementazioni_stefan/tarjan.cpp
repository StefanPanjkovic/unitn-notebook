#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > grafo;

int dfs_number_counter;
vector<int> dfs_num;
vector<int> dfs_low;
vector<bool> visited;
vector<int> S;
vector<vector<int> > scc;

void tarjan(int pos)
{
	dfs_num[pos] = dfs_number_counter;
	dfs_low[pos] = dfs_number_counter;
	dfs_number_counter++;
	visited[pos] = true;
	S.push_back(pos);
	
	for(auto it = grafo[pos].begin(); it != grafo[pos].end(); it++)
	{
		if(dfs_num[*it] == -1)
		{
			tarjan(*it);
		}
		if(visited[*it])
		{
			if(dfs_low[*it] < dfs_low[pos])
			{
				dfs_low[pos] = dfs_low[*it];
			}
		}
	}
	
	if(dfs_num[pos] == dfs_low[pos])
	{
		scc.push_back(vector<int>());
		for(;;)
		{
			int v = S.back();
			S.pop_back();
			visited[v] = false;
			
			scc.back().push_back(v);
			if(v == pos)
			{
				break;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	grafo.assign(n, vector<int>());
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
	}
	
	dfs_number_counter = 0;
	dfs_num.assign(n, -1);
	dfs_low.assign(n, -1);
	visited.assign(n, false);
	
	for(int i = 0; i < n; i++)
	{
		if(dfs_num[i] == -1)
		{
			tarjan(i);
		}
	}
	
	for(int i = 0; i < scc.size(); i++)
	{
		for(auto it = scc[i].begin(); it != scc[i].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	return 0;
}
