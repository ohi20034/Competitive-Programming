#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 10000000; /// 10^7
bool prime[MAX+5];
vector <int> primes;
void sieve()
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
    for(int i=2; i<=MAX; ++i)
    {
        if(prime[i])
            primes.push_back(i);
    }
}
/// Normal way 1
int countDiv(int n) /// sqrt(n) normal way
{
    int div=0;
    for(int i=1; i*i <= n; ++i)
    {
        if(i*i == n)
        {
            div+=1;
        }
        else if(n%i==0)
        {
            div+=2;
        }
    }
    return div;
}
int primeFactorDivCount(int n)
{
    if(n<1) return 0;
    int divisor=1;
    for(int i=0; primes[i]*primes[i] <= n; ++i)
    {
        if(n%primes[i]==0)
        {
            int cnt=1;
            while(n%primes[i]==0)
            {
                n/= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    if(n>1) divisor *= 2;
    return divisor;
}
int primeFactorDivsum(int n)
{
    int sum = 1;
    for (int i = 0; primes[i]*primes[i] <= n; i++)
    {
        if(n%primes[i]==0)
        {
            int cnt = 1;
            while(n%primes[i]==0)
            {
                n /= primes[i];
                cnt++;
            }
            sum *= (pow(primes[i], cnt) - 1) / (primes[i] - 1);
        }
    }
    if (n > 1) sum *= (pow(n, 2) - 1) / (n - 1);
}
int32_t main()
{
    sieve();
    int n;
    cin >> n;
    cout << primeFactorDivsum(n) <<"\n";
    //cout << countDiv(n) <<"\n";
    //cout << primeFactorDivCount(n) <<"\n";
    // main();
}
