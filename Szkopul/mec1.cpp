#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
const ll M_MAX = 1000123;
const ll MOD = 1798119187;
ll n, m;
ll hasz[N_MAX];
ll pot_29[M_MAX];

ll x;
map <ll, bool> uzyty_hasz;
bool result;


int main()
{
	ios_base::sync_with_stdio(0);

	pot_29[0] = 1;
	for (ll i = 1; i <= 1000000; i++)
	{
		pot_29[i] = pot_29[i-1]*3;
		pot_29[i] %= MOD;
	}

	/*cout << "Potęgi_29: " << endl;
	for (ll i = 1; i <= 50; i++)
		cout << pot_29[i] << endl;*/




	cin >> n >> m;
	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 1; j <= n/2; j++)
		{
			cin >> x;
			hasz[x] += (1*pot_29[i]);
			hasz[x] %= MOD;

		}

		for (ll j = n/2+1; j <= n; j++)
		{
			cin >> x;
			hasz[x] += (2*pot_29[i]);
			hasz[x] %= MOD;
		}
	}

	/*cout << "Hasze: " << endl;
	for (ll i = 1; i <= n; i++)
		cout << i << ": " << hasz[i] << endl;*/

	result = true;
	for (ll i = 1; i <= n; i++)
	{
		if (uzyty_hasz.count(hasz[i]))
		{
			result = false;
			break;
		}

		uzyty_hasz[hasz[i]] = true;
	}

	if (result)
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;


	return 0;
}