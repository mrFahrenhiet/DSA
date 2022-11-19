class Node {
    public int value;
    public int row;
    public int col;
    
    public Node(int v, int r, int c) {
        value = v;
        row = r;
        col = c;
    }
}

class NodeComparator implements Comparator<Node> {
    public int compare(Node n1, Node n2) {
        return n1.value - n2.value;
    }
}

class Solution {
    public int minimumEffortPath(int[][] heights) {
        int nosRows = heights.length;
        int nosCols = heights[0].length;
        int[] dRow = {1, 0, -1, 0};
        int[] dCol = {0, 1, 0, -1};
        PriorityQueue<Node> pq = new PriorityQueue<Node>(new NodeComparator());
        int[][] dp = new int[heights.length][heights[0].length];
        
        for(int i=0;i<heights.length;i++) {
            for(int j=0;j<heights[0].length;j++) dp[i][j] = Integer.MAX_VALUE;
        }
        
        pq.add(new Node(0, 0, 0));
        dp[0][0] = 0;
        
        while(!pq.isEmpty()) {
            Node curr = pq.poll();
            if(curr.row == nosRows - 1 && curr.col == nosCols - 1) return curr.value;
            for(int i=0;i<4;i++) {
                int newRow = curr.row + dRow[i], newCol = curr.col + dCol[i];
                if(newRow >= 0 && newCol >= 0 && newRow < nosRows && newCol < nosCols) {
                    int wt = Math.max(curr.value, Math.abs(heights[curr.row][curr.col] - heights[newRow][newCol]));
                    if(dp[newRow][newCol] > wt) {
                        dp[newRow][newCol] = wt;
                        pq.add(new Node(dp[newRow][newCol], newRow, newCol));
                    }
                }
            }
        }
        return dp[nosRows-1][nosCols-1];
    }
}