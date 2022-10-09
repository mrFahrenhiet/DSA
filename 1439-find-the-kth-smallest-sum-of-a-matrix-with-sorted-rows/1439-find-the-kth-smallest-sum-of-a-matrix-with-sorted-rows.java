class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int len = Math.min(k, mat[0].length);
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((a,b) -> b-a);
        pq.add(0);
        for(int[] row: mat) {
            PriorityQueue<Integer> temp = new PriorityQueue<Integer>((a,b) -> b-a);
            for(int curSum: pq) {
                for(int i=0;i<len;i++) {
                    temp.add(curSum + row[i]);
                    if(temp.size() > k) temp.poll();
                }
            }
            pq = temp;
        }
        return pq.poll();
    }
}