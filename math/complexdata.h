#ifndef COMPLEXDATA_H
#define COMPLEXDATA_H


#include <QString>
#include <QList>
#include "complexo.h"
#include "array_math.h"


class ComplexData
{

public:

    ComplexData();
    ComplexData(const ComplexData &);
    virtual ~ComplexData();

    ComplexData &operator=(const ComplexData &dat );  // Right side is the argument.
    friend ComplexData operator+(ComplexData a, ComplexData b );
    friend ComplexData operator+(ComplexData a);
    friend ComplexData operator-(ComplexData a, ComplexData b );
    friend ComplexData operator-(ComplexData a);
    friend ComplexData operator*(ComplexData a, ComplexData b );
    friend ComplexData operator/(ComplexData a, ComplexData b );
    friend ComplexData operator^(ComplexData a, ComplexData b );


    //friend Complexo operator+( Complexo a, Complexo b );

    QString StrFuncao;
    double real;
    double imag;
    bool FlagNumero;
    bool FlagDerivada;
    int NivelParentesis;
    QList<Complexo> array_xi;
    array_math m_array_xi;

    void SetNumero(double);
    void SetNumero(const Complexo &);
    void SetNumeroVar(double);
    void SetNumberArrai(QList<double> &xi);
    void SetNumberArrai(QList<Complexo> &xi);
    void SetFuncao(QString);
    bool ValidaFuncao();
    bool ValidaNumero();
    bool ValidaOperadores();
    bool ValidaFuncaoOperador();
    bool ValidaParentesis();
    bool ValidaConstantes();
    bool ValidaImaginario();
    int ValidaOperadorPrioridade();


};


/*
double cabs(Complexo);
double arg(Complexo );
Complexo conj(Complexo);
double real(Complexo);
double imag(Complexo);
double abs(Complexo);
Complexo sqrt(Complexo);

Complexo exp(Complexo);

Complexo sinc(Complexo);

*/
ComplexData abs(ComplexData &x);
//ComplexData arg(ComplexData &x);
ComplexData conj(ComplexData &x);
ComplexData real(ComplexData &x);
ComplexData imag(ComplexData &x);
ComplexData cbrt(ComplexData &x);
ComplexData sqrt(ComplexData &x);
ComplexData exp(ComplexData &x);
ComplexData sinc(ComplexData &x);

ComplexData cos(ComplexData &x);
ComplexData sin(ComplexData &x);
ComplexData tan(ComplexData &x);
ComplexData cot(ComplexData &x);
ComplexData csc(ComplexData &x);
ComplexData sec(ComplexData &x);

ComplexData cosh(ComplexData &x);
ComplexData sinh(ComplexData &x);
ComplexData tanh(ComplexData &x);
ComplexData coth(ComplexData &x);
ComplexData csch(ComplexData &x);
ComplexData sech(ComplexData &x);


ComplexData acos(ComplexData &x);
ComplexData asin(ComplexData &x);
ComplexData atan(ComplexData &x);
ComplexData acot(ComplexData &x);
ComplexData acsc(ComplexData &x);
ComplexData asec(ComplexData &x);


ComplexData acosh(ComplexData &x);
ComplexData asinh(ComplexData &x);
ComplexData atanh(ComplexData &x);
ComplexData acoth(ComplexData &x);
ComplexData acsch(ComplexData &x);
ComplexData asech(ComplexData &x);


ComplexData ln(ComplexData &x);
ComplexData log(ComplexData &x);







#endif // COMPLEXDATA_H
