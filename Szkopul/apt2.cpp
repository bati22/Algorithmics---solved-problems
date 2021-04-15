#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n;
ll c[N_MAX];
ll min_koszt = LLONG_MAX;
stack <ll> stos;
ll jas_pozycja;
ll result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> c[i];

	for (ll i = n; i >= 1; i--)
	{
		if(c[i] < min_koszt)
		{
			min_koszt = c[i];
			stos.push(i);
		}
	}

	ll i = 0;
	while(!stos.empty())
	{
		i = stos.top();
		result += c[i] * (i-jas_pozycja);
		jas_pozycja = i;
		stos.pop();
	}

	cout << result << '\n';


	return 0;
}