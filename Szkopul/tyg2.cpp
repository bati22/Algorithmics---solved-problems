#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 500123;
ll n;
ll r, k;
pair<ll, ll> t[N_MAX];

ll min_r;
ll result = 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> r >> k;
		t[i].first = r;
		t[i].second = r/k;
	}	

	sort(t+1, t+1+n);

	min_r = t[1].first;
	for (ll i = 1;  i<= n; i++)
	{
		if(t[i].second >= min_r)
		{
			result++;
			min_r = t[i].first;
		}
	}

	cout << result << '\n';



	return 0;
}