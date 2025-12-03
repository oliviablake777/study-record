#include<bits/stdc++.h>
using namespace std;
int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//打个月份表
bool check_valid(int date) {
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;//分离年月日 
    if (day == 0 || month <= 0 || month > 12)return false;//显然的不合法情况 
    if (month != 2 && day > months[month])return false;//月份不是2，day不合法就不合法 
    if (month == 2) {//月份是2 
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))if (day > 29)return false;//是闰月， day必须<=29 
        else if (day > 28)return false;//是平月，day必须<=28 
    }
    return true;
}
bool check_huiwen(string s)
{
    int len = s.size();
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
bool check_ABAB(string s)
{
    if (check_huiwen(s)) {
        if (s[0] != s[2] || s[1] != s[3] || s[0] == s[1])return false;
        return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    bool flag = 0;
    for (int i = n + 1;; i++) {//枚举回文数 
        if (check_valid(i)) {//合法 
            string s = to_string(i);//仅在C++11标准及以后出现，比较好用 
            if (check_huiwen(s) && !flag) {//输出第一个回文数 
                cout << i << endl;
                flag = 1;
            }
            if (check_ABAB(s)) {//输出第一个特殊回文数 
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}