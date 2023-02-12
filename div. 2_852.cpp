#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
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
void prob_d(void);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	prob_d();
	return 0;
}

void prob_a(void) {
	int t; cin >> t;
	f(tt, t) {
		ll a, b, n, m;
		cin >> a >> b >> n >> m;
		ll sum = 0;
		ll units = n / (m + 1);
		if (m >= n) {
			sum = min(a, b) * n;
		}
		else {
			sum += min(units * m * a, units * (m + 1) * b);
			ll remain = n - units * (m + 1);
			sum += min(a, b) * remain;
		}
		cout << sum << endl;
	}
}
void prob_b(void) {
	int t; cin >> t;
	vector<int>arr(2e5 + 1, 0);
	f(tt, t) {
		int x, y;
		cin >> x >> y;
		int num = 1;
		arr[0] = y;
		ff(i, y + 1, x + 1) {
			arr[num++] = i;
		}
		for (int i = x - 1; i >= y + 1; i--) {
			arr[num++] = i;
		}
		cout << num << endl;
		f(i, num)cout << arr[i] << " ";
		cout << endl;
	}
}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		int n;
		cin >> n;
		vector<int>arr(n);
		f(i, n)cin >> arr[i];
		int mini = 1;
		int maxi = n;
		int start = 1, end = n;
		bool find = false;
		while (end - start + 1 >= 4)
		{
			if (arr[start - 1] == mini) {
				mini++;
				start++;
			}
			else if (arr[start - 1] == maxi) {
				maxi--;
				start++;
			}
			else if (arr[end - 1] == mini) {
				mini++;
				end--;
			}
			else if (arr[end - 1] == maxi) {
				maxi--;
				end--;
			}
			else {
				find = true;
				break;
			}
		}
		if (find)cout << start << " " << end << endl;
		else cout << -1 << endl;
	}
}
void prob_d(void) {
	ll t = 1;
	//cin >> t;
	f(tt, t) {
		ll  n;
		cin >> n;
		map<ll, ll>p, q;
		f(i, n) {
			int x;
			cin >> x;
			p[x] = i;
		}
		f(i, n) {
			int x; cin >> x;
			q[x] = i;
		}
		ll start = min(p[1], q[1]);
		ll end = max(p[1], q[1]);
		ll sum = 0;
		ll unit = start;
		sum += unit * (unit + 1) / 2;
		unit = n - 1 - end;
		sum += unit * (unit + 1) / 2;
		unit = end - 1 - start;
		sum += unit * (unit + 1) / 2;
		ff(i, 2, n + 1) {
			ll qi = q[i], pi = p[i];
			if (pi < start && qi < start)sum += (1 + (n - 1 - end)) * (1 + (start - 1 - max(pi, qi)));
			if (pi > end && qi > end)sum += (1 + start) * (1 + (min(qi, pi) - 1 - end));
			if (min(pi, qi) < start && max(pi, qi) > end) sum += (1 + (start - 1 - min(pi, qi))) * (1 + (max(pi, qi) - 1 - end));
			start = min(start, min(qi, pi));
			end = max(end, max(pi, qi));
		}

		cout << sum + 1 << endl;;
	}
}
