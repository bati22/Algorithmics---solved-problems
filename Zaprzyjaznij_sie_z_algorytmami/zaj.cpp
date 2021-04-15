#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 300005;
int n;
bool m[N_MAX];
int fib[N_MAX];
int ile;
int skoki[N_MAX];
int wynik;


int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> m[i];
	fib[0] = 0;
	fib[1] = 1;
	ile = 1;
	while (fib[ile] <= n)
	{
		ile++;
		fib[ile] = fib[ile-1]+fib[ile-2];
	}

	/*cout << "Fibonacci: " << endl;
	for (int i = 0; i < ile; i++)
		cout << fib[i] << " ";
	cout << endl;
	cout << endl;*/

	for (int i = 0; i <= n; i++)
		skoki[i] = n+1;

	if (!m[0])
		skoki[0] = 0;

	for (int i = 1; i <= n; i++)
		if (!m[i])
			for (int j = 1; j < ile; j++)
				if (i-fib[j] >= 0)
					skoki[i] = min(skoki[i], skoki[i-fib[j]]+1);
	wynik = -1;
	if (skoki[n] <= n)
		wynik = skoki[n];
	cout << wynik << endl;


	
	





	return 0;
}