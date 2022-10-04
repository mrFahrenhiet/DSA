class ElementFreq {
    public int el;
    public int freq;
    public ElementFreq(int e, int f) {
        this.el = e;
        this.freq = f;
    }
}

class FreqComparator implements Comparator<ElementFreq> {
    @Override
    public int compare(ElementFreq e1, ElementFreq e2) {
        return e2.freq - e1.freq;
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<ElementFreq> pq = new PriorityQueue<ElementFreq>(nums.length, new FreqComparator());
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int num: nums)
            hm.put(num, hm.getOrDefault(num, 0) + 1);
        
        for(int key: hm.keySet())
            pq.add(new ElementFreq(key, hm.get(key)));
        
        
        int[] res = new int[k];
        int i = 0;
        while(i < k) {
            res[i] = pq.poll().el;
            i++;
        }

        return res;
    }
}