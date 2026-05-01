import java.util.*;
import java.io.*;

class Dijkstra {

    static int n, m;
    static List<int[]>[] g;
    static long[] dist;

    private static void dij(int src) {
        Arrays.fill(dist, (long)1e18);

        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> Long.compare(a[1], b[1])
        );

        dist[src] = 0;
        pq.add(new long[]{src, 0});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            int node = (int) cur[0];
            long d = cur[1];

            // if (vis[node] == 1) continue; 
            // vis[node] = 1;

            // optimization: skip outdated entries
            if (d > dist[node]) continue;

            for (int[] edge : g[node]) {
                int neigh = edge[0];
                int wt = edge[1];

                if (dist[neigh] > d + wt) {
                    dist[neigh] = d + wt;
                    pq.add(new long[]{neigh, dist[neigh]});
                }
            }
        }
    }

    private static void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        g = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) g[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            g[a].add(new int[]{b, w});
            g[b].add(new int[]{a, w});
        }

        dist = new long[n + 1];

        dij(1); // source = 1

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            if (dist[i] == (long)1e18) sb.append("-1 ");
            else sb.append(dist[i]).append(" ");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        solve();
    }
}