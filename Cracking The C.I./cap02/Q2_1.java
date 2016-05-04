import java.util.*;
//Test

public class Q2_1 {

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

		// O(N)
		public void removeDouble_A() {
			Set<Integer> viewd = new HashSet<>();
			Node previous = null;
			Node current = this;//use the head

			while(current != null) {
				if(viewd.contains(current.value)){
					previous.next = current.next; 
					System.out.println("Deleted: "+current.value);
				} else {
					previous = current;
					viewd.add(current.value);
				}

				current = current.next;
			}
		}

		// O(N^2)
		public void removeDouble_B() {
			Node outNode = this;
			while(outNode != null) {

				Node in = outNode;
				while(in.next != null) {
					if(in.next.value == outNode.value){
						in.next = in.next.next; //Skipp a node
					} else {
						in = in.next;
					}
				}

				outNode = outNode.next;
			}
		}
	}

	public static void main(String[] args) {
		Node head = new Node(1);

		for(int i=0; i<10; i++) {
			head.append(i);
		}
		for(int i=0; i<4; i++) {
			head.append(i);
		}

		head.printAll();
		System.out.println("---------------------");
		//head.removeDouble_A();
		head.removeDouble_B();
		head.printAll();
	}

}