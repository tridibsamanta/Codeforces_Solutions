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

	string num1, num2;
	cin >> num1 >> num2;

	string res = "";

	for (int i = 0; num1[i]; ++i) {
		if ((num1[i] == '0' && num2[i] == '1') ||
		        (num2[i] == '0' && num1[i] == '1'))
			res += '1';
		else
			res += '0';
	}

	cout << res;

	return 0;
}