#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<vector<int> > grafo;

int dfs_number_counter;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_parent;
vector<bool> articulation_vertex;
vector<ii> bridge;
int root_children;

void dfs(int pos)
{
	dfs_num[pos] = dfs_number_counter;
	dfs_low[pos] = dfs_number_counter;
	dfs_number_counter++;
	
	for(auto it = grafo[pos].begin(); it != grafo[pos].end(); it++)
	{
		if(dfs_num[*it] == -1)
		{
			dfs_parent[*it] = pos;
			if(pos == 0)
			{
				root_children++;
			}
			
			dfs(*it);
			
			if(dfs_low[*it] >= dfs_num[pos])
			{
				articulation_vertex[pos] = true;
			}
			if(dfs_low[*it] > dfs_num[pos])
			{
				bridge.push_back(ii(pos, *it));
			}
			
			if(dfs_low[*it] < dfs_low[pos])
			{
				dfs_low[pos] = dfs_low[*it];
			}
		}
		else if(*it != dfs_parent[pos])
		{
			if(dfs_num[*it] < dfs_low[pos])
			{
				dfs_low[pos] = dfs_num[*it];
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
		grafo[b].push_back(a);
	}
	
	dfs_number_counter = 0;
	dfs_num.assign(n, -1);
	dfs_low.assign(n, -1);
	dfs_parent.assign(n, -1);
	articulation_vertex.assign(n, false);
	root_children = 0;
	
	dfs(0);
	if(root_children > 1)
	{
		articulation_vertex[0] = true;
	}
	else
	{
		articulation_vertex[0] = false;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(articulation_vertex[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
	for(auto it = bridge.begin(); it != bridge.end(); it++)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
	cout << endl;
	
	return 0;
}
