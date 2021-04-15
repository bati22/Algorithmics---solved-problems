#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 1000005;
ll p[N_MAX];
ll n;
ll dp[N_MAX];
ll wynik;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	dp[0] = p[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = INT_MIN;
		for (int j = 1; j <= 6; j++)
			if (i >= j)
				dp[i] = max(dp[i], dp[i-j]);
		dp[i] += p[i];
	}
	wynik = dp[n-1];
	cout << wynik << endl;

	return 0 ;
}