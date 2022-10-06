class Solution {
    public int nthUglyNumber(int n) {
        long res = 1;
        if(n == 1) return 1;
        
        HashMap<Long, Boolean> isDone = new HashMap<>();
        PriorityQueue<Long> pq = new PriorityQueue<Long>();
        pq.add((long)1);
        isDone.put((long)1, true);
        
        for(long i=1;i<=n;i++) {
            long cur = pq.poll();
            res = cur;
            
            if(!isDone.containsKey(cur * 2)) pq.add(cur * 2);
            if(!isDone.containsKey(cur * 3)) pq.add(cur * 3);
            if(!isDone.containsKey(cur * 5)) pq.add(cur * 5);
            
            isDone.put(cur * 2, true);
            isDone.put(cur * 3, true);
            isDone.put(cur * 5, true);
        }
        
        return (int) (res);
    }
}