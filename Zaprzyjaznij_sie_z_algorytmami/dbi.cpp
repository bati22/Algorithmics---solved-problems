#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N_MAX = (2 << 21)+5;
ll t[N_MAX];
ll wynik = LLONG_MAX;
ll k;
ll pot=1;
ll indeks=1;


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> k;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < pot; j++)
		{
			cin >> t[indeks];
			if (i != 0)
				t[indeks] += t[indeks/2];
			if (i == k)
				wynik = min(wynik, t[indeks]);
			indeks++;
		}
		pot *= 2;
	}
	cout << wynik << endl;

	return 0 ;
}