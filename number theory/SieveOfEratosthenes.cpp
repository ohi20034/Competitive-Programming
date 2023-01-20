#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000; /// 10^7
bool prime[MAX+5];
void sieve1()
{
    memset(prime, true, sizeof prime);

    prime[1] = false;

    for(int i=2; i*i<=MAX; ++i)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    sieve();
    int n; cin >> n;
    cout << prime[n] <<'\n';
    main();
}

