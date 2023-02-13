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
void dfs_a(vector<vector<int>>& edges, vector<bool>& visit, int node);

void prob_b(void);
//bool dfs_b(vector<vector<int>>&edges, vector<int>&visit, int node, bool type = 0);

void prob_c(void);
bool dfs_c(vector<vector<int>>& edges, vector<int>& visit, vector<int>& out, int node);

void prob_d(void);
int dfs_d(vector<vector<int>>& edges, vector<bool>& visit, int node);


void prob_e(void);
int dfs_e(map<string, vector<string>>& edges, map<string, bool>& visit, string animal);

void prob_f(void);
int dfs_f(vector<vector<int>>& edges, int node);

void prob_g(void);
void dfs_g(vector<vector<int>>& edges, vector<bool>& visit, int node);

void prob_h(void);
void dfs_h(vector<vector<int>>& edges, vector<bool>& visit, vector<int>& out, int node);

void prob_i(void);
void  dfs_i(vector<vector<int>>& edges, vector<bool>& visit, int node);

void prob_j(void);

void prob_k(void);
void dfs_k(map<int, vector<int>>& edges, int node);

void prob_l(void);
void dfs_l(vector<vector<int>>& edges, vector<bool>& visit, vector<int>& prev, int node);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	prob_j();

	return 0;
}

void dfs_a(vector<vector<int>>& edges, vector<bool>& visit, int node) {
	if (visit[node])return;
	visit[node] = 1;
	f(i, edges[node].size()) {
		if (!visit[edges[node][i]])
			dfs_a(edges, visit, edges[node][i]);
	}
}
void prob_a(void) {
	int n, m; cin >> n >> m;
	vector<vector<int>>arr(n + 1, vector<int>(0));
	vector<bool>visit(n + 1, 0);
	f(i, m) {
		int u, v; cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	if (m != n - 1)cout << "NO" << endl;
	else {

		dfs_a(arr, visit, 1);
		int count = 0;
		f(i, n + 1)count += visit[i];
		if (count == n)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}


bool dfs_b(vector<vector<int>>& edges, vector<int>& visit, int node, bool type = 0) {
	if (visit[node] != -1 && type != visit[node])return false;
	else if (visit[node] != -1 && type == visit[node])return true;
	visit[node] = type;
	bool ac = true;
	for (int i = 0; i < edges[node].size(); i++)
		ac &= dfs_b(edges, visit, edges[node][i], !type);
	return ac;
}
void prob_b(void) {
	int t; cin >> t;
	f(tt, t) {
		bool ac = true;;
		int n, m; cin >> n >> m;
		vector<vector<int>> edges(n + 1, vector<int>(0));
		vector<int> visit(n + 1, -1);
		f(i, m) {
			int u, v;
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for (int i = 1; i < n + 1; i++) {
			if (visit[i] == -1)
				ac &= dfs_b(edges, visit, i);
		}

		cout << "Scenario #" << tt + 1 << ":" << endl;
		if (ac)cout << "No suspicious bugs found!" << endl;
		else 	cout << "Suspicious bugs found!" << endl;
	}
}

bool dfs_c(vector<vector<int>>& edges, vector<int>& visit, vector<int>& out, int node) {
	if (visit[node] == 1)return true;
	else if (visit[node] == 0)return false;
	visit[node] = 0;
	bool could = true;
	f(i, edges[node].size()) {
		could &= dfs_c(edges, visit, out, edges[node][i]);
	}
	visit[node] = 1;
	out.push_back(node);
	return could;
}

void prob_c(void) {
	int n, m;
	//cin >> n ;

	while (true)
	{


		cin >> n >> m;
		if (n == 0)break;
		vector<vector<int>>edges(n + 1, vector<int>(0));
		vector<int>visit(n + 1, -1);
		vector<int>out;
		f(i, m) {
			int u, v; cin >> u >> v;
			edges[v].push_back(u);
		}
		bool ac = true;
		ff(i, 1, n + 1) {
			if (visit[i] == -1)
				ac &= dfs_c(edges, visit, out, i);
		}
		if (ac) {
			f(i, out.size())cout << out[i] << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
}
int dfs_d(vector<vector<int>>& edges, vector<bool>& visit, int node) {
	if (visit[node])return 0;
	visit[node] = true;
	int sum = 1;

	f(i, edges[node].size())sum += dfs_d(edges, visit, edges[node][i]);
	return sum;
}
void prob_d(void) {
	int t; cin >> t;
	f(tt, t) {
		int n, m; cin >> n >> m;
		vector<bool>visit(n + 1, false);
		vector<vector<int>>edges(n + 1, vector<int>(0));
		f(i, m) {
			int u, v; cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int maxi = 0;
		ff(i, 1, n + 1) {
			maxi = max(maxi, dfs_d(edges, visit, i));
		}
		cout << maxi << endl;
	}
}
int dfs_e(map<string, vector<string>>& edges, map<string, bool>& visit, string animal) {
	if (visit[animal])return 0;
	visit[animal] = 1;
	int sum = 1;
	vector<string>eat = edges[animal];
	f(i, eat.size()) {
		sum += dfs_e(edges, visit, eat[i]);
	}
	return sum;
}

void prob_e(void) {
	int n, m;
	while (true)
	{
		cin >> n >> m;
		if (n == 0)break;
		map<string, bool>visit;
		map<string, vector<string>>edges;
		f(i, n) {
			string s;
			cin >> s;
			visit[s] = false;
			edges[s] = vector<string>(0);
		}
		f(i, m) {
			string u, v;
			cin >> u >> v;
			edges[v].push_back(u);
		}
		int maxi = 0;
		for (auto x : edges) {
			visit.clear();
			maxi = max(maxi, dfs_e(edges, visit, x.first));
		}
		cout << maxi << endl;
	}

}
int dfs_f(vector<vector<int>>& edges, int node) {
	int maxi = 0;
	f(i, edges[node].size()) {
		maxi = max(maxi, dfs_f(edges, edges[node][i]));
	}
	return 1 + maxi;
}
void prob_f(void) {
	int n;
	cin >> n;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	ff(i, 1, n + 1) {
		int s; cin >> s;
		if (s != -1) {
			edges[s].push_back(i);
		}
	}
	int maxi = 0;
	ff(i, 1, n + 1) {
		maxi = max(maxi, dfs_f(edges, i));
	}
	cout << maxi << endl;
}
void dfs_g(vector<vector<int>>& edges, vector<bool>& visit, int node) {
	if (visit[node])return;
	visit[node] = 1;
	f(i, edges[node].size()) {
		dfs_g(edges, visit, edges[node][i]);
	}
}
void prob_g(void) {
	int n; cin >> n;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	vector<bool>visit(n + 1, 0);
	f(i, n) {
		int x; cin >> x;
		edges[i + 1].push_back(x);
		edges[x].push_back(i + 1);
	}
	int count = 0;
	ff(i, 1, n + 1) {
		if (visit[i] == 0) {
			count += 1;
			dfs_g(edges, visit, i);
		}
	}
	cout << count << endl;
}
void dfs_h(vector<vector<int>>& edges, vector<bool>& visit, vector<int>& out, int node) {
	if (visit[node])return;
	visit[node] = 1;
	f(i, edges[node].size()) {
		dfs_h(edges, visit, out, edges[node][i]);
	}
	out.push_back(node);
}

void prob_h(void) {
	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0)break;
		vector<vector<int>>edges(n + 1, vector<int>(0));
		vector<bool>visit(n + 1, 0);
		vector<int>out;
		f(i, m) {
			int u, v; cin >> u >> v;
			edges[v].push_back(u);
		}
		ff(i, 1, 1 + n) {
			dfs_h(edges, visit, out, i);
		}
		f(i, out.size()) {
			cout << out[i] << " ";
		}
		cout << endl;

	}
}
void  dfs_i(vector<vector<int>>& edges, vector<bool>& visit, int node) {
	if (visit[node])return;
	visit[node] = 1;
	long long sum = 1;
	f(i, edges[node].size()) {
		dfs_i(edges, visit, edges[node][i]);
	}
}
void prob_i(void) {
	long long n, m;
	cin >> n >> m;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	vector<bool>visit(n + 1);
	f(i, m) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	long long maxi = 0;
	ff(i, 1, n + 1) {
		if (visit[i] == 0) {
			maxi += 1;
			dfs_i(edges, visit, i);
		}
	}
	cout << (((long long)1) << (n - maxi)) << endl;
}
void prob_j(void) {
	
}
void dfs_k(map<int, vector<int>>& edges, int node) {
	if (edges[node].size() == 0) {
		cout << node << endl;
		return;
	}
	int next = edges[node][0];
	if (edges[next][0] == node)edges[next].erase(edges[next].begin());
	else edges[next].erase(edges[next].begin() + 1);
	cout << node << " ";
	dfs_k(edges, next);
}
void prob_k(void) {
	int n; cin >> n;
	map<int, vector<int>>edges;
	f(i, n) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int start = -1;
	for (auto x : edges)if (x.second.size() == 1) {
		start = x.first;
		break;
	}
	dfs_k(edges, start);
}
void dfs_l(vector<vector<int>>& edges, vector<bool>& visit, vector<int>& prev, int node) {
	visit[node] = true;
	f(i, edges[node].size()) {
		if (!visit[edges[node][i]]) {
			prev[edges[node][i]] = node;
			dfs_l(edges, visit, prev, edges[node][i]);
		}
	}
}
void prob_l(void) {
	int n, r, l;
	cin >> n >> r >> l;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	vector<bool>visit(n + 1, 0);
	vector<int>prev(n + 1, -1);
	ff(i, 1, n + 1) {
		if (i == r)continue;
		int x; cin >> x;
		edges[x].push_back(i);
		edges[i].push_back(x);
	}
	dfs_l(edges, visit, prev, l);
	ff(i, 1, n + 1) {
		if (i == l)continue;
		cout << prev[i] << " ";
	}
	cout << endl;

}