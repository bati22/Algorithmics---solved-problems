#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
ll n, m;
ll t[N_MAX];
ll a;
ll b;
ll result;
bool pierwszy = true;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		 cin >> t[i];
		 if(t[i] >= m && pierwszy)
		 {
		 	b = i;
		 	pierwszy = false;
		 }
	}

	if(b==0)
	{
		cout << 0 << '\n';
		return 0;
	}


	for (a = 1;  a <= n; a++)
	{
		while( (t[b] < m || b < a) && b <= n)
			b++;
		if(b > n)
			break;
		result += (n-b+1);
	}

	cout << result << '\n';


	return 0;
}