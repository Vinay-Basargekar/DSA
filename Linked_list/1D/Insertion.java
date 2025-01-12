// Create a Node structure
// Defining Node structure
class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class Insertion {

    private static Node ConvertArr2LL(int arr[]){
    Node head = new Node(arr[0]);
    Node mover = head;

    for(int i=1 ; i<arr.length ; i++){
        Node temp = new Node(arr[i]);
        mover.next = temp;
        mover = temp;
    }
    return head;
    }
    private static void print(Node head) {
        Node current = head;

        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println(); 
    }
    
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
        // Node x = new Node(2);
        Node head = ConvertArr2LL(arr);

        print(head);

    }
}
