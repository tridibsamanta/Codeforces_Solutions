/*
~ Author    : @tridib_2003
~ Title     : 1A. Theatre Square
~ Link      : https://codeforces.com/problemset/problem/1/A
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
    	cin.tie(0);
    	
	/*int tc;
    	cin>>tc;
    	while(tc--) {
    	}
    	*/
	
	long long n, m, a;
	cin >> n >> m >> a;
	
	long long len, wid, total;	
	(n % a == 0) ? (len = n / a) : (len = n /a + 1);
	(m % a == 0) ? (wid = m / a) : (wid = m / a + 1);
	
	total = len*wid;
	cout << total << "\n"; 
		 
	return 0;
}
