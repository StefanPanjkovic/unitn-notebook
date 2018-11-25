#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
	private:
		vector<int> p;
		vector<int> rank;
		vector<int> set_size;
		int num_sets;
		
	public:
		UnionFind(int N)
		{
			p.assign(N, 0);
			for(int i = 0; i < N; i++)
			{
				p[i] = i;
			}
			rank.assign(N, 0);
			set_size.assign(N, 1);
			num_sets = N;
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
				num_sets--;
				int x = find_set(i);
				int y = find_set(j);
				if(rank[x] > rank[y])
				{
					p[y] = x;
					set_size[x] += set_size[y];
				}
				else
				{
					p[x] = y;
					set_size[y] += set_size[x];
					if(rank[x] == rank[y])
					{
						rank[y]++;
					}
				}
			}
		}
		
		int num_disjoint_sets(void)
		{
			return num_sets;
		}
		
		int size_of_set(int i)
		{
			return set_size[find_set(i)];
		}
};

int main(void)
{
}
