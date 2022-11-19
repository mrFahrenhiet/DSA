class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a,b)->a[3]-b[3]);
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0;i<nums1.length;i++)
            pq.add(new int[]{nums1[i], nums2[0], 0, nums1[i] + nums2[0]});
        
        int i = 0;
        while(i < k && pq.size() > 0) {
            int[] cur = pq.poll();
            res.add(new ArrayList<Integer>());
            for(int j=0;j<2;j++) res.get(i).add(cur[j]);
            if(cur[2] < nums2.length - 1)
                pq.add(new int[]{cur[0], nums2[cur[2]+1], cur[2]+1, cur[0]+nums2[cur[2]+1]});
            i++;
        }
        return res;
    }
}