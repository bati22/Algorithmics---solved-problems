#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1000005;
int z;
int F[N_MAX];
int pref[5][N_MAX];
int a, b;
int wynik;
int n=1000000;
bool pol_pierwsze[N_MAX];
int roznica;

int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 2; i*i <= n; i++)
	{
		if (!F[i])
		{
			for (int k = i*i; k <= n; k+=i)
			{
				if (!F[k])
					F[k] = i;
			}
		}
	}

	//cout << "liczby polpierwsze: " << endl;
	for (int i = 2; i <= n; i++)
		if (F[i] != 0 && F[i/F[i]] == 0 )
		{
			pol_pierwsze[i] = true;
			//cout << i << " ";
		}
	//cout << endl;

	//1 pod rzad
	for (int i = 2; i <= n; i++)
		if (pol_pierwsze[i])
			pref[1][i] = 1;

	//2 pod rzad
	for (int i = 2; i <= n; i++)
		if (pol_pierwsze[i] && pol_pierwsze[i-1])
			pref[2][i] = 1;

	//3 pod rzad
	for (int i = 2; i <= n; i++)
		if (pol_pierwsze[i] && pol_pierwsze[i-1] && pol_pierwsze[i-2])
			pref[3][i] = 1;

	for (int j = 1; j <= 3; j++)
		for (int i = 2; i <= n; i++)
			pref[j][i] += pref[j][i-1];

	cin >> z;
	for (int k = 0; k < z; k++)
	{
		cin >> a >> b;
		wynik = 0;

		roznica = pref[1][b] - pref[1][a-1];
		if (roznica > 0)
			wynik = 1;

		roznica = pref[2][b] - pref[2][a-1];
		if ( (roznica > 0) &&  (b-a>=1) )
		{
			if (roznica == 1)
			{
				if ( !(pref[2][a]>pref[2][a-1]) )
					wynik = 2;
			}

			else
				wynik = 2;
		}
		

		roznica = pref[3][b] - pref[3][a-1];
		if (roznica > 0 && b-a>=2)
		{
			

			if (roznica == 1)
			{
				if ( !(pref[3][a]>pref[3][a-1]) && !(pref[3][a]<pref[3][a+1]))
					wynik = 3;
			}
			else
				wynik = 3;
		}
			
		
		cout << wynik << endl;
	}

	return 0;
}