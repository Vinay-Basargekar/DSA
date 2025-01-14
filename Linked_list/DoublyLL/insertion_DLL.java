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

public class insertion_DLL {
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

    public static void main(String args[]){
        int arr[] = {10,20,30,40,50};
        Node head = convertArr2DLL(arr);

        // head = insertHead(head,6);
        print(head);
    }
}
