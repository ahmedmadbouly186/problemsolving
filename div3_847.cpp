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

void prob_a(void);
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
void prob_a(void) {
	int t; cin >> t;
	string pi = "314159265358979323846264338327";
	f(tt, t) {

		string s; cin >> s;
		int count = 0;
		f(i, s.size())if (s[i] == pi[i])count++; else break;
		cout << count << endl;

	}
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, s, r; cin >> n >> s >> r;
		int stall = s - r;
		vector<int >arr(n - 1, 1);
		int remain = r - (n - 1);
		f(i, n - 1) {
			int plus = min(min(remain, 5), stall - 1);
			remain -= plus;
			arr[i] += plus;
			cout << arr[i] << " ";
		}
		cout << stall << endl;;

	}
}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<int>arr(n);
		vector<vector<int>>data(n, vector<int>(n - 1));
		f(i, n)f(j, n - 1)cin >> data[i][j];
		vector<int>freq(n + 1);
		f(i, n) {
			freq[data[i][0]]++;
		}
		ff(i, 1, n + 1) {
			if (freq[i] == 1)arr[1] = i;
			else if (freq[i] > 1)arr[0] = i;
		}
		ff(i, 1, n - 1) {
			f(j, n) {
				if (data[j][i] != arr[i]) {
					arr[i + 1] = data[j][i];
					break;
				}
			}
		}
		f(i, n)cout << arr[i] << " ";
		cout << endl;
	}
}
void prob_d(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<int>arr(n);
		map<int, int>m;
		set<int>s;
		f(i, n) {
			cin >> arr[i];
			m[arr[i]]++;
			s.insert(arr[i]);
		}
		int count = 0;
		for (auto a : s) {
			int c = m[a];

			if (m.find(a - 1) != m.end())
				count += max(0, c - m[a - 1]);
			else
				count += c;
		}
		cout << count << endl;
	}
}
void prob_e(void) {

}
void prob_f(void) {

}