class Graph {
    public int V;
    public LinkedList<Integer> adj[];
    Graph(int nosNodes) {
        this.V = nosNodes;
        this.adj = new LinkedList[this.V];
        for(int i=0;i<nosNodes;i++)
            adj[i] = new LinkedList();
    }
    
    public void addEdge(int src, int dest) {
        this.adj[src].add(dest);
        this.adj[dest].add(src);
        return;
    }
}


class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        int res = 0;
        int[] restMap = new int[n];
        boolean visited[] = new boolean[n];
        for(int i=0;i<restricted.length;i++) restMap[restricted[i]] = 1;
        Queue<Integer> q = new LinkedList<Integer>();
        Graph g = new Graph(n);
        for(int i=0;i<edges.length;i++)
            g.addEdge(edges[i][0], edges[i][1]);
        q.add(0);
        visited[0] = true;
        while(q.size() > 0) {
            int front = q.remove();
            //System.out.print(front + "-");
            res++;
            for(int neigh: g.adj[front]) {
                //System.out.print(neigh + " ");
                if(restMap[neigh] <= 0 && !visited[neigh]) {
                    q.add(neigh);
                    visited[neigh] = true;
                }
            }
            //System.out.println();
        }
        return res;
    }
}