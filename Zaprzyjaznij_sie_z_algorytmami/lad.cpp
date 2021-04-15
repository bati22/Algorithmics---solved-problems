#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1005;
int n, k, q;
int d[N_MAX];
int dp[N_MAX][N_MAX];
int result[N_MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int j = 0; j <= k; j++)
		dp[1][j] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (j > 0)
				dp[i][j] += dp[i-1][j-1];
			if (j < k)
				dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= q;
		}
	}

	for (int i = 0; i < n; i++)
	{
		result[i] = 0;
		for (int j = 0; j <= k; j++)
		{
			result[i] += dp[d[i]][j];
			result[i] %= q;
		}
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
}
