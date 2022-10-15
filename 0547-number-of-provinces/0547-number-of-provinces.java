class Solution {
    public void dfs(int i, boolean[] visited, int[][] isConnected) {
        visited[i] = true;
        for(int j=0;j<isConnected[i].length;j++) {
            if(!visited[j] && isConnected[i][j] == 1)
                dfs(j, visited, isConnected); 
        }
        return;
    }
    public int findCircleNum(int[][] isConnected) {
        boolean[] visited = new boolean[isConnected.length];
        int res = 0;
        for(int i=0;i<isConnected.length;i++) {
            if(!visited[i]) {
                dfs(i, visited, isConnected);
                res++;
            }
        }
        return res;
    }
}