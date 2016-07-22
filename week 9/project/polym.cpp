#include <iostream>
using namespace std;
class Polynomial
{
private:
            int Nterms;
            double* pCoeffs;
public:
            double evaluateAt(double x);
            void print(void);
            Polynomial( double Coeffs[], int N_terms );
            ~Polynomial();
};
Polynomial::Polynomial( double Coeffs[], int N_terms )
{
            Nterms = N_terms;
            pCoeffs = new double[ Nterms ];
            for(int i=0; i<Nterms; i++)
                        pCoeffs[i] = Coeffs[i];

}
Polynomial::~Polynomial()
{
            if( pCoeffs )
            {
                        delete [] pCoeffs;
                        pCoeffs = NULL;
           }
}
double Polynomial::evaluateAt(double x)
{
            double sum = 0.0;
            double xPow = 1.0;
            if( pCoeffs )
                        for(int i=0; i<Nterms; i++)
                        {
                                    sum += xPow*pCoeffs[i];
                                    xPow *= x;
                        }
            return sum;
}
void Polynomial::print(void)
{
            std::cout << pCoeffs[Nterms-1] << "x^" << Nterms-1;
            for(int i=Nterms-2; i>=0; i--)
                        std::cout << " + " << pCoeffs[i] << "x^" << i;
            return;
}

int main(void)
{
           double Cnum[5] = { 19.0, 29.0, 1.0, 10.0, 8.0 };
            Polynomial Pnum( Cnum, 5 );
            cout << "Pnum = ";
            Pnum.print();
            cout << "\n Pnum(2.0) = " << Pnum.evaluateAt(2.0) << endl;
            return 0;
}
