// import java.util.Scanner;

// Defining Node structure
class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class node_creation{

    // Returing head to traverse via LL
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
    public static void main(String[] args) {
        int arr[] = {1,2,3,4};

        // Node x = new Node(2);
        Node head = ConvertArr2LL(arr);

        // Traversal of LL
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }

        // System.out.println(head.data);
    }
}