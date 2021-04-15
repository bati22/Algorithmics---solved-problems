#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 500009;
priority_queue <pair <ll, ll> > kopiec;
pair <ll, ll> pierwszy;
pair <ll, ll> drugi;
pair <ll, ll> dodawany;
ll k;
ll n;
ll j = 1;
ll e[N_MAX];
ll wynik;
bool uzyty[N_MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++)
		cin >> e[i];
	for (int i = 1; i <= k; i++)
	{
		dodawany.first = e[i];
		dodawany.second = i;
		kopiec.push(dodawany);
	}

	while (k <= n)
	{
		while (uzyty[kopiec.top().second])
			kopiec.pop();
		pierwszy = kopiec.top();
		kopiec.pop();

		while (uzyty[kopiec.top().second])
			kopiec.pop();
		drugi = kopiec.top();
		kopiec.push(pierwszy);
		wynik = max(wynik, pierwszy.first+drugi.first);
		uzyty[j] = true;
		j++;
		k++;
		dodawany.first = e[k];
		dodawany.second = k;
		kopiec.push(dodawany);
	}
	cout << wynik << endl;

	

	
	return 0;
}

/*
test:
8
8 6 0 1 2 3 4 0




*/