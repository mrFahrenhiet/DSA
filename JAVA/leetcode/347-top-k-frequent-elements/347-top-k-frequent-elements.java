class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        ArrayList<Integer>[] buckets = new ArrayList[nums.length+1];
        int[] res = new int[k];
        
        for(int num: nums) hm.put(num, hm.getOrDefault(num, 0) + 1);
        
        for(int num: hm.keySet()) {
            int freq = hm.get(num);
            if(buckets[freq] == null)
                buckets[freq] = new ArrayList<>();
            buckets[freq].add(num);
        }
        
        for(int j=buckets.length-1;j>=1 && k>0;j--) {
            if(buckets[j] == null) continue;
            ArrayList<Integer> temp = buckets[j];
            for(int num: temp) res[--k] = num;
        }
        
        return res;
    }
}