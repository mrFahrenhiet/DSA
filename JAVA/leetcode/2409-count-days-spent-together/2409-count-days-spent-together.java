class Solution {
    private int getDays(String date, int[] nosDays) {
        String[] dateSp = date.split("-");
        int days = nosDays[Integer.parseInt(dateSp[0]) - 1] + Integer.parseInt(dateSp[1]);
        return days;
    }
    
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] nosDays = new int[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<nosDays.length;i++)
            nosDays[i] += nosDays[i-1];
        
        int arrAlice = getDays(arriveAlice, nosDays);
        int arrBob = getDays(arriveBob, nosDays);
        int levAlice = getDays(leaveAlice, nosDays);
        int levBob = getDays(leaveBob, nosDays);
        int res = Math.min(levAlice, levBob) - Math.max(arrAlice, arrBob) + 1;
        return res < 0 ? 0 : res;
    }  
}