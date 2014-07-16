/*******************************************************
 * COMP2012 - 2012/13 Fall
 * Programming Assignment 2
 * File: List.cpp

 * MAR Chun Sum (20057384)
 *******************************************************/

#include "List.h"
using namespace std;

/* ListNode class: the list node of a linked list
       representing a term in a polynomial list
       member variables: coef & expon
*/

// constructors
ListNode::ListNode()
{
	next = NULL;
};

ListNode::ListNode(int c, int e)
{
	coef = c;
	expon = e;
	next = NULL;
};

// destructor
ListNode::~ListNode()
{
	next = NULL;
};

/* List class: a linked list
   representing a polynomial
 */

// constructor
List::List()
{
	head = NULL;
	tail = NULL;
};

// copy constructor
List::List(const List& a)
{
	ListNode* cur;
	ListNode* last;
	for (int i = 0 ; i < a.length() ; i++)
	{
		if (head == NULL) // first node
		{
			head = new ListNode (a.retrieveNode(i)->coef, a.retrieveNode(i)->expon);
			cur = head;
		}
		else //other node
		{
			ListNode* node;
			node = new ListNode (a.retrieveNode(i)->coef, a.retrieveNode(i)->expon);
			cur->next = node;
			last = cur;
			cur = node;
		}
	}
	tail = last;
};

// destructor
List::~List()
{
	while(head != NULL)
	{
		ListNode* temp;
		temp = head;
		head = head->next;
		delete temp;
	}
};

// If the linked list is empty, return true, else false
bool List::empty() const
{
	if ( head == NULL )
		return true;
	else
		return false;
};

// returns the number of node in the linked list
int List::length() const
{
	int count = 0;
	ListNode* temp;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
};

// add a node to the end of the linked list
void List::attachNode(int coef, int expon)
{
	ListNode* node;
	node = new ListNode(coef,expon);
	if (head == NULL) //empty list
	{
		head = node;
		tail = node;
	}
	else if (head->next == NULL) //list with only one node
	{
		head->next = node;
		tail->next = node;
		tail = node;
	}
	else //list with at least two nodes
	{
		tail->next = node;
		tail = node;
	}
};

void List::attachNode(ListNode* n)
{
	attachNode(n->coef,n->expon);
};
// delete the first node in the linked list
void List::deleteHead()
{
	if(head != NULL) //cannot delete empty
	{
		ListNode* temp;
		temp = head;
		head = head->next;
		delete temp;
	}
};
// find and return the n-th node in the linked list
ListNode* List::retrieveNode(int n) const
{
	ListNode* temp;
	temp = head;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	return temp;
};
