#include <bits/stdc++.h>
using namespace std;


int n;
int res;
int x;
int expected = 1;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		cin >> x;
		if ( x == expected ) {
			expected++;
		}
		else {
			res++;
		}
	}
	
	cout << res << '\n';
	
	
	
	return 0;
}