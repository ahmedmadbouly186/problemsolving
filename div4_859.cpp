#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include<iterator> // for iterators
#include <queue>

using namespace std;
#define ll long long
#define f(i,x)	for(ll i=0;i<x;i++)
#define ff(i,x,y)	for(ll i=x;i<y;i++)
#define fff(x,y)	for(ll i=x;i<y;i++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define print(x)	cout<<x<<endl
#define flush	cout.flush()
void prob_a(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g(void);
void prob_g2(void);
int n;
int m;
int i1;
int jj1;
int i2;
int j2;
string d;
bool find_ans;
map<string, int>directions = {
	{"UR",0 },{"UL",1 },{"DR",2 },{"DL",3 } };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prob_f();
}

void prob_a(void) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y, z; cin >> x >> y >> z;
		if (x + y == z)cout << "+" << endl;
		else cout << "-" << endl;
	}

}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		ll even = 0, odd = 0;
		f(i, n) {
			if (arr[i] & 1)odd += arr[i];
			else even += arr[i];
		}
		if (even > odd)yes;
		else no;
	}

}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<char>arr(n);
		f(i, n)cin >> arr[i];
		bool find1 = true, find2 = true;
		map<char, bool>m1, m2;
		m1[arr[0]] = 1;
		m2[arr[0]] = 0;
		ff(i, 1, n) {
			auto it = m1.find(arr[i]);
			if (it != m1.end() && it->second == m1[arr[i - 1]])find1 = false;
			else m1[arr[i]] = !m1[arr[i - 1]];
		}
		ff(i, 1, n) {
			auto it = m2.find(arr[i]);
			if (it != m2.end() && it->second == m2[arr[i - 1]])find2 = false;
			else m2[arr[i]] = !m2[arr[i - 1]];
		}
		if (find1 || find2)yes;
		else no;
	}
}
void prob_d(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, q; cin >> n >> q;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		ff(i, 1, n) {
			arr[i] += arr[i - 1];
		}
		f(i, q) {
			ll l, r, k; cin >> l >> r >> k;
			l--, r--;
			ll sum = arr[n - 1] - arr[r];
			if (l)sum += arr[l - 1];
			sum += (r - l + 1) * k;
			if (sum & 1)yes;
			else no;
		}
	}
}
void prob_e(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, q; cin >> n;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		ff(i, 1, n)arr[i] += arr[i - 1];
		int start = 1, end = n, mid;
		while (start < end)
		{
			mid = (end + start) / 2;
			ll answer;
			cout << "? " << mid << " ";
			f(i, mid)cout << i + 1 << " ";
			cout << endl;
			flush;
			cin >> answer;
			if (answer > arr[mid - 1])end = mid;
			else if (answer == arr[mid - 1]) start = mid + 1;
		}
		cout << "! " << start << endl;
	}
}
long long dfs(vector<vector<vector<bool>>>& dp) {
	int dir = directions[d];
	if (dp[i1][jj1][dir])
	{
		find_ans = false;
		return 0;
	}
	dp[i1][jj1][dir] = true;
	bool end = false;
	//int previ1 = i1, prevjj1 = jj1;
	if (d == "DR") {
		end = (i1 == i2 && jj1 == j2) || (i2 > i1 && j2 > jj1 && ((j2 - jj1) == (i2 - i1)));
		if ((m - jj1) < (n - i1)) {
			i1 += (m - jj1);
			jj1 = m;
			d = "DL";
		}
		else if ((n - i1) < (m - jj1)) {
			jj1 += (n - i1);
			i1 = n;
			d = "UR";
		}
		else {
			i1 = n; jj1 = m;
			d = "UL";
		}
	}
	else if (d == "DL") {
		end = (i1 == i2 && jj1 == j2) || (i2 > i1 && j2 < jj1 && ((jj1 - j2) == (i2 - i1)));
		if ((n - i1) > (jj1 - 1)) {
			i1 += (jj1 - 1);
			jj1 = 1;
			d = "DR";
		}
		else if ((jj1 - 1) > (n - i1)) {
			jj1 -= (n - i1);
			i1 = n;
			d = "UL";
		}
		else {
			i1 = n; jj1 = 1;
			d = "UR";
		}
	}
	else if (d == "UR") {
		end = (i1 == i2 && jj1 == j2) || (i2<i1&& j2>jj1 && ((j2 - jj1) == (i1 - i2)));
		if (i1 - 1 > m - jj1) {
			i1 -= (m - jj1);
			jj1 = m;
			d = "UL";
		}
		else if ((i1 - 1) < (m - jj1)) {
			jj1 += (i1 - 1);
			i1 = 1;
			d = "DR";
		}
		else {
			i1 = 1; jj1 = m;
			d = "DL";
		}
	}
	else if (d == "UL") {
		end = (i1 == i2 && jj1 == j2) || (i1 > i2 && jj1 > j2 && ((i1 - i2) == (jj1 - j2)));
		if (jj1 - 1 < i1 - 1) {
			i1 -= (jj1 - 1);
			jj1 = 1;
			d = "UR";
		}
		else if ((i1 - 1) < (jj1 - 1)) {
			jj1 -= (i1 - 1);
			i1 = 1;
			d = "DL";
		}
		else {
			i1 = 1; jj1 = 1;
			d = "DR";
		}
	}
	//if (previ1 == i1 && prevjj1 == jj1)dp[i1][jj1] = false;
	if (end)return 0;
	else return (long long)1 + dfs(dp);
}
void prob_f(void) {
	int t; cin >> t;
	f(tt, t) {
		cin >> n >> m >> i1 >> jj1 >> i2 >> j2 >> d;
		find_ans = true;

		vector<vector<vector<bool>>> dp = vector<vector<vector<bool>>>(n + 1, vector<vector<bool>>(m + 1, vector<bool>(4, false)));
		ll answer = dfs(dp);
		if (find_ans)cout << answer;
		else cout << -1;
		cout << endl;
	}
}
void prob_g1(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<ll>c(n);
		vector<ll>arr(n);
		vector<ll>sum(n);
		f(i, n)cin >> c[i];
		sort(c.begin(), c.end());
		arr[0] = 1;
		sum[0] = 1;
		bool ac = true;
		if (c[0] != 1)ac = false;
		else {
			ff(i, 1, n) {
				if (c[i] > sum[i - 1]) { ac = false; break; }
				else {
					arr[i] = c[i];
					sum[i] = c[i] + sum[i - 1];
				}
			}
		}
		if (ac)yes;
		else no;
	}
}
void prob_g2(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<ll>c(n);
		vector<ll>arr(n);
		vector<ll>sum(n);
		f(i, n)cin >> c[i];
		sort(c.begin(), c.end());
		arr[0] = 1;
		sum[0] = 1;
		bool ac = true;
		if (c[0] != 1)ac = false;
		else {
			ff(i, 1, n) {
				if (c[i] > sum[i - 1]) { ac = false; break; }
				else {
					arr[i] = c[i];
					sum[i] = c[i] + sum[i - 1];
				}
			}
		}
		if (ac)yes;
		else no;
	}
}