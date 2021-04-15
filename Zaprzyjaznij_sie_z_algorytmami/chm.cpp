#include <iostream>
using namespace std;

const int N_MAX = 500005;
int n; // liczba_chomikow
int m; // liczba pytan
int hamster[N_MAX];
int a;
int b;
int prefix_table[7][N_MAX];
int addition[7];




int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> hamster[i];
        addition[hamster[i]]++;

        for (int j = 1; j <= 5; j++)
        {
            prefix_table[j][i] = addition[j];
        }
    }

    /*cout << "Wyœwietlam: " << endl;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << prefix_table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/


    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        //cout << "a = " << a << "    b = " << b << endl;
        for (int j = 1; j <= 5; j++)
        {
            //cout << j << ": " << "prefix_table[j][b] = " << prefix_table[j][b] << "     prefix_table[j][a-1] = " << prefix_table[j][a-1] << endl;
            if (prefix_table[j][b] - prefix_table[j][a-1] > 0)
            {
                cout << j << endl;
                break;
            }

        }
    }






    return 0;
}

/*
5 3
2 3 4 3 1
1 3
1 5
2 4


*/




