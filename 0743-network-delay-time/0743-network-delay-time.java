class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        int[] nodetime = new int[n+1];
        int res = 0;
        for(int i=1;i<n+1;i++) nodetime[i] = Integer.MAX_VALUE;
        
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[1] - b[1]);
        
        ArrayList<int[]>[] graph = new ArrayList[n+1];
        for(int i=0;i<times.length;i++) {
            if(graph[times[i][0]] == null)
                graph[times[i][0]] = new ArrayList<int[]>();
            
            graph[times[i][0]].add(new int[]{times[i][1], times[i][2]});
        }
        
        nodetime[k] = 0;
        pq.add(new int[]{k, 0});
        while(pq.size() > 0) {
            int[] cur = pq.poll();
            if(graph[cur[0]] == null) continue;
            for(int[] nbr: graph[cur[0]]) {
                if(nodetime[nbr[0]] > nbr[1] + cur[1]) {
                    pq.add(new int[]{nbr[0], nbr[1] + cur[1]});
                    nodetime[nbr[0]] = nbr[1] + cur[1];
                }
            }
        }
        
        for(int t: nodetime) {
            if(t >= Integer.MAX_VALUE) return -1;
            res = Math.max(res, t);
        }
        
        
        return res;
    }
}