#include <iostream>
#include <list>

using namespace std;

void debug_vec(int *vector, int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

int compute_opt(int n, int *valueIndex, int *p, int *opt)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {   
        if (opt[n] != -1) return opt[n];

        else
        {
            opt[n] = max<int>(valueIndex[n] + compute_opt(p[n], valueIndex, p, opt), compute_opt(n-1, valueIndex, p, opt));
            return opt[n];
        }
    }
}

int main(){

    int n;

    cout << "Escreva a quantidade de intervalos: ";
    cin >> n;

    int *valueIndex = new int[n+1];
    int *p = new int[n+1];
    int *opt = new int[n+1];

    valueIndex[0] = 0; p[0] = 0; opt[0] = 0;

    //Inicializando os intervalos
    for (int i = 1; i <= n; i++)
    {
        cin >> valueIndex[i] >> p[i];
        opt[i] = -1; // -1 para indicar que aquela posição esta vazia || Auxilia compute_opt.
    }

    cout << compute_opt(n, valueIndex, p, opt);
    cout << endl;
    debug_vec(opt, n);
}