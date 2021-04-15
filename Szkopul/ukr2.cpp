#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll result;
string liczba;
string S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin.get();
	cin >> S;

	liczba = "";
	for (int i = 0; i < n; i++)
	{
		if (S[i] >= '0' && S[i] <= '9')
		{
			if (S[i] == '0' && liczba.size() > 0)
				liczba += S[i];
			else
				liczba += S[i];
		}

		else if (liczba.size() > 0)
		{
			result += atoi(liczba.c_str());
			liczba = "";
		}
	}

	if (liczba.size() > 0)
	{
		result += atoi(liczba.c_str());
		liczba = "";	
	}

	cout << result << endl;


	return 0;
}