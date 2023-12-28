#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> s;
    long long n, x, res = 0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        s.insert(x);
    } 
    while(s.size() > 1)
    {
        long long u = *s.begin();
        s.erase(s.begin());
        long long v = *s.begin();
        s.erase(s.begin());
        res += u+v;
        s.insert(u+v);
    }
    cout << res;
}