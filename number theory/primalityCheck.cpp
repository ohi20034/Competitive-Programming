#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
    if(n<2)
        return false;
    if(n<=3)
        return true;
    if(n%2==0)
        return false;
    for(int i=3; i*i <=n; i+=2)
    {
        if(n%2==0)
            return false;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    cout << prime(n) << '\n';
    main();
}
