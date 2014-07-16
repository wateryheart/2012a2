/*******************************************************
 * COMP2012 - 2012/13 Fall
 * Programming Assignment 2
 * File: main.cpp
 *
 * MAR Chun Sum (20057384)
 *******************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "Polynomial.h"

using namespace std;

int main(void)
{
   Polynomial a, b, d;

   a.readPoly("input1.txt");
   cout << "a=";
   a.print();
 
   b.readPoly("input2.txt");
   cout << "b=";
   b.print();

   d=a;
   cout << "d=";
   d.print();

   Polynomial e(b);
   cout << "e=";
   e.print();

   cout << "a(2)=" << a(2) << endl;

   if (a==b) cout << "a equals to b." << endl;
   else cout << "a does not equal to b." << endl;

   cout << "a+b=";
   (a+b).print();

   cout << "a-b=";
   (a-b).print();

   cout << "a*b="; 
   (a*b).print();

   cout << "d+=b; d=";
   d+=b;
   d.print();

   cout << "e-=a; e=";
   e-=a;
   e.print();

   cout << "b+=10; b=";
   b+=10;
   b.print();

   cout << "10+b=";
   Polynomial temp;
   temp=10+b;
   temp.print();

   cout << "10*b=";
   (10*b).print();

   cout << "b*10=";
   (b*10).print();

   cout << "e*=10, e=";
   e*=10;
   e.print();

   return (0); 
}
