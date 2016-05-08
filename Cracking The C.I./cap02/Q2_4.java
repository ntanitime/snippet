import java.util.*;

public class Q2_4 {

	public static class IntWrapper {
		public int value = 0;
	}

	public static class Node{
		Node next;
		int value;

		public Node(int d){
			value = d;
			next = null;
		}

		public void append(int d){
			Node toAdd = new Node(d);
			Node n = this;
			while(n.next != null){
				n = n.next;
			}

			n.next = toAdd; 
		}

		public void printAll(){
			int i = 0;
			Node n = this;
			System.out.println(i + " " + n.value);

			while(n.next != null){
				n = n.next;
				System.out.println(++i + " " + n.value);
			}
		}

		// O(n) time
		public Node partitionByValue(int i) {
			Node node = this;
			Node head_left = null;
			Node head_right = null;
			Node current_left = null;
			Node current_right = null;

			while(node != null) {
				Node tNode = node;//temp node
				node = node.next;
				tNode.next = null;//N.B. oterwise you keep old connections

				if(tNode.value >= i) {
					if (head_right == null) {//init right part
						head_right = tNode;
						current_right = head_right;
					} else {
						current_right.next = tNode;
						current_right = current_right.next;
					}
				} else {
					if (head_left == null) {
						head_left = tNode;
						current_left = head_left;
					} else {
						current_left.next = tNode;
						current_left = current_left.next;
					}
				}
			}

			if(head_right == null){
				return head_left;
			}
			//Fine also if "head_right == null"
			
			current_left.next = head_right;
			return head_left;
		}

		//Here we don't keep the order
		public Node partitionByValue_B(int i) {
			Node node = this;
			Node head = node;
			Node tail = node;

			while(node != null) {
				Node tNode = node;
				node = node.next;
				tNode.next = null;

				if(tNode.value >= i) {//Insert at tail
					tail.next = tNode;
					tail = tail.next;
				} else {//Insert at head
					tNode.next = head;
					head = tNode;
				}
			}
			return head;
		}

	}

	public static void main(String[] args) {
		Node head = new Node(1);

		for(int i=10; i>0; i--) {
			head.append(i);
		}

		head.printAll();
		System.out.println("-----");
		head = head.partitionByValue_B(2);
		head.printAll();
	}

}