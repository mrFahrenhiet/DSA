class Node {
    public int node;
    public int distance;
    
    public Node(int n, int d) {
        node = n;
        distance = d;
    }
}

class Solution {

    // prims
    private int manhattan(int[][] points, int idx_1, int idx_2) {
        return Math.abs(points[idx_1][0] - points[idx_2][0]) + Math.abs(points[idx_1][1] - points[idx_2][1]);
    }
    public int minCostConnectPoints(int[][] points) {
        int res = 0;
        
        PriorityQueue<Node> pq = new PriorityQueue<Node>((a, b) ->(a.distance - b.distance));
        
        boolean[] visited = new boolean[points.length];
        
        pq.add(new Node(0, 0));
        
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            
            if(visited[cur.node]) continue;
            
            res += cur.distance;
            
            visited[cur.node] = true;
            
            for(int i=0;i<points.length;i++) {
                if(visited[i] || i == cur.node) continue;
                
                pq.add(new Node(i, manhattan(points, cur.node, i)));
            }
        }
        
        return res;
        
    }
}