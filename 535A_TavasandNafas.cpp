/*
~ Author    : @tridib_2003
~ Title     : 535A. Tavas and Nafas
~ Link      : https://codeforces.com/contest/535/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

string single_digit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string double_digit[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x = n / 10;
	int y = n % 10;

	switch (n) {
	case 0:
		cout << "zero" << '\n';
		break;
	case 10:
		cout << "ten" << '\n';
		break;
	case 11:
		cout << "eleven" << '\n';
		break;
	case 12:
		cout << "twelve" << '\n';
		break;
	case 13:
		cout << "thirteen" << '\n';
		break;
	case 14:
		cout << "fourteen" << '\n';
		break;
	case 15:
		cout << "fifteen" << '\n';
		break;
	case 16:
		cout << "sixteen" << '\n';
		break;
	case 17:
		cout << "seventeen" << '\n';
		break;
	case 18:
		cout << "eighteen" << '\n';
		break;
	case 19:
		cout << "nineteen" << '\n';
		break;
	default: {
		if (!x)
			cout << single_digit[y] << '\n';
		else if (!y)
			cout << double_digit[x] << '\n';
		else
			cout << double_digit[x] << '-' << single_digit[y] << '\n';
	}
	}

	return 0;
}