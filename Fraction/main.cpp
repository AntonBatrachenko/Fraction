#include<iostream>
using namespace std;

const char tab = '\t';

class Fraction
{
	int Integer;
	int Numerator;
	int Denominator;
public:
	int getInteger() const
	{
		return this->Integer;
	}
	int getNumerator() const
	{
		return this->Numerator;
	}
	int getDenominator() const
	{
		return this->Denominator;
	}
	void setInteger(int Integer)
	{
		this->Integer = Integer;
	}
	void setNumerator(int Numerator)
	{
		this->Numerator = Numerator;
	}
	void setDenominator(int Denominator)
	{
		if (Denominator == 0)
		{
			this->Denominator = 1;
		}
		else
		{
			this->Denominator = Denominator;
		}
	}
	Fraction()
	{
		this->Integer = 0;
		this->Numerator = 0;
		this->Denominator = 1;
		cout << "DefaultConstructor:" << tab << this << endl;
	}
	Fraction(int Integer)
	{
		this->Integer = 0;
		this->Numerator = 0;
		this->Denominator = 1;
		cout << "SingleArgumentConstructor:" << tab << this << endl;
	}
	Fraction(int Numerator, int Denominator)
	{
		this->Integer = 0;
		this->Numerator = Numerator;
		this->Denominator = Denominator;
		cout << "Constructor:" << tab << this << endl;
	}
	Fraction(int Integer, int Numerator, int Denominator)
	{
		this->Integer = Integer;
		this->Numerator = Numerator;
		this->Denominator = Denominator;
		cout << "Constructor:" << tab << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->Integer = other.Integer;
		this->Numerator = other.Numerator;
		this->Denominator = other.Denominator;
		cout << "CopyConstructor:" << tab << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:" << tab << this << endl;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->Integer = other.Integer;
		this->Numerator = other.Numerator;
		this->Denominator = other.Denominator;
		cout << "CopyAssignment:" << tab << this << endl;
		return *this;
	}

	operator int()
	{
		return this->Integer;
	}

	operator double()
	{
		return Integer + ((double)Numerator / (double)Denominator);
	}
	void ToProper()
	{
		Integer += Numerator / Denominator;
		Numerator %= Denominator;
	}
	void ToImproper()
	{
		Numerator += Integer * Denominator;
		Integer = 0;
	}
	void Reduce()
	{
		int more;
		int less;
		int reminder;
		if (Numerator < Denominator)
		{
			less = Numerator;
			more = Denominator;
		}
		else
		{
			less = Denominator;
			more = Numerator;
		}
		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int gcd = more;
		Numerator /= gcd;
		Denominator /= gcd;
	}
	void Print() const
	{
		if (Integer != 0)
		{
			cout << Integer;
		}
		if (Numerator != 0)
		{
			if (Integer)
			{
				cout << "(";
			}
			cout << Numerator << "/" << Denominator;
			if (Integer)
			{
				cout << ")";
			}
		}
		if(Integer == 0 && Numerator == 0)
		{
			cout << 0;
		}
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	Fraction res;
	left.Reduce();
	right.Reduce();
	left.ToImproper();
	right.ToImproper();
	res.setNumerator(left.getNumerator() * right.getNumerator());
	res.setDenominator(left.getDenominator() * right.getDenominator());
	return res;
}

Fraction operator/(Fraction left, Fraction right)
{
	left.Reduce();
	right.Reduce();
	left.ToImproper();
	right.ToImproper();
	Fraction res
	(
		left.getNumerator() * right.getDenominator(),
		left.getDenominator() * right.getNumerator()
	);
	return res;
}

ostream& operator<< (ostream& os, const Fraction& obj)
{
	if (obj.getInteger()!= 0)
	{
		cout << obj.getInteger();
	}
	if (obj.getNumerator() != 0)
	{
		if (obj.getInteger())
		{
			cout << "(";
		}
		cout << obj.getNumerator() << "/" << obj.getDenominator();
		if (obj.getInteger())
		{
			cout << ")";
		}
	}
	if (obj.getInteger() == 0 && obj.getNumerator() == 0)
	{
		cout << 0;
	}
	return os;
}

void main()
{
	setlocale(LC_ALL, "Russian");
}