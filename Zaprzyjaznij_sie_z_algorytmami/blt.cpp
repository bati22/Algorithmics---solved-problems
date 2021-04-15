#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000005;
priority_queue<pair<ll, ll> > min_gates;
pair <ll, ll> gate;
ll n;
ll result;


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> gate.first >> gate.second;
		gate.first *= -1;
		min_gates.push(gate);
		while (min_gates.top().second == 0)
			min_gates.pop();
		/*cout << "Kopiec: " << endl;
		cout << "Cena: " << -min_gates.top().first << endl;
		cout << "Ilość: " << min_gates.top().second << endl;
		cout << endl;
		cout << endl;*/
		result -= min_gates.top().first;

		gate.first = min_gates.top().first;
		gate.second = min_gates.top().second-1;
		min_gates.pop();
		min_gates.push(gate);

	}
	cout << result << endl;
	

	
	return 0;
}

/*
test:
8
8 6 0 1 2 3 4 0




*/