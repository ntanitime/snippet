import java.util.*;

public class Q2_2 {

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

		// O(n^2) time
		public Node getKth(int i) {
			int count = 0;
			Node current = this;
			while(current != null){
				current = current.next;
				count++;
			}

			current = this;
			count-= i;

			while(current != null){
				if(--count == 0) {
					return current;
				}
				current = current.next;
			}

			return null;
		}

		// O(n) space
		public Node getKth_recursive(Node n, int k, IntWrapper i) {
			if(n == null) {
				return n;
			}

			Node node = getKth_recursive(n.next, k, i);
			if(i.value++ == k) {
				return n;
			}

			return node;
		}

		// O(n) time, O(1) space
		public Node getKth_iterative(int kth) {
			if (kth < 0) {
				return null;
			}

			Node p1 = this;
			Node p2 = this;
			for(int i=0; i<kth; i++) {
				p2 = p2.next;
				if(p2 == null) {
					return null;
				}
			}

			while(p2.next != null) {
				p1 = p1.next;
				p2 = p2.next;
			}

			return p1;
		}
	}

	public static void main(String[] args) {
		Node head = new Node(1);

		for(int i=0; i<10; i++) {
			head.append(i);
		}

		head.printAll();
		System.out.println("NODE.value: "+head.getKth(0).value);
		System.out.println("NODE.value: "+head.getKth(1).value);
		System.out.println("NODE.value: "+head.getKth(9).value);
		System.out.println("NODE.value: "+head.getKth(10).value);
		System.out.println("---------------------");
		System.out.println("NODE.value: " + head.getKth_recursive(head, 0, new IntWrapper()).value);
		System.out.println("NODE.value: " + head.getKth_recursive(head, 1, new IntWrapper()).value);
		System.out.println("NODE.value: " + head.getKth_recursive(head, 9, new IntWrapper()).value);
		System.out.println("NODE.value: " + head.getKth_recursive(head, 10, new IntWrapper()).value);
		System.out.println("---------------------");
		System.out.println("NODE.value: "+head.getKth_iterative(0).value);
		System.out.println("NODE.value: "+head.getKth_iterative(1).value);
		System.out.println("NODE.value: "+head.getKth_iterative(9).value);
		System.out.println("NODE.value: "+head.getKth_iterative(10).value);

	}

}