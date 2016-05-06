import java.util.*;

public class Q2_3 {

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

		public boolean deleteNode(Node toDelete) {
			if(toDelete == null || toDelete.next == null) {//Can't delete last node of linked-list
				return false;
			}

			Node nextNode = toDelete.next;
			toDelete.value = nextNode.value;
			toDelete.next = nextNode.next;
			return true;
		}

	}

	public static void main(String[] args) {
		Node head = new Node(1);

		for(int i=0; i<10; i++) {
			head.append(i);
		}

		head.printAll();
		System.out.println("result: "+head.deleteNode(head.next.next));
		System.out.println("result: "+head.deleteNode(head.next));
		System.out.println("result: "+head.deleteNode(head.next));
		head.printAll();
	}

}