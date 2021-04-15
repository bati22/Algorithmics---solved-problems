#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;

pair <ll, ll> deski[N_MAX];
ll n, m;
ll pref[N_MAX];
ll g[N_MAX];
ll x;
ll a, b;


bool sprawdz(ll x)
{
	for (ll i = 1; i <= 1000000; i++)
		pref[i] = 0;
	for (ll i = 1; i <= x; i++)
		pref[g[i]]++;
	for (ll i = 1; i <= 1000000; i++)
		pref[i] += pref[i-1];

	for (ll i = 1; i <= n; i++)
	{
		a = deski[i].first;
		b = deski[i].second;
		ll wbite_gwozdzie = pref[b] - pref[a-1];
		if (wbite_gwozdzie < 1)
			return false;
	}
	return true;
}

ll wyszukaj_binarnie(ll l, ll p)
{
	ll mid = (l+p)/2LL;
	if (sprawdz(mid))
	{
		if(mid==1)
			return mid;
		else if (sprawdz(mid-1))
			wyszukaj_binarnie(l, mid-1);
		else
			return mid;
	}

	else
		wyszukaj_binarnie(mid+1, p);
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> deski[i].first >> deski[i].second;
	for (ll i = 1; i <= m; i++)
		cin >> g[i];
	cout << wyszukaj_binarnie(1, m) << endl;
	




	return 0;
}