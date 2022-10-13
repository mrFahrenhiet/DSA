class MedianFinder {
    PriorityQueue<Integer> minQ;
    PriorityQueue<Integer> maxQ;
    boolean even;
    public MedianFinder() {
        this.minQ = new PriorityQueue<Integer>((a,b)->b-a);
        this.maxQ = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        minQ.offer(num);
        maxQ.offer(minQ.poll());
        
        if(maxQ.size() > minQ.size())
            minQ.offer(maxQ.poll());
    }
    
    public double findMedian() {
        if(minQ.size() <= maxQ.size())
            return (minQ.peek() + maxQ.peek()) / 2.0;
        else return minQ.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */