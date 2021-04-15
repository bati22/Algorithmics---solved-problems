#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 200123;
const ll INF = LLONG_MAX / 4;

vector <ll> A [ N_MAX ]; //lista sasiedztwa
//ll W [ N_MAX ] [ N_MAX ]; //wagi
map <pair<ll, ll>, ll> W;
bool visited [ N_MAX ];
ll D [ N_MAX ]; //koszt dotarcia do i-tego wierzcholka


ll n; // liczba wierzcholkow
ll m; // liczba krawedzi


ll a;
ll b;
ll w;

void Dijkstra(ll source ) {

	//koszty wszedzie to inf
	for ( ll i = 1; i <= n; i++ ) {
		D [ i ] = INF;
	}

	//koszt dotarcia do pierwszego wierzcholka
	D [ source ] = 0;

	//tworze kopiec
	priority_queue<pair<ll, ll>> pq;

	//wrzucam do kopca wierzcholek poczatkowy
	pair<ll, ll> thisPair;
	thisPair.first = 0;
	thisPair.second = source;
	pq.push(thisPair);

	while ( !pq.empty() ) {
		//zdejumje z kopca pare
		ll v = pq.top().second;
		pq.pop();

		//cout << "zdjety z kopca: " << v << '\n';

		if ( !visited[v]) {
			//cout << v << '\n';
			visited [ v ] = true;

			for ( ll i = 0; i < (long long) A [ v ].size(); i++ ) {
			//	cout << "tu" << '\n';
				ll u = A [ v ] [ i ];
				if ( D [ v ] + W [ make_pair(u, v) ] < D [ u ] ) {
					D [ u ] = D [ v ] + W [ make_pair(u, v)  ];
					if ( !visited [ u ] ) {
						thisPair.first = -D [ u ];
						thisPair.second = u;
						//cout << "do pary: " << u << '\n';
						pq.push(thisPair);
					}
				}
			}
		}
	}
}

pair<ll, ll> t [ N_MAX ]; // x y 
pair<pair<ll, ll>, ll> t_xy [ N_MAX ]; // x y indeks
pair<pair<ll, ll>, ll> t_yx [ N_MAX ]; // y x indeks

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n;
	for ( ll i = 1; i <= n; i++ ) {
		cin >> t [ i ].first;
		cin >> t [ i ].second;

		t_xy [ i ].first.first = t [ i ].first;
		t_xy [ i ].first.second = t [ i ].second;
		t_xy [ i ].second = i;

		t_yx [ i ].first.first = t [ i ].second;
		t_yx [ i ].first.second = t [ i ].first;
		t_yx [ i ].second = i;


	}
	//cin >> m;

	sort(t_xy+1, t_xy+1+n);
	sort(t_yx+1, t_yx+1+n);

	for ( ll i = 1; i < n; i++ ) {
		ll a = t_xy [ i ].second;
		ll b = t_xy [ i + 1 ].second;
		ll w = min(
			abs(t_xy [ i ].first.first-t_xy [ i + 1 ].first.first),
			abs(t_xy [ i ].first.second-t_xy [ i + 1 ].first.second)
			);
		A [ a ].push_back(b);
		A [ b ].push_back(a);
		W [ make_pair(a, b) ] = w;
		W [ make_pair(b, a) ] = w;

	//	cout << a << " -- " << b << '\n';
	}

	for ( ll i = 1; i < n; i++ ) {
		ll a = t_yx [ i ].second;
		ll b = t_yx [ i + 1 ].second;
		ll w = min(
			abs(t_yx [ i ].first.first-t_yx [ i + 1 ].first.first),
			abs(t_yx [ i ].first.second-t_yx [ i + 1 ].first.second)
			);
		A [ a ].push_back(b);
		A [ b ].push_back(a);
		W [ make_pair(a, b) ] = w;
		W [ make_pair(b, a) ] = w;
	}

	

	Dijkstra(1);

	cout << D [ n ] << '\n';

	return 0;
}