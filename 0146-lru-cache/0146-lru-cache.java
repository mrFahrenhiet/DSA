class ListNode {
    int key;
    int value;
    ListNode next;
    ListNode prev;
    
    ListNode(int key, int value) {
        this.key = key;
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}


class LRUCache {
    HashMap<Integer, ListNode> cacheMap;
    int capacity;
    ListNode leastRecentlyUsed;
    ListNode latest;


    public LRUCache(int capacity) {
        this.cacheMap = new HashMap<Integer, ListNode>();
        this.capacity = capacity;
        
        this.leastRecentlyUsed = new ListNode(-1, -1);
        this.latest = new ListNode(-1, -1);
        this.leastRecentlyUsed.next = this.latest;
        this.latest.prev = this.leastRecentlyUsed;
    }
    
    private ListNode getLeastRecentlyUsedNode() {
        return this.leastRecentlyUsed.next;
    }
    
    private void deleteNode(ListNode node) {
        ListNode prv = node.prev;
        ListNode nxt = node.next;
        
        if(prv != null) prv.next = nxt;
        if(nxt != null) nxt.prev = prv;
        
        node.prev = null;
        node.next = null;
        
        return;
    }
    
    private void insertNode(ListNode node) {
        ListNode cur = this.latest.prev;
        ListNode next = this.latest;
        
        cur.next = node;
        next.prev = node;
        
        node.prev = cur;
        node.next = next;
        
        return;
    }
    
    public int get(int key) {
        if(!this.cacheMap.containsKey(key)) return -1;
        ListNode temp = this.cacheMap.get(key);
        
        this.deleteNode(temp);
        this.insertNode(temp);
        
        return this.cacheMap.get(key).value;
    }
    
    public void put(int key, int value) {
        if(this.cacheMap.containsKey(key)) {
            ListNode temp = this.cacheMap.get(key);
            
            this.deleteNode(temp);
            this.cacheMap.remove(key);
            
            temp.value = value;
            
            this.insertNode(temp);
            this.cacheMap.put(key, temp);
            
        }
        else {
            if(this.cacheMap.size() >= this.capacity) {
                ListNode last = this.getLeastRecentlyUsedNode();
                
                this.deleteNode(last);
                this.cacheMap.remove(last.key);
            }
            
            ListNode newNode = new ListNode(key, value);
            
            this.insertNode(newNode);
            
            this.cacheMap.put(key, newNode);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */