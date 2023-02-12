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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	f(tt, t) {
		int n, k; cin >> n >> k;
		int seg = n / k;
		vector<int>freq(26);
		f(i, n) {
			char c;
			cin >> c;
			freq[c - 'a']++;
		}
		f(i, k) {
			int index = 0;
			while (index<seg &&freq[index])
			{
				freq[index]--;
				index++;
			}
			cout << (char)('a' + index);
		}
		cout << endl;
	}
}

void prob_a(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, k; cin >> n >> k;
		int seg = n / k;
		vector<int>freq(26);
		f(i, n) {
			char c;
			cin >> c;
			freq[c - 'a']++;
		}
		f(i, k) {
			int index = 0;
			while (index < seg && freq[index])
			{
				freq[index]--;
				index++;
			}
			cout << (char)('a' + index);
		}
		cout << endl;
	}
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		ll l, r; cin >> l >> r;
		ll bl = floorl(sqrtl(l)),br= floorl(sqrtl(r));
		ll sum1 = -ceil((l - bl * bl) / (double)bl);
		ll sum2 = (br - bl) * 3;
		ll sum3 = ceil((r - br * br + 1) / (double)br);
		cout << sum1 + sum2 + sum3 << endl;
	}
}
void prob_c(void) {

}