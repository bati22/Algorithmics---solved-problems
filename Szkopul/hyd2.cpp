#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 200005;
ll n;
ll u[N_MAX];
ll z[N_MAX];
ll r[N_MAX];
ll koszt[N_MAX];
vector <ll> G[N_MAX];
ll x;
pair <ll, ll> z_i;
priority_queue <pair<ll, ll>> Q;
bool C[N_MAX];

ll counter_done_heads[N_MAX];
vector <ll> head_where[N_MAX];
stack <ll> vertex_to_count;
ll new_heads;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> u[i] >> z[i] >> r[i];
		for (int j = 0; j < r[i]; j++)
		{
			cin >> x;
			head_where[x].push_back(i);
			G[i].push_back(x);
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (unsigned int j = 0; j < G[i].size(); j++)
			cout << G[i][j] << " ";
		cout << endl;
	}*/

	for (int i = 1; i <= n; i++)
	{
		z_i.first = -z[i];
		z_i.second = i;
		Q.push(z_i);
	}
	//cout << "Minimalna wartość oraza indeks: " << z[Q.top().second] << " " <<  Q.top().second << endl;

	while (!Q.empty())
	{
		int i = Q.top().second;
		if (!C[i])
		{
			koszt[i] = z[i];
			//cout << "koszt " << i << ": " << koszt[i] << endl;
			//cout << endl;
			C[i] = true;
			
			for (unsigned int j = 0; j < head_where[i].size(); j++)
				counter_done_heads[head_where[i][j]]++;
			for (unsigned int j = 0; j < head_where[i].size(); j++)
				if (counter_done_heads[head_where[i][j]] == G[head_where[i][j]].size())
				{
					vertex_to_count.push(head_where[i][j]);
					//cout << "na stos: " << head_where[i][j] << endl;
				}
			while(!vertex_to_count.empty())
			{
				i = vertex_to_count.top();
				if (!C[i])
				{
					new_heads = u[i];
					//cout << "new_heads = u[" << i << "](" << u[i] << ")";
					for (unsigned int j = 0; j < G[i].size(); j++)
					{
						new_heads += koszt[G[i][j]];
						//cout << "+ koszt[" << G[i][j] << "](" << koszt[G[i][j]] << ")";
					}
					//cout << endl;
					//cout << "new_heads: " << new_heads << endl;
					//cout << "z[" << i << "]=" << z[i] << endl;
					koszt[i] = min(z[i], new_heads);
					//cout << "koszt " << i << ": " << koszt[i] << endl;
					//cout << endl;
					C[i] = true;
					vertex_to_count.pop();
					for (unsigned int j = 0; j < head_where[i].size(); j++)
						counter_done_heads[head_where[i][j]]++;
					for (unsigned int j = 0; j < head_where[i].size(); j++)
						if (counter_done_heads[head_where[i][j]] == G[head_where[i][j]].size())
						{
							vertex_to_count.push(head_where[i][j]);
							//cout << "na stos: " << head_where[i][j] << endl;
						}
				}
				else
					vertex_to_count.pop();
				
			}

		}
		Q.pop();
	}

	cout << koszt[1] << endl;

	return 0;
}