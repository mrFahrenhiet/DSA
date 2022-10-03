class Points {
    public int x;
    public int y;
    public double vec;
    
    public Points(int xc, int yc) {
        this.x = xc;
        this.y = yc;
        this.vec = Math.sqrt(xc*xc + yc*yc);
    }
}
class PointsComparator implements Comparator<Points> {
    @Override
    public int compare(Points p1, Points p2) {
        return p2.vec > p1.vec ? 1 : p2.vec < p1.vec ? -1 : 0;
    }
}
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Points> pq = new PriorityQueue<Points>(k, new PointsComparator());
        for(int i=0;i<k;i++) {
            pq.add(new Points(points[i][0], points[i][1]));
        }
        for(int i=k;i<points.length;i++) {
            Points newPoint = new Points(points[i][0], points[i][1]);
            Points currWorst = pq.peek();
            if(newPoint.vec < currWorst.vec) {
                pq.poll();
                pq.add(newPoint);
            }
        }
        int[][] res = new int[k][2];
        int i = 0;
        while(pq.size() > 0) {
            Points point = pq.poll();
            res[i] = new int[]{point.x, point.y};
            i++;
        }
        return res;
    }
}