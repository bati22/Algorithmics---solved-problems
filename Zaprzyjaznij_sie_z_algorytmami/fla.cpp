#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000005;
ll t[N_MAX];
ll n;
bool mount[N_MAX];
ll near_mount[N_MAX];
ll now_mount;
ll k;
ll result;
ll counter;



int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> t[i];
	for (ll i = 1; i < n-1; i++)
	{
		if ( t[i] > max(t[i-1], t[i+1]) ) 
			mount[i] = true;
	}
	/*cout << "Szczyty: " << endl;
	for (int i = 0; i < n; i++)
		if (mount[i])
			cout << i << " ";
	cout << endl;*/

	near_mount[n-1] = -1;
	for (ll i = n-2; i >= 0; i--)
	{
		if (mount[i])
			near_mount[i] = i;
		else
			near_mount[i] = near_mount[i+1];
	}

	/*cout << "Najbliższy szczyt: " << endl;
	for (ll i = 0; i < n; i++)
		cout << near_mount[i] << " ";
	cout << endl;*/

	for (ll k = 1; k*k <= n; k++)
	{
		now_mount = 0;
		counter = 0;
		while (now_mount < n && counter < k)
		{
			now_mount = near_mount[now_mount];
			if (now_mount == -1)
				break;
			counter++;
			now_mount += k;
		}
		result = max(result, counter);
	}
	cout << result << endl;


	return 0 ;
}