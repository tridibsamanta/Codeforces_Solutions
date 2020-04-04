/*
~ Author    : @tridib_2003
~ Title     : 4A. Watermelon
~ Link      : https://codeforces.com/problemset/problem/4/A
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*int tc;
    cin>>tc;
    while(tc--) {
    }
    */
    int w;
    cin >> w;
    if(w > 2 && w % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
	return 0;
}
