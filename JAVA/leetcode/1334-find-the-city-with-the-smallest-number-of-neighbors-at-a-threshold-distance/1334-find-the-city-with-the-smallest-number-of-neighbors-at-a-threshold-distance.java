// Dijkstras App O( N * (N + E Log N))
class Solution {
    private int dijkstras(int n, HashMap<Integer, ArrayList<int[]>> graph, int thresh, int src) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(n, (a, b) -> Integer.compare(a[1], b[1]));
        
        int[] dist = new int[n];
        for(int i=0;i<graph.size();i++) dist[i] = Integer.MAX_VALUE;
        
        pq.add(new int[] {src, 0});
        dist[src] = 0;
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            
            if(!graph.containsKey(cur[0])) continue;
            
            for(int[] nbr: graph.get(cur[0])) {
                if(dist[nbr[0]] > dist[cur[0]] + nbr[1]) {
                    dist[nbr[0]] = dist[cur[0]] + nbr[1];
                    pq.add(new int[] {nbr[0], nbr[1]});
                }
            }
        }
        
        int nbrs = 0;
        
        for(int i=0;i<n;i++) {
            //System.out.println(dist[i]);
            if(dist[i] <= thresh && i != src) nbrs++;
        }
        
        //System.out.println("****");
        
        return nbrs;
    }
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // app 1: dijkstras for each node
        HashMap<Integer, ArrayList<int[]>> graph = new HashMap<Integer, ArrayList<int[]>>();
        
        for(int[] edge: edges) {
            if(!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());            
            
            if(!graph.containsKey(edge[1]))
                graph.put(edge[1], new ArrayList<int[]>());
            
            graph.get(edge[0]).add(new int[] {edge[1], edge[2]});
            graph.get(edge[1]).add(new int[] {edge[0], edge[2]});
        }
        
        int res = -1, minNbrs = n;
        
        for(int i=0;i<n;i++) {
            int nbrs = dijkstras(n, graph, distanceThreshold, i);
            //System.out.println(nbrs);
            if(minNbrs > nbrs) {
                minNbrs = nbrs;
                res = i;
            }
            else if(minNbrs == nbrs) res = i;
        }
        
        return res;
    }
}

// Floyd Warshall App O(N^3)
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] dp = new int[n][n];
        int res = -1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) dp[i][j] = 0;
                else dp[i][j] = (int)(1e9);
            }
        }
        
        for(int[] edge: edges) {
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int nCitiesMin = Integer.MAX_VALUE;
        
        for(int i=0;i<n;i++) {
            int nCities = 0;
            for(int j=0;j<n;j++) {
                if(dp[i][j] <= distanceThreshold && i != j)
                    nCities++;
            }
            if(nCitiesMin >= nCities) {
                nCitiesMin = nCities;
                res = i;
            }
        }
        
        return res;
    }
}