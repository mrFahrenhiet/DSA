class Solution {
    private long res = 0;
    private int helper(ArrayList<Integer>[] graph, int seats, int parent, int cur) {
        int nosPeople = 1;
        if(graph[cur] != null) {
            for(int nbr: graph[cur]) {
                if(nbr != parent) {
                    nosPeople += helper(graph, seats, cur, nbr);
                }
            }
        }
        
        int x = Math.min(nosPeople, seats);     
        double fuelCost = Math.ceil((double)nosPeople / (double)x);
        
        //System.out.println(fuelCost + " " + cur + " " + nosPeople);
        
        if(cur != 0) res += (long)fuelCost;
        
        return nosPeople;
    }
    public long minimumFuelCost(int[][] roads, int seats) {
        // init
        
        ArrayList<Integer>[] graph = new ArrayList[roads.length+1];
        
        // fill graph
        for(int[] road: roads) {
            if(graph[road[0]] == null) graph[road[0]] = new ArrayList<Integer>();
            graph[road[0]].add(road[1]);
            
            if(graph[road[1]] == null) graph[road[1]] = new ArrayList<Integer>();
            graph[road[1]].add(road[0]);
        }
        
        long x = helper(graph, seats, 0, 0);
        
        return res;
        
    }
}