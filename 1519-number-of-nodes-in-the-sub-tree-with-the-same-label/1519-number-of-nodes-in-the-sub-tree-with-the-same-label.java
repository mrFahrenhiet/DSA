class Solution {
    private int[] helper(ArrayList<Integer>[] tree, boolean[] visited, String labels, int[] res, int cur) {
        int[] hash = new int[26];
        
        hash[labels.charAt(cur) - 'a']++;
        visited[cur] = true;

        if(tree[cur] != null) {
            for(int nbr: tree[cur]) {
                if(!visited[nbr]) {
                    int[] temp = helper(tree, visited, labels, res, nbr);

                    // merge hashmaps
                    for(int i=0;i<26;i++) {
                        hash[i] += temp[i];
                    }
                }
            }
        }

        res[cur] += hash[labels.charAt(cur) - 'a'];

        return hash;
    }

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        ArrayList<Integer>[] tree = new ArrayList[n];
        boolean[] visited = new boolean[n];
        int[] res = new int[n];
        
        for(int[] edge: edges) {
            if(tree[edge[0]] == null) tree[edge[0]] = new ArrayList<Integer>();
            if(tree[edge[1]] == null) tree[edge[1]] = new ArrayList<Integer>();

            tree[edge[0]].add(edge[1]);
            tree[edge[1]].add(edge[0]);
        }

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                int[] hashMap = helper(tree, visited, labels, res, i);
            }
        }


        return res;
    }
}