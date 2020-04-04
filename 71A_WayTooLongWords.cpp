/*
~ Author    : @tridib_2003
~ Title     : 71A. Way Too Long Words
~ Link      : https://codeforces.com/problemset/problem/71/A
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
    	cin.tie(0);

	int tc;
    	cin>>tc;
    	while(tc--) {
		string word;
		cin >> word;

		if(word.length() > 10) {
            cout << word[0] << word.length()-2 << word[word.length()-1] << "\n";
		}
		else
			cout << word << "\n";
	}

	return 0;
}
