#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair <ll ,ll> added_minimum;
priority_queue <pair <ll ,ll>> kopiec;
ll n;
ll x;
ll y;
ll result = 1;
ll j = 0;
int licznik;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> x >> y;
	added_minimum.first = x;
	added_minimum.second = 0;
	kopiec.push(added_minimum);
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		added_minimum.first = x;
		added_minimum.second = i;
		kopiec.push(added_minimum);
		//cout << "i = " << i << endl;
		//cout << "j = " << j << endl;
		while (y < kopiec.top().first)
		{
			j++;
			//cout << j << endl;
			while (kopiec.top().second < j)
			{
				kopiec.pop();
				/*cout << "y: " << y << endl;
				cout << "kopiec.top().first: " << kopiec.top().first << endl;
				cout << "j: " << j << endl;
				cout << "kopiec.top().second: " << kopiec.top().second << endl;
				cout << endl;
				cout << endl;*/
			}
			//cout << endl;
			//cout << endl;

		}
		
		//cout << "kopiec po: " << kopiec.top().first << " " << kopiec.top().second << endl;
		//cout << endl;
		//cout << endl;
		result = max(result, i-j+1);
	}
	cout << result << endl;
	

	
	return 0;
}

/*
test:
8
8 6 0 1 2 3 4 0




*/