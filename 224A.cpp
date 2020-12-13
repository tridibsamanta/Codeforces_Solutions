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

	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;

	double sum = 4 * (sqrt(a1 * a2 / a3) + sqrt(a3 * a1 / a2) + sqrt(a3 * a2 / a1));
	cout << sum;

	return 0;
}