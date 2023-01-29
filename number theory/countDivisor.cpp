#include <bits/stdc++.h>
using namespace std;
#define int long long
int countDiv(int n)
{
    int div=0;
    for(int i=1; i*i <= n; ++i)
    {
        if(i*i == n){
            div+=1;
        }
        else if(n%i==0){
            div+=2;
        }
    }
    return div;
}
int32_t main()
{
    int n; cin >> n;
    cout << countDiv(n) <<"\n";
    main();
}
