/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, cur = head, tail = head;
        
        while(fast != null && fast.next != null && cur != null) {
            fast = fast.next.next;
            cur = cur.next;
            
            if(cur == fast) {
                cur = head;
                while(cur != fast) {
                    fast = fast.next;
                    cur = cur.next;
                }
                return cur;
            }
        }
        
        return null;
        

    }
}