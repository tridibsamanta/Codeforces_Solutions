/*
~ Author    : @tridib_2003
~ Title     : 158A. Next Round
~ Link      : https://codeforces.com/problemset/problem/158/A
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

	int n, k, i;
	cin >> n >> k;

	int count = 0, score[n];
	for(int i = 0; i < n; i++)
        cin >> score[i];

	for(int i = 0; i < n; i++)
        if(score[i] >= score[k-1] && score[i] > 0)
            count++;

    cout << count << "\n";

	return 0;
}
