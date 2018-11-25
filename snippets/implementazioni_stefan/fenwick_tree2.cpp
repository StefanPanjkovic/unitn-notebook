#include <bits/stdc++.h>

using namespace std;

class FenwickTree
{
	private:
		vector<int> ft;
		
	public:
		FenwickTree(const vector<int>& v)
		{
			int n = v.size();
			ft.assign(n+1, 0);
			for(int i = 0; i < n; i++)
			{
				for(int j = i+1; j < ft.size(); j += (j&(-j)))
				{
					ft[j] += v[i];
				}
			}
		}
		
		int query(int pos)
		{
			int somma = 0;
			while(pos > 0)
			{
				somma += ft[pos];
				pos -= (pos & (-pos));
			}
			return somma;
		}
		
		void update(int i, int j, int value)
		{
			while(i < ft.size())
			{
				ft[i] += value;
				i += (i&(-i));
			}
			j++;
			while(j < ft.size())
			{
				ft[j] -= value;
				j += (j&(-j));
			}
		}
};

int main(void)
{
	int n;
	cin >> n;
	
	vector<int> A;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	
	vector<int> diff;
	diff.push_back(A[0]);
	for(int i = 1; i < n; i++)
	{
		diff.push_back(A[i]-A[i-1]);
	}
	
	FenwickTree ft(diff);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int a, b, c, valore;
		cin >> a;
		if(a == 0)
		{
			cin >> b >> c >> valore;
			ft.update(b+1, c+1, valore);
		}
		else
		{
			cin >> b;
			cout << ft.query(b+1) << endl;
		}
	}
	
	return 0;
}
