#include <bits/stdc++.h>
using namespace std;

int n;
string S;
map <char, int> mapa;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	while(cin >> S)
	{
		for (unsigned int i = 0; i < S.size(); i++)
		{
			mapa[S[i]]++;
		}
	}

	for (char i = 'a'; i <= 'z'; i++)
	{
		if (mapa.count(i))
			cout << i << " " <<  mapa[i] << endl;
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (mapa.count(i))
			cout << i << " " <<  mapa[i] << endl;
	}






	return 0;
}