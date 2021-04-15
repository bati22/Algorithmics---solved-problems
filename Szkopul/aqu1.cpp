#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N2_MAX = 2000;

ll n, r;
ll pref[N2_MAX][N2_MAX];
ll a;

ll x_start;
ll y_start;

unordered_map <ll, pair<int, int>> mapa;
//pair<ll, ll> para_ij;
pair<int, int> para_xy;

ll x, y;
ll klucz;

ll result, wsp1_x, wsp1_y, wsp2_x, wsp2_y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> r;

	x_start = 1;
	y_start = (n*2-1)/2+1;

	for (ll i = 1; i <= n; i++)
	{
		x = x_start;
		y = y_start;
		for (ll j = 1; j <= n; j++)
		{
			cin >> a;
			pref[x][y] = a;

			klucz = i * 10000 + j;

			para_xy.first = x;
			para_xy.second = y;

			mapa[klucz] = para_xy;

			x++;
			y++;
		}
		x_start++;
		y_start--;
	}


	/*cout << "Wyświetlam dużą tablicę: " << endl;
	for (ll i = 1; i <= (n*2)-1; i++)
	{
		for (ll j = 1; j <= (n*2)-1; j++)
		{
			cout << pref[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
	cout << '\n';*/


	for (ll i = 1; i <= (n*2)-1; i++)
		for (ll j = 1; j <= (n*2)-1; j++)
			pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		


	/*cout << "Wyświetlam tablicę prefiksową: " << endl;
	for (ll i = 1; i <= (n*2)-1; i++)
	{
		for (ll j = 1; j <= (n*2)-1; j++)
		{
			cout << pref[i][j] << '\t';
		}
		cout << '\n';
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
	cout << '\n';*/
	



	while(r > 0)
	{
		ll i, j, l;
		cin >> i >> j >> l;
		klucz = i * 10000 + j;
		x = mapa[klucz].first;
		y = mapa[klucz].second;

		//cout << "x: " << x << endl;
		//cout << "y: " << y << endl;

		wsp1_x = max(1LL, x-l);
		wsp1_y = max(1LL, y-l);
		wsp2_x = min(n*2LL-1LL, x+l);
		wsp2_y = min(n*2LL-1LL, y+l);

		/*cout << "wsp1_x: " << wsp1_x << endl;
		cout << "wsp1_y: " << wsp1_y << endl;
		cout << "wsp2_x: " << wsp2_x << endl;
		cout << "wsp2_y: " << wsp2_y << endl;
		cout << "calosc: " << pref[wsp2_x][wsp2_y] << endl;
		cout << "róg: " << pref[wsp1_x-1][wsp1_y-1] << endl;
		cout << "gora: " << pref[wsp1_x-1][wsp2_y] << endl;
		cout << "lewo: " << pref[wsp2_x][wsp1_y-1] << endl;

		cout << endl;*/


		result = pref[wsp2_x][wsp2_y] - pref[wsp1_x-1][wsp2_y] - pref[wsp2_x][wsp1_y-1] + pref[wsp1_x-1][wsp1_y-1];

		cout << result << '\n';


		//cout << endl;
		//cout << endl;
		//cout << endl;


		r--;
	}



	return 0;
}

/*
5 2
6 3 0 0 9
7 1 4 0 5
0 5 0 0 2
0 0 0 8 0
1 2 0 0 0
2 2 1
4 5 2

*/