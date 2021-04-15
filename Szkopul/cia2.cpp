// ciag
/*
Rozwiązanie
Dzielę ciąg na podciągi o długości k (ostatni podciąg
może być krótszy). Kolejne podciągi, każdy pisany od nowego
wiersza, tworzą dwuwymiarową tablicę o ilości kolummn równej k.
W miejsca w których nie ma liczby wpisuję -1, tam gdzie liczba
jest parzysta zmieniam w tablicy dwuwymiarowej na 0, a tam gdzie
jest nieparzysta zmieniam na 1. Do wyniku dodaję minimum z liczby liczb
parzystych i nieparzystych z każdej kolumny. Po wykonaniu tej operacji
sprawdzam, czy suma liczb w pierwszym wierszu tablicy jest parzysta.
Jeśli jest nieparzysta, to od wyniku odejmuję min z liczby liczb
parzystych i nieparzystych z kolumny, w której różnica pomiędzy
ilością liczb parzystych a nieparzystych jest najmniejsza. Potem
z tej samej kolumny dodaję max z liczby liczb parzystych 
i nieparzystych.





*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000005;

vector <ll> line;
vector <vector <ll>> table;
ll n, k;
ll counter;
ll parzysta[N_MAX];
ll nieparzysta[N_MAX];
ll result;
ll gorna_liczba;
ll min_roznica = LLONG_MAX;
ll nr_kolumny;
ll mindiff = LLONG_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (ll i = 0; i < k; i++)
		line.push_back(-1);
	for (ll i = 0; i < n; i++)
	{
		cin >> line[counter];
		line[counter] %= 2;
		counter++;
		if ( (counter==k) || (i==n-1))
		{
			table.push_back(line);
			counter = 0;
			for (ll j = 0; j < k; j++)
				line[j] = -1;
		}
	}

	/*cout << "Wyświetlam: " << endl;
	for (unsigned int i = 0; i < table.size(); i++)
	{
		for (unsigned int j = 0; j < table[i].size(); j++)
			cout << table[i][j] << " ";
		cout << endl;
	}*/

	for (int i = 0; i < k; i++)
	{
		for (unsigned int j = 0; j < table.size(); j++)
		{
			if (table[j][i] == 1)
				nieparzysta[i]++;
			else if (table[j][i] == 0)
				parzysta[i]++;
		}
		result += min(parzysta[i], nieparzysta[i]);
	}

	for (int i = 0; i < k; i++)
	{
		mindiff = min(mindiff, abs(parzysta[i]-nieparzysta[i]));
		if (nieparzysta[i] > parzysta[i])
			gorna_liczba++;
	}
	if (gorna_liczba%2==1)
	{
		result += mindiff;
	}
	cout << result << endl;



	

	return 0;
}