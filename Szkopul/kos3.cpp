#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k; // wysokosc kozika
ll w; // wysokosc wymagana przez trenera
ll m; // wartosc powiekszania sie uza po kazdym uderzeniu
ll res;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> k;
	cin >> w;
	cin >> m;
	
	if ( w > k ) {
		w -= k;
		res = w / m;
		if ( w % m != 0 ) {
			res++;
		}
	}
	
	cout << res << '\n';
	
	return 0;
}
