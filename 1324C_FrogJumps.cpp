/*
~ Author    : @tridib_2003
~ Title     : 1324C. Frog Jumps
~ Link      : https://codeforces.com/contest/1324/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string dir;
		cin >> dir;

		int len = dir.length();

		int prev_r = -1, curr_r = -1, r_diff = 0, last_r_diff = -1, first_r_diff = -1;

		for (int i = 0; i < len; ++i) {
			if (dir[i] == 'R') {

				// Max. diff between two adj. R
				prev_r = curr_r;
				curr_r = i;
				if (prev_r >= 0) {
					int curr_diff = curr_r - prev_r;
					r_diff = max(r_diff, curr_diff);
				}

				//Diff between starting position and first R
				if (first_r_diff == -1)
					first_r_diff = i + 1;

				//Diff between destination and nearest R
				last_r_diff = len - i;
			}
		}

		if (first_r_diff == -1)
			cout << len + 1 << "\n";
		else
			cout << max( max(r_diff, first_r_diff), last_r_diff) << "\n";

	}
	return 0;
}