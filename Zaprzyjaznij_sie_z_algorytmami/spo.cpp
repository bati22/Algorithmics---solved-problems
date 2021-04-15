#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1005;
ll n;
ll fib[N_MAX];
ll licznik;
ll wynik;

int main()
{
	ios_base::sync_with_stdio(0);
	fib[1] = 1;
	fib[2] = 2;
	for (ll i = 3; i <= 60; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
		fib[i] %= 10;
	}

	/*for (int i = 1; i <= 60; i++)
	{
		cout << fib[i] << " ";
		licznik++;
		if (licznik == 10)
		{
			licznik = 0;
			cout << endl;
		}
	}*/
	
	cin >> n;
	n %= 60;
	if (n==0)
		n=60;
	//cout << "Nowe n: " << n << endl;
	wynik = fib[n-2]+fib[n]; 
	wynik %= 10;
	cout << wynik << endl;


	
	





	return 0;
}