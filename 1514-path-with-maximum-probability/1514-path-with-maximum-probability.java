class Node {
    public int node;
    public double prob;
    
    Node(int node, double prob) {
        this.node = node;
        this.prob = prob;
    }
}

class NodeComparable implements Comparator<Node> {
    @Override
    public int compare(Node a, Node b) {
        if(a.prob < b.prob) return 1;
        else if(a.prob == b.prob) return 0;
        else return -1;
    }
}

class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        ArrayList<Node>[] graph = new ArrayList[n];
        boolean[] visited = new boolean[n];
        PriorityQueue<Node> pq = new PriorityQueue<Node>(edges.length, new NodeComparable());
        
        //graph create
        for(int i=0;i<edges.length;i++) {
            if(graph[edges[i][0]] == null) graph[edges[i][0]] = new ArrayList<Node>();
            if(graph[edges[i][1]] == null) graph[edges[i][1]] = new ArrayList<Node>();
            
            graph[edges[i][0]].add(new Node(edges[i][1], succProb[i]));
            graph[edges[i][1]].add(new Node(edges[i][0], succProb[i]));
        }
        
        // bfs
        pq.add(new Node(start, 1.0));
        visited[start] = true;
        while(pq.size() > 0) {
            Node cur = pq.poll();
            visited[cur.node] = true;
            if(cur.node == end) return cur.prob;
            if(graph[cur.node] == null) continue;
            for(Node nbr: graph[cur.node]) {
                if(visited[nbr.node]) continue;
                double newProb = cur.prob * nbr.prob;
                pq.add(new Node(nbr.node, newProb));
            }
        }
        
        return 0.0;
    }
}