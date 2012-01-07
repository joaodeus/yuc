#include "array_math.h"

array_math::array_math()
{


}


int array_math::setArray(const double &min, const double &max, const double &step)
{
    array_xi.clear();
    for(double i=min; i <= max;i=i+step)
    {
        array_xi.append(i);
    }

    return array_xi.size();
}

int array_math::setArray(const double &min, const double &max)
{
    return setArray(min,max,(1));
}


array_math &array_math::operator =(const array_math &a)
{
    array_xi=a.array_xi;
    return *this;
}

///////////////////////////////////////////////
//math operations



array_math cabs(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(cabs(x.array_xi.at(i)));
    }
    return y;
}

array_math arg(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(arg(x.array_xi.at(i)));
    }
    return y;
}

array_math conj(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(conj(x.array_xi.at(i)));
    }
    return y;
}

array_math real(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(real(x.array_xi.at(i)));
    }
    return y;
}
array_math imag(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(imag(x.array_xi.at(i)));
    }
    return y;
}

array_math abs(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(abs(x.array_xi.at(i)));
    }
    return y;
}

array_math sqrt(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sqrt(x.array_xi.at(i)));
    }
    return y;
}

array_math cbrt(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(cbrt(x.array_xi.at(i)));
    }
    return y;
}

array_math exp(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(exp(x.array_xi.at(i)));
    }
    return y;
}

array_math sinc(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sinc(x.array_xi.at(i)));
    }
    return y;
}

array_math cos(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(cos(x.array_xi.at(i)));
    }
    return y;
}

array_math sin(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sin(x.array_xi.at(i)));
    }
    return y;
}

array_math tan(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(tan(x.array_xi.at(i)));
    }
    return y;
}

array_math cot(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(cot(x.array_xi.at(i)));
    }
    return y;
}

array_math csc(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(csc(x.array_xi.at(i)));
    }
    return y;
}

array_math sec(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sec(x.array_xi.at(i)));
    }
    return y;
}

array_math cosh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(cosh(x.array_xi.at(i)));
    }
    return y;
}

array_math sinh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sinh(x.array_xi.at(i)));
    }
    return y;
}

array_math tanh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(tanh(x.array_xi.at(i)));
    }
    return y;
}

array_math coth(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(coth(x.array_xi.at(i)));
    }
    return y;
}

array_math csch(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(csch(x.array_xi.at(i)));
    }
    return y;
}

array_math sech(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(sech(x.array_xi.at(i)));
    }
    return y;
}

array_math acos(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acos(x.array_xi.at(i)));
    }
    return y;
}

array_math asin(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(asin(x.array_xi.at(i)));
    }
    return y;
}

array_math atan(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(atan(x.array_xi.at(i)));
    }
    return y;
}

array_math atan(const array_math &Zy,const array_math &Zx)
{
    array_math y;
    if (Zy.array_xi.size() != Zx.array_xi.size())
        return y;

    for(int i=0;i < Zy.array_xi.size(); i++)
    {
        y.array_xi.append(atan(Zy.array_xi.at(i),Zx.array_xi.at(i)));
    }
    return y;
}

array_math acot(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acot(x.array_xi.at(i)));
    }
    return y;
}

array_math asec(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(asec(x.array_xi.at(i)));
    }
    return y;
}

array_math acsc(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acsc(x.array_xi.at(i)));
    }
    return y;
}

array_math asinh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(asinh(x.array_xi.at(i)));
    }
    return y;
}

array_math acosh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acosh(x.array_xi.at(i)));
    }
    return y;
}

array_math atanh(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(atanh(x.array_xi.at(i)));
    }
    return y;
}

array_math acoth(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acoth(x.array_xi.at(i)));
    }
    return y;
}

array_math acsch(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(acsch(x.array_xi.at(i)));
    }
    return y;
}

array_math asech(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(asech(x.array_xi.at(i)));
    }
    return y;
}

array_math ln(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(ln(x.array_xi.at(i)));
    }
    return y;
}

array_math log(const array_math &x)
{
    array_math y;
    for(int i=0;i<x.array_xi.size();i++)
    {
        y.array_xi.append(log(x.array_xi.at(i)));
    }
    return y;
}

