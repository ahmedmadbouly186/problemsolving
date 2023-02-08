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
bool dfs_b(vector<vector<int>>& edges, vector<bool>& visit, int node, bool type);

void prob_c(void);
bool dfs_c(vector<vector<int>>&edges, vector<int>&visit, vector<int>&out, int node);

void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g(void);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	prob_c();

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

		cout << "Scenario #" << tt+1 << ":" << endl;
		if (ac)cout << "No suspicious bugs found!" << endl;
		else 	cout << "Suspicious bugs found!" << endl;
	}
}

bool dfs_c(vector<vector<int>>& edges, vector<int>& visit,vector<int>&out, int node) {
	if (visit[node] == 1)return true;
	else if (visit[node] == 0)return false;
	visit[node] = 0;
	bool could = true;
	f(i, edges[node].size()) {
		could&=dfs_c(edges, visit, out, edges[node][i]);
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


		cin >>n>> m;
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
void prob_d(void) {

}
void prob_e(void) {

}
void prob_f(void) {

}
void prob_g(void) {

}
