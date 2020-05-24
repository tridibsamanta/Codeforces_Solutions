/*
~ Author    : @tridib_2003
~ Title     : 1326D2. Prefix-Suffix Palindrome (Hard version)
~ Link      : https://codeforces.com/contest/1326/problem/D2
*/

#include<bits/stdc++.h>
using namespace std;

int kmp(string s)
{
	vector<int> lps(s.size(), 0);

	for (int i = 1; i < (int)lps.size(); ++i)
	{
		int prev_idx = lps[i - 1];

		while (prev_idx > 0 && s[i] != s[prev_idx])
		{
			prev_idx = lps[prev_idx - 1];
		}

		lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
	}

	return lps[lps.size() - 1];
}

int largestPrefixPalindrome(string s) {
	string t = s + '?';
	reverse(s.begin(), s.end());
	t += s;
	return kmp(t);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string s;
		cin >> s;

		int n = s.length();

		int l = 0;

		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			if (s[i] == s[j])
				++l;
			else
				break;
		}

		string rem = s.substr(l, n - 2 * l);

		string res = s.substr(0, l);

		if (rem.size()) {
			int len_pre = largestPrefixPalindrome(rem);
			reverse(rem.begin(), rem.end());
			int len_suf = largestPrefixPalindrome(rem);

			if (len_pre > len_suf) {
				reverse(rem.begin(), rem.end());
				res += rem.substr(0, len_pre);
			}
			else
				res += rem.substr(0, len_suf);

		}

		res += s.substr(n - l, l);

		cout << res << '\n';
	}

	return 0;
}