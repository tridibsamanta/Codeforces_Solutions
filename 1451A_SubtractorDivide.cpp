/*
 ~ Author    : @tridib_2003
 ~ Title     : 1451A. Subtract or Divide
 ~ Link      : https://codeforces.com/contest/1451/problem/A
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

int getMoves(int n) {

	if (n == 1)
		return 0;

	if (n == 2)
		return 1;

	if (n & 1)
		return 1 + getMoves(n - 1);
	else
		return 1 + getMoves(2);
}

int main() {

	FIO;

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		int moves = getMoves(n);
		cout << moves << '\n';
	}

	return 0;
}