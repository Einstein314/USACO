//#include "bits/stdc++.h"
////#include "kimko_stdc++.h"
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> pii;
//
//#define FOR(i, a, b) for (int i=a; i<b; i++)
//#define F0R(i, a) for (int i=0; i<a; i++)
//#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
//#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
//
//#define mp make_pair
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
//
//const int MOD = 1000000007;
//double PI = 4*atan(1);
//
//const int MAX_VAL = (int)1e9;
//
//#include <fstream.h>
//
//const int Inf = 1000 * 1000 * 1000;
//
//ifstream in ("fence6.in");
//ofstream out ("fence6.out");
//
//struct Edge {
//    Edge () { }
//    Edge (int _to, int _dist):to (_to), dist (_dist) { }
//    int     to, dist;
//}       edges[100][8];
//int     edgeCo[100];
//int     nodeCo = 0;
//
//int     sigs[100][2];
//void
//AddEdge (int from, const Edge & edge)
//{
//    edges[from][edgeCo[from]++] = edge;
//}
//
//Edge
//RemoveEdge (int from, int to)
//{
//    int     i;
//    for (i = 0; i < edgeCo[from]; ++i) {
//        if (edges[from][i].to == to) {
//            Edge    tmp = edges[from][i];
//            edges[from][i] = edges[from][--edgeCo[from]];
//            return tmp;
//        }
//    }
//}
//
//int
//GetNode (int *segs, int len) {
//    int     i, max0 = 0, max1 = 0;
//    for (i = 0; i < len; ++i) {
//        if (segs[i] > max1) {
//            if (segs[i] > max0) {
//                max1 = max0;
//                max0 = segs[i];
//            }
//            else
//                max1 = segs[i];
//        }
//    }
//    for (i = 0; i < nodeCo; ++i)
//        if (max0 == sigs[i][0] && max1 == sigs[i][1])
//            return i;
//    sigs[nodeCo][0] = max0;
//    sigs[nodeCo][1] = max1;
//
//    return nodeCo++;
//}
//
//int
//CalcShortestPath (int from, int to, int lessThan) {
//    bool    visited[100];
//    int     dist[100];
//
//    int     i;
//    for (i = 0; i < nodeCo; ++i)
//        visited[i] = false, dist[i] = Inf;
//
//    visited[from] = true;
//    dist[from] = 0;
//    int     lastVisited = from;
//
//    for (;;) {
//        int     j;
//        for (j = 0; j < edgeCo[lastVisited]; ++j) {
//            const   Edge & edge = edges[lastVisited][j];
//            int     d = dist[lastVisited] + edge.dist;
//            if (d < lessThan && dist[edge.to] > d)
//                dist[edge.to] = d;
//        }
//
//        int     minDist = Inf;
//        for (j = 0; j < nodeCo; ++j)
//            if (!visited[j] && minDist > dist[j])
//                lastVisited = j, minDist = dist[j];
//
//        if (minDist == Inf)
//            break;
//
//        visited[lastVisited] = true;
//    }
//
//    return dist[to];
//}
//
//void
//ReadArray (int *arr, int len, istream & in)
//{
//    int     i;
//    for (i = 0; i < len; ++i)
//        in >> arr[i];
//}
//
//int
//main () {
//    int     segCo;
//    in >> segCo;
//
//    int     i;
//    for (i = 0; i < segCo; ++i) {
//        int     dist, co1, co2, segs[9];
//        in >> segs[0] >> dist >> co1 >> co2;
//
//        ReadArray (segs + 1, co1, in);
//        int     node1 = GetNode (segs, co1 + 1);
//
//        ReadArray (segs + 1, co2, in);
//        int     node2 = GetNode (segs, co2 + 1);
//
//        AddEdge (node1, Edge (node2, dist));
//        AddEdge (node2, Edge (node1, dist));
//    }
//    int     minPerim = Inf;
//    while (nodeCo != 0) {
//        int     node = nodeCo - 1;
//        if (edgeCo[node] > 1) {
//            for (i = 0; i < edgeCo[node]; ++i) {
//                int     otherNode = edges[node][i].to;
//
//                Edge    out = RemoveEdge (node, otherNode);
//                Edge    in = RemoveEdge (otherNode, node);
//
//                int     perim = out.dist + CalcShortestPath (node,
//                                                             otherNode, minPerim - out.dist);
//
//                if (minPerim > perim)
//                    minPerim = perim;
//
//                AddEdge (node, out);
//                AddEdge (otherNode, in);
//            }
//        }
//        for (i = 0; i < edgeCo[node]; ++i)
//            RemoveEdge (edges[node][i].to, node);
//        --nodeCo;
//    }
//
//    out << minPerim << '\n';
//
//    return 0;
//}
