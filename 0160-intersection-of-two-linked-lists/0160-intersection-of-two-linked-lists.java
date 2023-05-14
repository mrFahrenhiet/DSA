/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tailA = headA;
        ListNode tailB = headB;
        
        int lenA = 0;
        int lenB = 0;
        
        while(tailA != null) {
            tailA = tailA.next;
            lenA++;
        }
        
        while(tailB != null) {
            tailB = tailB.next;
            lenB++;
        }
        
        while(lenA > lenB) {
            headA = headA.next;
            lenA--;
        }
        
        while(lenA < lenB) {
            headB = headB.next;
            lenB--;
        }
        
        while(headA != null && headB != null) {
            if(headA == headB) return headA;
            headA = headA.next;
            headB = headB.next;
        }
        
        return headB;
    }
}