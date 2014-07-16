/*******************************************************
 * COMP2012 - 2012/13 Fall
 * Programming Assignment 2
 * File: List.h 

 * MAR Chun Sum (20057384)
 *******************************************************/

#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

/* ListNode class: the list node of a linked list 
       representing a term in a polynomial list
       member variables: coef & expon
 */
class ListNode
{
  public:
    int coef;
    int expon;
    ListNode* next;

    // constructors
    ListNode();
    ListNode(int c, int e);
    // destructor
    ~ListNode();
};

/* List class: a linked list
   representing a polynomial
 */
class List
{
  public:
    // constructor
    List();
    // copy constructor
    List(const List& a);
    // destructor
    ~List();

    // If the linked list is empty, return true, else false
    bool empty() const;
    // returns the number of node in the linked list
    int length() const;
    // add a node to the end of the linked list
    void attachNode(int coef, int expon);
    void attachNode(ListNode*);
    // delete the first node in the linked list
    void deleteHead();
    // find and return the n-th node in the linked list
    ListNode* retrieveNode(int n) const;
    
  private:
    ListNode *head;
    ListNode *tail;
};

#endif
