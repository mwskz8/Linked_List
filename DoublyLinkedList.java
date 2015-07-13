/*
  Author: A Sun	
  Subject:	Doubly Linked List w/ Head & Tail Pointers
*/

class Node {
    Node prev;
    int num;
    Node next;

    public Node(int val) 
    {
      prev = null;
      num = val;
      next = null;
    }
}

class DoublyLinkedList 
{
    private Node head = null;
    private Node tail = null;

    // Add to end of list
    public void add(int val)
    {
      Node last = getLastNode();
       
      if (last == null)
	head = new Node(val);
      else { 
        last.next = new Node(val);
	last.next.prev = last;
	tail = last.next;
      }
    }
 
    public void delete(int val) 
    {
        Node prevNode = null;
        Node currNode = head;

// When head is null 
        if(head == null){
            return;
        }

// When head is NOT null
	// if only consider the available nodes, &&
	// if current node's num NOT match
        while (currNode != null && currNode.num != val) {
            prevNode = currNode;
            currNode = currNode.next;
        }
	// So, after the while loop, the cases left to check:
	// if either 
	// 1) current node is null (reach end of list), or 
	// 2) current node's number matches

	// As for 2), if either
	// a) current node is first node, or
	// b) current node is last node, or
	// c) current node is between first and last node

	// 1)
        if (currNode == null) {
            System.out.println("A node with that value does not exist.");
            return;
        }
	// a)
        if(prevNode == null){
            head = head.next;
	    //head.prev = null; // wrong: assign null to null
            return;
        }
	// b) 
	if (currNode == tail) {
            prevNode.next = currNode.next;
	    tail = prevNode;
	    return;
	}
	// c)
	prevNode.next = currNode.next;
	currNode.next.prev = prevNode;
    }

    public void printReverse() 
    {
        System.out.println("");
        if(head == null){
            System.out.print("EMPTY");
            return;
        }
        Node tmpNode = tail;
        while (tmpNode != null) {
            System.out.print(tmpNode.num + " -> ");
            tmpNode = tmpNode.prev;
        }
    }

    public void print() 
    {
        System.out.println("");
        if(head == null){
            System.out.print("EMPTY");
            return;
        }
        Node tmpNode = head;
        while (tmpNode != null) {
            System.out.print(tmpNode.num + " -> ");
            tmpNode = tmpNode.next;
        }
    }

    public Node getLastNode()
    {
      Node tmp = head;
 
      // if list NOT exists
      if (tmp == null)
	return null;
      // if list exists
      while (tmp.next != null) {
        tmp = tmp.next;
      }
      return tmp;
    }

    public static void main(String[] args) 
    {
        DoublyLinkedList myList = new DoublyLinkedList();
        myList.print();

        myList.add(35);
        myList.add(33);
        myList.add(31);

        myList.print();
	myList.printReverse();

        myList.delete(31);
        myList.delete(33);
        myList.delete(35);
        myList.print();

        myList.delete(35);
        myList.print();
    }
}

