class Solution {
    PriorityQueue<Integer> minQ = new PriorityQueue<Integer>();
    PriorityQueue<Integer> maxQ = new PriorityQueue<Integer>((a, b)->b.compareTo(a));
    
    public void add(int num) {
        minQ.offer(num);
        maxQ.offer(minQ.poll());
        if(maxQ.size() > minQ.size()) minQ.offer(maxQ.poll());
    }
    public double getMedian() {
        if(minQ.size() == maxQ.size()) {
            return (((double)minQ.peek() + (double)maxQ.peek()) / 2.0);
        }
        return (double)minQ.peek();
    }
    public void remove(int num, double curMedian) {
        if(num < curMedian) maxQ.remove(num);
        else minQ.remove(num);
        
        if(maxQ.size() > minQ.size()) minQ.offer(maxQ.poll());
        if(minQ.size() - maxQ.size() > 1) maxQ.offer(minQ.poll());
    }
    public double[] medianSlidingWindow(int[] nums, int k) {
        int s = 0, e = 0, i = 0;
        double[] res = new double[nums.length - k + 1];
        
        while(s <= e && e < nums.length) {
            add(nums[e]);
            if(e - s + 1 == k) {
                res[i] = getMedian();
                remove(nums[s++], res[i]);
                i++;
            }
            e++;
        }
        
        return res;
    }
}