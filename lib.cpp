#pragma GCC optimization("Ofast")
//#pragma GCC target("popcnt")

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
typedef long long ll;
typedef vector<vector<int>> matrix;
#define f(x,y) for(ll x=0;x<y;x++)
#define ff(x,z,y) for(ll x=z;x<y;x++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define print(x) cout<<x<<endl
#define is_odd(x) (x%2!=0)
#define FIO	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))

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

void prob_M(void);
void prob_N(void);
void prob_O(void);
void prob_P(void);

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
void prob_M(void) {

}
void prob_N(void) {

}
void prob_O(void) {

}
void prob_P(void) {

}

template <typename T>
bool is_prime(T n) {
	if (n == 2)return true;
	if (n == 0 || n == 1 || n % 2 == 0)return false;
	T  sqr = sqrt(n);
	for (T i = 3; i <= sqr; i += 2)
	{
		if (n % i == 0)return false;
	}
	return true;
}
/// <summary>
/// return the gcd greatest comon divisor of a and b
/// </summary>
template <typename T>
T  gcd(T  a, T b) {
	if (a == 1 || b == 1)return 1;
	else if (a == 0)return b;
	else if (b == 0)return a;
	return gcd(b, a % b);
}
/// <summary>
/// return the gcd least comon multiblier of a and b
/// </summary>
template <typename T>
T  lcm(T a, T b) {
	return a * b / gcd(a, b);
}
/// <summary>
/// count the number of digit in number
/// </summary>
/// <typeparam name="T"> prefer to be integer like short or long or long long</typeparam>
/// <param name="num">the input number that we need to calc the number of digits for it</param>
/// <returns>the number of digiets</returns>
template <typename T>
T count_digit(T num) {
	int count = 0;
	while (num != 0) {
		num = num / 10;
		count++;
	}
	return count;

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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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
/////////////////////////////////////////////////////////////// Heap sort ///////////////////////////////////////////

void push_down(vector<int>& v, int idx, int sz) {
	while (idx < sz) {
		int lf = 2 * idx + 1, rt = lf + 1, mx;
		if (lf >= sz)
			break;
		else if (rt >= sz) mx = lf;
		else mx = v[lf] > v[rt] ? lf : rt;
		if (v[mx] > v[idx])
			swap(v[mx], v[idx]), idx = mx;
		else break;

	}
}
void push_up(vector<int>& v, int idx) {
	while (idx) {
		int p = (idx - 1) / 2;
		if (v[p] < v[idx])
			swap(v[p], v[idx]), idx = p;
		else break;
	}
}
void add(vector<int>& v, int val, int sz) {
	v[sz] = val;
	push_up(v, sz);
}
void remove_max(vector<int>& v, int sz) {
	v[0] = v[--sz];
	push_down(v, 0, sz);
}
void heap_sort(vector<int>& v) {
	for (int sz = 1; sz < v.size(); ++sz)
		add(v, v[sz], sz);
	for (int sz = v.size(); sz > 0; --sz) {
		int mx = v[0];
		remove_max(v, sz);
		v[sz - 1] = mx;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// DSU ///////////////////////////////////////////////////////
const int N = 1e6 + 10;
int par[N];
void init(int n) {
	for (int i = 1; i <= n; i++)
		par[i] = i;
}
int find_parent(int u) {
	if (par[u] == u)return u;
	else return par[u] = find_parent(par[u]);
}

bool is_con(int u, int v) {
	return find_parent(u) == find_parent(v);
}

void con(int u, int v) {
	if (is_con(u, v))return;
	u = find_parent(u);
	v = find_parent(v);
	par[u] = v;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// Dijkstra //////////////////////////////////////////////////////////////
//complixty = O(E + vlog(v) )
vector<vector<pair<int, int>>> g;
vector<ll>dist;
vector<int>par;
int n, m;
void test_case() {
	cin >> n >> m;
	g = vector<vector<pair<int, int>>>(n + 1);
	dist = vector<ll>(n + 1, 1e17);
	par = vector<int>(n + 1, -1);
	f(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
}
void dijkstra(int src) {
	dist[src] = 0;
	par[src] = -1;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>>pq;
	pq.push({ 0,src });
	while (!pq.empty())
	{
		ll curent_cost = pq.top().first, node = pq.top().second;
		pq.pop();
		if (curent_cost > dist[node])continue;
		for (auto x:g[node])
		{
			int next = x.first;
			ll next_cost = curent_cost + x.second;
			if (next_cost < dist[next])
			{
				pq.push({ next_cost,next });
				par[next] = node;
				dist[node] = curent_cost;
			}
		}
	}
}
void path(int node) {
	if (par[node] != -1)
		path(par[node]);
	cout << node << " ";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////