#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

#pragma region vectorInt

class vectorInt
{
	int *v_;
	int length_;
	int element_count_;
public:
	vectorInt(const int columns);
	bool is_empty() { return length_ == 0; }
	void add(int x);
	int sum();
	int get_max();
	int get_item(int index);
	int get_max_id();
	int get_length() { return length_; }
	
	void sort();
	vectorInt operator*(vectorInt l);
	vectorInt operator+(vectorInt l);
};

vectorInt::vectorInt(const int columns = 0)
{
	v_ = new int[columns];
	length_ = columns;
	element_count_ = 0;
}

void vectorInt::add(const int x)
{
	v_[element_count_++] = x;
}

istream& operator>>(istream& input, vectorInt& l)
{
	int length;
	if (l.is_empty())
	{
		input >> length;
		l = *(new vectorInt(length));
	}
	length = l.get_length();
	int val;
	for (auto i = 0; i < length; i++)
	{
		input >> val;
		l.add(val);
	}
	return input;
}

ostream& operator<<(ostream& output, vectorInt l)
{
	const auto length = l.get_length();
	for (auto i = 0; i < length; i++)
	{
		output << l.get_item(i) << " ";
	}
	output << endl;
	return output;
}

vectorInt vectorInt::operator*(vectorInt l)
{
	auto lista_n = new vectorInt(l.get_length());
	const auto length = get_length();
	for (auto i = 0; i < length; i++)
		lista_n->add(v_[i] * l.v_[i]);
	return *lista_n;
}

vectorInt vectorInt::operator+(vectorInt l)
{
	auto lista_n = new vectorInt(l.get_length());
	const auto length = get_length();
	for (auto i = 0; i < length; i++)
		lista_n->add(v_[i] + l.v_[i]);
	return *lista_n;
}

int vectorInt::sum()
{
	auto s = 0;
	for (auto i = 0; i < length_; i++)
		s += v_[i];
	return s;
}

int vectorInt::get_max()
{
	if (this->is_empty())
		throw new exception("List is empty");
	auto max = v_[0];

	for (auto i = 1; i < length_; i++)
		if (v_[i] > max)
			max = v_[i];
	return max;
}

int vectorInt::get_max_id()
{
	const auto max = get_max();
	auto i = 0;
	while (i < length_)
	{
		if (v_[i] == max)
			return i;
		i++;
	}
	return i;
}

int vectorInt::get_item(const int index)
{
	if( index > element_count_ || index < 0 )
		throw new exception("Index not valid!");
	return v_[index];
}

void vectorInt::sort()
{
	for (auto i = 0; i < length_ - 1; i++)
		for (auto j = 0; j < length_ - i - 1; j++)
			if (v_[j] > v_[j + 1])
				swap(v_[j], v_[j + 1]);
}

#pragma endregion

#pragma region matrix

class matrix
{
	vectorInt* lines_;
	int columns_nr_;
	int lines_nr_;

public:
	matrix(const int lines, const int columns);
	bool is_empty() { return lines_nr_ == 0 || columns_nr_ == 0; }
	int get_lines_count() { return lines_nr_; }
	int get_columns_count() { return columns_nr_; }
	vectorInt get_line(const int index);

	friend istream& operator>>(istream& input, matrix& mtrx);
	matrix operator+(matrix mtrx);
};

matrix::matrix(const int lines = 0, const int columns = 0)
{
	lines_ = new vectorInt[lines];
	for (auto i = 0; i < lines; i++)
		lines_[i] = *(new vectorInt(columns));
	columns_nr_ = columns;
	lines_nr_ = lines;
}

vectorInt matrix::get_line(const int index)
{
	if (index < 0 || index> lines_nr_)
		throw new exception("Index not valid!");
	return lines_[index];
}

istream& operator>>(istream& input, matrix& mtrx)
{
	int lines, columns;
	if (mtrx.is_empty())
	{
		input >> lines >> columns;
		mtrx = *(new matrix(lines, columns));
	}
	lines = mtrx.get_lines_count();
	for (auto i = 0; i < lines; i++)
	{
		input >> mtrx.lines_[i];
	}
	return input;
}

ostream& operator<<(ostream& output, matrix& mtrx)
{
	const auto lines = mtrx.get_lines_count();
	for (auto i = 0; i < lines; i++)
	{
		output << mtrx.get_line(i);
	}
	output << endl;
	return output;
}

matrix matrix::operator+(matrix mtrx)
{
	auto matrix_n = new matrix(lines_nr_, columns_nr_);
	for (auto i = 0; i < lines_nr_; i++)
		matrix_n->lines_[i] = lines_[i] + mtrx.lines_[i];
	return *matrix_n;
}

#pragma endregion

bool customValidation(matrix mtrx, vectorInt x, vectorInt y)
{
	auto lines_count = mtrx.get_lines_count();
	for(auto i = 0; i < lines_count; i++)
		if((mtrx.get_line(i) * x).sum() != y.get_item(i))
			return false;
	return true;
}

int main()
{
	ifstream f1("date1.in");
	matrix m1;
	f1 >> m1;
	vectorInt x = { m1.get_columns_count() }, y = { m1.get_lines_count() };
	f1 >> x >> y;
	if (customValidation(m1, x, y))
		cout << "DA!";
	else
		cout << "NU!";
	f1.close();
	return 0;
}
