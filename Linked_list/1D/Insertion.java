// Defining Node structure
class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }

    Node(int data,Node next){
        this.data = data;
        this.next = next;
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
    
    private static Node inserthead(Node head,int k){
        Node x = new Node(k,head);
        // x.next = head;
        head = x;
        return head;
    }

    private static Node insertTail(Node head,int k){
        Node x = new Node(k);
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = x;
        return head;
    }

    private static Node insertKth(Node head,int k,int el){
        if(head == null){
            return head;
        }
        if(k==1){
            Node x = new Node(k,head);
            return x;
        }

        Node temp = head;
        int count = 0;
        while(temp != null){
            count++;
            if(count == k){
                Node x = new Node(el);
                x.next = temp.next;
                temp.next = x;
                break;
            }
            temp = temp.next;
        }
        return head;
    }

    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
        // Node x = new Node(2);
        Node head = ConvertArr2LL(arr);

        head = insertKth(head,3,10);

        print(head);

    }
}
