#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>primeFactors;
void primeFact(int n)
{
    for(int i=2; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            primeFactors.push_back({i,cnt});
        }
    }
    if(n>1)
        {
            primeFactors.push_back({n,1});
        }
}
    int main()
    {
        int n;
        cin >> n;
        primeFact(n);
        for(auto i:primeFactors)
        {
            cout << i.first<<"^"<<i.second<<" ";
        }
    }
