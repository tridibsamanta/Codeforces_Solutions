/*
~ Author    : @tridib_2003
~ Title     : 1335C. Two Teams Composing
~ Link      : https://codeforces.com/contest/1335/problem/C
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

        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++mp[a[i]]; // Increasing the freq by 1
        }

        // Finding the one with max freq
        int max_freq = 0;
        map<int, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); ++itr)
            max_freq = max(itr->second, max_freq);

        // Finding number of players in a team
        int players = 0;
        for (int c = 1; c <= max_freq; ++c) {
            if (max_freq == c ? c <= (mp.size() - 1) : max_freq > c && c <= mp.size())
                players = c;
        }
        cout << players << '\n';
    }
    return 0;
}