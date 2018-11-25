#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class UnionFind
{
	private:
		vector<int> p;
		vector<int> rank;
		
	public:
		UnionFind(int N)
		{
			p.assign(N, 0);
			for(int i = 0; i < N; i++)
			{
				p[i] = i;
			}
			rank.assign(N, 0);
		}
		
		int find_set(int i)
		{
			if(p[i] == i)
			{
				return i;
			}
			else
			{
				p[i] = find_set(p[i]);
				return p[i];
			}
		}
		
		bool is_same_set(int i, int j)
		{
			return (find_set(i) == find_set(j));
		}
		
		void union_set(int i, int j)
		{
			if(!is_same_set(i, j))
			{
				int x = find_set(i);
				int y = find_set(j);
				if(rank[x] > rank[y])
				{
					p[y] = x;
				}
				else
				{
					p[x] = y;
					if(rank[x] == rank[y])
					{
						rank[y]++;
					}
				}
			}
		}
};

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, ii> > grafo;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		grafo.push_back(pair<int, ii>(c, ii(a, b)));
	}
	sort(grafo.begin(), grafo.end());
	
	int mst_cost = 0;
	UnionFind ufds(n);
	for(int i = 0; i < m; i++)
	{
		if(!ufds.is_same_set(grafo[i].second.first, grafo[i].second.second))
		{
			mst_cost += grafo[i].first;
			ufds.union_set(grafo[i].second.first, grafo[i].second.second);
		}
	}
	cout << mst_cost << endl;
	
	return 0;
}
