#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define f(i,x)	for(ll i=0;i<x;i++)
#define ff(i,x,y)	for(int i=x;i<y;i++)
#define fff(x,y)	for(int i=x;i<y;i++)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl

void BFS_a(vector<vector<int>>& edges, vector<int>& visit, int n, int start);
void prob_a(void);

void prob_b(void);

void BFS_C(vector<int>& visit, int start, int target);
void prob_c(void);

void prob_d(void);
void prob_e(void);
void prob_f(void);
void prob_g(void);
void prob_h(void);
void prob_i(void);

void BFS_j(vector<vector<char>>& maze, vector<pair<int, int>>& out, int startx, int starty);
void prob_j(void);

ll BFS_k(vector<vector<int>>& edges, vector<ll>& visit, int node, ll val);
void prob_k(void);

void prob_l(void);
void prob_M(void);
void prob_N(void);

/// <summary>
/// BFS code inside the func itself
/// </summary>
void prob_O(void);

void prob_P(void);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	prob_N();
	return 0;
}
void BFS_a(vector<vector<int>>& edges, vector<int>& visit, int n, int start) {
	queue<int>q;
	visit[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		for (auto x : edges[node])
		{
			if (visit[x] == -1) {
				q.push(x);
				visit[x] = visit[node] + 1;
			}
		}
		q.pop();
	}
}
void prob_a(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>edges(n + 1, vector<int>(0)); vector<int> visit(n + 1, -1);
	f(i, m) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	BFS_a(edges, visit, n, 1);
	int cnt = 0;
	ff(i, 1, n + 1) {
		if (visit[i] != -1)cnt++;
	}
	if (cnt == n && m == n - 1)cout << "yes" << endl;
	else cout << "no" << endl;
}
void prob_b(void) {

}
void BFS_C(vector<int>& visit, int start, int target) {
	int cur = start;
	queue<int>q;
	q.push(cur);
	visit[cur] = 0;
	while (cur != target)
	{
		cur = q.front();
		if (cur - 1 > 0 && visit[cur - 1] == -1) {
			visit[cur - 1] = visit[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 > 0 && cur < target && visit[cur * 2] == -1) {
			visit[cur * 2] = visit[cur] + 1;
			q.push(cur * 2);
		}
		q.pop();
	}
}
void prob_c(void) {
	int n, m;
	cin >> n >> m;
	vector<int> visit(1e5, -1);
	BFS_C(visit, n, m);
	cout << visit[m] << endl;
}
void prob_d(void) {
	int n, m; cin >> n >> m;
	vector<vector<int>>forest(n + 1, vector<int>(m + 1, -1));
	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	int k; cin >> k;
	queue<pair<int, int>>q;
	f(i, k) {
		int u, v; cin >> u >> v;
		forest[u][v] = 0;
		q.push({ u,v });
	}
	while (!q.empty())
	{
		int cury = q.front().first, curx = q.front().second;
		f(i, 4)
			if (cury + dy[i] >= 1 && cury + dy[i] <= n && curx + dx[i] >= 1 && curx + dx[i] <= m && forest[cury + dy[i]][curx + dx[i]] == -1)
			{
				forest[cury + dy[i]][curx + dx[i]] = forest[cury][curx] + 1;
				q.push({ cury + dy[i],curx + dx[i] });
			}
		q.pop();
	}
	int maxi = -1;
	int indexx = -1, indexy = -1;
	ff(i, 1, n + 1)
		ff(j, 1, 1 + m)
		if (forest[i][j] > maxi) {
			maxi = forest[i][j];
			indexy = i;
			indexx = j;
		}
	cout << indexy << " " << indexx << endl;

}
void prob_e(void) {

}
void prob_f(void) {

}
void prob_g(void) {

}

ll BFS_h(vector<vector<int>>& edges, vector<ll>& visit, int node, ll val) {
	if (visit[node] != -1)return 0;
	visit[node] = 0;
	ll maxi1 = 0;
	ll maxi2 = 0;
	for (auto x : edges[node]) {
		ll out = BFS_h(edges, visit, x, val + 1);
		if (out > maxi1) {
			maxi2 = maxi1; maxi1 = out;
		}
		else if (out > maxi2)maxi2 = out;
	}
	maxi2 = max(maxi2, val);
	visit[node] = maxi1 + maxi2;
	return maxi1 + 1;
}
void prob_h(void) {
	int n, m; cin >> n >> m;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	f(i, m) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<ll> visit(n + 1, -1);
	BFS_h(edges, visit, 1, 0);
	ll out = -1;
	ff(i, 1, n + 1)out = max(out, visit[i]);
	cout << out << endl;
}
void prob_i(void) {

}

void BFS_j(vector<vector<char>>& maze, vector<pair<int, int>>& out, int startx, int starty) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	int n = maze.size();
	int m = maze[0].size();
	vector<vector<bool>>visit(n, vector<bool>(m, false));
	visit[startx][starty] = true;
	queue<pair<int, int>>q;
	q.push({ startx,starty });
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		f(i, 4) {
			int childx = curx + dx[i];
			int childy = cury + dy[i];
			if (childx >= 0 && childx < n && childy >= 0 && childy < m && visit[childx][childy] == false && maze[childx][childy] == '.') {
				visit[childx][childy] = true;
				q.push({ childx ,childy });
			}
		}

		q.pop();
		out.push_back({ curx,cury });
	}

}
void prob_j(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char>>maze(n, vector<char>(m));
	f(i, n)
		f(j, m)
		cin >> maze[i][j];
	vector<pair<int, int>>out;
	bool find = false;
	f(i, n) {
		f(j, m)
			if (maze[i][j] == '.') {
				BFS_j(maze, out, i, j);
				find = true;
				break;
			}
		if (find)break;
	}
	for (int i = out.size() - 1; i > (out.size() - 1 - k); i--)
	{

		maze[out[i].first][out[i].second] = 'X';
	}
	//cout << endl << endl;
	f(i, n) {
		f(j, m)
			cout << maze[i][j];
		cout << endl;

	}
}

ll BFS_k(vector<vector<int>>& edges, vector<ll>& visit, int node, ll val) {
	if (visit[node] != -1)return 0;
	visit[node] = 0;
	ll maxi1 = 0;
	ll maxi2 = 0;
	for (auto x : edges[node]) {
		ll out = BFS_k(edges, visit, x, val + 1);
		if (out > maxi1) {
			maxi2 = maxi1; maxi1 = out;
		}
		else if (out > maxi2)maxi2 = out;
	}
	maxi2 = max(maxi2, val);
	visit[node] = maxi1 + maxi2;
	return maxi1 + 1;
}
void prob_k(void) {
	int n; cin >> n;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	f(i, n - 1) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<ll> visit(n + 1, -1);
	BFS_k(edges, visit, 1, 0);
	ll out = -1;
	ff(i, 1, n + 1)out = max(out, visit[i]);
	cout << out << endl;
}

void prob_l(void) {

}

void prob_M(void) {

}
bool BFS_N_help(vector<vector<int>>& edges, vector<bool>& visit, map<pair<int, int>, bool>& m, vector<int>& out,int node,bool prob) {
	if (visit[node])return false;
	visit[node] = 1;
	bool child = false;
	for (auto x : edges[node]) {
		child |= BFS_N_help(edges, visit, m, out, x, m[{min(x, node), max(x, node)}]);
	}
	if (prob && !child)out.push_back(node);
	return child || prob;
}
void BFS_N(vector<vector<int>>& edges, vector<bool>& visit, map<pair<int, int>, bool>& m, vector<int>& out) {
	visit[1] = 1;
	for (auto x : edges[1]) {
		BFS_N_help(edges, visit, m, out, x, m[{1, x}]);
	}
}
void prob_N(void) {
	int n; cin >> n;
	vector<vector<int>>edges(n + 1, vector<int>(0));
	vector<bool>visit(n + 1, 0);
	map<pair<int, int>, bool>m;
	vector<int>out;
	f(i, n - 1) {
		int u, v, t; cin >> u >> v >> t;
		edges[u].push_back(v);
		edges[v].push_back(u);
		m[{min(u, v), max(u, v)}] = t == 2;
	}
	BFS_N(edges, visit, m, out);
	int N = out.size();
	cout << N << endl;
	f(i, N) {
		cout << out[i] << " ";
	}
	cout << endl;
}

void prob_O(void) {
	int n; cin >> n;
	vector<set<int>>edges(n + 1, set<int>());
	f(i, n - 1) {
		int u, v; cin >> u >> v;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	vector<int>input(n);
	f(i, n) {
		cin >> input[i];
	}

	bool ac = input[0] == 1;
	queue<int>q;
	int cur = 1;
	ff(i, 1, n) {
		while (edges[cur].size() == 0)
		{
			if (q.empty()) {
				ac = false;
				break;
			}
			else {
				cur = q.front();
				q.pop();
			}
		}
		if (ac) {
			if (edges[cur].find(input[i]) != edges[cur].end()) {
				q.push(input[i]);
				edges[cur].erase(input[i]);
				edges[input[i]].erase(cur);
			}
			else ac = false;
		}
	}
	if (ac)cout << "YES" << endl;
	else cout << "NO" << endl;
}
void prob_P(void) {

}