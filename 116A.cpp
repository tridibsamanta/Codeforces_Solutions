/*
 ~ Author    : @tridib_2003
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

	int n;
	cin >> n;

	int min_capacity = 0, curr_capacity = 0;

	FOR(i, n) {

		int exit, entry;
		cin >> exit >> entry;

		curr_capacity -= exit;
		curr_capacity += entry;

		min_capacity = max(min_capacity, curr_capacity);

	}

	cout << min_capacity;

	return 0;
}