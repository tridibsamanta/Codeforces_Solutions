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

	vector<pair<int, int> > points;

	FOR(i, n) {

		int x, y;
		cin >> x >> y;

		points.emplace_back(make_pair(x, y));
	}

	int supercentral = 0;

	for (auto i : points) {

		int x = i.first, y = i.second;
		bool right = false, left = false, lower = false, upper = false;

		for (auto j : points) {

			if (j.second == y) {
				if (j.first > x)
					right = true;
				else if (j.first < x)
					left = true;
			}

			if (j.first == x) {
				if (j.second < y)
					lower = true;
				if (j.second > y)
					upper = true;
			}
		}

		if (right == true && left == true && lower == true && upper == true)
			++supercentral;
	}

	cout << supercentral;

	return 0;
}