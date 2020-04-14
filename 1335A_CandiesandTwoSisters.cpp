/*
~ Author    : @tridib_2003
~ Title     : 1335A. Candies and Two Sisters
~ Link      : https://codeforces.com/contest/1335/problem/A
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;

        int total_ways = 0;

        if (n < 3)
            cout << total_ways << "\n";
        else {
            if (n % 2 == 0) {
                total_ways = n / 2 - 1;
                cout << total_ways << "\n";
            }
            else {
                total_ways = n / 2;
                cout << total_ways << "\n";
            }
        }
    }

    return 0;
}
