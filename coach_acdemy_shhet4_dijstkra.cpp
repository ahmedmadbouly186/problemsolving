
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
#include <iterator> // for iterators
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;
#define f(x, y) for (ll x = 0; x < y; x++)
#define ff(x, z, y) for (ll x = z; x < y; x++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define print1(x) cout << "out: " << x << endl
#define print(x) cout << x << endl
#define is_odd(x) (x % 2 != 0)
#define all(v) v.begin(), v.end()
#define sortv(v) sort(all(v))
vector<vector<pair<int, ll>>> g;
vector<ll> dist;
vector<int> par;
int n, m, k;
////// solution for problem a
void dijstkra_a(int src);
void prob_a(void);

////// solution for problem b
void dijstkra_b(int src);
void path_b(int src);
void prob_b(void);

////// solution for problem c
void dijstkra_c();
void prob_c(void);

////// solution for problem d
void dijstkra_d(int);
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prob_d();
	return 0;
}

void dijstkra_a(int src)
{
	dist[src] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push({0, src});
	while (!pq.empty())
	{
		int node = pq.top().second;
		ll cur_cost = pq.top().first;
		pq.pop();
		if (dist[node] < cur_cost)
			continue;
		for (auto &ch : g[node])
		{
			int next_node = ch.first;
			ll next_cost = cur_cost + ch.second;
			if (dist[next_node] > next_cost)
			{
				dist[next_node] = next_cost;
				pq.push({next_cost, next_node});
			}
		}
	}
}
void prob_a(void)
{
	int t = 1;
	cin >> t;
	f(tt, t)
	{
		int src, dis;
		cin >> n >> m >> src >> dis;
		g = vector<vector<pair<int, ll>>>(1 + n);
		dist = vector<ll>(1 + n, 1e12);
		f(i, m)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		dijstkra_a(src);
		if (dist[dis] == 1e12)
			print("NONE");
		else
			print(dist[dis]);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dijstkra_b(int src)
{
	dist[src] = 0;
	par[src] = -1;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push({0, src});
	while (!pq.empty())
	{
		ll current_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (current_dist > dist[cur_node])
			continue;
		for (auto &ch : g[cur_node])
		{
			int next = ch.first;
			ll next_dist = current_dist + ch.second;
			if (next_dist < dist[next])
			{
				dist[next] = next_dist;
				par[next] = cur_node;
				pq.push({next_dist, next});
			}
		}
	}
}
void path_b(int node)
{
	if (par[node] != -1)
		path_b(par[node]);
	cout << node << " ";
}
void prob_b(void)
{
	int t = 1;
	// cin >> t;
	f(tt, t)
	{
		cin >> n >> m;
		g = vector<vector<pair<int, ll>>>(1 + n);
		dist = vector<ll>(1 + n, 1e17);
		par = vector<int>(1 + n, 0);
		f(i, m)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		dijstkra_b(1);
		if (par[n] == 0)
			print(-1);
		else
			path_b(n);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dijstkra_c()
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	ff(i, 1, 1 + n)
	{
		pq.push({dist[i], i});
	}
	while (!pq.empty())
	{
		ll cur = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cur)
			continue;
		for (auto &ch : g[node])
		{
			int next = ch.first;
			ll next_len = cur + ch.second;
			if (next_len < dist[next])
			{
				dist[next] = next_len;
				pq.push({dist[next], next});
			}
		}
	}
}
void prob_c(void)
{
	int t = 1;
	// cin >> t;
	f(tt, t)
	{
		cin >> n >> m;
		g = vector<vector<pair<int, ll>>>(1 + n);
		dist = vector<ll>(1 + n);
		f(i, m)
		{
			int u, v;
			ll w;
			cin >> u >> v >> w;
			w *= 2;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		f(i, n)
		{
			ll a;
			cin >> a;
			dist[i + 1] = a;
		}
		dijstkra_c();
		ff(i, 1, 1 + n)
		{
			cout << dist[i] << " ";
		}
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dijstkra_d(int src)
{
	dist[src] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({0, src});
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cur_cost = abs(pq.top().first);
		pq.pop();
		if (dist[node] < cur_cost)
			continue;
		for (auto &ch : g[node])
		{
			int nex = ch.first;
			int next_cost = ch.second + cur_cost;
			if (dist[nex] <= next_cost)
				continue;
			dist[nex] = next_cost;
			pq.push({next_cost * -1ll, nex});
		}
	}
}

void prob_d(void)
{
	int t;
	cin >> t;
	f(tt, t)
	{
		int s, d;
		cin >> n >> m >> s >> d;
		g = vector<vector<pair<int, ll>>>(1 + n);
		dist = vector<ll>(1 + n, 1e17);
		f(i, m)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		dijstkra_d(s);
		cout << "Case #" << tt + 1 << ": ";
		if (dist[d] == 1e17)
			cout << "unreachable";
		else
			cout << dist[d];
		cout << endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void prob_e(void)
{
}
void prob_f(void)
{
}
void prob_g(void)
{
}
void prob_h(void)
{
}
void prob_i(void)
{
}
void prob_j(void)
{
}
void prob_k(void)
{
}
void prob_l(void)
{
}
void prob_M(void)
{
}
void prob_N(void)
{
}
void prob_O(void)
{
}
void prob_P(void)
{
}