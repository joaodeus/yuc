#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <math.h>
#include <QList>

class Complexo
{

public:
    Complexo();
    Complexo(double,double);
    Complexo(const Complexo &);
    Complexo(const double);
    virtual ~Complexo();

    double r, i;

    friend Complexo operator+( Complexo a, Complexo b );
   // friend QList<Complexo> operator+(const QList<Complexo> &a, const QList<Complexo> &b);
    friend Complexo operator+( double a, Complexo b );
    friend Complexo operator+( Complexo a, double b );
    friend Complexo operator-( Complexo a, Complexo b );
    friend Complexo operator-( double a, Complexo b );
    friend Complexo operator-( Complexo a, double b );
    friend Complexo operator-( Complexo a);
    friend Complexo operator*( Complexo a, Complexo b );
    friend Complexo operator*( double a, Complexo b );
    friend Complexo operator*( Complexo a, double b );
    friend Complexo operator/( const Complexo a, const Complexo b );
    friend Complexo operator/( const Complexo a, const double b );
    friend Complexo operator/( const double a, const Complexo b );
    friend Complexo operator^( const Complexo x, const Complexo y);
    friend Complexo operator^( const double x, const Complexo y);
    friend Complexo operator^( const Complexo x, const double y);

    friend bool operator ==( Complexo x, Complexo y);
    friend bool operator !=( Complexo x, Complexo y);

    Complexo &operator=(const Complexo & );  // Right side is the argument.
    Complexo &operator=(const double & );  // Right side is the argument.

};


/*
 double j0(double x);
     float j0f(float x);
     double j1(double x);
     float j1f(float x);
     double jn(int n, double x);
     float jnf(int n, float x);
     double y0(double x);
     float y0f(float x);
     double y1(double x);
     float y1f(float x);
     double yn(int n, double x);
     float ynf(int n, float x);
*/


double cabs(Complexo x);
QList<double> cabs(QList<Complexo> &x);

//Complexo cabs(Complexo x);
//QList<Complexo> cabs(QList<Complexo> &x);


double arg(Complexo );
QList<double> arg(QList<Complexo> &x);


Complexo conj(Complexo x);
QList<Complexo> conj(QList<Complexo> &x);

double real(Complexo);
QList<Complexo> real(QList<Complexo> &x);

double imag(Complexo);
QList<Complexo> imag(QList<Complexo> &x);

double abs(Complexo);
QList<Complexo> abs(QList<Complexo> &x);

Complexo sqrt(Complexo);
QList<Complexo> sqrt(QList<Complexo> &x);

Complexo cbrt(Complexo);
QList<Complexo> cbrt(QList<Complexo> &x);

Complexo exp(Complexo);
QList<Complexo> exp(QList<Complexo> &x);

Complexo sinc(Complexo);
QList<Complexo> sinc(QList<Complexo> &x);

Complexo cos(const Complexo &x);
QList<Complexo> cos(QList<Complexo> &x);

Complexo sin(Complexo);
QList<Complexo> sin(QList<Complexo> &x);

Complexo tan(Complexo);
QList<Complexo> tan(QList<Complexo> &x);

Complexo cot(Complexo);
QList<Complexo> cot(QList<Complexo> &x);

Complexo csc(Complexo);
QList<Complexo> csc(QList<Complexo> &x);

Complexo sec(Complexo);
QList<Complexo> sec(QList<Complexo> &x);

Complexo cosh(Complexo);
QList<Complexo> cosh(QList<Complexo> &x);

Complexo sinh(Complexo);
QList<Complexo> sinh(QList<Complexo> &x);

Complexo tanh(Complexo);
QList<Complexo> tanh(QList<Complexo> &x);

Complexo coth(Complexo);
QList<Complexo> coth(QList<Complexo> &x);

Complexo csch(Complexo);
QList<Complexo> csch(QList<Complexo> &x);

Complexo sech(Complexo);
QList<Complexo> sech(QList<Complexo> &x);



Complexo acos(Complexo);
QList<Complexo> acos(QList<Complexo> &x);

Complexo asin(Complexo);
QList<Complexo> asin(QList<Complexo> &x);

Complexo atan(Complexo);
QList<Complexo> atan(QList<Complexo> &x);

Complexo atan(Complexo, Complexo);
QList<Complexo> atan(QList<Complexo> &Zy,QList<Complexo> &Zx);

Complexo acot(Complexo);
QList<Complexo> acot(QList<Complexo> &x);

Complexo asec(Complexo);
QList<Complexo> asec(QList<Complexo> &x);

Complexo acsc(Complexo);
QList<Complexo> acsc(QList<Complexo> &x);


Complexo asinh(Complexo);
QList<Complexo> asinh(QList<Complexo> &x);

Complexo acosh(Complexo);
QList<Complexo> acosh(QList<Complexo> &x);

Complexo atanh(Complexo);
QList<Complexo> atanh(QList<Complexo> &x);

Complexo acoth(Complexo);
QList<Complexo> acoth(QList<Complexo> &x);

Complexo acsch(Complexo);
QList<Complexo> acsch(QList<Complexo> &x);

Complexo asech(Complexo);
QList<Complexo> asech(QList<Complexo> &x);


Complexo ln(Complexo);
QList<Complexo> ln(QList<Complexo> &x);

Complexo log(Complexo);
QList<Complexo> log(QList<Complexo> &x);




#endif // COMPLEXO_H
