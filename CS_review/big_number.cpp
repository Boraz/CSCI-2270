#include "big_number.h"

using namespace std;

// default constructor, creates a 0
big_number::big_number()
{
	head_ptr = tail_ptr = nullptr;
	add_node(head_ptr, tail_ptr, '0');
	positive = true;
	base = 10;
	digits = 1;
}

// int constructor; create big_number from base 10 integer
big_number::big_number(int i)
{
	digits = 0;
	head_ptr = new node;
	tail_ptr = head_ptr;
	head_ptr->next = head_ptr->prev = nullptr;
	base = 10; // assume decimal
	positive = true;
	
	if (i == 0)
	{
		head_ptr->data = '0';
		digits = 1;
		return;
	}
	if (i < 0) 
	{
		positive = false;
		i *= -1;
	}
	
	head_ptr->data = i % 10 + '0';
	i /= 10;
	++digits;
	
	while (i > 0)
	{
		head_ptr->prev = new node;
		head_ptr->prev->data = (i % 10) + '0';
		head_ptr->prev->next = head_ptr;
		head_ptr = head_ptr->prev;
		head_ptr->prev = nullptr;
		++digits;
		i /= 10;
	}
}

// copy constructor, creates a deep copy of m
big_number::big_number(const big_number& m)
{
	head_ptr = nullptr;
	tail_ptr = nullptr;
	*this = m;
}

// conversion constructor; convert m to a different base
big_number::big_number(const big_number& m, unsigned int b)
{
	head_ptr = tail_ptr = nullptr;
	positive = m.positive;
	
	big_number zero;
	zero.base = b;
	*this = zero;
	unsigned int digit;
	
	big_number* values = new big_number[m.base + 1];
	
	big_number j = 0;
	j.base = b;
	
	for (unsigned int i = 0; i <= m.base; ++i)
	{
		values[i] = j;
		++j;
	}
	
	for (const node* cursor = m.head_ptr; cursor != nullptr;
		cursor = cursor->next)
	{
		if (isdigit(cursor->data))
			digit = cursor->data - '0';
		else
			digit = cursor->data - 'a' + 10;
		big_number intermed = values[m.base] * (*this);
		if (intermed > zero)
		{
			intermed.sum(values[digit]);
		}
		else 
		{
			big_number temp(intermed);
			intermed = values[digit];
			intermed += temp;
		}
		*this = intermed;
	}	
	delete [] values;
}

// create a big_number from a string
big_number::big_number(const string& s, unsigned int b)
{
	digits = 0;
	// changed to unsigned int
	unsigned int index = 0;
	positive = true;
	if (s[0] == '-')
	{
		positive = false;
		++index;	
	}
	if (s[0] == '+')
	{
		++index;	
	}
	head_ptr = new node;
	head_ptr->data = s[index++];
	head_ptr->next = nullptr;
	head_ptr->prev = nullptr;
	tail_ptr = head_ptr;
	// forgot to count up first digit
	++digits;
	while (index < s.length())
	{
		tail_ptr->next = new node;
		tail_ptr->next->data = s[index++];
		tail_ptr->next->next = nullptr;
		tail_ptr->next->prev = tail_ptr;
		tail_ptr = tail_ptr->next;
		++digits;
	}

}

// destructor
big_number::~big_number()
{
	clear_list(head_ptr, tail_ptr);
}

// assignment operator
big_number& big_number::operator=(const big_number& m)
{
	if (this == &m) return *this;
	base = m.base;
	copy_list(m.head_ptr, head_ptr, tail_ptr);
	positive = m.positive;
	digits = m.digits;
	return *this;
}

// set value to original value + b; return answer in original number's base
big_number& big_number::operator+= (const big_number& b)
{
	big_number m = b;
	big_number n = *this;
	*this = n.sum(m);
	return *this;
}

// set value to original value * b; return answer in original number's base
big_number& big_number::operator*= (const big_number& b)
{
	big_number n = mult(b);
	*this = n;
	return *this;
}

// set value to original value - b; return answer in original number's base
big_number& big_number::operator-= (const big_number& b)
{
	big_number m = b;
	big_number n = *this;
	*this = n.diff(m);
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
	*this += 1;
	return *this;
}

// prefix decrement
big_number& big_number::operator--()
{
	*this -= 1;
	return *this;
}

int cmp(const big_number& a, const big_number& b)
{
	if (a.digits > b.digits) return 1;
	if (a.digits < b.digits) return -1;
	const node* a_cursor;
	const node* b_cursor;
	for (a_cursor = a.head_ptr, b_cursor = b.head_ptr; 
		b_cursor != nullptr && a_cursor->data == b_cursor->data; 
		b_cursor = b_cursor->next, a_cursor = a_cursor->next)
		;
	if (a_cursor == nullptr) return 0;
	if (a_cursor->data > b_cursor->data) return 1;
	return -1;
}

bool operator >(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return true;
	if (!a.positive && b.positive)
		return false;
	if (a.positive)
		return cmp(a, b) > 0;
	else
		return cmp(a, b) < 0;
	return false;
}

bool operator >=(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return true;
	if (!a.positive && b.positive)
		return false;
	if (a.positive)
		return cmp(a, b) >= 0;
	else
		return cmp(a, b) <= 0;
	return true;
}

bool operator <(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return false;
	if (!a.positive && b.positive)
		return true;
	if (a.positive)
		return cmp(a, b) < 0;
	else
		return cmp(a, b) > 0;
	return false;
}
			
bool operator <=(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive && !b.positive)
		return false;
	if (!a.positive && b.positive)
		return true;
	if (a.positive)
		return cmp(a, b) <= 0;
	else
		return cmp(a, b) >= 0;
	return true;
}
			
bool operator==(const big_number& a, const big_number& b)
{
//	big_number temp_b(b, a.base);
	if (a.positive != b.positive) return false;
	
	return cmp(a, b) == 0;
}
	
bool operator!=(const big_number& a, const big_number& b)
{
	return !(a == b);
}

ostream& operator <<(ostream& out, const big_number& n)
{
	if (!n.positive) out << '-';
	for (const node* cursor = n.head_ptr; cursor != nullptr; cursor = cursor->next)
			out << cursor->data;
	out << "(" << n.base << ")";
	return out;
}

istream& operator >>(istream& in, big_number& n)
{
	unsigned int base;
	cout << "Enter a base: ";
	cin >> base;
	cout << "Enter a number: ";
	string babin;
	in >> babin;
	
	big_number baboo(babin, base);
	n = baboo;
	return in;
}

big_number operator+(const big_number& a, const big_number& b)
{
	big_number answer;
	big_number m = a;
	big_number n = b;
	
	if(n.digits > m.digits)
	{
	big_number s;
	s = m;
	m = n;
	n = s;
	}

	
	if(m.positive == true && n.positive == true) 
	{
		answer = m.diff(n);
	}
	if(m.positive == false && n.positive == false)
	{
		answer = n.diff(m);
	}
	if(m.positive == true && n.positive == false)
	{
		answer = m.sum(n);
		answer.positive = true;
	}
	if(m.positive == false && n.positive == true)
	{
		answer = m.sum(n);
		answer.positive = false;
	}
	return answer;
}

big_number operator-(const big_number& a, const big_number& b)
{
	big_number answer;
	big_number m = a;
	big_number n = b;
	
	if(n.digits > m.digits)
	{
	big_number s;
	s = m;
	m = n;
	n = s;
	}

	if(m.positive == true && n.positive == true) 
	{
		answer = m.diff(n);
	}
	if(m.positive == false && n.positive == false)
	{
		answer = n.diff(m);
	}
	if(m.positive == true && n.positive == false)
	{
		answer = m.sum(n);
		answer.positive = true;
	}
	if(m.positive == false && n.positive == true)
	{
		cout << "here" << endl;
		answer = m.sum(n);
		answer.positive = false;
	}
	return answer;
}

big_number operator*(const big_number& a, const big_number& b)
{
	big_number answer;
	answer *= a;
	answer *= b;
	return answer;
}

big_number factorial(const big_number& a)
{
	big_number answer;
	return answer;
}

// helper function: assume |*this| >= |m|
big_number& big_number::sum(const big_number& m)
{
	node* cursor = tail_ptr;
	const node* mcursor = m.tail_ptr;
	digits = 0;  // a little scary, but let's roll with it anyway
	unsigned int dig1, dig2, result;
	unsigned int carry = 0;
	while (cursor != nullptr && mcursor != nullptr)
	{
		// we added an alphabet string to the big_number.h
		dig1 = base36.find(cursor->data);
		dig2 = base36.find(mcursor->data);
		result = carry + dig1 + dig2;
		if (result >= base) // we have to carry
		{
			// this code is simpler, more correct and more elegant; 
			// thanks to Audi Li!
			cursor->data = base36[result % base];
			carry = 1;
		}
		else // we don't have to carry
		{
			cursor->data = base36[result];
			carry = 0;
		}
		cursor = cursor->prev;
		mcursor = mcursor->prev;
		++digits;
	}
	while (cursor != nullptr)
	{
		dig1 = base36.find(cursor->data);
		result = carry + dig1;
		if (result >= base) // carry
		{
			cursor->data = base36[result % base];
			carry = 1;
		}
		else // no carry
		{
			cursor->data = base36[result];
			carry = 0;
		}
		cursor = cursor->prev;
		++digits;
	}
	
	if (carry > 0)
	{
		head_ptr->prev = new node;
		head_ptr->prev->prev = nullptr;
		head_ptr->prev->next = head_ptr;
		head_ptr->prev->data = '1';
		++digits;
		head_ptr = head_ptr->prev;
	}
	return *this;
}

big_number& big_number::diff(const big_number& m)
{	
	node* cursor = tail_ptr;
	const node* mcursor = m.tail_ptr;
	unsigned int digit1, digit2, result;
	unsigned int borrowed = 0;
	
	while (cursor != nullptr && mcursor != nullptr)
	{
		digit1 = base36.find(cursor->data);
		digit2 = base36.find(mcursor->data);
		if(borrowed == 1)
		{
			if(digit1 == 0)
			{
				digit1 = digit1 + 9;
				borrowed = 1;
			}
			else
			{
			digit1 = digit1 - 1;
			borrowed = 0;
			}
		}
		if(digit1 < digit2) // borrow from next
		{
			digit1 += 10;
			borrowed = 1;
		}
		result = (digit1 - digit2);
		cursor->data = base36[result];
		cursor = cursor->prev;
		mcursor = mcursor->prev;
	}
	while(mcursor == nullptr && cursor != nullptr)
	{
		digit1 = base36.find(cursor->data);		
		
		if(digit1 == 0)
		{
			digit1 = digit1 + 9;
			result = digit1;
			cursor->data = base36[result];
			borrowed = 0;
		}
		else
		{
			digit1 = digit1 - 1;
			result = digit1;
			cursor->data = base36[result];
			borrowed = 0;
		}
		cursor = cursor->prev;
		}
		trim();
	return *this;
}

big_number& big_number::mult(const big_number& b) // shift multiplication
{
	big_number shift;
	big_number n1(*this);
	big_number n2(b);
	node* s_cursor = shift.tail_ptr;
	node* t_cursor = n1.tail_ptr;
	node* b_cursor = n2.tail_ptr;
	unsigned int digit1, digit2, result = 0, carry = 0;
	
	while(b_cursor != nullptr) // shift to next multiplication digit
	{
		while (t_cursor != nullptr) // multiply the whole num by one digit
		{
			digit1 = base10.find(t_cursor->data); // 
			digit2 = base10.find(b_cursor->data);
			result = digit1 * digit2; // 
			if(carry > 0)
			{
				result += carry;
				carry = 0;
			}
			while(result > 9) // change to base for +base10
			{
				result -= 10;
				carry++;
			}
			s_cursor->data += result; // drop result into memory
			
			node* added_node = new node; // new node to the head
			added_node->next = s_cursor;
			added_node->prev = nullptr;
			s_cursor->prev = added_node;
			s_cursor = s_cursor->prev;
			shift.head_ptr = s_cursor;
			
			t_cursor = t_cursor->prev; // move t_cursor
		}
		cout << "moving b cursor" << endl;
		b_cursor = b_cursor->prev;
		t_cursor = tail_ptr;
	}
	if(carry > 0)
	{
		cout << carry << " carry" <<endl;
		s_cursor->data += carry; // issues printing char numbers vs numbers
		carry = 0;
	}
	*this = shift;
	return *this;
}

void big_number::trim()
{
	while (head_ptr != tail_ptr && head_ptr->data == '0')
	{
		--digits;
		head_ptr = head_ptr->next;
		delete head_ptr->prev;
		head_ptr->prev = nullptr;
	}
}
