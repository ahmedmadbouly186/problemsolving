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

using namespace std;
typedef long long ll;
#define f(x,y) for(ll x=0;x<y;x++)
#define ff(x,z,y) for(ll x=z;x<y;x++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define print(x) cout<<x<<endl
#define is_odd(x) (x%2!=0)
void prob_a(void);
void prob_b(void);
void prob_c(void);
void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g(void);
void prob_h(void);
void prob_i(void);
void prob_j(void);
void prob_k(void);
void prob_l(void);

void prob_a(void) {

}
void prob_b(void) {

}
void prob_c(void) {

}
void prob_d(void) {

}
void prob_e(void) {

}
void prob_f(void) {

}
void prob_g(void) {

}
void prob_h(void) {

}
void prob_i(void) {

}
void prob_j(void) {

}
void prob_k(void) {

}
void prob_l(void) {

}
/// <summary>
/// return the gcd greatest comon divisor of a and b
/// </summary>
long long  gcd(long long  a, long long b) {
	if (a == 1 || b == 1)return 1;
	else if (a == 0)return b;
	else if (b == 0)return a;
	return gcd(b, a % b);
}
/// <summary>
/// return the gcd least comon multiblier of a and b
/// </summary>
long long  lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}
void comb(int N, int K)
{
	std::string bitmask(K, 1); // K leading 1's
	bitmask.resize(N, 0); // N-K trailing 0's

	// print integers and permute bitmask
	do {
		for (int i = 0; i < N; ++i) // [0..N-1] integers
		{
			if (bitmask[i]) std::cout << " " << i;
		}
		std::cout << std::endl;
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int upper(vector<ll>arr, ll value) {
	int start = 0, end = arr.size() - 1, mid = -1;

	if (arr.size() > 0 && arr[arr.size() - 1] < value)
		return -1;
	while (start <= end)
	{
		mid = (end + start) / 2;

		if (arr[mid] == value)
			return mid;
		else if (arr[mid] > value && mid == 0)
			return mid;
		else if (arr[mid] > value && arr[mid - 1] < value)
			return mid;
		else if (arr[mid] > value)
			end = mid - 1;
		else
			start = mid + 1;

	}
	return -1;
}

int lower(vector<ll>arr, ll value) {
	int start = 0, end = arr.size() - 1, mid = -1;

	if (arr.size() > 0 && arr[0] > value)
		return -1;
	while (start <= end)
	{
		mid = (end + start) / 2;


		if (arr[mid] < value && mid == (arr.size() - 1))
			return mid;
		else if (arr[mid] < value && arr[mid + 1] >= value)
			return mid;
		else if (arr[mid] >= value)
			end = mid - 1;
		else
			start = mid + 1;

	}
	return -1;
}
int equal(vector<ll>arr, ll value) {
	int start = 0, end = arr.size() - 1, mid = -1;

	while (start <= end)
	{
		mid = (end + start) / 2;


		if (arr[mid] == value)
			return mid;
		else if (arr[mid] > value)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}



///////////////////////////// segmant tree in special case of number of elements in specific range /////////////////////

int getRange(vector<int>& st, int si, int qs, int qe, int ss, int se) {
	if (ss >= qs && se <= qe)
		return st[si];
	if (qe<ss || qs>se)
		return 0;
	int mid = (ss + se) / 2;
	return getRange(st, 2 * si + 1, qs, qe, ss, mid) +
		getRange(st, 2 * si + 2, qs, qe, mid + 1, se);
}
void increment(vector<int>& st, int si, int ss, int se, int index) {
	/// ss strat
	/// se end
	/// 
	if (index<ss || index> se)
		return;
	st[si]++;
	if (se == ss)
		return;
	int mid = (ss + se) / 2;
	increment(st, si * 2 + 1, ss, mid, index);
	increment(st, si * 2 + 2, mid + 1, se, index);

}
/// <summary>
/// n is the numebr of elements in arr 
/// </summary>
int h = (int)(ceil(log2(n)));
int size = 2 * (1 << h) - 1;
vector<int>st(size, 0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////