

// Class representing a Node in a linked list
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class Deletion {

    // Method to convert an array to a linked list
    private static Node convertArrayToLinkedList(int[] arr) {
        if (arr.length == 0) return null;

        Node head = new Node(arr[0]); 
        Node current = head;

        for (int i = 1; i < arr.length; i++) {
            current.next = new Node(arr[i]);
            current = current.next;
        }
        return head;
    }

    private static void printLinkedList(Node head) {
        Node current = head;

        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println(); 
    }

    private static Node deleteHead(Node head) {
        if (head == null) {
            return null; 
        }
        return head.next; 
    }

    // Method to delete the tail of the linked list
    private static Node deleteTail(Node head) {
        if (head == null || head.next == null) {
            return null; 
        }
        Node current = head;
        while (current.next.next != null) {
            current = current.next;
        }
        current.next = null; 
        return head;
    }

    private static Node deletekthNode(Node head,int k){
        if(head == null) return head;
        if(k == 1){
            head = head.next;
            return head;
        }
        Node temp = head;
        int count = 0;
        Node prev = null;

        while(temp != null){
            count++;
            if(count == k){
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
    
    private static Node deleteEl(Node head,int el){
        if(head == null) return head;
        if(head.data == el){
            head = head.next;
            return head;
        }
        Node temp = head;
        Node prev = null;

        while(temp != null){
            if(temp.data == el){
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};

        // Convert the array to a linked list
        Node head = convertArrayToLinkedList(arr);

        // Delete the head node 
        // System.out.print("Linked list after deleting the head: ");
        head = deleteHead(head);
        // printLinkedList(head);

        // Delete the tail node 
        // System.out.print("Linked list after deleting the tail: ");
        head = deleteTail(head);
        // printLinkedList(head);

        // delete at kth index
        head = deletekthNode(head,2);
        // printLinkedList(head);

        head = deleteEl(head, 3);
        printLinkedList(head);

    }
}
