#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;

ll n, m;
ll l[N_MAX]; // tyle musi byc ogniw we fragmencie
ll c[N_MAX]; // o tym kolorze
ll a[N_MAX];

ll wymagane_elementy[N_MAX];
ll zliczane_elementy[N_MAX];

ll ile_nierownych_elementow;
ll dlugosc_fragmentu;

ll indeks1;
ll indeks2;

ll result;
ll now_element;



int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (ll i = 1; i <= m; i++)
		cin >> l[i];
	for (ll i = 1; i <= m; i++)
		cin >> c[i];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];

	for (ll i = 1; i <= m; i++) 
	{
		dlugosc_fragmentu += l[i];
		wymagane_elementy[c[i]] += l[i];
	}		

	indeks1 = 1;
	indeks2 = dlugosc_fragmentu;

	if(indeks2 > n)
	{
		cout << 0 << '\n';
		return 0;
	}


	for (ll i = indeks1; i <= indeks2; i++)
		zliczane_elementy[a[i]]++;



	/*cout << "wymagane_elementy: " << '\n';
	for (ll i = 1; i <= n; i++)
		cout << wymagane_elementy[i] << " ";
	cout << '\n';
	cout << '\n';

	cout << "zliczane_elementy: " << '\n';
	for (ll i = 1; i <= n; i++)
		cout << zliczane_elementy[i] << " ";
	cout << '\n';
	cout << '\n';*/

	
	for(ll i = 1; i <= n; i++)
	{
		if(wymagane_elementy[i] != zliczane_elementy[i])
			ile_nierownych_elementow++;
	}

	//cout << "ile_nierownych_elementow i zliczane: " << endl;
	while(indeks2 <= n)
	{
		/*cout << indeks1 << ": " << endl;
		cout << ile_nierownych_elementow << '\n';
		for (ll i = 1; i <= n; i++)
			cout << zliczane_elementy[i] << " ";
		cout << endl;
		cout << endl;*/

		if(ile_nierownych_elementow==0)
			result++;
		
		now_element = a[indeks1];
		if(wymagane_elementy[now_element]==zliczane_elementy[now_element])
			ile_nierownych_elementow++;
		else if(zliczane_elementy[now_element]-1==wymagane_elementy[now_element])
			ile_nierownych_elementow--;

		zliczane_elementy[now_element]--;
		indeks1++;

		
		indeks2++;
		now_element = a[indeks2];
		zliczane_elementy[now_element]++;
		if(wymagane_elementy[now_element] == zliczane_elementy[now_element])
			ile_nierownych_elementow--;
		else if(zliczane_elementy[now_element] == wymagane_elementy[now_element]+1)
			ile_nierownych_elementow++;

	}
	//cout << endl;
	//cout << endl;

	cout << result << '\n';


	return 0;
}

/*
7 3
2 1 1
1 2 3
4 2 1 3 1 2 5

*/