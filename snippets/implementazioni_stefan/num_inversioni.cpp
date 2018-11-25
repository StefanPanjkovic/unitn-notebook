#include <bits/stdc++.h>

using namespace std;

class FenwickTree
{
	private:
		vector<int> ft;
		
	public:
		FenwickTree(const vector<int> &_V)
		{
			int N = _V.size();
			ft.assign(N+1, 0);
			for(int i = 0; i < N; i++)
			{
				for(int j = i+1; j < ft.size(); j += (j&(-j)))
				{
					ft[j] += _V[i];
				}
			}
		}
		
		int rsq(int b)
		{
			int somma = 0;
			
			while(b > 0)
			{
				somma += ft[b];
				b -= (b & (-b));
			}
			
			return somma;
		}
		
		int rsq(int a, int b)
		{
			if(a == 1)
			{
				return rsq(b);
			}
			else
			{
				return rsq(b) - rsq(a-1);
			}
		}
		
		void update_point(int index, int valore)
		{
			while(index < ft.size())
			{
				ft[index] += valore;
				index += (index & (-index));
			}
		}
};

int main(void)
{
	int n;
	cin >> n;
	
	vector<int> vettore;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vettore.push_back(a);
	}
	
	vector<int> v(100000, 0);
	FenwickTree ft(v);
	int num_inversioni = 0;
	for(int i = 0; i < n; i++)
	{
		num_inversioni += ft.rsq(vettore[i]+1, 100000);
		ft.update_point(vettore[i], 1);
	}
	cout << num_inversioni << endl;
	
	return 0;
}
