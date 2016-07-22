#include <iostream>
using namespace std;

class Polynomial
{
private:
	int Nterms;
	double* pCoeffs;// from lowest to highest order
public:
	// functions
	double evaluateAt(double x);
	void print(void);

    // constructor
	Polynomial( double Coeffs[], int N_terms );// full construction from given array of coefficients
	// destructor
	~Polynomial();// destructor VERY important this case
};

// full constructor. Must be passed an array of coeffs. and the array size.
Polynomial::Polynomial( double Coeffs[], int N_terms )
{
	Nterms = N_terms;
	pCoeffs = new double[ Nterms ];// allocate an array to hold the coefficient values
	for(int i=0; i<Nterms; i++)
		pCoeffs[i] = Coeffs[i];// assign in straight order
}

// destructor - releases memory for the dynamically allocated coefficient array
Polynomial::~Polynomial()
{
	if( pCoeffs )
	{
		delete [] pCoeffs;
		pCoeffs = NULL;
	}
}
// finds P(x)
double Polynomial::evaluateAt(double x)
{
	double sum = 0.0;
	double xPow = 1.0;
	if( pCoeffs )
		for(int i=0; i<Nterms; i++)
		{
			sum += xPow*pCoeffs[i];// add up the terms
			xPow *= x;// build up the power of x from term to term
		}

	return sum;
}
// simple version produces crude output. Finetune to suit.
void Polynomial::print(void)
{
	// 1st term
	std::cout << pCoeffs[Nterms-1] << "x^" << Nterms-1;
	// remaining terms
	for(int i=Nterms-2; i>=0; i--)
		std::cout << " + " << pCoeffs[i] << "x^" << i;
	return;
}

int main(void)// example use
{
	// Pnum = 8*x^4 + 10*x^3 + x^2 + 29*x + 19
	double Cnum[5] = { 19.0, 29.0, 1.0, 10.0, 8.0 };
	Polynomial Pnum( Cnum, 5 );
	cout << "Pnum = ";
	Pnum.print();
	cout << "\n Pnum(2.0) = " << Pnum.evaluateAt(2.0) << endl;
	return 0;
}
