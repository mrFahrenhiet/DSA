import java.util.*;
import java.io.*;


class DisjointSet {
    int[] ranks;
    int[] parents;
    int[] sizes;

    public DisjointSet(int nNodes) {
        ranks = new int[nNodes+1];
        sizes = new int[nNodes+1];
        parents = new int[nNodes+1];

        for(int i=0;i<=nNodes;i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }

    public void printDSU() {
        for(int rank: ranks) System.out.print(rank + " ");
        System.out.println();

        for(int parent: parents) System.out.print(parent + " ");
        System.out.println();

        for(int size: sizes) System.out.print(size + " ");
        System.out.println();

        return;
    }

    public int findParent(int node) {
        if(this.parents[node] == node)
            return node;
            
        return this.parents[node] = findParent(this.parents[node]);
    }

    public void unionRank(int u, int v) {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u == ult_p_v) return;

        int rank_u = this.ranks[ult_p_u];
        int rank_v = this.ranks[ult_p_v];

        if(rank_u > rank_v) this.parents[ult_p_v] = ult_p_u;
        else if(rank_u < rank_v) this.parents[ult_p_u] = ult_p_v;
        else if(rank_u == rank_v) {
            this.parents[ult_p_v] = ult_p_u;
            this.ranks[ult_p_u]++;
        }
    }

    public void unionSize(int u, int v) {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u == ult_p_v) return;

        int size_u = this.sizes[ult_p_u];
        int size_v = this.sizes[ult_p_v];

        if(size_u >= size_v) {
            this.parents[ult_p_v] = ult_p_u;
            this.sizes[ult_p_u] += size_v;
        }
        else {
            this.parents[ult_p_u] = ult_p_v;
            this.sizes[ult_p_v] += size_u;
        }

        return;
    }
}

public class DSU {
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                System.setOut(new PrintStream(
                    new FileOutputStream("output.txt")));
                scn = new Scanner(new File("input.txt"));
            }
            catch (Exception e) {
            }
        }
        int nNodes = scn.nextInt();
        int nEdges = scn.nextInt();
        
        DisjointSet dsu = new DisjointSet(nNodes);

        // dsu.unionRank(1, 2);
        // dsu.unionRank(2, 3);
        // dsu.unionRank(4, 5);
        // dsu.unionRank(6, 7);
        // dsu.unionRank(5, 6);

        // boolean isSameComponent = dsu.findParent(1) == dsu.findParent(7);
        // System.out.println(isSameComponent);

        // dsu.printDSU();

        // dsu.unionRank(3, 7);

        System.out.println();

        // boolean isSameComponent_2 = dsu.findParent(1) == dsu.findParent(7);
        // System.out.println(isSameComponent_2);

        dsu.unionSize(1, 2);
        dsu.unionSize(2, 3);
        dsu.unionSize(4, 5);
        dsu.unionSize(6, 7);
        dsu.unionSize(5, 6);

        // isSameComponent = dsu.findParent(1) == dsu.findParent(7);
        // System.out.println(isSameComponent);

        dsu.unionSize(3, 7);

        // isSameComponent_2 = dsu.findParent(1) == dsu.findParent(7);
        // System.out.println(isSameComponent_2);

        dsu.printDSU();
    }
}