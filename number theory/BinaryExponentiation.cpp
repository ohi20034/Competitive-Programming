#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int binaryExpo(int base,int pow)
{
    if(pow==0)
    {
        return 1;
    }
    auto res = binaryExpo(base,pow/2);
    if(pow%2)
        return res*res*base;
    return res*res;
}
int main()
{
    int power,base;
    cin >> base >> power;
    cout << binaryExpo(base,power) <<'\n';
}
