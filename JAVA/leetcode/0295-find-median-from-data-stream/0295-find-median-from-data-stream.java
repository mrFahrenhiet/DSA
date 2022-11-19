class MedianFinder {
    PriorityQueue<Integer> minQ;
    PriorityQueue<Integer> maxQ;

    public MedianFinder() {
        this.minQ = new PriorityQueue<Integer>();
        this.maxQ = new PriorityQueue<Integer>((a,b)->b-a);
    }
    
    public void addNum(int num) {
        minQ.offer(num);
        maxQ.offer(minQ.poll());
        
        if(maxQ.size() > minQ.size())
            minQ.offer(maxQ.poll());
    }
    
    public double findMedian() {
        if(minQ.size() == maxQ.size())
            return (minQ.peek() + maxQ.peek()) / 2.0;
        return minQ.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */