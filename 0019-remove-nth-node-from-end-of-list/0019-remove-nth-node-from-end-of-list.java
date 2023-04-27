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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ahead = head;
        ListNode cur = head;
        ListNode prev = null;
        int i = 0;
        
        while(i < n) {
            ahead = ahead.next;
            i++;
        }
        
        while(ahead != null) {
            prev = head;
            head = head.next;
            ahead = ahead.next;
        }
        
        if(prev == null) return cur.next;
        else prev.next = head.next;
        
        if(head.next != null) head.next = null;
                
        return cur;
    }
}