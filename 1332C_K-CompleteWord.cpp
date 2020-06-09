/*
~ Author    : @tridib_2003
~ Title     : 1332C. K-Complete Word
~ Link      : https://codeforces.com/contest/1332/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define PI                  3.141592653589793
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;
	w(tc) {

		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int ans = 0;

		for (int i = 0; i < k / 2; ++i) {

			int freq[26] = {0};

			for (int si = 0; si + k - 1 < n; si += k) {

				int pos1 = si + i;
				int pos2 = si + (k - 1 - i);

				freq[s[pos1] - 'a']++;
				freq[s[pos2] - 'a']++;
			}

			int total_idx = 2 * (n / k);
			int max_freq = *max_element(freq, freq + 26);

			ans += total_idx - max_freq;
		}

		if (k & 1) {

			int freq[26] = {0};

			for (int i = k / 2; i < n; i += k)
				freq[s[i] - 'a']++;

			int total_idx = n / k;
			int max_freq = *max_element(freq, freq + 26);

			ans += total_idx - max_freq;
		}

		cout << ans << '\n';
	}

	return 0;
}