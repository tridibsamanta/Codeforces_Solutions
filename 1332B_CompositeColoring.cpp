/*
~ Author    : @tridib_2003
~ Title     : 1332B. Composite Coloring
~ Link      : https://codeforces.com/contest/1332/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

#define ll 					long long int
#define PI 					3.141592653589793
#define MOD 				1000000007
#define vi 					vector<int>
#define mk(arr, n, type) 	type *arr = new type[n];
#define FOR(a, c) 			for (int(a) = 0; (a) < (c); (a)++)
#define w(x)				int x; cin >> x; while(x--)
#define FIO 				ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

	w(tc) {

		int n;
		cin >> n;

		mk(arr, n, int);
		FOR(i, n)
		cin >> arr[i];

		mk(color, n, int);
		FOR(i, n)
		color[i] = -1;

		int color_type = 1;

		for (int p : primes) {

			bool used = 0;

			for (int i = 0; i < n; ++i) {

				if (color[i] != -1)
					continue;

				if (arr[i] % p)
					continue;

				used = 1;
				color[i] = color_type;
			}
			if (used)
				++color_type;
		}

		cout << color_type - 1 << '\n';

		FOR(i, n)
		cout << color[i] << ' ';

		cout << '\n';
	}

	return 0;
}