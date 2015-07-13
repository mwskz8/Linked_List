/*
  Author:	A Sun
  Subject:	Doubly Linked List w/ Head & Tail Pointers
*/

#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *right; //next node
  struct node *left;  //previous node
} node_t;

void add(int val);
node_t *find(int val);
int delete(int val);
void print();

node_t *head = NULL; //point to front of the list
node_t *tail = NULL; //point to end of the list
node_t *curr; //newly created node

int count = 0; //track total nodes created
int tmp_count=0; //track num of nodes traversed in find()
 
void add(int val)
{
  if (head == NULL) {
    curr = malloc(sizeof(node_t));
    count++;
    head = tail= curr;
    
    curr->val = val;
    curr->right = NULL;
    curr->left = NULL;
  } 
  else { //add to end of the list
    curr = malloc(sizeof(node_t));
    count++;

    tail->right = curr; //point previous node to new node

    curr->val = val;
    curr->right = NULL;
    curr->left = tail;  //point new node to previous node
    
    tail = curr;  //point to end of the node
  }
}

/* Note:
   The smart and efficient way to write this method is to
   implement find() first 
*/
int delete(int val)
{
  node_t *tmp;

  // NOT found
  if ((tmp = find(val)) == NULL)  return -1;
  // Found
  else {
    // if only one node exists in the list
    if (count == 1 && tmp_count == 1) {
      head = tail = NULL;
      count--;
      return 0;
    }
    // if more than one node exist
    if (count >= tmp_count) {
      // first node is the one
      if (tmp_count == 1) {
	head = head->right;
        head->left = NULL;
        count--;
        return 0;
      }
      // last node is the one
      if (count == tmp_count) {
        tail = tail->left;
	tail->right == NULL;
        count--;
        return 0;
      }
      // between 1st and last node is the one 
      tmp->left->right = tmp->right;
      tmp->right->left = tmp->left;
      count--;
      return 0;
    }
  }
}

// Traverse from head to tail to find the node
node_t *find(int val)
{
  node_t *tmp = head;
  
  /* Base case: no node */
  if (head == NULL && tail == NULL) {
    printf("Linked list NOT exist!\n");
    return NULL;
  }

  /* Medium case: 1 node exists */
  if (head == tail) {
    // current node's value matches
    if (head->val == val && tail->val == val) {
      tmp_count++;
      return tmp;
    }
    // current node's value NOT matches
    if (head->val != val && tail->val != val) {
      printf("No node matches the val needed\n");
      return NULL;
    }
  }

  /* Complex case: more than 1 node exist */
  // -- has NOT found the node
  while (tmp->val != val) {
    tmp_count++; 
    
    // last node NOT reached
    if (tmp->right != NULL) {
      tmp = tmp->right;
    }
    // last node reached
    else {
      printf("Last node reached, node NOT found\n");
      return NULL;
    }
  }  
  // -- has found the node
  tmp_count++; 
  printf("Node found, tmp->val:%d\n", tmp->val);
  return tmp; 
}

// Print linked list
void print()
{
  node_t *tmp = head;
  int i=1;

  if (tmp == NULL) { 
    printf("Empty list\n");
    return;
  }
  
  while (i++ <= count) {
    printf("%d ", tmp->val);
    tmp = tmp->right;
  } printf("\n");
}

main()
{
  int i=1, rc=0;

  while (i<=4) {
    add(i);
    i++;
  }
  print();
  
  //find(2);

/*  printf("rc: %d\n", rc = delete(3));
  print();*/
}
