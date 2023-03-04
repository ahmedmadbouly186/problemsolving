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

void prob_a(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);

bool is_prime(int n) {
	if (n == 2)return true;
	if (n == 0 || n == 1 || n%2==0)return false;
	int sqr = sqrt(n);
	for (int  i = 3; i <= sqr; i+=2)
	{
		if (n % i == 0)return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	const ll mod = 998244353;
	ll n; cin >> n;
	vector<int>arr(n * 2);
	vector<int >freq(1000001, 0);
	f(i, 2*n)cin >> arr[i];
	f(i, 2 * n)freq[arr[i]]++;
	set<int>s;
	f(i, 2 * n)
		if (is_prime(arr[i]))
			s.insert(arr[i]);
	int x = 0;
	if (s.size() < n)cout << 0 << endl;
	else if (s.size() == n) {
		int counter = 0;
		f(i, 2 * n) {
			counter += freq[arr[i]];
			if (s.find(arr[i]) == s.end())
				counter --;
		}

	}
	else {

	}
	return 0;
}



void prob_a(void) {
	int t; cin >> t;

	ff(tt, 0, t) {
		ll n; cin >> n;
		vector<string>data(2 * n - 2);
		vector<string>test(0);
		f(i, 2 * n - 2) {
			cin >> data[i];
			if (data[i].size() == n - 1)test.push_back(data[i]);
		}
		string s1 = test[0];
		string s2 = test[1];
		bool ac = true;
		for (int i = 0, j = s2.size() - 1; i < s1.size(); i++, j--) {
			if (s1[i] != s2[j])
				ac = false;
		}
		if (ac)yes;
		else no;
	}
}
void prob_b(void) {
	int t; cin >> t;

	ff(tt, 0, t) {
		ll n; cin >> n;
		vector<int>arr(n);
		f(i, n)cin >> arr[i];
		f(i, n)if (arr[i] == 1)arr[i] = 2;
		f(i, n - 1) {
			if (arr[i + 1] % arr[i] == 0)arr[i + 1]++;
		}
		f(i, n)cout << arr[i] << " ";
		cout << endl;
	}
}
void prob_c(void) {
	int t; cin >> t;
	ff(tt, 0, t) {
		ll n; cin >> n;
		vector<int>arr(n);
		f(i, n)cin >> arr[i];
		vector<int>data(n, 0);
		f(i, n) {
			data[i]++;
			if (i + arr[i] < n)data[i + arr[i]]--;
		}
		ff(i, 1, n)data[i] += data[i - 1];
		f(i, n)cout << data[i] << " ";
		cout << endl;
	}
}

void prob_d(void) {
}