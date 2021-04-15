#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1000005;
int n = 1000000;
int a, b, d;
int F[N_MAX];
int pref[N_MAX];
bool pierwsze[N_MAX];
int wynik;

int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 2; i*i <= n; i++)
		if (!F[i])
		{
			pierwsze[i] = true;
			for (int k = i*i; k<=n; k+=i)
			{
				if (!F[k])
					F[k] = i;
			}
		}

	/*cout << "Tablica F, od 1 do 30: " << endl;
	for (int i = 1; i <= 30; i++)
		cout << F[i] << " ";
	cout << endl;
	cout << endl;*/

	for (int i = 1; i <= n; i++)
		if (F[i] != 0 && F[i/F[i]] == 0 && F[i] != i/F[i])
			pref[i] = 1;

	/*cout << "Tablica pref, od 1 do 30: " << endl;
	for (int i = 1; i <= 30; i++)
		cout << pref[i] << " ";
	cout << endl;
	cout << endl;

	cout  << "Pierwsze, od 1 do 30: " << endl;
	for (int i = 1; i <= 30; i++)
		if (pierwsze[i])
			cout << i << " ";
	cout << endl;
	cout << endl;*/

	for (int i = 2; i*i*i <= n; i++)
		if (pierwsze[i])
			pref[i*i*i] = 1;

	/*cout  << "Doskonałe drugiego rodzaju, od 1 do  30: " << endl;
	for (int i = 1; i <= 30; i++)
		if (pref[i])
			cout << i << " ";
	cout << endl;
	cout << endl;*/

	for (int i = 1; i <= n; i++)
		pref[i] += pref[i-1];

	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cin >> a >> b;
		wynik = pref[b] - pref[a-1];
		cout << wynik << endl;
	}


	





	return 0;
}