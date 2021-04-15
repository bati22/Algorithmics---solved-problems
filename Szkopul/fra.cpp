#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n, k;
ll d[N_MAX];
multiset <ll> l;
ll x;
ll result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;

	for (ll i = 1; i <= n; i++)
		cin >> d[i];

	for (ll i = 1; i <= k; i++)
	{
		cin >> x;
		l.insert(x);
	}

	sort(d+1, d+1+n);

	while(n != 0)
	{
		if(l.upper_bound(d[n]*5-1) != l.end())
		{
			auto wskaznik = l.upper_bound(d[n]*5-1);
			result++;
			l.erase(wskaznik);
		}

		else
		{
			if(l.upper_bound(d[n]*3-1) != l.end())
			{
				auto wskaznik = l.upper_bound(d[n]*3-1);
				result++;
				l.erase(wskaznik);

			}

			else
				break;

			if(l.upper_bound(d[n]*2-1) != l.end())
			{
				auto wskaznik = l.upper_bound(d[n]*2-1);
				result++;
				l.erase(wskaznik);

			}

			else
				break;

		}

		n--;
	}		

	if(n==0)
		cout << result << '\n';
	else
		cout << "NIE" << '\n';

	return 0;
}

/*
3 8
5 4 3
14 14 14 14 14 14 14 14
*/