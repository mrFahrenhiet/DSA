class Solution {
    public long taskSchedulerII(int[] tasks, int space) {
        HashMap<Integer, Long> hm = new HashMap<Integer, Long>();
        long days = 0;
        for(int i=0;i<tasks.length;i++) {
            if(!hm.containsKey(tasks[i])) days++;
            else {
                long nextTime = hm.get(tasks[i]) + space;
                if(days >= nextTime) days++;
                else days += (nextTime - days) + 1;
            }
            hm.put(tasks[i], days);
        }
        return days;
    }
}