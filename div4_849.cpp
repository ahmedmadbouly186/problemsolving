#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long
#define f(i,x)	for(ll i=0;i<x;i++)
#define ff(i,x,y)	for(int i=x;i<y;i++)
#define fff(x,y)	for(int i=x;i<y;i++)

void prob_a(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g1(void);
void prob_g2(void);

void vote(vector<int>& st, int si, int qs, int qe, int ss, int se) {
	if (ss >= qs && se <= qe)
	{
		st[si]++;
		return;
	}
	if (qe<ss || qs>se)return;
	int mid = (ss + se) / 2;
	vote(st, 2 * si + 1, qs, qe, ss, mid);
	vote(st, 2 * si + 2, qs, qe, mid + 1, se);
}
int get_votes(vector<int>& st, int si, int ss, int se, int index) {
	if (index == ss && se == index)
	{
		return st[si];
	}
	if (index<ss || index> se)
		return 0;
	int mid = (ss + se) / 2;
	int val1 = get_votes(st, si * 2 + 1, ss, mid, index);
	int val2 = get_votes(st, si * 2 + 2, mid + 1, se, index);
	return val1 + val2 + st[si];

}
unordered_map<int, int>values;

int sum_deg(int n) {
	if (values.find(n) != values.end())return values[n];
	if (n == 0)return 0;
	int out = n % 10 + sum_deg(n / 10);
	values[n] = out;
	return out;
}
long long  gcd(long long  a, long long b) {
	if (a == 1 || b == 1)return 1;
	else if (a == 0)return b;
	else if (b == 0)return a;
	return gcd(b, a % b);
}
long long  lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	ff(tt, 0, t) {
		
	}
	return 0;
}



void prob_a(void) {
	int t; cin >> t;
	string s = "codeforces";

	ff(tt, 0, t) {
		char c;
		cin >> c;
		bool find = false;
		f(i, s.size())if (c == s[i])find = true;
		if (find)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
void prob_b(void)
{
	int t; cin >> t;

	ff(tt, 0, t) {
		int n; cin >> n;
		int x = 0, y = 0;
		bool find = false;
		f(i, n) {
			char c; cin >> c;
			if (c == 'L')x--;
			else if (c == 'R')x++;
			else if (c == 'U')y++;
			else y--;
			if (x == 1 && y == 1)find = true;
		}
		if (find)cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}
void prob_c(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n; cin >> n;
		vector<char>s(n);
		f(i, n)cin >> s[i];
		int moves = 0;
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			if (s[i] != s[j])moves++;
			else break;
		}
		cout << n - 2 * moves << endl;;

	}
}
void prob_d(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n; cin >> n;
		vector<char>s(n);
		vector<int>a(26), b(26);
		f(i, n) {
			cin >> s[i];
			b[s[i] - 'a']++;
		}
		int fa = 0, fb = 0;
		f(i, 26)if (b[i])fb++;
		int maxi = fb;
		f(i, n) {
			a[s[i] - 'a']++;
			b[s[i] - 'a']--;
			if (!b[s[i] - 'a'])fb--;
			if (a[s[i] - 'a'] == 1)fa++;
			maxi = max(maxi, fa + fb);
		}
		cout << maxi << endl;
	}
}
void prob_e(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n; cin >> n;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		ll sum = 0;
		ll temp = 0;
		ll num = 0;
		ll mini = 2147483647;
		f(i, n) {
			sum += abs(arr[i]);
			if (arr[i] <= 0)num++;
			mini = min(mini, abs(arr[i]));
		}
		if (num % 2 != 0)sum -= 2 * mini;
		cout << sum << endl;
	}
}

void prob_f(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int q, n; cin >> n >> q;
		vector<int>arr(n);
		vector<int>neg_votes(n);
		f(i, n)cin >> arr[i];
		int h = (int)(ceil(log2(n)));
		int size = 2 * (1 << h) - 1;
		vector<int>st(size, 0);
		f(i, q) {
			int type; cin >> type;
			if (type == 1) {
				int s, e; cin >> s >> e;
				vote(st, 0, s - 1, e - 1, 0, n - 1);
			}
			else {
				int index; cin >> index;
				int number = neg_votes[index - 1] + get_votes(st, 0, 0, n - 1, index - 1);
				neg_votes[index - 1] -= number;
				while (number--)
				{
					arr[index - 1] = sum_deg(arr[index - 1]);
					if (arr[index - 1] < 10)break;
				}
				cout << arr[index - 1] << endl;
			}
		}
	}
}
void prob_g1(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		ll n, c; cin >> n >> c;
		vector<ll>arr(n);
		f(i, n) {
			cin >> arr[i];
			arr[i] += i + 1;
		}
		int count = 0;
		sort(arr.begin(), arr.end());
		ll sum = 0;
		f(i, n) {
			sum += arr[i];
			if (sum <= c)count++;
			else break;
		}
		cout << count << endl;
	}
}
void prob_g2(void) {

}