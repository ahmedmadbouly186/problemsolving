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

int lower(vector<ll>& arr, ll taster, ll value) {

	int start = 0, end = arr.size() - 1 - taster, mid = -1;
	ll total = arr[arr.size() - 1 - taster];
	if (arr.size() > 1 && ((arr[end] - arr[end - 1]) > value))
		return -1;
	while (start <= end)
	{
		mid = (end + start) / 2;

		if (mid && (value >= (total - arr[mid])) && (value < (total - arr[mid - 1])))
			return arr.size()-1-taster-mid;
		else if ((mid==0)&&(value >= (total - arr[mid])) )
			return arr.size() - 1 - taster - mid;
		else if ((total-arr[mid]) > value)
			start = mid + 1;
		else
			end = mid - 1 ;

	}
	return -1;
}
void prob_a(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);
void prob_e(void);
void prob_f(void);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	return 0;
}


void prob_a(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, m; cin >> n >> m;
		string s1, s2; cin >> s1 >> s2;
		for (int i = s2.size() - 1; i >= 0; i--)
		{
			s1 += s2[i];
		}
		int neede = 0;
		f(i, s1.size() - 1) {
			if (s1[i] == s1[i + 1])neede += 1;
		}
		if (neede > 1)cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, k; cin >> n >> k;
		bool find = false;
		bool find2 = false;
		f(i, n) {
			int s, e;
			cin >> s >> e;
			if (k == s)find = true;
			if (k == e)find2 = true;
		}
		if (find && find2)cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}
void prob_c(void) {
	int t; cin >> t;
	f(tt, t) {
		int n; cin >> n;
		vector<ll>a(n), b(n);
		vector < ll>sum(n), end_serve(n, 0), add(n, 0);
		f(i, n)cin >> a[i];
		f(i, n)cin >> b[i];
		f(i, n) {
			sum[i] = b[n - 1 - i];
			if (i)sum[i] += sum[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int people = n - i;
			if (a[i] >= sum[people - 1])
				end_serve[i + people - 1]++;
			else {
				if (b[i] > a[i])add[i] = a[i];
				else {
					int num = lower(sum, i, a[i]);
					end_serve[i + num - 1]++;
					add[i + num] += (a[i] - (sum[people - 1] - sum[people - num - 1]));
				}
			}
		}
		int serve = 0;
		f(i, n) {
			if (a[i] >= b[i])serve++;
			cout << serve * b[i] + add[i] << " ";
			serve -= end_serve[i];
		}
		cout << endl;
	}
}
void prob_d(void) {

}
void prob_e(void) {

}
void prob_f(void) {

}