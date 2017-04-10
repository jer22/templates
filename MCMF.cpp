struct Edge {
    int to, cost, cap, originalcost, originalcap;
    Edge *nex, *inv;
    Edge() {}
    Edge(int _to, int _cap, int _cost, Edge* N) {
    	to = _to, cap = _cap, cost = _cost, originalcost = _cost, originalcap = _cap, nex = N;
    }
};

int n, m;
Edge *G[MAXV];
Edge edges[MAXE + MAXE];
char vis[MAXV];
int d[MAXV];

void addEdge(int from, int to, int capacity, int cost) {
	edges[++last] = Edge(to, capacity, cost, G[from]);
	G[from] = edges + last;
	edges[++last] = Edge(from, 0, -cost, G[to]);
	G[to] = edges + last;
	G[from] -> inv = G[to];
	G[to] -> inv = G[from];
}
int aug(int cur, int nowfl, int &ncost, int &cost) {
	if(cur==T)return cost+=ncost*nowfl,nowfl;
    vis[cur]=1;
    int l=nowfl;
    for(register Edge *e=G[cur];e;e=e->nex) {
    	if (!e->cost && !vis[e->to]) {
	        int &delta = e->cap;
	        if(delta)
	        {
	            int d=aug(e->to,l<delta?l:delta, ncost, cost);
	            delta-=d,e->inv->cap+=d,l-=d;
	            if(!l)return nowfl;
	        }
    		
    	}
    }
    return nowfl-l;
}
char modlabel(int &ncost) {
	int dd=INF;
    for(register int i=0;i<=T;++i)if(vis[i])
        for(Edge *j=G[i];j;j=j->nex)
            if(!vis[j->to] && j->cap && j->cost<dd)dd=j->cost;
    if(dd==INF)return 0;
    for(register int i=0;i<=T;++i)if(vis[i])
        for(Edge *j=G[i];j;j=j->nex)
            j->cost-=dd,j->inv->cost+=dd;
    ncost += dd;
    return 1;
}
std::pair<int, int> minCostMaxFlow() {
	int flow = 0, cost = 0;
	int ncost = 0;
	do do memset(vis,0,sizeof(vis));
    while(aug(S,INF, ncost, cost));
    while(modlabel(ncost));
	for( register Edge *e = G[S]; e; e = e->nex)
		flow += e -> inv-> cap;
	// cout << cost << endl;
	return make_pair(flow, cost);
}