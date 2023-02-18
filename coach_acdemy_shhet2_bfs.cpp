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

void BFS_j(vector<vector<char>>&maze, vector<pair<int, int>>&out, int startx, int starty);
void prob_j(void);
void prob_k(void);
void prob_l(void);


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	prob_j();
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
	if (cnt == n && m == n - 1)cout << "YES" << endl;
	else cout << "NO" << endl;
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
			if (childx >= 0 && childx < n && childy>=0 && childy < m && visit[childx][childy] == false && maze[childx][childy] == '.') {
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
void prob_k(void) {

}
void prob_l(void) {

}