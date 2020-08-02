// verify https://cses.fi/problemset/task/1671
// CP4 implementation 

const int MX = 1e5 + 5;
const ll INF = 1e18;
vector<pair<int,ll>> adj[MX];
vector<ll> dist;
priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

void dijkstra() {
    // s = 1, 1-indexed
    dist.assign(n+1, INF); dist[1] = 0;
    pq.push({0,1});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        // assert(dist[u] == d);
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }

        }

    }

}
