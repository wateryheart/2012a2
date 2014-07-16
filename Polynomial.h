/*******************************************************
 * COMP2012 - 2012/13 Fall
 * Programming Assignment 2
 * File: Polynomial.h
 *
 * MAR Chun Sum (20057384)
 *******************************************************/
#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "List.h"

using namespace std;

/* Polynomial class:
   providing operations on polynomial(s)
   e.g. ==, +, -, *, (), +=, -+, *=
 */ 
class Polynomial
{
   public:
     // Default constructor 
     Polynomial();
     // Constructor for constant polynomial
     Polynomial(int c);
     // Copy constructor
     Polynomial(const Polynomial& a);
     // Destructor
     ~Polynomial();

     // print the polynomial a in decreasing order of exponent
     void print() const;
     // read and create a polynomial from the file of fileName
     // 
     void readPoly(const char* filename);
     // Assignment operator
     Polynomial& operator=(const Polynomial& a); 
     // Addition assignment operator
     Polynomial& operator+=(const Polynomial& a); 
     // Subtraction assignment operator
     Polynomial& operator-=(const Polynomial& a); 
     // Multiplication assignment operator
     Polynomial& operator*=(const Polynomial& a); 
 
     // Evaluate the polynomial a at value of x 
     int operator()(int x) const;


   private:
     List polyList;

   // Addition operator
   friend Polynomial operator+(const Polynomial& b, const Polynomial& a);
   // Subtraction operator
   friend Polynomial operator-(const Polynomial& b, const Polynomial& a);
   // Multiplication operator
   friend Polynomial operator*(const Polynomial& b, const Polynomial& a);

   // Equal to operator
   friend bool operator==(const Polynomial& b, const Polynomial& a);
     
};

#endif
