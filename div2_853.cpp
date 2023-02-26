#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
#define ll long long
#define f(i,x)	for(ll i=0;i<x;i++)
#define ff(i,x,y)	for(int i=x;i<y;i++)
#define fff(x,y)	for(int i=x;i<y;i++)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl

void prob_a(void);
void prob_b(void);
void prob_c(void);

int  gcd(int  a, int b) {
	if (a == 1 || b == 1)return 1;
	else if (a == 0)return b;
	else if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	prob_c();
	return 0;
}
void prob_a(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<int>arr(n);
		f(i, n)cin >> arr[i];
		bool find = false;
		f(i, n) {
			ff(j, i + 1, n) {
				if (gcd(arr[i], arr[j]) <= 2)find = true;
			}
		}
		if (find)YES;
		else NO;
	}
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<char>arr(n);
		f(i, n)cin >> arr[i];
		bool find_true = 0;
		int chan = 0;
		vector<bool>could(n / 2);
		for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
			could[i] = !(arr[i] == arr[j]);
		}
		f(i, n / 2) {
			if (could[i] && find_true == 0)chan++;
			find_true = could[i];
		}
		if (chan > 1)NO;
		else YES;
	}
}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		ll n, m; cin >> n >> m;
		map<ll, ll>ma;
		map<ll, ll>sta;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		f(i, n)sta[arr[i]] = 0;
		f(i, m) {
			ll pos, new_val; cin >> pos >> new_val;
			ll old_val = arr[pos - 1];
			ma[old_val] += i + 1 - sta[old_val];
			arr[pos - 1] = new_val;
			sta[new_val] = i + 1;

		}
		f(i, n) {
			ll old_val = arr[i];
			ma[old_val] += m + 1 - sta[old_val];
		}
		ll count = 0;
		ll cnt = m * (m + 1) / 2;
		for (auto x : ma)
		{
			ll dis = m + 1 - x.second;
			count += cnt - dis * (dis - 1) / 2;
		}
		cout << count << endl;
	}
}