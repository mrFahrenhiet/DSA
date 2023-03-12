/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>((a,b) -> a.val - b.val);
        ListNode res = new ListNode(-1);
        ListNode traveler = res;
        
        for(ListNode list: lists) {
            if(list != null) pq.add(list);
        }
        
        while(pq.size() > 0) {
            ListNode cur = pq.poll();
            if(cur != null) {
                traveler.next = cur;
                traveler = traveler.next;
                if(cur.next != null) pq.add(cur.next);
            }
        }
        
        return res.next;
    }
}