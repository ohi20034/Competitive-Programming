#include <bits/stdc++.h>
using namespace std;
int binaryExpo(int pow,int base)
{
    if(pow==0){
        return 1;
    }
    if(pow%2==0)
    {
        auto res = binaryExpo(pow/2,base);
        return (res*res);
    }
    return (base*binaryExpo(pow-1,base));
}
int main()
{
    int power,base;
    cin >> base >> power;
    cout << binaryExpo(power,base) <<'\n';
}
