#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n;
pair <ll, ll> tab[N_MAX];
ll t[N_MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> tab[i].second >> tab[i].first;

	sort(tab+1, tab+1+n);

	for (ll i = 1; i <= n; i++)
		t[i] = tab[i].first - tab[i].second - tab[i-1].first;

	/*cout << "t: "<< '\n';
	for (ll i = 1; i <= n; i++)
		cout << t[i] << " ";
	cout << '\n';*/

	for(ll i = n; i >= 1; i--)
	{
		if(t[i] < 0)
			t[i-1] += t[i];
	}

	cout << t[1] << '\n';

	



	return 0;
}