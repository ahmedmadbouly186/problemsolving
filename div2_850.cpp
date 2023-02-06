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
void prob_a2(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g1(void);
void prob_g2(void);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}

void prob_a2(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n; cin >> n;
		ll sumA = 1, sumB = 0;
		ll oddA = 1, oddB = 0, evenA = 0, evenB = 0;
		int i = 2;
		int cas = 1;
		n--;
		while (n)
		{
			int num = min(n, i);
			int start = 1 + sumA + sumB;
			if (cas == 1 || cas == 2) {
				sumB += num;
				int add_even = 0;
				if (start % 2 == 1)add_even = num / 2;
				else add_even = (num + 1) / 2;
				evenB += add_even;
				oddB += num - add_even;

			}
			else if (cas == 3 || cas == 4) {
				sumA += num;
				int add_even = 0;
				if (start % 2 == 1)add_even += num / 2;
				else add_even += (num + 1) / 2;
				evenA += add_even;
				oddA += num - add_even;
			}

			if (cas == 4)cas = 0;
			cas++;
			i++;
			n -= num;
		}
		cout << oddA << " " << evenA << " " << oddB << " " << evenB << endl;
	}
}
void prob_b(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n, w, h; cin >> n >> w >> h;
		vector<int>a(n), b(n);
		f(i, n)cin >> a[i];
		f(i, n)cin >> b[i];
		int mini = 2147483647;
		/*f(i, n - 1) {
			mini = min(mini, b[i + 1] - b[i]);
		}*/
		bool find = true;
		if (n >= 1) {
			int pos = b[0] + h - w;
			int ac = min(b[0] - h - (pos - w), b[1] - h - 1 - (pos + w));
			ff(i, 1, n) {
				pos += (a[i] - a[i - 1]);
				if (b[i] - h < pos - w)find = false;
				if (b[i] + h - (pos + w) > ac)find = false;
				else if (b[i] + h > pos + w) {
					int new_pos = b[i] + h - w;
					ac -= new_pos - pos;
					pos = new_pos;
				}

				if (find == false)break;
				if (i < n - 1) {
					ac = min(ac, b[i + 1] - h - 1 - (pos + w));
				}
				ac = min(ac, b[i] - h - (pos - w));
			}
		}
		if (find)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
void prob_c(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		int n; cin >> n;
		vector<ll>arr(n);
		f(i, n)cin >> arr[i];
		sort(arr.begin(), arr.end());
		ll sum = arr[0] - 1;
		arr[0] = 1;
		ff(i, 1, n) {
			if (arr[i] - arr[i - 1] > 1)sum += arr[i] - (1 + arr[i - 1]);
			arr[i] = min(arr[i], arr[i - 1] + 1);
		}
		cout << sum << endl;
	}
}
