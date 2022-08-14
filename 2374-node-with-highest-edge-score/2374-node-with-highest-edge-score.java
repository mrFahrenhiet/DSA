class Graph {
    public int V;
    public LinkedList<Integer>[] adjList;
    
    Graph(int nosNodes) {
        this.V = nosNodes;
        this.adjList = new LinkedList[nosNodes];
        for(int i=0;i<nosNodes;i++)
            this.adjList[i] = new LinkedList();
    }
    
    public void addEdge(int src, int dest) {
        this.adjList[src].add(dest);
    }
}

class Solution {
    public int edgeScore(int[] edges) {
        Graph g = new Graph(edges.length);
        for(int i=0;i<edges.length;i++) {
            g.addEdge(edges[i], i);
        }
        
        long maxSum = 0;
        int res = -1;
        for(int i=0;i<edges.length;i++) {
            if(g.adjList[i].size() > 0) {
                long sum = 0;
                for(int num: g.adjList[i]) sum += num;
                //System.out.println(sum);
                if(maxSum < sum) {
                    maxSum = sum;
                    res = i;
                }
            }
        }
        return res;
    }
}