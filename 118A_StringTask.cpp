/*
~ Author    : @tridib_2003
~ Title     : 118A. String Task
~ Link      : https://codeforces.com/problemset/problem/118/A
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
    cin.tie(0);
    /*
	int tc;
    cin>>tc;
    while(tc--) {
	}
	*/

	string str;
	cin >> str;

	for(int i = 0; i < str.length(); i++) {
        switch(str[i]) {
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
            case 'y' :
            case 'a' - ' ':
            case 'e' - ' ':
            case 'i' - ' ':
            case 'o' - ' ':
            case 'u' - ' ':
            case 'y' - ' ': continue;
            default :
                cout << "." << (char)tolower(str[i]);
        }
	}
	return 0;
}
