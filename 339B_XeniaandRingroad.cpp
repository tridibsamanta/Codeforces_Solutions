/*
 ~ Author    : @tridib_2003
 ~ Title     : 339B. Xenia and Ringroad
 ~ Link      : https://codeforces.com/contest/339/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	int tc = 1;
	//cin >> tc;
	while (tc--) {

		int n, m;
		cin >> n >> m;

		int prev = 1;

		int curr;
		ll time = 0;
		for (int i = 0; i < m; ++i) {
			cin >> curr;
			if (curr >= prev)
				time += curr - prev;
			else
				time += n - prev + curr;
			prev = curr;
		}

		cout << time << '\n';

	}

	return 0;
}