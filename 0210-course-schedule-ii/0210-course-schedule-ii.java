class Solution {
    private boolean dfs(ArrayList<Integer>[] graph, boolean[] visited, boolean[] curPath, Stack<Integer> top, int x) {
        visited[x] = true;
        curPath[x] = true;
        if(graph[x] != null) {
            for(int nbr: graph[x]) {
                if(curPath[nbr]) return false;
                if(!visited[nbr]) {
                    boolean travel = dfs(graph, visited, curPath, top, nbr);
                    if(!travel) return false;
                }
            }
        }
        curPath[x] = false;
        top.push(new Integer(x));
        return true;
    }
    public int[] findOrder(int numCourses, int[][] prereq) {
        boolean[] visited = new boolean[numCourses];
        boolean[] curPath = new boolean[numCourses];
        int[] res = new int[numCourses];
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        int r = 0;
        Stack<Integer> topologicalPath = new Stack<Integer>();
        
        for(int i=0;i<prereq.length;i++) {
            if(graph[prereq[i][1]] == null)
                graph[prereq[i][1]] = new ArrayList<Integer>();
            graph[prereq[i][1]].add(prereq[i][0]);
        }
        for(int i=0;i<numCourses;i++) {
            if(!visited[i]) {
                boolean x = dfs(graph, visited, curPath, topologicalPath, i);
                if(!x) return new int[]{};
            }
        }
        
        while(!topologicalPath.empty())
            res[r++] = topologicalPath.pop();
        
        return res;
    }
}