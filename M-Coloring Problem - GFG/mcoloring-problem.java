//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int tc = scan.nextInt();

        while (tc-- > 0) {
            int N = scan.nextInt();
            int M = scan.nextInt();
            int E = scan.nextInt();

            boolean graph[][] = new boolean[N][N];

            for (int i = 0; i < E; i++) {
                int u = scan.nextInt() - 1;
                int v = scan.nextInt() - 1;
                graph[u][v] = true;
                graph[v][u] = true;
            }

            System.out.println(new solve().graphColoring(graph, M, N) ? 1 : 0);
        }
    }
}

// } Driver Code Ends


class solve {
    // Function to determine if graph can be coloured with at most M colours
    // such
    // that no two adjacent vertices of graph are coloured with same colour.
    private boolean isSafe(boolean[] nbrs, int[] colors, int node) {
        for(int i=0;i<nbrs.length;i++) {
            if(nbrs[i] && colors[i] == colors[node]) return false;
        }
        
        return true;
    }
    private boolean dfs(boolean[][] graph, int[] colors, int m, int cur) {
        if(cur >= graph.length) return true;
        for(int i=1;i<=m;i++) {
            colors[cur] = i;
            if(isSafe(graph[cur], colors, cur) && dfs(graph, colors, m, cur+1))
                return true;
            colors[cur] = 0;
        }
        return false;
    }
    public boolean graphColoring(boolean graph[][], int m, int n) {
        int[] colors = new int[n];
        return dfs(graph, colors, m, 0);
    }
}