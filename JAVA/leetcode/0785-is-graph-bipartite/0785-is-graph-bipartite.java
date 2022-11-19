class Solution {
    private boolean helper(HashMap<Integer, ArrayList<Integer>> g, int[] colors, int src) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(src);
        colors[src] = 1;
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int nbr: g.get(cur)) {
                if(colors[nbr] == colors[cur]) return false;
                if(colors[nbr] == 0) {
                    if(colors[cur] == -1) colors[nbr] = 1;
                    else colors[nbr] = -1;
                    q.add(nbr);
                }
            }
        }
        
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        HashMap<Integer, ArrayList<Integer>> g = new HashMap<>();
        int[] colors = new int[graph.length];
        
        for(int i=0;i<graph.length;i++) {
            if(!g.containsKey(i)) g.put(i, new ArrayList<Integer>());
            for(int nbr: graph[i]) g.get(i).add(nbr);
        }
        
        for(int i=0;i<graph.length;i++) {
            if(colors[i] == 0) {
                boolean x = helper(g, colors, i);
                if(!x) return false;
            }
        }
        
        return true;
    }
}