#include <bits/stdc++.h>
using namespace std;

int a, b, wynik;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a >> b;
	while (a != b)
	{
		if (a < b)
			b/=2;
		else
			a/=2;
		wynik++;
	}
	cout << wynik << endl;
	
	return 0 ;
}