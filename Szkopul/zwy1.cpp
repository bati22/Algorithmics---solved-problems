#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 123;
ll N;
ll max_value = -1;
string result = "";
ll t[N_MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (ll i = 0; i < N; i++)
	{
		cin >> t[i];
		max_value = max(t[i], max_value);
	}

	for (ll i = 0; i < N; i++)
	{
		if(t[i]==max_value)
		{
			char znak = 'A';
			znak += i;
			result += znak;
		}
	}

	sort(result.begin(), result.end());
	cout << result << endl;



	return 0;
}