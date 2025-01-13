package Linked_list.DoublyLL;

class Node{
    int data;
    Node next;
    Node back;

    Node(int data){
        this.data = data;
        this.next = null;
        this.back = null;
    }

    Node(int data,Node next,Node back){
        this.data = data;
        this.next = next;
        this.back = back;
    }
}

public class deletion_DLL {

    private static void print(Node head) {
        Node current = head;

        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println(); 
    }

    private static Node convertArr2DLL(int[] arr){
        Node head = new Node(arr[0]);
        Node prev = head;

        for(int i=1 ; i<arr.length ; i++){
            Node temp = new Node(arr[i],null,prev);
            prev.next = temp;
            prev = temp;
        }
        return head;
    } 

    private static Node deleteHead(Node head){
        if(head == null || head.next == null) return null;
        Node temp = head;
        head = temp.next;
        temp.next = null;
        head.back = null;
        return head;
    }
    
    private static Node deleteTail(Node head){
        Node temp = head;

        while(temp.next.next != null){
            temp = temp.next;
        }
        Node prev = temp.next;
        prev.back = null;
        temp.next = null;

        return head;
    }
    
    private static Node deleteKth(Node head,int k){
        if(head == null || k <= 0) return null;

        Node temp = head;
        int count = 0;


        // Traverse to find the kth node
        while (temp != null && count < k) {
            temp = temp.next;
            count++;
        }

        if (temp == null) {
        System.out.println("K is larger than the length of the list.");
        return head; // If k exceeds the list length, return the unchanged list
    }

    // Handle cases for deletion
        Node prev = temp.back;
        Node front = temp.next;

        if(prev == null && front == null){
            // only 1 node present
            return null;
        }else if(prev == null){
            // Deleting the head 
            return deleteHead(head);
        }else if(front == null){
            // Deleting the tail
            return deleteTail(head);
        }

        // Deleting a middle node
        prev.next = front;
        front.back = prev;

        temp.next = null;
        temp.back = null;

        return head;
    }
    public static void main(String args[]){
        int arr[] = {10,20,30,40,50};
        Node head = convertArr2DLL(arr);

        head = deleteKth(head,6);
        print(head);
    }
}
