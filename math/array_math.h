#ifndef ARRAY_MATH_H
#define ARRAY_MATH_H

#include <QList>
#include "complexo.h"


class array_math
{
public:
    array_math();

    QList<Complexo> array_xi;
    int setArray(const double &min, const double &max, const double &step);
    int setArray(const double &min, const double &max);

    array_math &operator=( const array_math & );  // Right side is the argument.

};


array_math cabs(const array_math &x);
array_math arg(const array_math &x);
array_math conj(const array_math &x);
array_math real(const array_math &x);
array_math imag(const array_math &x);
array_math abs(const array_math &x);
array_math sqrt(const array_math &x);
array_math cbrt(const array_math &x);
array_math exp(const array_math &x);
array_math sinc(const array_math &x);
array_math cos(const array_math &x);
array_math sin(const array_math &x);
array_math tan(const array_math &x);
array_math cot(const array_math &x);
array_math csc(const array_math &x);
array_math sec(const array_math &x);
array_math cosh(const array_math &x);
array_math sinh(const array_math &x);
array_math tanh(const array_math &x);
array_math coth(const array_math &x);
array_math csch(const array_math &x);
array_math sech(const array_math &x);
array_math acos(const array_math &x);
array_math asin(const array_math &x);
array_math atan(const array_math &x);
array_math atan(const array_math &Zy, const array_math &Zx);
array_math acot(const array_math &x);
array_math asec(const array_math &x);
array_math acsc(const array_math &x);
array_math asinh(const array_math &x);
array_math acosh(const array_math &x);
array_math atanh(const array_math &x);
array_math acoth(const array_math &x);
array_math acsch(const array_math &x);
array_math asech(const array_math &x);
array_math ln(const array_math &x);
array_math log(const array_math &x);

#endif // ARRAY_MATH_H
