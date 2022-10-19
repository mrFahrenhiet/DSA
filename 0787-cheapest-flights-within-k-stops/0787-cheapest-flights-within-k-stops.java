class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        HashMap<Integer, List<int[]>> graph = new HashMap<>();
        HashMap<Integer, Integer> visited = new HashMap<>();
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[1] - b[1]);
        
        // init graph
        for(int[] flight: flights) {
            if(!graph.containsKey(flight[0]))
                graph.put(flight[0], new ArrayList<int[]>());
            
            graph.get(flight[0]).add(new int[]{flight[1], flight[2]});
        }
        
        // bfs
        pq.add(new int[]{src, 0, k});
        while(pq.size() > 0) {
            int[] curr = pq.poll();
            
            if(curr[0] == dst) return curr[1];
            if(visited.containsKey(curr[0]) && visited.get(curr[0]) >= curr[2]) continue;
            
            visited.put(curr[0], curr[2]);
            
            if(!graph.containsKey(curr[0]) || curr[2] < 0) continue;
            for(int[] nbr: graph.get(curr[0])) {
                int newPrice = curr[1] + nbr[1];
                int nosStops = curr[2] - 1;
                pq.add(new int[]{nbr[0], newPrice, nosStops});
            }
        }
        return -1;
    }
}