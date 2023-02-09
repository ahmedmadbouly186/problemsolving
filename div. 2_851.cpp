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
void prob_e(void);
void prob_f(void);
void prob_g1(void);
void prob_g2(void);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		if (n % 2 == 0)cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int>arr1(n);
			vector<int>arr2(n);
			f(i, n)arr1[i] = i + 1;
			f(i, n)arr2[i] = arr1[i] + n;
			int index1 = 0;
			int index2 = (n + 1) / 2 - 1;
			f(i, n) {
				if (index1 < 0)index1 = n - 1;
				if (index2 < 0)index2 = n - 1;
				cout << arr1[index1] << " " << arr2[index2] << endl;;
				index1 -= 1;
				index2 -= 1;
			}
		}
	}

	return 0;
}

void prob_a(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<int>arr(n);
		int count_2 = 0;
		f(i, n) {
			cin >> arr[i];
			if (arr[i] == 2)count_2 += 1;
		}
		if (count_2 % 2 == 1)cout << -1 << endl;
		else {
			count_2 /= 2;
			f(i, n) {
				if (arr[i] == 2)count_2 -= 1;
				if (count_2 == 0) {
					cout << i + 1 << endl;
					break;
				}
			}
		}
	}
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		int a = 0, b = 0;
		bool flag = 0;
		int count = 0;
		while (n)
		{
			int unit = n % 10;
			a += pow(10, count) * (unit / 2);
			b += pow(10, count) * (unit / 2);
			if (unit % 2 == 1) {
				if (flag)a += pow(10, count);
				else b += pow(10, count);
				flag = !flag;
			}
			count++;
			n /= 10;
		}
		cout << a << " " << b << endl;
	}
}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		if (n % 2 == 0)cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int>arr1(n);
			vector<int>arr2(n);
			f(i, n)arr1[i] = i + 1;
			f(i, n)arr2[i] = arr1[i] + n;
			int index1 = 0;
			int index2 = (n + 1) / 2 - 1;
			f(i, n) {
				if (index1 < 0)index1 = n - 1;
				if (index2 < 0)index2 = n - 1;
				cout << arr1[index1] << " " << arr2[index2] << endl;;
				index1 -= 1;
				index2 -= 1;
			}
		}
	}
}
void prob_d(void) {

}
void prob_e(void) {

}
void prob_f(void) {

}
void prob_g1(void) {

}
void prob_g2(void) {

}