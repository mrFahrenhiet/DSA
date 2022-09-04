class MyCalendar {
    TreeMap<Integer, Integer> books;
    public MyCalendar() {
        books = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Integer floor = books.lowerKey(end);
        if(floor == null || books.get(floor) <= start) {
            books.put(start, end);
            return true;
        }
        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */