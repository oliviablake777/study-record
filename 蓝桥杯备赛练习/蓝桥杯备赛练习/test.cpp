#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
int l, r;
bool pfs(int x)
{
    return (int)sqrt(x) == sqrt(x);
}
int main() {
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (pfs(i))
        {
            int k = 10;
            while (k <= i * 10)
            {
                int x = i % k;
                int y = i / k;
                k *= 10;
                if (pfs(x) && pfs(y)) {
                    cout << i << endl;
                    break;
                }
                k *= 10;
            }
        }
    }
    return 0;
}
