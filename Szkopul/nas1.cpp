#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string S;
string T;

ll dlugosc_now;
ll max_dlugosc;
char numer_max;
char numer_teraz;

ll min_dlugosc;
char numer_min;

bool czy_jasne(char c) // czy samogloska
{
	c = tolower(c);

	if(c == 'a')
		return true;
	else if(c== 'e')
		return true;
	else if(c== 'i')
		return true;
	else if(c== 'o')
		return true;
	else if(c== 'u')
		return true;
	else if(c== 'y')
		return true;
	else
		return false;
}

bool czy_wieksze(char c) // czy duza litera
{
	if(c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

char zwroc_liczbe(char c)
{
	if(czy_wieksze(c))
	{
		if(czy_jasne(c))
			return '1';
		else
			return '2';
	}

	else
	{
		if(czy_jasne(c))
			return '3';
		else
			return '4';
	}
}

void aktualizuj_max()
{
	if(dlugosc_now > max_dlugosc)
	{
		max_dlugosc = dlugosc_now;
		numer_max = numer_teraz;
	}

	else if(dlugosc_now == max_dlugosc && numer_teraz < numer_max)
		numer_max = numer_teraz;
}

void aktualizuj_min()
{
	if(dlugosc_now < min_dlugosc)
	{
		min_dlugosc = dlugosc_now;
		numer_min = numer_teraz;
	}

	else if(dlugosc_now == min_dlugosc && numer_teraz < numer_min)
		numer_min = numer_teraz;
}

ll poczatkowe = 0;
ll koncowe = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;

	while (n != 0)
	{
		cin >> S;
		T = '0';
		dlugosc_now = 0;
		max_dlugosc = 0;
		numer_max = '7';
		numer_teraz = '7';

		min_dlugosc = LLONG_MAX;
		numer_min = '7';
		poczatkowe = 0;
		koncowe = 0;

		for (unsigned int i = 0; i < S.size(); i++)
			T += zwroc_liczbe(S[i]);

		//cout << S << endl;
	//	cout << T << endl;
	//	cout << endl;
		//cout << endl;


		if(T[1]==T[T.size()-1])
		{
			numer_teraz = T[1];
			for (ll i = 1;  i < T.size(); i++)
			{
				if(T[i]==T[1])
					poczatkowe++;
				else
					break;
			}

			for (ll i = T.size()-1; i >= 1; i--)
			{
				if(T[i]==T[1])
					koncowe++;
				else
					break;
			}

			if(poczatkowe==T.size()-1)
				dlugosc_now = poczatkowe;
			else
				dlugosc_now = poczatkowe +koncowe;

			aktualizuj_min();
			aktualizuj_max();
		}

		dlugosc_now = 0;
		numer_teraz = '7';


		for (int i = 1+poczatkowe; i < T.size()-koncowe; i++)
		{
			if(T[i-1]==T[i])
				dlugosc_now++;
			else
			{
				dlugosc_now = 1;
				numer_teraz = T[i];
			}

			if(i==T.size()-1 || T[i] != T[i+1])
			{
				aktualizuj_max();
				aktualizuj_min();
			}
		}


		cout << max_dlugosc << " ";
		if(numer_max=='1')
			cout << "JASNE" << '\n';
		else if(numer_max=='2')
			cout << "CIEMNE" << '\n';
		else if(numer_max=='3')
			cout << "jasne" << '\n';
		else
			cout << "ciemne" << '\n';


		cout << min_dlugosc << " ";
		if(numer_min=='1')
			cout << "JASNE" << '\n';
		else if(numer_min=='2')
			cout << "CIEMNE" << '\n';
		else if(numer_min=='3')
			cout << "jasne" << '\n';
		else
			cout << "ciemne" << '\n';

		n--;
	}



	return 0;
}


/*
2
oaBDrlIOIaeiy
oioioioi

*/