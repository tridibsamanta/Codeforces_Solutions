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

	int zeroCount = 0, fiveCount = 0;

	FOR(i, n) {
		int num;
		cin >> num;

		if (num)
			++fiveCount;
		else
			++zeroCount;
	}

	if (!zeroCount)
		cout << -1;
	else if (fiveCount < 9)
		cout << 0;
	else {
		string nine_five = "555555555";

		FOR(i, fiveCount / 9)
		cout << nine_five;

		while (zeroCount--)
			cout << 0;
	}

	return 0;
}