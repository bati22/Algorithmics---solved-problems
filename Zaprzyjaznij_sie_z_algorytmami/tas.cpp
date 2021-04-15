#include <iostream>
#include <cmath>
using namespace std;

const int N_MAX = 1000005;
int wynik;
int n;
int a[N_MAX];
int s;
int lewa;
int prawa;
int roznica;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }



    wynik = 2 * 1000 + 1;
    for (int i = 0; i < n-1; i++)
    {
        lewa += a[i];
        prawa = s-lewa;
        roznica = abs(lewa - prawa);
        wynik = min(wynik, roznica);

        /*cout << i << ": " << endl;
        cout << "lewa: " << lewa << endl;
        cout << "prawa: " << prawa << endl;
        cout << "roznica: " << roznica << endl;
        cout << "wynik: " << wynik << endl;
        cout << endl;
        cout << endl;*/
    }
    cout << wynik << endl;


    return 0;
}

/*
5
3 1 2 4 3

*/
