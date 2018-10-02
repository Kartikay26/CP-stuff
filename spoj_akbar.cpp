#include <bits/stdc++.h>
#include "prettyprint.hpp"
using namespace std;

typedef long long int lli;
#define int lli

typedef pair<int, int> pii;
typedef vector<int> vi;

#define debug(x) cout << "debug: " << #x " = " << x << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

bool bfs(vector<vi> &graph, vector<int> &sources, int start_city, int str, int source){
	set<int> cities_now = {start_city};
	set<int> cities_later;
	int depth = str;
	for (int cur_depth = 0; cur_depth <= depth; ++cur_depth) {
		debug(cities_now);
		for(auto cur_city : cities_now){
			if(sources[cur_city] == source){
				continue;
			}
			if(sources[cur_city] == 0){
				sources[cur_city] = source;
				cities_later.insert(all(graph[cur_city]));
			} else {
				return false;
			}
		}
		cities_now = cities_later;
		cities_later.clear();
	}
	return true;
}

bool testcase(){
	int n, r, m;
	cin >> n >> r >> m;
	vector<vi> graph(n+1);
	vector<int> sources(n+1);
	for (int i = 0; i < r; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	debug(graph);
	for (int i = 0; i < m; ++i) {
		int k, s;
		cin >> k >> s;
		if (! bfs(graph, sources, k, s, i+1)) return false;
		debug(sources);
	}
	for (int i = 1; i <= n; ++i) {
		if(!sources[i]) return false;
	}
	return true;
}

int32_t main(){
	fast_io();
	int T; cin >> T; for (int i = 0; i < T; ++i) {
		cout << (testcase() ? "Yes" : "No") << endl;
	}
}