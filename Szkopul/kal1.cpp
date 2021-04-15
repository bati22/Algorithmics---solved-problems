#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;

ll n, m;
ll pref_a[N_MAX];
ll pref_b[N_MAX];

ll z;
ll dzien, miesiac;
char c;

ll liczba_dni;

ll wyszukaj_B(ll l, ll p, ll value)
{
	ll mid = (l+p)/2;
	if(pref_b[mid] >= value) // wieksza rowna wartosc
	{
		if(pref_b[mid-1] < value)
			return mid;
		else
			wyszukaj_B(l, mid-1, value);
	}

	else // za malo
		wyszukaj_B(mid+1, p, value);
}

ll wyszukaj_A(ll l, ll p, ll value)
{
	ll mid = (l+p)/2;
	if(pref_a[mid] >= value) // wieksza rowna wartosc
	{
		if(pref_a[mid-1] < value)
			return mid;
		else
			wyszukaj_A(l, mid-1,value);
	}

	else // za malo
	{
		wyszukaj_A(mid+1, p, value);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> pref_a[i];
		pref_a[i] += pref_a[i-1];
	}

	for (ll i = 1; i <= m; i++)
	{
		cin >> pref_b[i];
		pref_b[i] += pref_b[i-1];
	}

	

	cin >> z;
	while(z != 0)
	{
		cin >> dzien >> miesiac >> c;

		if (c=='A')
		{
			liczba_dni = pref_a[miesiac-1] + dzien;
			miesiac = wyszukaj_B(1, m, liczba_dni);
			dzien = liczba_dni - pref_b[miesiac-1];
			cout << dzien << " " << miesiac << '\n';
		}

		else // B
		{

			liczba_dni = pref_b[miesiac-1] + dzien;
			miesiac = wyszukaj_A(1, n, liczba_dni);
			dzien = liczba_dni - pref_a[miesiac-1];
			cout << dzien << " " << miesiac << '\n';
		}



		z--;
	}




	return 0;
}

/*
3 6
20 10 4
10 10 6 4 2 2
4
11 1 A
2 1 B
2 6 B
3 3 A

3 6
20 10 4
10 10 6 4 2 2
1
2 6 B

*/