/*
~ Author    : @tridib_2003
~ Title     : 1335B. Construct the String
~ Link      : https://codeforces.com/contest/1335/problem/B
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n, a, b;
        cin >> n >> a >> b;

        string str;

        int size = 0;
        while (size < n) {
            char ch = 'a';
            for (int i = 1; i <= b; ++i) {
                str.push_back(ch);
                if (str.length() == n)
                    break;
                ++ch;
            }
            size += b;
        }
        cout << str << "\n";
    }
    return 0;
}

/* Algo -
1. 'b' distinct characters in a substring of length 'a', in a string of total length 'n'
2. form the string of length 'n' by repeating a set of exactly 'b' distinct characters
3. hence, any substring of length 'a' (>= b) is bound to have exactly 'b' distinct characters
4. Actually we dont need to take 'a' into consideration in our code !
*/
