#include "big_number.h"

using namespace std;



// default constructor, creates a 0
big_number::big_number() // class members ' :: '
{
	head_ptr = tail_ptr = nullptr; // make sure its empty
	add_node(head_ptr, tail_ptr, '0');
	positive = true;
	base = 10;
	digits = 1; 
}

// int constructor; create big_number from base 10 integer
big_number::big_number(int i)
{
	digits = 0; // set
	base = 10; // assuming base 10
	head_ptr = tail_ptr = nullptr; // testing
	positive = true;
	
	if(i == 0) // special case
	{
		add_node(head_ptr, tail_ptr, '0');
		digits = 1;
	}
	else
	{
		if(i < 0) // negative
		{
			positive = false;
			i *= -1; // copy of int i 
		}
		
		while(i > 0 )
		{
			if(head_ptr != nullptr)
			{
				head_ptr->prev = new node; // change from nullptr to move the head_ptr to this node
				head_ptr->prev->data = (i % 10) + '0'; // add zero to convert to char from number
				head_ptr->prev->next = head_ptr;
				head_ptr = head_ptr->prev;
			}
			else
			{
				head_ptr = new node;
				head_ptr->data = (i % 10) + '0'; // note above
				tail_ptr = head_ptr;
				head_ptr->prev = nullptr;
				head_ptr->next = nullptr;
			}
			digits++;
			i /= 10;
		}
	}
}

// copy constructor, creates a deep copy of m
big_number::big_number(const big_number& m) // make sure its a deep copy
{
	copy_list(m.head_ptr, head_ptr, tail_ptr);
	digits = m.digits;
	positive = m.positive;
	base = m.base;
}

// create a big_number from a string
big_number::big_number(const string& s, unsigned int b)
{
	digits = 0;
	unsigned int index = 0;
	
	positive = true;
	
	if(s[0] == '-')
	{
		positive = false;
		++index;
	}
	if(s[0] == '+')
	{
		++index;
	}
	
	head_ptr = new node;
	head_ptr->data = s[index];
	head_ptr->next = nullptr;
	head_ptr->prev = nullptr;
	tail_ptr = head_ptr;
	
	while(index < s.length())
	{
		tail_ptr->next = new node;
		tail_ptr->next->data = s[++index];
		tail_ptr->next->next = nullptr;
		tail_ptr->next->prev = tail_ptr;
		tail_ptr = tail_ptr->next;
		++digits;
	}
}

// destructor
big_number::~big_number() // works fine
{
	node* removed_node_ptr = head_ptr;	

	while (removed_node_ptr != nullptr && removed_node_ptr->next != nullptr)
		removed_node_ptr = removed_node_ptr->next;
		
	if (removed_node_ptr != nullptr && removed_node_ptr->next != nullptr)
	{
		node* next_node_ptr = removed_node_ptr->next->next; 
		delete removed_node_ptr->next;
		removed_node_ptr->next = next_node_ptr;
	} // could just clear the list, but this deletes the nodes
	 // clearlist(head_ptr, tail_ptr)
}

// assignment operator
big_number& big_number::operator=(const big_number& m)
{
	return *this; // return the number by address
	 // unsure TA said it was working. didn't get the shallow copy message
}

// set value to original value + b; return answer in original number's base
big_number& big_number::operator+= (const big_number& b)
{
	 // something to make sure the bigger number is on top for addition
	 // helper function here
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator*= (const big_number& b)
{
	return *this;
}

// set value to original value - b; return answer in original number's base
big_number& big_number::operator-= (const big_number& b)
{
	return *this;
}

// set value to original value / b; return answer in original number's base
big_number& big_number::operator/= (const big_number& b)
{
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator%= (const big_number& b)
{
	return *this;
}

// prefix increment
big_number& big_number::operator++()
{
	return *this;
}

// prefix decrement
big_number& big_number::operator--()
{
	return *this;
}

bool operator >(const big_number& a, const big_number& b)
{
	if(a.positive == true && b.positive == false) // positive vs negative
	{
		return true; // +a > -b
	}
	if(a.positive == false && b.positive == true) // negative vs positive
	{
		return false; // -a > +b
	}
	
	if(a.digits > b.digits) // if a is larger than b
	{
		return true; // aaa > b
	}
	
	if(a.digits == b.digits && a.positive == true && b.positive == true) // case for both # +
	{
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data > cursor_b->data) // if a > b at a leading digit
			{
				return true;
			}
				cursor_a = cursor_a->next;
				cursor_b = cursor_b->next;
		}
		return false;
	}
	if(a.digits == b.digits && a.positive == false && b.positive == false) // case for both # -
	{
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data < cursor_b->data) // note above inverted
			{
				return true;
			}
				cursor_a = cursor_a->next;
				cursor_b = cursor_b->next;
		}
		return false;
	}
	return false;
}

bool operator >=(const big_number& a, const big_number& b)
{
	if(a.positive == true && b.positive == false) // positive vs negative
	{
		return true;
	}
	if(a.digits > b.digits) // if a is larger than b
	{
		return true;
	}
	if(a.digits == b.digits && a.positive == true && b.positive == true) // case for both # +
	{
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data >= cursor_b->data)
			{
				return true;
			}
				cursor_a = cursor_a->next;
				cursor_b = cursor_b->next;
		}
		return false;
	}
	if(a.digits == b.digits && a.positive == false && b.positive == false) // case for both # -
	{
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data <= cursor_b->data) // 
			{
				return true;
			}
				cursor_a = cursor_a->next;
				cursor_b = cursor_b->next;
		}
		return false;
	}
	return false;
}

bool operator <(const big_number& a, const big_number& b)
{
	if(a.positive == false && b.positive == true)
	{
		return true;
	}
	if(a.positive == true && b.positive == false)
	{
		return false;
	}
	if(a.digits > b.digits)
	{
		return false;
	}
	if(a.positive == true && b.positive == true)
	{	
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{	
			if(cursor_a->data < cursor_b->data)
			{
				return true;				
			}
		cursor_a = cursor_a->next;
		cursor_b = cursor_b->next;
		}
		return false;
	}	
	if(a.digits == b.digits && a.positive == false && b.positive == false) // case for both # -
	{
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data > cursor_b->data)
			{
				return true;
			}
				cursor_a = cursor_a->next;
				cursor_b = cursor_b->next;
			}
		return false;
		}
	return false;
}
			
bool operator <=(const big_number& a, const big_number& b)
{
	if(a.positive == false && b.positive == true)
	{
		return true;
	}
	if(a.positive == true && b.positive == false)
	{
		return false;
	}
	if(a.digits < b.digits)
	{
		return true;
	}
	if(a.positive == true && b.positive == true)
	{	
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data <= cursor_b->data)
			{
				return true;				
			}
			cursor_a = cursor_a->next;
			cursor_b = cursor_b->next;
		}
		return false;
	}	
	if(a.positive == false && b.positive == false)
	{	
		node* cursor_a = a.head_ptr;
		node* cursor_b = b.head_ptr;
		
		while(cursor_a || cursor_b != nullptr)
		{
			if(cursor_a->data <= cursor_b->data)
			{
				return false;
			}
			cursor_a = cursor_a->next;
			cursor_b = cursor_b->next;
			}
		return true;
		}
	return false;
}
			
bool operator==(const big_number& a, const big_number& b)
{
	 // big_number temp_b(b, a.base);
	if(a.positive != b.positive)return false; // cant be equal + vs -
	
	if(a.digits != b.digits)return false; // must be the same number of digits
	
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	
	while(cursor_a && cursor_b != nullptr)
	{
	if(cursor_a->data == cursor_b->data) // check from the front 
		{
			cursor_a = cursor_a->next;
			cursor_b = cursor_b->next;
		}
		else
		{
			return false; // if one digit isn't equal
		}
	}
	return true;
}
	
bool operator!=(const big_number& a, const big_number& b)
{
	if(a.positive != b.positive)return true;
	
	if(a.digits != b.digits)return true;
	
	node* cursor_a = a.head_ptr;
	node* cursor_b = b.head_ptr;
	
	while(cursor_a && cursor_b != nullptr)
	{
		if(cursor_a->data == cursor_b->data)
		{
			cursor_a = cursor_a->next;
			cursor_b = cursor_b->next;
		}
		else
		{
			return true;
		}
	}
	return false;
}

ostream& operator <<(ostream& out, const big_number& n)
{
	node* cursor = new node;
	cursor = n.head_ptr;
	if(n.positive == false)
	{
		out << "-";
	}
	for(unsigned int i = 0; i < n.digits; i++) // loop to out characters
	{
		out << cursor->data;
		cursor = cursor->next;
	}
	return out;
}

istream& operator >>(istream& in, big_number& n)
{
	string temp; // temp to hold input
	in >> temp; 
	big_number i(temp,10);
	n = i;
	return in;
}

big_number operator+(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator-(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator*(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator/(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number operator%(const big_number& a, const big_number& b)
{
	big_number answer;
	return answer;
}

big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}

big_number& big_number::sum(const big_number& m) // helper function; assumer |*this| >= |m|
{
	 // start at the tail
	node* cursor = tail_ptr;
	const node* mcursor = m.tail_ptr;
	digits = 0; // a little scary buts lets roll with it
	
	unsigned int digit1, digit2, result;
	unsigned int carry = 0;
	
	while(cursor != nullptr && mcursor != nullptr)
	{
		digit1 = base36.find(cursor->data);
		digit2 = base36.find(mcursor->data);
		result = carry + digit1 + digit2;
		
		if(result >= base)
		{
			if(base <= 10)
			{
				cursor->data = (result % base) + '0';
			}
			else
				cursor->data = result + 'a' - 10;
			carry = 1;
		}
		else
		{
			if(base <= 10)
			{
				cursor->data = result + '0';
			}
			else
				cursor->data = result + 'a' - 10;
			carry = 0;
		}
		cursor = cursor->prev; // started at the tail
		mcursor = mcursor->prev;
		++digits;
	}
	while(cursor != nullptr)
	{
		digit1 = base36.find(cursor->data);
		result = carry + digit1 + digit2;
		
		if(result >= base)
		{
			if(base <= 10)
			{
				cursor->data = (result % base) + '0';
			}
			else
				cursor->data = result + 'a' - 10;
			carry = 1;
		}
		else
		{
			if(base <= 10)
			{
				cursor->data = result + '0';
			}
			else
				cursor->data = result + 'a' - 10;
			carry = 0;
		}
		cursor = cursor->prev;
		++digits;
	}
	if(carry > 0 )
	{
		head_ptr->prev = new node;
		head_ptr->prev->prev = nullptr;
		head_ptr->prev->next = head_ptr;
		head_ptr->prev->data = '1';
		head_ptr = head_ptr->prev;
		++digits;
	}
	
	return *this; // new function called dig, instead of carry we would use borrow
}
/*
void big_number::trim()
{
	while(head_ptr != tail_ptr && head_ptr->data == '0')
	{
		--digits;
		head_ptr = head_ptr->next;
		delete head_ptr->prev;
		head_ptr->prev = nullptr;
	}
}
*/
