class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> mergedIntervals = new ArrayList<>();
        
        // sort according to starting interval;
        Arrays.sort(intervals, (a, b) -> a[0]-b[0]);
        
        // init start and end;
        int startInterval = intervals[0][0];
        int endInterval = intervals[0][1];
        
        // Try to create a single largest interval;
        for(int[] interval: intervals) {
            if(interval[0] <= endInterval)
                endInterval = Math.max(endInterval, interval[1]);
            else {
                mergedIntervals.add(new int[]{startInterval, endInterval});
                startInterval = interval[0];
                endInterval = interval[1];
            }
        }
        
        mergedIntervals.add(new int[]{startInterval, endInterval});
        
        return mergedIntervals.toArray(new int[mergedIntervals.size()][2]);
    }
}