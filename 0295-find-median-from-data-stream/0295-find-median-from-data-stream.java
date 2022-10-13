class MedianFinder {
    PriorityQueue<Integer> minQ;
    PriorityQueue<Integer> maxQ;
    boolean even;
    public MedianFinder() {
        this.minQ = new PriorityQueue<Integer>((a,b)->b-a);
        this.maxQ = new PriorityQueue<Integer>();
        this.even = true;
    }
    
    public void addNum(int num) {
        if(even) {
            maxQ.offer(num);
            minQ.offer(maxQ.poll());
        }
        else {
            minQ.offer(num);
            maxQ.offer(minQ.poll());
        }
        this.even = !this.even;
    }
    
    public double findMedian() {
        if(even)
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