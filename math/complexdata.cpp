#include "complexdata.h"
#include "calculadora.h"


ComplexData::ComplexData()
{
    real=0;
    imag=0;
    StrFuncao="";
    FlagNumero=true;
    FlagDerivada=false;
    NivelParentesis=0;
}

ComplexData::~ComplexData()
{

}


ComplexData &ComplexData::operator=(const ComplexData &dat )
{

    StrFuncao = dat.StrFuncao;
    real = dat.real;
    imag = dat.imag;
    FlagNumero = dat.FlagNumero;
    FlagDerivada = dat.FlagDerivada;
    NivelParentesis = dat.NivelParentesis;
    array_xi = dat.array_xi;

    return *this;  // Assignment operator returns left side.
}

ComplexData operator+(ComplexData a, ComplexData b )
{
    ComplexData z;
    z.array_xi.clear();


    if (a.array_xi.size()==0 && b.array_xi.size()>0)
    {
        Complexo aux=Complexo(a.real,a.imag);
        for(int i=0;i<b.array_xi.size();i++)
        {
            z.array_xi.append(aux+b.array_xi.at(i));
        }
    }
    else if (a.array_xi.size()>0 && b.array_xi.size()==0)
    {
        Complexo aux=Complexo(b.real,b.imag);
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)+aux);
        }
    }
    else if (a.array_xi.size()>0 && a.array_xi.size()==b.array_xi.size())
    {
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)+b.array_xi.at(i));
        }
    }


    z.real=a.real+b.real;
    z.imag=a.imag+b.imag;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao=a.StrFuncao;
    return z;
}


ComplexData operator+(ComplexData a)
{
    return a;
}


ComplexData operator-(ComplexData a)
{
    ComplexData z;
    z.array_xi.clear();

    for (int i=0;i<a.array_xi.size();i++)
    {
        z.array_xi.append(0-a.array_xi.at(i));
    }

    z.real=0-a.real;
    z.imag=0-a.imag;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao="-"+a.StrFuncao;
    return z;
}

ComplexData operator-(ComplexData a, ComplexData b )
{
    ComplexData z;
    z.array_xi.clear();

    if (a.array_xi.size()==0 && b.array_xi.size()>0)
    {
        Complexo aux=Complexo(a.real,a.imag);
        for(int i=0;i<b.array_xi.size();i++)
        {
            z.array_xi.append(aux-b.array_xi.at(i));
        }
    }
    else if (a.array_xi.size()>0 && b.array_xi.size()==0)
    {
        Complexo aux=Complexo(b.real,b.imag);
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)-aux);
        }
    }
    else if (a.array_xi.size()>0 && a.array_xi.size()==b.array_xi.size())
    {
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)-b.array_xi.at(i));
        }
    }
    z.real=a.real-b.real;
    z.imag=a.imag-b.imag;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao=a.StrFuncao;
    return z;
}



ComplexData operator*(ComplexData a, ComplexData b )
{
    ComplexData z;
    z.array_xi.clear();

    if (a.array_xi.size()==0 && b.array_xi.size()>0)
    {
        Complexo aux=Complexo(a.real,a.imag);
        for(int i=0;i<b.array_xi.size();i++)
        {
            z.array_xi.append(aux*b.array_xi.at(i));
        }
    }
    else if (a.array_xi.size()>0 && b.array_xi.size()==0)
    {
        Complexo aux=Complexo(b.real,b.imag);
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)*aux);
        }
    }
    else if (a.array_xi.size()>0 && a.array_xi.size()==b.array_xi.size())
    {
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)*b.array_xi.at(i));
        }
    }

    Complexo auxz;
    Complexo aux1=Complexo(a.real,a.imag);
    Complexo aux2=Complexo(b.real,b.imag);
    auxz=aux1*aux2;
    z.real=auxz.r;
    z.imag=auxz.i;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao=a.StrFuncao;
    return z;
}


ComplexData operator/(ComplexData a, ComplexData b )
{
    ComplexData z;
    z.array_xi.clear();

    if (a.array_xi.size()==0 && b.array_xi.size()>0)
    {
        Complexo aux=Complexo(a.real,a.imag);
        for(int i=0;i<b.array_xi.size();i++)
        {
            z.array_xi.append(aux/b.array_xi.at(i));
        }
    }
    else if (a.array_xi.size()>0 && b.array_xi.size()==0)
    {
        Complexo aux=Complexo(b.real,b.imag);
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)/aux);
        }
    }
    else if (a.array_xi.size()>0 && a.array_xi.size()==b.array_xi.size())
    {
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)/b.array_xi.at(i));
        }
    }

    Complexo auxz;
    Complexo aux1=Complexo(a.real,a.imag);
    Complexo aux2=Complexo(b.real,b.imag);
    auxz=aux1/aux2;
    z.real=auxz.r;
    z.imag=auxz.i;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao=a.StrFuncao;
    return z;
}

ComplexData operator^(ComplexData a, ComplexData b )
{
    ComplexData z;
    z.array_xi.clear();

    if (a.array_xi.size()==0 && b.array_xi.size()>0)
    {
        Complexo aux=Complexo(a.real,a.imag);
        for(int i=0;i<b.array_xi.size();i++)
        {
            z.array_xi.append(aux^b.array_xi.at(i));
        }
    }
    else if (a.array_xi.size()>0 && b.array_xi.size()==0)
    {
        Complexo aux=Complexo(b.real,b.imag);
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)^aux);
        }
    }
    else if (a.array_xi.size()>0 && a.array_xi.size()==b.array_xi.size())
    {
        for(int i=0;i<a.array_xi.size();i++)
        {
            z.array_xi.append(a.array_xi.at(i)^b.array_xi.at(i));
        }
    }

    Complexo auxz;
    Complexo aux1=Complexo(a.real,a.imag);
    Complexo aux2=Complexo(b.real,b.imag);
    auxz=aux1^aux2;
    z.real=auxz.r;
    z.imag=auxz.i;
    z.FlagNumero=a.FlagNumero;
    z.FlagDerivada=a.FlagDerivada;
    z.NivelParentesis=a.NivelParentesis;
    z.StrFuncao=a.StrFuncao;
    return z;
}


ComplexData::ComplexData(const ComplexData &dat)
{
    StrFuncao = dat.StrFuncao;
    real = dat.real;
    imag = dat.imag;
    FlagNumero = dat.FlagNumero;
    FlagDerivada = dat.FlagDerivada;
    NivelParentesis = dat.NivelParentesis;
    array_xi = dat.array_xi;

       // return *this;  // Assignment operator returns left side.
}

void ComplexData::SetNumeroVar(double Numero)
{
    real=Numero;
    imag=0;
    FlagNumero=true;
    FlagDerivada=true;
    StrFuncao.sprintf("%lf",Numero);
}


void ComplexData::SetNumero(double Numero)
{
    real=Numero;
    imag=0;
    FlagNumero=true;
    FlagDerivada=false;
    StrFuncao.sprintf("%lf",Numero);
}

void ComplexData::SetNumero(const Complexo &Numero)
//void ComplexData::SetNumero(double r, double i)
{
        //real=Numero.r;
        //imag=Numero.i;
    real=Numero.r;
    imag=Numero.i;
    FlagNumero=true;
    FlagDerivada=false;
    StrFuncao=ComplexoToQString(Numero);

}

void ComplexData::SetNumberArrai(QList<Complexo> &xi)
{
    FlagNumero=true;
    FlagDerivada=false;

    array_xi = xi;
}

void ComplexData::SetNumberArrai(QList<double> &xi)
{
    FlagNumero=true;
    FlagDerivada=false;

    array_xi.clear();
    Complexo z;
    z.i=0;

    for(int i=0;i<xi.size();i++)
    {
        z.r=xi.at(i);
        array_xi.append(z);
    }

}


void ComplexData::SetFuncao(QString funcao)
{    
    real=0;
    imag=0;
    array_xi.clear();
    FlagNumero=false;
    FlagDerivada=false;
    StrFuncao=funcao;
}


bool ComplexData::ValidaNumero()
{      
    if (FlagNumero)
        return 1;
    else
        return 0;
}


bool ComplexData::ValidaFuncao()
{

    if (!StrFuncao.compare("sinc",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("sin",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("cos",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("tan",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("cot",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("csc",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("sec",Qt::CaseInsensitive))
        return 1;



    if (!StrFuncao.compare("sinh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("cosh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("tanh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("coth",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("csch",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("sech",Qt::CaseInsensitive))
        return 1;



    if (!StrFuncao.compare("asin",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acos",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("atan",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acot",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acsc",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("asec",Qt::CaseInsensitive))
        return 1;



    if (!StrFuncao.compare("asinh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acosh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("atanh",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acoth",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("acsch",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("asech",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("conj",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("real",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("imag",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("abs",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("cbrt",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("sqrt",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("log",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("ln",Qt::CaseInsensitive))
        return 1;

    if (!StrFuncao.compare("exp",Qt::CaseInsensitive))
        return 1;

    return 0;
}




bool ComplexData::ValidaOperadores()
{

    if (StrFuncao == "+")
        return 1;

    if (StrFuncao == "-")
        return 1;

    if (StrFuncao == "*")
        return 1;

    if (StrFuncao == "/")
        return 1;

    if (StrFuncao == "^")
        return 1;

    if (StrFuncao == "E")
        return 1;

    return 0;
}


bool ComplexData::ValidaParentesis()
{
    if (StrFuncao == "(")
        return 1;

    if (StrFuncao == ")")
        return 1;

    if (StrFuncao == "|")
        return 1;

    return 0;
}


int ComplexData::ValidaOperadorPrioridade()
{      
    if (StrFuncao == "+" || StrFuncao == "-" )
        return 0;

    if (StrFuncao == "*" || StrFuncao == "/" )
        return 1;

    if (StrFuncao == "^" || StrFuncao == "E" )
        return 2;

    return -1;
}




bool ComplexData::ValidaFuncaoOperador()
{
    if (ValidaFuncao())
        return 1;

    if (ValidaOperadores())
        return 1;

    if (ValidaParentesis())
        return 1;

    return 0;
}


bool ComplexData::ValidaConstantes()
{       
    //if (FlagNumero && !StrFuncao.compare("pi",Qt::CaseInsensitive))
    if ( !StrFuncao.compare("pi",Qt::CaseInsensitive))
        return 1;

    //if (FlagNumero && !StrFuncao.compare("e",Qt::CaseInsensitive))
    if ( !StrFuncao.compare("e",Qt::CaseSensitive))
        return 1;

    //if (FlagNumero && !StrFuncao.compare("i",Qt::CaseInsensitive))
    if ( !StrFuncao.compare("i",Qt::CaseInsensitive))
        return 1;


    return 0;
}


bool ComplexData::ValidaImaginario()
{     
    if (FlagNumero && imag != 0)
        return 1;

    return 0;
}

/*
ComplexData cabs(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z.r=cabs(Complexo(x.real,x.imag));
    z.i=0;
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=cabs(x.array_xi);
    return y;
}
*/

ComplexData abs(ComplexData &x)
{
    x.array_xi=abs(x.array_xi);
    x.real=cabs(Complexo(x.real,x.imag));
    x.imag=0;
    return x;
}

ComplexData conj(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=conj(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=conj(x.array_xi);
    return y;
}


ComplexData real(ComplexData &x)
{
    x.array_xi=real(x.array_xi);
    x.imag=0;
    return x;
}


ComplexData imag(ComplexData &x)
{
    x.array_xi=imag(x.array_xi);
    x.real=x.imag;
    x.imag=0;
    return x;
}

ComplexData cbrt(ComplexData &x)
{
    Complexo z;
    z=cbrt(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=cbrt(x.array_xi);
    return x;
}

ComplexData sqrt(ComplexData &x)
{
    Complexo z;
    z=sqrt(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=sqrt(x.array_xi);
    return x;
}

ComplexData exp(ComplexData &x)
{
    Complexo z;
    z=exp(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=exp(x.array_xi);
    return x;
}

ComplexData sinc(ComplexData &x)
{
    Complexo z=sinc(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=sinc(x.array_xi);
    return x;
}


ComplexData cos(ComplexData &x)
{
    Complexo z=cos(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=cos(x.array_xi);
    return x;
}

ComplexData sin(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=sin(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=sin(x.array_xi);
    return y;
}

ComplexData tan(ComplexData &x)
{
    Complexo z=tan(Complexo(x.real,x.imag));
    x.real=z.r;
    x.imag=z.i;
    x.array_xi=tan(x.array_xi);
    return x;
}

ComplexData cot(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=cot(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=cot(x.array_xi);
    return y;
}

ComplexData csc(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=csc(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=csc(x.array_xi);
    return y;
}

ComplexData sec(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=sec(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=sec(x.array_xi);
    return y;
}





ComplexData cosh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=cosh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=cosh(x.array_xi);
    return y;
}

ComplexData sinh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=sinh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=sinh(x.array_xi);
    return y;
}

ComplexData tanh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=tanh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=tanh(x.array_xi);
    return y;
}

ComplexData coth(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=coth(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=coth(x.array_xi);
    return y;
}

ComplexData csch(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=csch(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=csch(x.array_xi);
    return y;
}

ComplexData sech(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=sech(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=sech(x.array_xi);
    return y;
}

////////////////////////////////////


ComplexData acos(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acos(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acos(x.array_xi);
    return y;
}

ComplexData asin(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=asin(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=asin(x.array_xi);
    return y;
}

ComplexData atan(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=atan(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=atan(x.array_xi);
    return y;
}

ComplexData acot(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acot(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acot(x.array_xi);
    return y;
}

ComplexData acsc(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acsc(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acsc(x.array_xi);
    return y;
}

ComplexData asec(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=asec(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=asec(x.array_xi);
    return y;
}



///////////////////////////////////////



ComplexData acosh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acosh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acosh(x.array_xi);
    return y;
}

ComplexData asinh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=asinh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=asinh(x.array_xi);
    return y;
}

ComplexData atanh(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=atanh(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=atanh(x.array_xi);
    return y;
}

ComplexData acoth(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acoth(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acoth(x.array_xi);
    return y;
}

ComplexData acsch(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=acsch(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=acsch(x.array_xi);
    return y;
}

ComplexData asech(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=asech(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=asech(x.array_xi);
    return y;
}

//////////////////////////////////////////////77

ComplexData ln(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=ln(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=ln(x.array_xi);
    return y;
}
ComplexData log(ComplexData &x)
{
    ComplexData y=x;
    Complexo z;
    z=log(Complexo(x.real,x.imag));
    y.real=z.r;
    y.imag=z.i;
    y.array_xi=log(x.array_xi);
    return y;
}
