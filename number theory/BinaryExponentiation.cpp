#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int binaryExpo(int pow,int base)
{
    if(pow==0)
    {
        return 1;
    }
    if(pow%2==0)
    {
        auto res = binaryExpo(pow/2,base)%MOD;
        return (res*res)%MOD;
    }
    return (base%MOD*(binaryExpo(pow-1,base)%MOD))%MOD;
}
int main()
{
    int power,base;
    cin >> base >> power;
    cout << binaryExpo(power,base)%MOD <<'\n';
}
