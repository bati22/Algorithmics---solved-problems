#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000005;
ll n;
ll w[N_MAX];
ll result;
ll average;
queue <pair<ll, ll>> high_value;
queue <pair<ll, ll>> low_value;
pair <ll, ll> add_value_index;
ll over_value;
ll lack_value;
ll pref[N_MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	// wprowadzam wartosci i licze srednia
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		average += w[i];
	}
	average /= n;

	//wprowadzam wartosci do kolejek
	for (int i = 0; i < n; i++)
	{
		add_value_index.first = w[i];
		add_value_index.second = i;
		if (add_value_index.first > average)
			high_value.push(add_value_index);
		else if (add_value_index.first < average)
			low_value.push(add_value_index);
	}

	while (high_value.size() > 0)
	{
		lack_value = average - low_value.front().first;
		over_value = high_value.front().first - average;
		if (lack_value >= over_value)
		{
			high_value.front().first -= over_value;
			low_value.front().first += over_value;
			pref[min(high_value.front().second, low_value.front().second)+1]++;
			pref[max(high_value.front().second, low_value.front().second)+1]--;
		}
		else
		{
			low_value.front().first += lack_value;
			high_value.front().first -= lack_value;
			pref[min(high_value.front().second, low_value.front().second)+1]++;
			pref[max(high_value.front().second, low_value.front().second)+1]--;
		}

		if (low_value.front().first == average)
			low_value.pop();
		if (high_value.front().first == average)
			high_value.pop();
	}
	
	/*cout << "pref przed: " << endl;
	for (int i = 0; i < n; i++)
		cout << pref[i] << " ";
	cout << endl;*/

	for (int i = 1; i < n; i++)
		pref[i] += pref[i-1];

	/*cout << "pref po: " << endl;
	for (int i = 0; i < n; i++)
		cout << pref[i] << " ";
	cout << endl;*/

	for (int i = 0; i < n; i++)
		if (pref[i])
			result++;
	cout << result << endl;



	return 0;
}
