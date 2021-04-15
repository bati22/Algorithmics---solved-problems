#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 10005;
int n, k;
int m[N_MAX];
int dp[5][N_MAX];
int result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> m[i];
	for (int j = 1; j < n; j++)
		dp[0][j] = j;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i%2][j] = dp[1-(i%2)][j];
		for (int j = 0; j < n; j++)
		{
			int p = m[j];
			if (p >= 0)
				dp[i%2][p] = min(dp[i%2][p], dp[1-(i%2)][j]+1);
		}
		for (int j = 1; j < n; j++)
			dp[i%2][j] = min(dp[i%2][j], dp[i%2][j-1]+1);
	}
	result = dp[k%2][n-1];
	cout << result << endl;

	return 0;
}
