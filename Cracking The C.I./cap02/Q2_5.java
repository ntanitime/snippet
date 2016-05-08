import java.util.*;

public class Q2_5 {

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

		public Node addReverse(Node a, Node b) {
			Node node = new Node(0);
			Node newHead = node;
			int carry = 0;

			while(a != null || b != null){
				node.value += carry;
				if(a != null) {
					node.value += a.value;
					a = a.next;
				}

				if(b != null) {
					node.value += b.value;
					b = b.next;
				}

				if (node.value >= 10) {
					carry = 1;
					node.value -= 10;
				} else {
					carry = 0;
				}

				node.next = new Node(0);
				node = node.next;
			}

			if(carry > 0) {
				node.value = 1;
			}

			return newHead;
		}

		public Node add(Node a, Node b) {
			Node node = new Node(0);
			Node newHead = node;
			int carry = 0;

			while(a != null || b != null){
				node.value += carry;
				if(a != null) {
					node.value += a.value;
					a = a.next;
				}

				if(b != null) {
					node.value += b.value;
					b = b.next;
				}

				if (node.value >= 10) {
					carry = 1;
					node.value -= 10;
				} else {
					carry = 0;
				}

				node.next = new Node(0);
				node = node.next;
			}

			if(carry > 0) {
				node.value = 1;
			}

			return newHead;
		}

	}

	public static void main(String[] args) {
		Node a = new Node(0);
		Node b = new Node(0);

		for(int i=2; i<8; i++) {
			a.append(i);
			b.append(i);
		}

		a.printAll();
		System.out.println("-------");
		Node res = a.addReverse(a,b);
		res.printAll();
	}

}