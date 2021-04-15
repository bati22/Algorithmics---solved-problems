#include <bits/stdc++.h>
using namespace std;

stack <char> stos;
string ciag;
const int N_MAX = 1005;
int n;
bool odp[N_MAX];


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ciag;
        odp[i] = true;
        while(stos.size() != 0)
            stos.pop();
        for (int j = 0; j < ciag.size(); j++)
        {
            if (ciag[j] == '(' || ciag[j] == '{' || ciag[j] == '[')
                stos.push(ciag[j]);
            else
            {
                if (stos.size()==0)
                {
                    odp[i] = false;
                    break;
                }

                else if (stos.top() == '(' && ciag[j] == ')')
                    stos.pop();
                else if (stos.top() == '[' && ciag[j] == ']')
                    stos.pop();
                else if (stos.top() == '{' && ciag[j] == '}')
                    stos.pop();
                else
                {
                    odp[i] = false;
                    //cout << "zle: " << j << endl;
                    break;
                }
            }
        }
        if (stos.size() != 0)
            odp[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (odp[i])
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }



    return 0;
}

/*
2
{[()()]}
([)()]


*/
