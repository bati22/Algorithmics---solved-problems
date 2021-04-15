#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll result;
ll result_now;
ll n;
string S;
stack <char> stos;

bool czy_owierajacy(char znak)
{
	if(znak=='(')
		return true;
	else if(znak=='{')
		return true;
	else if(znak=='[')
		return true;
	else
		return false;
}

bool czy_pasuja(char znak)
{
	if(znak==')' && stos.top()=='(')
		return true;
	else if(znak=='}' && stos.top()=='{')
		return true;
	else if(znak==']' && stos.top()=='[')
		return true;
	else
		return false;

}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> n;
	cin >> S;

	for (ll i = 0; i < S.size(); i++)
	{
		char znak = S[i];
		if(czy_owierajacy(znak))
		{
			stos.push(znak);
			result_now++;
			result = max(result, result_now);
		}
		else
		{
			if(!stos.empty() && czy_pasuja(znak))
			{
				stos.pop();
				result_now--;
			}
			else
			{
				result = -1;
				break;
			}
		}
	}

	if(stos.size()>0)
		result = -1;

	if(result == -1)
		cout << "NIE" << '\n';
	else
		cout << result << '\n';


	return 0;
}