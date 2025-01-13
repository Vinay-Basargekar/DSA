
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

public class add2Nos {
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

    private static Node add2Node(Node head,Node head1){
        Node t1 = head;
        Node t2 = head1;

        Node dummNode = new Node(-1);
        Node current = dummNode;
        int carry = 0;

        while(t1 != null || t2 != null){
            int sum = carry;
            if(t1 != null){
                sum = sum + t1.data;
            }
            if(t2 != null){
                sum = sum + t2.data;
            }
            Node newNode = new Node(sum % 10);
            carry = sum / 10;
            current.next = newNode;
            current = current.next;
            if(t1 != null){
                t1 = t1.next;
            }
            if(t2 != null){
                t2 = t2.next;
            }
        }
        if(carry > 0){
            Node newNode = new Node(carry);
            current.next = newNode;
        }
        return dummNode.next;
    }
    public static void main(String[] args) {
        int arr[] = {3,5};
        int arr1[] = {4,5,9,9};
        // Node x = new Node(2);
        Node head = ConvertArr2LL(arr);
        Node head1 = ConvertArr2LL(arr1);

        Node newHead = add2Node(head,head1);
        print(newHead);

    }
}
