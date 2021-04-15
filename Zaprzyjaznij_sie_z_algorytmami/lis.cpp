#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1000005;

int n, m, a, b;
vector <int> A[N_MAX];
int odwiedzony[N_MAX];
int iden;
int iden_set[N_MAX];
int z, x, y;

void dfs(int v)
{
	odwiedzony[v] = true;
	iden_set[v] = iden;

	for (int i = 0; i < A[v].size(); i++)
	{
		int u = A[v][i];
		if (!odwiedzony[u])
			dfs(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!odwiedzony[i])
		{
			iden++;
			dfs(i);
		}
	}
	cin >> z;
	for (int i = 0; i < z; i++)
	{
		cin >> x >> y;
		if (iden_set[x]==iden_set[y])
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}

	
	
	return 0 ;
}