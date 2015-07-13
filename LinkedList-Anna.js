/*
  Author: A Sun	
  Subject:	Single Linked List 
*/

var LinkedList = function(e) {

  var first, last, count = 0;

  var Node =function(val) {

    /* If you want to create the properties, value and next, on 
       the new object instance (this), you need to do this with 
       this.value and this.next.

       The following won't work, and they aren't accessible 
       outside this function:

       var value = val;
       var next = null;
    */
    this.value = val;
    this.next = null;
  }

  this.push = function(val) {
    var node = new Node(val);

    if (first == null) {
      first = last = node;
    }
    else {
      last.next = node;
      last = node;
    }
    count++;
  }

  this.popFirst = function() {
    if (first == null) {	// 0 node exists
      return null;
    }
    if (first == last) {	// 1 node exists
      first = last = null;
      count--;
      return;
    }
    first = first.next;		// more than 1 node exist
    count--;
    return;
  }

  // recursivly searching for the node
  this.search = function(val, currNode) {
    var tmp = currNode || first;  // recursion purpose

    if (tmp.value == val) { 
        console.log("Found");
	return true;
    }
    if (tmp.next != null) {
	return this.search(val, tmp.next);
    }
    console.log("Not found");
    return false;
  }

  this.print = function() {
    var i = 0, tmp = first;

    if (first == null)
	return null;
   
    // put linked list in an array to print out 
    var arr = new Array();
    while (i < count) {     
        arr[i] = tmp.value;
	tmp = tmp.next;
	i++;
    }
    return console.log(arr);
  } 

}


var list = new LinkedList();
list.push(1);
list.push(2);
list.push(3);
list.push(4);
list.print();

list.popFirst();
list.print();

list.search(3);
list.search(5);

