struct Edge{
	int from, to, cap, flow, cost;
	Edge(int u, int v, int c, int f, int x)
		: from(u), to(v), cap(c), flow(f), cost(x) {}
};

int n, m;
vector<int> G[MAXN];
vector<Edge> edges;
bool done[MAXN];
int dist[MAXN];
int pre[MAXN];
int f[MAXN];

void addEdge(int from, int to, int cap, int cost) {
	edges.push_back(Edge(from, to, cap, 0, cost));
	edges.push_back(Edge(to, from, 0, 0, -cost));
	int e = edges.size();
	G[from].push_back(e - 2);
	G[to].push_back(e - 1);
}

bool spfa(int& flow, int& cost) {
	memset(dist, 0x3f, sizeof(dist));
	memset(done, 0, sizeof(done));
	dist[S] = 0;
	done[S] = 1;
	pre[S] = 0;
	f[S] = INF;
	queue<int> buff;
	buff.push(S);
	while(!buff.empty()) {
		int current = buff.front();
		buff.pop();
		done[current] = 0;
		for (int i = 0; i < G[current].size(); i++) {
			Edge& e = edges[G[current][i]];
			if (e.cap > e.flow && dist[e.to] > dist[current] + e.cost) {
				dist[e.to] = dist[current] + e.cost;
				pre[e.to] = G[current][i];
				f[e.to] = min(f[current], e.cap - e.flow);
				if (!done[e.to]) {
					done[e.to] = 1;
					buff.push(e.to);
				}
			}
		}
	}
	if (dist[T] == INF)
		return false;
	flow += f[T];
	cost += dist[T] * f[T];
	for (int u = T; u != S; u = edges[pre[u]].from) {
		edges[pre[u]].flow += f[T];
		edges[pre[u] ^ 1].flow -= f[T];
	}
	return true;
}

int minCostMaxFlow() {
	int flow = 0, cost = 0;
	while(spfa(flow, cost));
	return cost;
}
