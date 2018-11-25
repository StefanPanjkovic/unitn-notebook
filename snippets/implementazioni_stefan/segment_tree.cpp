#include <bits/stdc++.h>

#define INF 2000000000

using namespace std;

typedef pair<int, int> ii;

class SegmentTree
{
	private:
		int n;
		vector<int> A;
		vector<ii> st;
		vector<bool> modified;
		
		void build(int p, int L, int R)
		{
			if(L == R)
			{
				st[p].first = L;
				st[p].second = A[L];
			}
			else
			{
				build(2*p, L, (L+R)/2);
				build(2*p+1, (L+R)/2+1, R);
				if(st[2*p].second <= st[2*p+1].second)
				{
					st[p].first = st[2*p].first;
					st[p].second = st[2*p].second;
				}
				else
				{
					st[p].first = st[2*p+1].first;
					st[p].second = st[2*p+1].second;
				}
			}
		}
		
		ii rmq(int p, int L, int R, int i, int j)
		{
			if(i>R || j<L)
			{
				return ii(-1, INF);
			}
			if(L>=i && R<=j)
			{
				return st[p];
			}
			
			if(modified[p])
			{
				propagate(p, L, R);
			}
			ii p1 = rmq(2*p, L, (L+R)/2, i, j);
			ii p2 = rmq(2*p+1, (L+R)/2+1, R, i, j);
			return (p1.second <= p2.second) ? p1 : p2;
		}
		
		void update(int p, int L, int R, int i, int j, int new_value)
		{
			if(i>R || j<L)
			{
				return;
			}
			if(L>=i && R<=j)
			{
				st[p].first = L;
				st[p].second = new_value;
				modified[p] = true;
				return;
			}
			
			if(modified[p])
			{
				propagate(p, L, R);
			}
			update(2*p, L, (L+R)/2, i, j, new_value);
			update(2*p+1, (L+R)/2+1, R, i, j, new_value);
			if(st[2*p].second <= st[2*p+1].second)
			{
				st[p].first = st[2*p].first;
				st[p].second = st[2*p].second;
			}
			else
			{
				st[p].first = st[2*p+1].first;
				st[p].second = st[2*p+1].second;
			}
		}
		
		void propagate(int p, int L, int R)
		{
			st[2*p].first = L;
			st[2*p].second = st[p].second;
			modified[2*p] = true;
			
			st[2*p+1].first = (L+R)/2+1;
			st[2*p+1].second = st[p].second;
			modified[2*p+1] = true;
			
			modified[p] = false;
		}
		
	public:
		SegmentTree(const vector<int>& A_)
		{
			n = (int)A_.size();
			A = A_;
			st.assign(4*n, ii(0, 0));
			modified.assign(4*n, false);
			build(1, 0, n-1);
		}
		
		ii rmq(int i, int j)
		{
			return rmq(1, 0, n-1, i, j);
		}
		
		void update(int i, int j, int new_value)
		{
			update(1, 0, n-1, i, j, new_value);
		}
};

int main(void)
{
}
