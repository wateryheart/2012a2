/*******************************************************
 * COMP2012 - 2012/13 Fall
 * Programming Assignment 2
 * File: Polynomial.h
 *
 * MAR Chun Sum (20057384)
 *******************************************************/
#include "Polynomial.h"
using namespace std;

 // Default constructor
Polynomial::Polynomial()
{
};

 // Constructor for constant polynomial
Polynomial::Polynomial(int c)
{
	polyList.attachNode(c,0);
};

 // Copy constructor
Polynomial::Polynomial(const Polynomial& a)
{
	for(int i = 0; i < a.polyList.length(); i++)
	{
		polyList.attachNode(a.polyList.retrieveNode(i));
	}
};

// Destructor
Polynomial::~Polynomial()
{
	polyList.~List();
};

// print the polynomial a in decreasing order of exponent
void Polynomial::print() const
{
	int position = 1;
	if (polyList.length() == 0) //if polynomial is empty
		cout << "0";
	else
	{
		for (int i = 0; i < polyList.length(); i++)
		{
			if (polyList.retrieveNode(i)->expon == 0)
			{
				if (position == 1) //first element
					cout << polyList.retrieveNode(i)->coef;
				else //non-first element with sign
				{
					if (polyList.retrieveNode(i)->coef >= 0) //positive number should have + sign
						cout << "+" << polyList.retrieveNode(i)->coef;
					else
						cout << polyList.retrieveNode(i)->coef;
				}
			}
			else if (polyList.retrieveNode(i)->expon == 1)
			{
				if (position == 1) //first element
				{
					if (polyList.retrieveNode(i)->coef == 1)
						cout << "X";
					else if(polyList.retrieveNode(i)->coef == -1)
						cout << "-X";
					else
						cout << polyList.retrieveNode(i)->coef << "X";
				}
				else //non-first element with sign
				{
					if (polyList.retrieveNode(i)->coef == 1)
						cout << "+X";
					else if(polyList.retrieveNode(i)->coef == -1)
						cout << "-X";
					else if (polyList.retrieveNode(i)->coef > 1)
						cout << "+" << polyList.retrieveNode(i)->coef << "X";
					else
						cout << polyList.retrieveNode(i)->coef << "X";
				}
			}
			else
			{
				if (position == 1) //first element
				{
					if (polyList.retrieveNode(i)->coef == 1)
						cout << "X^" << polyList.retrieveNode(i)->expon;
					else if(polyList.retrieveNode(i)->coef == -1)
						cout << "-X^"<< polyList.retrieveNode(i)->expon;
					else
						cout << polyList.retrieveNode(i)->coef << "X^" << polyList.retrieveNode(i)->expon;

				}
				else //non-first element with sign
				{
					if (polyList.retrieveNode(i)->coef == 1)
						cout << "+X^" << polyList.retrieveNode(i)->expon;
					else if(polyList.retrieveNode(i)->coef == -1)
						cout << "-X^"<< polyList.retrieveNode(i)->expon;
					else if (polyList.retrieveNode(i)->coef > 1)
						cout << "+" << polyList.retrieveNode(i)->coef << "X^" << polyList.retrieveNode(i)->expon;
					else
						cout << polyList.retrieveNode(i)->coef << "X^" << polyList.retrieveNode(i)->expon;
				}
			}
			position++;
		}
	}
	cout << endl;
};
// read and create a polynomial from the file of fileName
//
void Polynomial::readPoly(const char* filename)
{
	char content[100], ch;
	int i = 0, c = 0, e = 0;
	ifstream file(filename);
	if (file.is_open())
	{
		while (file.get(ch)) //get the content of file into chat array
			content[i++] = ch;
		content[i] = '\0';
		file.close();
	}
	else
		cout << "Error: File not found." << endl;

	//for(int k = 0; k <= i; k++)
	//	cout << content[k];

	int ns = 0, s = 0, position = 1;
	bool x;
	while (content[ns] != '\0')
	{
		if ((content[ns] == '+' || content[ns] == '-') && ns != 0)
		{
			x = false;
			for (int l = s; l < ns; l++)
			{
				if (content[l] == 'x') //with coefficient
				{
					x = true;
					if(position == 1) //first node
					{
						//coefficient
						if (content[0]== '-')
						{
							if (content[1] == 'x') //-x
								c = -1;
							else //-cx
								c = 0 - atoi(&content[1]);
						}
						else
						{
							if (content[0] == 'x') //x
								c = 1;
							else //cx
								c = atoi(&content[0]);
						}

						//exponent
						if (content[ns-1] == 'x')
							e = 1;
						else
							e = atoi(&content[l+2]);
					}
					else //non-first node
					{
						//coefficient
						if (content[s] == '+')
						{
							if (content[s+1] == 'x') //+x
								c = 1;
							else //+cx
								c = atoi(&content[s+1]);
						}
						else if (content[s]== '-')
						{
							if (content[s+1] == 'x') //-x
								c = -1;
							else //-cx
								c = 0 - atoi(&content[s+1]);
						}

						//exponent
						if (content[ns-1] == 'x')
							e = 1;
						else
							e = atoi(&content[l+2]);
					}
				}
			}
			if (x == false) //constant only
			{
				e = 0;

				//coefficient
				if (position == 1)
				{
					if (content[0] == '-')
						c = 0 - atoi(&content[1]);
					else
						c = atoi(&content[0]);
				}
				else
				{
					if (content[s] == '+')
						c = atoi(&content[s+1]);
					else
						c = 0 - atoi(&content[s+1]);
				}
			}
			polyList.attachNode(c,e);
			position++;
			s = ns;
			c = 0;
			e = 0;
		}
		ns++;
	}

	x = false;
	for (int l = s; l < ns; l++)
	{
		if (content[l] == 'x')  //with coefficient
		{
			x = true;
			//coefficient
			if (content[s] == '+')
			{
				if (content[s+1] == 'x') //+x
					c = 1;
				else //+cx
					c = atoi(&content[s+1]);
			}
			else if (content[s]== '-')
			{
				if (content[s+1] == 'x') //-x
					c = -1;
				else //-cx
					c = 0 - atoi(&content[s+1]);
			}
			//exponent
			if (content[ns-1] == 'x')
				e = 1;
			else if (content[ns-1] == c)
				e = 0;
			else
				e = atoi(&content[l+2]);
			polyList.attachNode(c,e);
		}
	}
	if (x == false) //constant only
	{
		e = 0;

		//coefficient
		if (position == 1)
		{
			if (content[0] == '-')
				c = 0 - atoi(&content[1]);
			else
				c = atoi(&content[0]);
		}
		else
		{
			if (content[s] == '+')
				c = atoi(&content[s+1]);
			else
				c = 0 - atoi(&content[s+1]);
		}
		polyList.attachNode(c,e);
	}
	int tc, te;
	//sort it in decreasing order
	for (int m = 0; m < polyList.length(); m++)
	{
		for (int n = m + 1; n < polyList.length(); n++)
		{
			if (polyList.retrieveNode(m)->expon < polyList.retrieveNode(n)->expon)
			{
				tc = polyList.retrieveNode(m)->coef;
				te = polyList.retrieveNode(m)->expon;
				polyList.retrieveNode(m)->coef = polyList.retrieveNode(n)->coef;
				polyList.retrieveNode(m)->expon = polyList.retrieveNode(n)->expon;
				polyList.retrieveNode(n)->coef = tc;
				polyList.retrieveNode(n)->expon = te;
			}
		}
	}

	//combine coefficient of same exponent
	Polynomial sort;
	int co, largestExpon;
	largestExpon = polyList.retrieveNode(0)->expon;
	for(int p = largestExpon; p >= 0; p--)
	{
		co = 0;
		for(int q = 0; q < polyList.length(); q++)
		{
			if(polyList.retrieveNode(q)->expon == p)
				co = co + polyList.retrieveNode(q)->coef;
		}
		if (co != 0) //only record coefficient of exponent not equal to 0
			sort.polyList.attachNode(co,p);
	}
	polyList.~List();
	for(int s = 0; s < sort.polyList.length(); s++)
	{
		polyList.attachNode(sort.polyList.retrieveNode(s));
	}

};

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& a)
{
	polyList.~List();
	for(int i = 0; i < a.polyList.length(); i++)
	{
		polyList.attachNode(a.polyList.retrieveNode(i));
	}
	return *this;
};

// Addition assignment operator
Polynomial& Polynomial::operator+=(const Polynomial& a)
{
	*this = *this + a;
	return *this;
};

// Subtraction assignment operator
Polynomial& Polynomial::operator-=(const Polynomial& a)
{
	*this = *this - a;
	return *this;
};

// Multiplication assignment operator
Polynomial& Polynomial::operator*=(const Polynomial& a)
{
	*this = *this * a;
	return *this;
};

// Evaluate the polynomial a at value of x
int Polynomial::operator()(int x) const
{
	int sum = 0;
	for (int i = 0; i < polyList.length(); i++)
	{
		sum = sum + polyList.retrieveNode(i)->coef * (int)pow(x , polyList.retrieveNode(i)->expon);
	}
	return sum;
};

// Addition operator
Polynomial operator+(const Polynomial& b, const Polynomial& a)
{
	Polynomial c;
	int i = 0, j = 0;
	while (i < a.polyList.length() && j < b.polyList.length())
	{
		if (a.polyList.retrieveNode(i)->expon > b.polyList.retrieveNode(j)->expon)
		{
			c.polyList.attachNode(a.polyList.retrieveNode(i));
			i++;
		}
		else if (a.polyList.retrieveNode(i)->expon < b.polyList.retrieveNode(j)->expon)
		{
			c.polyList.attachNode(b.polyList.retrieveNode(j));
			j++;
		}
		else if (a.polyList.retrieveNode(i)->expon == b.polyList.retrieveNode(j)->expon)
		{
			if(a.polyList.retrieveNode(i)->coef + b.polyList.retrieveNode(j)->coef != 0)
				c.polyList.attachNode(a.polyList.retrieveNode(i)->coef + b.polyList.retrieveNode(j)->coef, a.polyList.retrieveNode(i)->expon);
			i++;
			j++;
		}
	}
	if(i < a.polyList.length())
	{
		c.polyList.attachNode(a.polyList.retrieveNode(i));
		i++;
	}
	if(j < b.polyList.length())
	{
		c.polyList.attachNode(b.polyList.retrieveNode(j));
		j++;
	}
	return c;
};

// Subtraction operator
Polynomial operator-(const Polynomial& b, const Polynomial& a)
{
	Polynomial c;
	int i = 0, j = 0;
	while (i < a.polyList.length() && j < b.polyList.length())
	{
		if (a.polyList.retrieveNode(i)->expon > b.polyList.retrieveNode(j)->expon)
		{
			c.polyList.attachNode(0- a.polyList.retrieveNode(i)->coef,a.polyList.retrieveNode(i)->expon);
			i++;
		}
		else if (a.polyList.retrieveNode(i)->expon < b.polyList.retrieveNode(j)->expon)
		{
			c.polyList.attachNode(b.polyList.retrieveNode(j));
			j++;
		}
		else if (a.polyList.retrieveNode(i)->expon == b.polyList.retrieveNode(j)->expon)
		{
			if(b.polyList.retrieveNode(j)->coef - a.polyList.retrieveNode(i)->coef != 0)
				c.polyList.attachNode(b.polyList.retrieveNode(j)->coef - a.polyList.retrieveNode(i)->coef, a.polyList.retrieveNode(i)->expon);
			i++;
			j++;
		}
	}
	if(i < a.polyList.length())
	{
		c.polyList.attachNode(0- a.polyList.retrieveNode(i)->coef,a.polyList.retrieveNode(i)->expon);
		i++;
	}
	if(j < b.polyList.length())
	{
		c.polyList.attachNode(b.polyList.retrieveNode(j));
		j++;
	}
	return c;
};

// Multiplication operator
Polynomial operator*(const Polynomial& b, const Polynomial& a)
{
	Polynomial mul, sol;
	//multiply two polynomial
	if (a.polyList.length() == 0 || b.polyList.length() == 0)
	{
		mul.polyList.attachNode(0,0);
	}
	else
	{
		for (int i = 0; i < a.polyList.length(); i++)
		{
			for (int j = 0; j < b.polyList.length(); j++)
			{
				mul.polyList.attachNode(a.polyList.retrieveNode(i)->coef * b.polyList.retrieveNode(j)->coef ,
						a.polyList.retrieveNode(i)->expon + b.polyList.retrieveNode(j)->expon);
			}
		}
	}

	//sort it in decreasing order
	int c = 0, e = 0;
	for (int m = 0; m < mul.polyList.length(); m++)
	{
		for (int n = m + 1; n < mul.polyList.length(); n++)
		{
			if (mul.polyList.retrieveNode(m)->expon < mul.polyList.retrieveNode(n)->expon)
			{
				c = mul.polyList.retrieveNode(m)->coef;
				e = mul.polyList.retrieveNode(m)->expon;
				mul.polyList.retrieveNode(m)->coef = mul.polyList.retrieveNode(n)->coef;
				mul.polyList.retrieveNode(m)->expon = mul.polyList.retrieveNode(n)->expon;
				mul.polyList.retrieveNode(n)->coef = c;
				mul.polyList.retrieveNode(n)->expon = e;
			}
		}
	}

	//combine coefficient of same exponent
	int tc, largestExpon;
	largestExpon = mul.polyList.retrieveNode(0)->expon;
	for(int p = largestExpon; p >= 0; p--)
	{
		tc = 0;
		for(int q = 0; q < mul.polyList.length(); q++)
		{
			if(mul.polyList.retrieveNode(q)->expon == p)
				tc = tc + mul.polyList.retrieveNode(q)->coef;
		}
		if (tc != 0) //only record coefficient of exponent not equal to 0
			sol.polyList.attachNode(tc,p);
	}

	return sol;
};

// Equal to operator
bool operator==(const Polynomial& b, const Polynomial& a)
{
	if (a.polyList.length() != b.polyList.length())
		return false;
	else
	{
		for (int i = 0; i < a.polyList.length(); i++)
		{
			if(a.polyList.retrieveNode(i)->coef != b.polyList.retrieveNode(i)->coef)
				return false;
			if(a.polyList.retrieveNode(i)->expon != b.polyList.retrieveNode(i)->expon)
				return false;
		}
	}
	return true;
};
