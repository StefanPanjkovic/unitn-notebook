#include <bits/stdc++.h>

using namespace std;

class SparseTable
{
	private:
		int A[10000];
		int st[10000][25];
		
	public:
		SparseTable(int n, int A_[])
		{
			for(int i = 0; i < n; i++)
			{
				A[i] = A_[i];
				st[i][0] = i;
			}
			
			for(int j = 1; (1<<j) <= n; j++)
			{
				for(int i = 0; i+(1<<j)-1 < n; i++)
				{
					if(A[st[i][j-1]] < A[st[i+(1<<(j-1))][j-1]])
					{
						st[i][j] = st[i][j-1];
					}
					else
					{
						st[i][j] = st[i+(1<<(j-1))][j-1];
					}
				}
			}
		}
		
		int query(int i, int j)
		{
			int k = (int)floor(log((double)j-i+1) / log(2.0));
			if(A[st[i][k]] <= A[st[j-(1<<k)+1][k]])
			{
				return st[i][k];
			}
			else
			{
				return st[j-(1<<k)+1][k];
			}
		}
};

int main(void)
{
}
