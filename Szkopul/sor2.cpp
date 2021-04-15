#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 153;
pair<int, string> pary[N_MAX];
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> pary[i].second;
		pary[i].first = pary[i].second.size();
	}

	sort(pary+1, pary+1+n);

	for (int i = 1; i <= n; i++)
		cout << pary[i].second << '\n';




	return 0;
}