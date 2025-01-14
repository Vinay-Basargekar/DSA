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

public class sort012 {

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
    // brute force solution- O(2N), O(N)
    private static Node segregate(Node head){
        if(head == null){
            return head;
        }
        int count0 = 0,count1 = 0,count2 = 0;
        Node temp = head;
        while(temp != null){
            if(temp.data == 0){
                count0++;
            }else if(temp.data == 1){
                count1++;
            }else{
                count2++;
            }
            temp = temp.next;
        }
        temp = head;
        while(temp != null){
            if(count0 > 0){
                temp.data = 0;
                count0--;
            }else if(count1 > 0){
                temp.data = 1;
                count1--;
            }else{
                temp.data = 2;
                count2--;
            }
            temp = temp.next;
        }
        return head;
    }

    private static Node segregateOptimal(Node head){
        if(head == null || head.next == null){
            return head;
        }
        Node onehead = new Node(-1);
        Node twohead = new Node(-1);
        Node zerohead = new Node(-1);
        Node zero = zerohead;
        Node one = onehead;
        Node two = twohead;
        
        Node temp = head;

        while(temp != null){
            if(temp.data == 0){
                zero.next = temp;
                zero = zero.next;
            }else if(temp.data == 1){
                one.next = temp;
                one = one.next;
            }else{
                two.next = temp;
                two = two.next;
            }
            temp = temp.next;
        }

        zero.next = (onehead.next != null) ? onehead.next : twohead.next;
        one.next = twohead.next;
        two.next = null;

        return zerohead.next;
    }
    public static void main(String[] args) {
        int arr[] = {1,2,2,0,1,0};
        // Node x = new Node(2);
        Node head = ConvertArr2LL(arr);

        head = segregateOptimal(head);
        print(head);
    }
}
