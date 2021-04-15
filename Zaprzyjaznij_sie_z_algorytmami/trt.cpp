#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 2000009;
ll f_begin, f_end;
ll a, b, n, k;
ll x[N_MAX];
ll y[N_MAX];
ll part_x[N_MAX];
ll part_y[N_MAX];
ll v;
ll part_number;
ll last_result;

ll check(ll v)
{
	ll result = 0;
	ll j = n;
	for (ll i = 0; i <= n; i++)
	{
		while(j >= 0 && part_x[i]*part_y[j] >= v)
			j--;
		result += n-j;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a >> b >> n >> k;
	x[n+1] = a;
	y[n+1] = b;
	part_number = n+1;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++)
		cin >> y[i];
	f_begin = 1;
	f_end = a*b;
	for (int i = 0; i <= n; i++)
	{
		part_x[i] = x[i+1]-x[i];
		part_y[i] = y[i+1]-y[i];
	}
	sort(part_y, part_y+n+1);
	sort(part_x, part_x+n+1);

	/*cout << "Boki x: " << endl;
	for (int i = 0; i <= n+1; i++)
		cout << x[i] << " ";
	cout << endl;
	cout << endl;

	cout << "Boki y: " << endl;
	for (int i = 0; i <= n+1; i++)
		cout << y[i] << " ";
	cout << endl;
	cout << endl;

	cout << "Kawałki x: " << endl;
	for (int i = 0; i <= n; i++)
		cout << part_x[i] << " ";
	cout << endl;
	cout << endl;

	cout << "Kawałki y: " << endl;
	for (int i = 0; i <= n; i++)
		cout << part_y[i] << " ";
	cout << endl;
	cout << endl;*/

	while (f_begin <= f_end)
	{
		v = (f_begin+f_end)/2;
		if (check(v) >= k)
		{
			f_begin = v+1;
			last_result = v;
		}
		

		else
			f_end = v-1;
	}
	cout << last_result << endl;
	
	

	return 0;
}