#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string S;
ll dlugosc;
ll result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> S;
	for (int i = 0; i < n; i++)
	{
		if(S[i]=='Z')
		{
			dlugosc++;
		}
		else	
		{	
			if(dlugosc % 3 > 0)
				result += (dlugosc/3)+1;
			else
				result += (dlugosc/3);

			dlugosc = 0;
		}

		if(i==n-1)
		{
			if(dlugosc % 3 > 0)
				result += (dlugosc/3)+1;
			else
				result += (dlugosc/3);
			
			dlugosc = 0;
		}
	}

	cout << result << '\n';



	return 0;
}

/*
11
ZWZWZZZZ
*/