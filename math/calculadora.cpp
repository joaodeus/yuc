
#include "calculadora.h"
#include <QObject>
//#include "graph2Dwidget/glgraph.h"
#include <QCoreApplication>
#include <QMessageBox>
//#include <QObject>
#include <QEventLoop>


QString groupDigits(QString str, bool bGroup)
{
    if (bGroup == false)
        return str;

    QString aux=str;
    QString auxE;
    QStringList listE; //splits the number in the exponential E
    //i.e  3.435E+7 , splits into 3.435 and E+7
    listE=aux.split("E");

    if (listE.size() == 2)
        auxE=listE[1];
    else
        auxE="";

    QStringList listPoint;//split the number in the decimal point
    //i.e.:  45.23 is split into 45 and 23
    listPoint=listE[0].split(".");

    QString aux1="";//

    int count=0;
    for(int i=listPoint[0].size()-1;i>=0;i--)
    {
        if (count ==3)
        {
            aux1.prepend(" ");
            count=0;
        }
        aux1.prepend(listPoint[0].at(i));
        count++;
    }

    QString aux2="";
    if (listPoint.size() == 2)
    {
        count=0;
        for(int i=0;i<listPoint[1].size();i++)
        {
            if (count ==3)
            {
                aux2.append(" ");
                count=0;
            }

            aux2.append(listPoint[1].at(i));
            count++;
        }
    }

    QString final;
    final=aux1;
    if (listPoint.size() == 2)
        final=final+"."+aux2;

    if (listE.size() == 2)
        final=final+"E"+auxE;


    return final;
}

QString ComplexoToQString(const Complexo &z, bool bPrecision, int precision, char format, bool bGroup)
{
    //options:
    //general - G
    //fixed decimal - f
    //scientific - E

    if (bPrecision)
        precision=-1;

    QString aux;
   // char format;
   // format='G';

    if (z.i ==0)
    {
        aux=QString("%1").arg(z.r,0,format,precision);
        aux=groupDigits(aux,bGroup);
        //aux=QString("%1").arg(z.r,0,'G',25);
    }
    else
    {
        if (z.r != 0)
        {
            QString aux1=groupDigits(QString("%1").arg(z.r,0,format,precision),bGroup);
            QString aux2;

            if (z.i >0)
            {
                aux2=groupDigits(QString("%1").arg(z.i,0,format,precision),bGroup);
                aux=aux1+" + "+aux2+"i";
            }
            else
            {
                aux2=groupDigits(QString("%1").arg(-z.i,0,format,precision),bGroup);
                aux=aux1+" - "+aux2+"i";
            }

            /*
            if (z.i > 0)
                aux=QString("%1+%2i").arg(z.r,0,format,precision).arg(z.i,0,format,precision);
            else
                aux=QString("%1-%2i").arg(z.r,0,format,precision).arg(-z.i,0,format,precision);
                */
        }
        else
        {
            aux=groupDigits(QString("%1").arg(z.i,0,format,precision),bGroup);
            aux=aux+"i";
            //aux=QString("%1i").arg(z.i,0,format,precision);
        }
    }

//  AfxMessageBox(aux);
    return aux;

}


QString ComplexoToQString( const Complexo &z)
{
    int precision=-1;//default
    char format='G'; //auto, 'E' or 'f'
    //E - format as [-]9.9E[+|-]999
    //f - format as [-]9.9
    //G - use E or f format, whichever is the most concise

    return ComplexoToQString(z, true, precision, format, true);
}


QString ComplexoToQString( const Complexo &z, const int &precision)
{
    char format='G';
    ComplexoToQString(z, false, precision, format, true);
}


Calculadora::Calculadora()
{
    Flag_Graus_Rad_Grados=1;
    ERRO=false;
    e = 2.7182818284590452354;

    // ComplexData xx;
    //Pilha.append(xx);
    flagCalculationEquation=false;
    flagAbortFunction=false;
}

Calculadora::~Calculadora()
{

}


//under development function
Complexo Calculadora::WichExpressionIsThis(QString expression)
{

    Complexo z;
    z = f(expression);
    if (!this->ERRO)//if didnt occurred any errors than this is a expression i.e. "2+3"
    {
        return z;
    }

    return z;
}

//return true if it's a valid math expression like 2+4*5.5
bool Calculadora::isExpression(QString & expression)
{
    f(expression);
    return !ERRO;
}

//return true if it's a valid equation, i.e. 2x^3-3x=4x+2
bool Calculadora::isEquation(QString &expression)
{
    QStringList Fx_Gx=expression.split("=");
    //check if it's a equation like f(x)=g(x)
    //Fx_Gx[0] will be f(x) and Fx_Gx[1] will be g(x)
    if (Fx_Gx.size() != 2)
    {
        return false;
    }

    QStringList list_var; //list of variables, must be of size one
    int n_var = this->GetVariaveis(expression,list_var);

    if (n_var != 1)
    {
        return false;
    }

    //check if f(x) and g(x) are valid expressions,
    // we pick a random value of x=1.232 to validate
    double x=1.232;
    this->fx(Fx_Gx[0],x,list_var[0]);
    if (ERRO)
        return false; //invalid f(x)

    this->fx(Fx_Gx[1],x,list_var[0]);
    if (ERRO)
        return false; //invalid g(x)

    return true;
}

//check if it's a equation and a assignment like "x=4+3"
bool Calculadora::isEquation_assignment(QString &expression)
{
    if (isEquation(expression) == false)
        return false;

    QStringList Fx_Gx=expression.split("=");
    QStringList list_var; //list of variables, must be of size one
    this->GetVariaveis(expression,list_var);

    if ( list_var[0]==Fx_Gx[0] ) //f(x) is equal to x
    {
        f(Fx_Gx[1]);
        if (ERRO) //invalid g(x)
            return false;
        else
            return true; // it's a assignment, i.e. x=3+2
    }
    else // it's a valid equation like 2x=4-x, but not a assignment like x=4+2
        return false;

}

//check if it's a convertion equation, with 2 variables, and the first member is equal to one of the variables
//i.e. "Celsius = Kelvin - 273.15"  or "Kelvin = Celsius + 273.15"
// or "kilometer = 1000 * meter" or "meter = 0.001 * kilometer"
//return's the 2 variables in list_var
bool Calculadora::isConvertion_equation(QString &expression, QStringList &list_var)
{
    expression.remove(" ");
    QStringList Fx_Gx=expression.split("=");
    //check if it's a equation like f(x)=g(x)
    //Fx_Gx[0] will be f(x) and Fx_Gx[1] will be g(x)
    if (Fx_Gx.size() != 2)
    {
        return false;
    }

    //list of variables, must be of size 2
    int n_var = this->GetVariaveis(expression,list_var);

    if (n_var != 2)
    {
        return false;
    }

    //check if the first member is equal to the first variable
    if (Fx_Gx[0] != list_var[0])
    {
        return false;
    }

    //check if the second member is a valid expression
    // we pick a random value of x=1.232 to validate
    double x=1.232456456;
    fx(Fx_Gx[1],x,list_var[1]);
    if (ERRO)
        return false; //invalid g(x)

    return true;
}



Complexo Calculadora::f(QString str)
{
    QList<double> vv;
    QList<QString> xx;

    //vv.append(v);
    //xx.append(x);

    return f_n_variaveis(str,vv,xx);
}

Complexo Calculadora::fx(QString str/*expressao*/, double v/*valor*/,
                                                QString x/*variavel*/)
{
    QList<double> vv;
    QList<QString> xx;

    vv.append(v);
    xx.append(x);

    return f_n_variaveis(str,vv,xx);
}

Complexo Calculadora::fxy(QString str/*expressao*/,
                          double v/*valor*/,QString x/*variavel*/,
                          double v1/*valor*/,QString x1/*variavel*/)
{
    QList<double> vv;
    QList<QString> xx;

    vv.append(v);
    vv.append(v1);
    xx.append(x);
    xx.append(x1);

    return f_n_variaveis(str,vv,xx);
}

/////////////////////////////////////////////////


Complexo Calculadora::fxyz(QString str/*expressao*/,
                          double v/*valor*/,QString x/*variavel*/,
                          double v1/*valor*/,QString x1/*variavel*/,
                          double v2/*valor*/,QString x2/*variavel*/ )
{


    QList<double> vv;
    QList<QString> xx;

    vv.append(v);
    vv.append(v1);
    vv.append(v2);
    xx.append(x);
    xx.append(x1);
    xx.append(x2);

    return f_n_variaveis(str,vv,xx);

}



// creates a array of double
QList<double> Calculadora::array( double min, double max, double step)
{
    QList<double> ar;

    for(double i=min; i <= max;i=i+step)
    {
        ar.append(i);
    }

    return ar;
}

QList<double> Calculadora::array( double min, double max)
{
    QList<double> ar;

    for(int i=min; i <= max;i=i++)
    {
        ar.append(i);
    }

    return ar;
}

/////////////////////////////////////////////////////////////////

//This function calculates a expression of type yi=f(xi), where xi is an array of values
// yi will hold the result
//example: y=4+x
// if x = [0,1,2,3]  then y = [4,5,6,7]
//

Complexo Calculadora::f_array_x(QString str, QString var_x, QList<double> &xi, QList<Complexo> &zi)
{
    QList<double> vv; // variable values - ghost variable doesnt do nothing
    QList<QString> xx; //variable definitios - ghost variable doesnt do nothing
    QList<double> arrai_yi;     // ghost variable, doesnt do nothing
    QString var_y="";           // ghost variable, doesnt do nothing


    return f_n_variaveis(str, vv, xx, var_x, xi, var_y, arrai_yi, zi);
}

// function with two variables, an arrai and a double, wich returns a arrai
// example: y=f(arrai x, double t)
//          y=cos(arrai_x,t); where arrai_x=[0,1,2,3,...];
//          t = 2;
//          and zi will be a array with the result

Complexo Calculadora::f_array_x_t(QString str, QString var_x, QList<double> &arrai_xi, QList<Complexo> &zi,
                              double t, QString var_t)
{
    QList<double> vv;
    QList<QString> xx;
    QList<double> arrai_yi;     // ghost variable, doesnt do nothing
    QString var_y="";           // ghost variable, doesnt do nothing


    vv.append(t);
    xx.append(var_t);
    return f_n_variaveis(str, vv, xx, var_x, arrai_xi, var_y, arrai_yi, zi);
}

// function with three variables, two arrais and a double, wich returns a arrai
// example: y=f(arrai x, arrai y, double t)
//          y=cos(arrai_x,arrai y, t);
//          arrai_x=[0,1,2,3,...];
//          arrai_y=[-10,-9,-8,...];
//          t = 2, and arrai_zi will be a array with the result

Complexo Calculadora::f_array_xy_t(QString str,
                      QString var_x, QList<double> &arrai_xi,
                      QString var_y, QList<double> &arrai_yi,
                      QList<Complexo> &arrai_zi, double t, QString var_t)
{

    QList<double> vv;
    QList<QString> xx;
    vv.append(t);
    xx.append(var_t);
    return f_n_variaveis(str, vv, xx, var_x, arrai_xi, var_y, arrai_yi, arrai_zi);
}

/////////////////////////////////////////////////////////////////

//function with n variables and n corresponding values
//example:  y=f(x1,x2,x3,...,xn);
//  x1=v1; x2=v2, .. xn=vn;  vn is the value

// example: y = x1-4*x2^2-cos(t); x1=1; x2=2; t=0
//then y=1-4*(2)-cos(0) = -8


Complexo Calculadora::f_n_variaveis(QString str,
                                    QList<double> &xi,
                                    QList<QString> &xn)
{
    QList<double> arrai_xi;     // ghost variable, doesnt do nothing
    QString var_x="";           // ghost variable, doesnt do nothing
    QList<double> arrai_yi;     // ghost variable, doesnt do nothing
    QString var_y="";           // ghost variable, doesnt do nothing

    QList<Complexo> arrai_zi;   // ghost variable, doesnt do nothing

    return f_n_variaveis(str,xi, xn, var_x, arrai_xi, var_y, arrai_yi, arrai_zi);
}


// same as the functon above, only that some variables, arrai_xi and arrai_yi, are arrais instead of doubles

Complexo Calculadora::f_n_variaveis(QString str/*expressao*/,
                                    QList<double> &xi, //arrai of values assigned to xn
                                    QList<QString> &xn, //arrai of variables
                                    QString var_arrai_xi, QList<double> &arrai_xi, //a variable that is a arrai
                                    QString var_arrai_yi, QList<double> &arrai_yi, //a variable that is a arrai
                                    QList<Complexo> &arrai_zi) //returns the result of str in arrai_zi
{

    int i;
    int ii;
    int j;
  //  str.remove(" ",Qt::CaseSensitive);
    int Len=str.length();
    Complexo err(0,0);
    QString str_aux;
    QString valor_k_aux;
    Complexo z;
    double num_aux;
    int L;
    int count_Left_Bracket=0;
    int count_Right_Bracket=0;

    ComplexData dat;
  //  ComplexData dat_aux;
    Pilha.clear();

    if (str.size() == 0)
    {
        ERRO=true;
        return err;
    }



    for(i=0;i<Len;i++)
    {
        ERRO=true;


        //verifica se é numero
        //check if it's a number
        if (str[i].isDigit() || str[i]=='.')
        {
          //  ERRO=true;
            num_aux=SacaNumero(str,i);
            L=Pilha.size();
            if (L>0)
            {
                if ( Pilha[L-1].ValidaImaginario())
                {
                    dat.SetFuncao("*");
                    Pilha.append(dat);
                    //L=Pilha.GetSize();
                    //Pilha.SetSize(L+1);
                    //Pilha[L]=dat;
                }
            }
            ERRO=false;
            dat.SetNumero(num_aux);
            Pilha.append(dat);
            goto forbottom;
        }





        //check if it's a array like [2 3 4 5] or [2,3,4,5]
        if (str[i] == '[')
        {
            ii=i;
            SacaNumberArrai(str,ii);//  SacaFuncao(str,ii);
            goto forbottom;
        }




         //verifica se é operador +,-,* ,/,E , (,)
        //check if it's a operadtor like +,-, *, /, E or (,)
        dat.SetFuncao(QString(str[i]));
        if (dat.ValidaOperadores() || dat.ValidaParentesis())
        {
            if (i>0)
            {
                //se existe um expressăo tipo (3+3)(2+4) acrescenta '*' para ficar (3+3)*(2+4)
                //if it's a expression like (3+3)(2+4), add's '*' so it wll be (3+3)*(2+4)
                if ( str.at(i) == '(' && str.at(i-1) == ')')
                {
                    dat.SetFuncao("*");
                    Pilha.append(dat);
                }

                //if we have something like 4(3+2)
                // we add '*' so it will be 4*(3+2)
                L=Pilha.size();
                if (L>0)
                {
                    if (str.at(i) == '(' && Pilha[L-1].ValidaNumero())
                    {
                        dat.SetFuncao("*");
                        Pilha.append(dat);
                    }
                }
            }

            if (i==0)
            {
                // se existe uma expressao tipo -2 acrescenta '0' para ficar 0-2
                // is it's a expression like -2 adds 0 so it will be 0-2
                if (str.at(i) == '-')
                {
                    dat.SetNumero(0);
                    Pilha.append(dat);
                }
            }

            ERRO=false;
            dat.SetFuncao(QString(str[i]));
            Pilha.append(dat);
            //L=Pilha.GetSize();
            //Pilha.SetSize(L+1);
            //Pilha[L]=dat;

            if (dat.StrFuncao == "(")
                count_Left_Bracket++;
            if (dat.StrFuncao == ")")
                count_Right_Bracket++;

            goto forbottom;
        }





        //verifica se ?e funcao (sin, cos, ...) ou se é PI(3.14...), e(2.71..) ou i(imaginario)
        //if (isalpha(str[i])) //se é uma letra
        if (str[i].isLetter())
        {
          //  ERRO=true;
            ii=i;
            str_aux=SacaFuncao(str,ii);
            dat.SetFuncao(str_aux);
            //verifica se uma funcao definida (cos, sin, tan, ...)
            if (dat.ValidaFuncao())
            {

                L=Pilha.size();
                if (L>0)
                {
                    if ( Pilha[L-1].ValidaNumero())
                    {
                        dat.SetFuncao("*");
                        L=Pilha.size();
                        Pilha.append(dat);
                    }
                }
                dat.SetFuncao(str_aux);
                ERRO=false;
                Pilha.append(dat);
                L=Pilha.size();
                i=ii;
                goto forbottom;
            }


            //verifica se uma constante definida PI(3.14) e(2.71) ou imaginário ('j' ou 'i')
            dat.StrFuncao=str_aux;
            dat.FlagNumero=true;
            if (dat.ValidaConstantes())
            {

                if ( !str_aux.compare("i",Qt::CaseInsensitive) )
                    //  ||  !str_aux.compare("j",Qt::CaseInsensitive)
                {
                    //check if before the 'i' there's a number: 2i
                    //if so, set '2i', instead of apppending '*' and '2'
                    L=Pilha.size();
                    if (L>0)
                    {
                        if ( Pilha[L-1].ValidaNumero())
                        {

                            z.i=Pilha[L-1].real;
                            z.r=0;
                            Pilha[L-1].SetNumero(z);
                            ERRO=false;
                            i=ii;
                            goto forbottom;
                        }
                    }

                    ERRO=false;
                    z.r=0;
                    z.i=1;
                    dat.SetNumero(z);
                    Pilha.append(dat);
                    i=ii;
                    goto forbottom;
                }

                //verifica se antes da constantes existia um numero, por ex. 2pi
                //entăo adiciona ´*´ para ficar 2*pi
                L=Pilha.size();
                if (L>0)
                {
                    if ( Pilha[L-1].ValidaNumero())
                    {
                        dat.SetFuncao("*");
                        L=Pilha.size();
                        Pilha.append(dat);
                    }
                }

                //L=Pilha.GetSize();
                //Pilha.SetSize(L+1);
                if (!str_aux.compare("pi", Qt::CaseInsensitive))
                {
                    ERRO=false;
                    dat.SetNumero(M_PI);
                    Pilha.append(dat);
                    i=ii;
                    goto forbottom;
                }

                if (!str_aux.compare("e"))
                {
                    ERRO=false;
                    dat.SetNumero(e);
                    Pilha.append(dat);
                    i=ii;
                    goto forbottom;
                }

                /*
                if ( !str_aux.compare("i",Qt::CaseInsensitive) )
                    //  ||  !str_aux.compare("j",Qt::CaseInsensitive)
                {
                    ERRO=false;
                    z.r=0;
                    z.i=1;
                    dat.SetNumero(z);
                    Pilha.append(dat);
                    i=ii;
                    goto forbottom;
                }*/
            }
        }



        //verifica se é variável
        if (str[i].isLetter())
        {
         //   ERRO=true;
            ii=i;
            str_aux=SacaFuncao(str,ii);
            dat.SetFuncao(str_aux);

            //verifica se é variavel x
            //verifies if it is a variable x
            for (j=0;j<xn.size();j++) //percorre a lista das variaveis
            {
                if (str_aux==xn[j]) // se é uma variavel
                {
                    L=Pilha.size();
                    if (L>0)
                    {
                        //se antes da variavel está um numero, por ex. 2
                        //adiciona ´*´ para ficar 2*
                        if ( Pilha[L-1].ValidaNumero())
                        {
                            dat.SetFuncao("*");
                            Pilha.append(dat);
                            //L=Pilha.GetSize();
                            //Pilha.SetSize(L+1);
                            //Pilha[L]=dat;
                        }
                    }
                    ERRO=false;
                    dat.SetNumeroVar(xi[j]);
                    Pilha.append(dat);
                    i=ii;
                    goto forbottom;
                    //if (i>=Len-1)
                      //  break;
                }
            }


            //verifies if it is variable arrai_xi
            if (str_aux == var_arrai_xi)  // if it is a variable
            {
                L=Pilha.size();
                if (L>0)
                {
                    //se antes da variavel está um numero, por ex. 2
                    //adiciona ´*´ para ficar 2*
                    if ( Pilha[L-1].ValidaNumero())
                    {
                        dat.SetFuncao("*");
                        Pilha.append(dat);
                        //L=Pilha.GetSize();
                        //Pilha.SetSize(L+1);
                        //Pilha[L]=dat;
                    }
                }
                ERRO = false;
                dat.SetNumberArrai(arrai_xi);
                Pilha.append(dat);
                i=ii;
                goto forbottom;
            }

            //verifies if it is variable arrai_yi
            if (str_aux == var_arrai_yi)  // if it is a variable
            {
                L=Pilha.size();
                if (L>0)
                {
                    //se antes da variavel está um numero, por ex. 2
                    //adiciona ´*´ para ficar 2*
                    if ( Pilha[L-1].ValidaNumero())
                    {
                        dat.SetFuncao("*");
                        Pilha.append(dat);
                        //L=Pilha.GetSize();
                        //Pilha.SetSize(L+1);
                        //Pilha[L]=dat;
                    }
                }
                ERRO = false;
                dat.SetNumberArrai(arrai_yi);
                Pilha.append(dat);
                i=ii;
                goto forbottom;
            }



        }


        if (str.at(i) == ' ')
            ERRO = false;

        forbottom:

        if (ERRO)
        {
            return err;
        }
    }

    if (Pilha.size()== 1)
    {
        if (Pilha[0].FlagNumero == false)
        {
            ERRO=true;
            return err;
        }
    }


    //equals the number of left/right brackets
    if(count_Left_Bracket > count_Right_Bracket)
    {
        dat.SetFuncao(")");
        while(count_Left_Bracket > count_Right_Bracket)
        {
            Pilha.append(dat);
            count_Right_Bracket++;
        };
    }


    ComplexData w;
    w=ResolvePilha();


    arrai_zi = w.array_xi;
    z.r=w.real;
    z.i=w.imag;


//    ShowPilha();
    return z;

}


QString Calculadora::f_substitui_var(QString f, QStringList xi,
                                     QStringList vi)
{
    QString str_aux;
    QString aux_str_file;
    int i,ii;
    int l;

    ERRO=true;
    if (xi.size() != vi.size())
        return f;

    for(i=0;i<f.length();i++)
    {
        ii=i;
        str_aux="";
        str_aux=SacaFuncao(f,i);

        if (str_aux != "")
        {
            for(l=0;l<xi.size();l++)
            {
                if (str_aux==xi[l])
                {
                    //f.Delete(ii,str_aux.length());
                    f.remove(ii,str_aux.length());
                    //f.insert(ii,vi[l]);
                    f.insert(ii,"("+vi[l]+")");
                    i=i+(vi[l].length()-str_aux.length())+2 ;
                    break;
                }
            }
        }
    }

    ERRO=false;
    return f;
}


QString Calculadora::f_substitui_var_caracter(QString f,
                                              QList<QString> &xi,
                                              QList<QString> &vi,
                                              QString x_caracter)
{
    f=f_substitui_var(f,xi,vi);
    f=f_substitui_var(f,x_caracter,"x");

    return f;
}


QString Calculadora::f_substitui_var(QString f, QString xi, QString vi)
{

    QString str_aux;
    int i;//ii;
    //int l;

    for(i=0;i<f.length();i++)
    {
        //ii=i;
        str_aux=SacaFuncao(f,i);

        if (str_aux==xi)
        {
            //f.Delete(i,str_aux.length());
            f.remove(i,str_aux.length());
            f.insert(i,vi);
            i=-1;
        }
    }

    return f;
}




double Calculadora::SacaNumero(QString str_numero, int &i)
{

    QString str_aux;
    bool ok;

    str_aux.clear();

    while (str_numero[i].isDigit() || str_numero[i]=='.' || str_numero[i]==' ' )
    {
        str_aux+=str_numero[i];

        if (i< str_numero.length()-1)
        {
            i++;
        }
        else
        {
            str_aux.remove(" ",Qt::CaseSensitive);
            return str_aux.toDouble(&ok);
        }

    }

    i--;

    str_aux.remove(" ",Qt::CaseSensitive);
    return str_aux.toDouble(&ok);

}

QList<Complexo> Calculadora::SacaNumberArrai(QString str_arraiNumber, int &i)
{
    Calculadora calc_aux;
 //under development function
    QString str_aux;
    bool ok;
    QStringList list_arrai;
    QList<Complexo> list_arrai_number;

    if (str_arraiNumber.at(i) != '[')
        return list_arrai_number;

    //lets grab the array
    // i.e. :  [3 , 5 , 7], we grab "3 , 5 , 7"
    i++;
    while(str_arraiNumber.at(i) != ']' && i < str_arraiNumber.size()-1)
    {
        str_aux.append(str_arraiNumber.at(i));
        i++;
    }

    //str.replace(QString("ou"), QString("o"));
    //replace "3 , 5 , 7" to "3   5   7"
    str_aux.replace(QString(","),QString(" "));
    //grab the numbers to QList, i.e.: 3-5-7
    list_arrai=str_aux.split(" ", QString::SkipEmptyParts);

/*

    for(int j=0;j<list_arrai.size();i++)
    {
        Complexo zzz= f(list_arrai.at(j));
        list_arrai_number.append(zzz);
    }

    double x;
    x=4;
*/
    return list_arrai_number;
}

QString Calculadora::SacaFuncao(QString str_funcao, int &i)
{
    //this function checks if the string starts with letters and contains letters
    // or '_' and numbers at the end.
    //it return the string, e.g 'x' or 'myvariable', or 'myvariable11' or 'myfunction'
    //the exception is a string like 'E22', because this coul be a operator, if a previous number exists
    // like 2E3, in this case it woul return a fake variable 'E3', causing a bug
    // it tries to check this situation


    QString str_aux;
    str_aux.clear();

    if (str_funcao[i]=='?')
        return "?";

    //if first caracter is not a letter returns, its not a function
    if (!str_funcao[i].isLetter())
        return str_aux;


    //check for a false bug like 2E3
    if ( (i>0) && str_funcao[i] == 'E' )
    {
        if (i < str_funcao.length()-1)
        {
            if (str_funcao[i+1] == '-' || str_funcao[i+1] == '+' || str_funcao[i+1].isDigit())
                return str_aux;
        }
    }


    while (str_funcao[i].isLetterOrNumber() || str_funcao[i]=='_'  /*&& str_funcao[i] != 'E'*/)
    {
        str_aux+=str_funcao[i];

        if (i< str_funcao.length()-1)
            i++;
        else
            return str_aux;
    }

    i--;

    return str_aux;

}


bool Calculadora::has_time_variable(QString f)
{
    QStringList list_var;
    GetVariaveis(f,list_var);

    for (int i=0;i< list_var.size();i++)
    {
        if (list_var.at(i) == "t")
        {
            return true;
        }
    }
    return false;
}


int Calculadora::GetVariaveis(QString f, QStringList &Var)
{
    ComplexData dat;
    QString str_aux;
    bool flag_Duplicate_Var;
    int i;
    int l;

    Var.clear();

    for(i=0;i<f.length();i++)
    {
        if (f[i].isLetter())
        {
            str_aux=SacaFuncao(f,i);
            dat.SetFuncao(str_aux);

            if (!dat.ValidaConstantes() && !dat.ValidaFuncao())
            {
                flag_Duplicate_Var=false;
                for(l=0;l<Var.size();l++)
                {
                    if (str_aux==Var[l])
                    {
                        flag_Duplicate_Var=true;
                        break;
                    }
                }

                if ((!flag_Duplicate_Var) && (str_aux != ""))
                        Var.append(str_aux);
            }
        }
    }

    return Var.size();
}



bool Calculadora::ValidaPilhaAnterior(int i)
{
    if (i>0)
            return 1;

    return 0;
}


bool Calculadora::ValidaPilhaSeguinte(int i)
{
    //int L=Pilha.size();

    if (i>= Pilha.size()-1)
            return 0;
    else
            return 1;

}


bool Calculadora::ValidaPilhaAnterior2(int i)
{
    if (i>1)
        return 1;
    else
        return 0;
}


bool Calculadora::ValidaPilhaSeguinte2(int i)
{

    if (i< Pilha.size()-2)
        return 1;
    else
        return 0;

}


void Calculadora::ShowPilha()
{
    int i;
    QString str;
    QMessageBox mbox;
    Complexo z;


    if (Pilha.size()==0)
    {
        mbox.setText("Pilha Vazia");
        mbox.exec();
    }

    //QMessageBox::("Pilha Vazia"); //,QString("Pilha Vazia"));
   // mbox.setText("Pilha");
    //mbox.exec();

    for(i=0;i<Pilha.size();i++)
    {
        if (Pilha[i].ValidaFuncaoOperador())
        {
            mbox.setText(Pilha[i].StrFuncao);
            mbox.exec();
        }
        else
        {
            z.r=Pilha[i].real;
            z.i=Pilha[i].imag;
            str=ComplexoToQString(z);
            mbox.setText(str);
            mbox.exec();
        }

    }



    /*
    for(i=0;i<Pilha.size();i++)
    {
        if (Pilha[i].ValidaFuncaoOperador())
        {
            mbox.setText(Pilha[i].StrFuncao);
            mbox.exec();
        }
        else
        {
            if (Pilha[i].real == 0)
            {
                if (Pilha[i].imag == 0)
                    str.arg(Pilha[i].real,0,'G',6);
                   // QTextStream(&str)<<Pilha[i].real;

                if (Pilha[i].imag > 0)
                    str.arg(Pilha[i].imag,0,'G',6);
                if (Pilha[i].imag < 0)
                    str.arg(-Pilha[i].imag,0,'G',6);


                mbox.setText(str);
                mbox.exec();

            }

            if (Pilha[i].real > 0)
            {
                if (Pilha[i].imag == 0)
                    str.arg(Pilha[i].real,0,'G',6);

                if (Pilha[i].imag > 0)
                    //str.Format("%G+i%G", Pilha[i].real ,Pilha[i].imag);


                if (Pilha[i].imag < 0)
                    str=QString("%1G-%2G").arg(Pilha[i].real).arg(-Pilha[i].imag);
                 //QString status = QString("Processing file %1 of %2: %3")
                   //  .arg(i).arg(total).arg(fileName);

                mbox.setText(str);
                mbox.exec();

            }

            if (Pilha[i].real < 0)
            {
                if (Pilha[i].imag == 0)
                    str.arg(-Pilha[i].real,0,'G',6);

                if (Pilha[i].imag > 0)
                    str=QString("-%1G+i%2G").arg(-Pilha[i].real).arg(Pilha[i].imag);
                    //str.Format("-%G+i%G", -Pilha[i].real ,Pilha[i].imag);

                if (Pilha[i].imag < 0)
                    str=QString("-%1G-i%2G").arg(-Pilha[i].real).arg(-Pilha[i].imag);
                    //str.Format("-%G-i%G", -Pilha[i].real ,-Pilha[i].imag);

                mbox.setText(str);
                mbox.exec();

            }
                      //  AfxMessageBox(str);
        }

       // mbox.setText(str);
       // mbox.exec();
    }
    */

}

/////////////////////////////////

Complexo Calculadora::resolvePilhaaux(QList<ComplexData> Pilha)
{
   // int size=Pilha.size();
    Complexo z;
    QList<ComplexData> Pilha1;
    QList<ComplexData> Plha2;


    if (Pilha.size()==1 && Pilha[0].FlagNumero)
    {
        z.r=Pilha[0].real;
        z.i=Pilha[0].imag;
        return z;
    }


    for(int i=0;i<Pilha.size();i++)
    {

        while( Pilha[i].FlagNumero  &&  i<Pilha.size()-1)
            i++;

        if (Pilha[i].ValidaOperadorPrioridade() == 0)
        {
            Pilha1=Plha2=Pilha;
        }
    }


    return z;
}

ComplexData Calculadora::ResolvePilha()
{

    int i;
    //QString str_aux;
    QString debug;
    //Complexo z;
    int idebug;


    //ShowPilha();
    if (Pilha.size()==1 && Pilha[0].FlagNumero)
    {
       // z.r=Pilha[0].real;
       // z.i=Pilha[0].imag;
       // return z;
        return Pilha[0];
    }


    for(i=0;i<Pilha.size();i++)
    {
        idebug=Pilha.size();

        while( Pilha[i].FlagNumero  &&  i<Pilha.size()-1)
            i++;

        debug=Pilha[i].StrFuncao;
         //sin2, cos3,etc

         if ( Pilha[i].ValidaFuncao() && i < (Pilha.size()-1))
         {
            if (Pilha[i+1].FlagNumero)
            {
                OperaFuncao(i);
                return ResolvePilha();
            }
        }

        idebug=Pilha.size();

        //se a+b,etc

        if ( !Pilha[i].FlagNumero  && i>0  &&  ValidaPilhaSeguinte(i) )
        {
            //if it is a operator and next and previos are numbers, i.e. 2+3
            if ( Pilha[i-1].FlagNumero && Pilha[i+1].FlagNumero)
            {
                // if after this calculation there are no more operators, do the calculation
                if ( !ValidaPilhaSeguinte2(i) )
                {
                    opera(i);
                    return ResolvePilha();
                }
                else // else check for operator priority
                {

                    /*if ( (Pilha[i+2].ValidaOperadores() || Pilha[i+2].ValidaParentesis() )
                        && (Pilha[i].ValidaOperadorPrioridade() >= Pilha[i+2].ValidaOperadorPrioridade()))
                    {
                        opera(i);
                        return ResolvePilha();
                    }*/
                    if (Pilha[i+2].ValidaParentesis()
                        || (Pilha[i].ValidaOperadorPrioridade() == 0 && Pilha[i+2].ValidaOperadorPrioridade() == 0)
                        || (Pilha[i].ValidaOperadorPrioridade() == 1 && Pilha[i+2].ValidaOperadorPrioridade() <= 1)
                        || (Pilha[i].ValidaOperadorPrioridade() == 2 && Pilha[i+2].ValidaOperadorPrioridade() < 2))
                    {
                        opera(i);
                        return ResolvePilha();
                    }
                }
            }
        }




        //se (2) ou |5|, remove parentesis
        //	if (!Pilha[i].FlagNumero && i< (Pilha.GetSize()-2))

        if (!Pilha[i].FlagNumero && ValidaPilhaSeguinte2(i))
        {
            if ((Pilha[i].StrFuncao == "(" && Pilha[i+2].StrFuncao == ")" )
                ||  (Pilha[i].StrFuncao == "|" && Pilha[i+2].StrFuncao == "|" ))
                {
                OperaRemoveParentesis(i);
                return ResolvePilha();
            }
        }




        //cos-2, solves -2;  8/-3, solves -3; ...
       /* if ( (Pilha[i].ValidaOperadores()) && (i > 0) && (Pilha[i-1].ValidaFuncaoOperador()) )
            {
            if ((Pilha[i].StrFuncao=="+" || Pilha[i].StrFuncao=="-")
                && (i < Pilha.size())
                && (Pilha[i+1].ValidaNumero()))
                {
                OperaFuncao(i);
                return ResolvePilha();
                }
            }*/


        //cos-2, solves -2;  8/-3, solves -3; ...
        if ( (Pilha[i].ValidaOperadores()) && (i > 0) && (Pilha[i-1].ValidaFuncaoOperador()) )
        {
            if ( (Pilha[i].StrFuncao=="+" || Pilha[i].StrFuncao=="-")
                && ( ValidaPilhaSeguinte(i) )
                && ( Pilha[i+1].ValidaNumero() )
                && ( ValidaPilhaSeguinte2(i) )
                && ( Pilha[i+2].ValidaOperadorPrioridade() == 2 )
                    )
            {
                ;
                //OperaFuncao(i);
                //return ResolvePilha();
            }
            else if ( (Pilha[i].StrFuncao=="+" || Pilha[i].StrFuncao=="-")
                     && ( ValidaPilhaSeguinte(i) )
                     && ( Pilha[i+1].ValidaNumero() )
                     //&& ( ValidaPilhaSeguinte2(i) )
                     //&& ( Pilha[i+2].ValidaOperadorPrioridade() == 2 )
                         )
            {
                OperaFuncao(i);
                return ResolvePilha();
            }

        }



        // -2 , -2*...., -2^.....
        if (!Pilha[i].FlagNumero && i==0 && ValidaPilhaSeguinte(i))
            if ( (Pilha[i].ValidaOperadorPrioridade() == 0 )
                && Pilha[i+1].ValidaNumero() )
                {
                OperaFuncao(i);
                return ResolvePilha();
            }


    }




    return Pilha[0];
    //return z;
}

void Calculadora::opera(int i)
{

  //  Complexo n1(Pilha[i-1].real,Pilha[i-1].imag);
  //  Complexo n2(Pilha[i+1].real,Pilha[i+1].imag);
  //  Complexo n;

    //n1=Pilha[i-1].r;
    //n2=Pilha[i+1].r;

    if (Pilha[i].StrFuncao=="+")
    {
        Pilha[i-1]=Pilha[i-1]+Pilha[i+1];
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }

    if (Pilha[i].StrFuncao=="-")
    {
        Pilha[i-1]=Pilha[i-1]-Pilha[i+1];
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }


    if (Pilha[i].StrFuncao=="*")
    {
        Pilha[i-1]=Pilha[i-1]*Pilha[i+1];
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }
    //    n=n1*n2;

    if (Pilha[i].StrFuncao=="/")
    {
        Pilha[i-1]=Pilha[i-1]/Pilha[i+1];
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }


    if (Pilha[i].StrFuncao=="^")
    {
        Pilha[i-1]=Pilha[i-1]^Pilha[i+1];
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }


    if (Pilha[i].StrFuncao=="E")
    {
        ComplexData aux;
        aux.SetNumero(10);
        //Pilha[i+1]=aux^Pilha[i+1];
        //Pilha[i-1]=Pilha[i-1]*Pilha[i+1];
        Pilha[i-1]=Pilha[i-1]*(aux^Pilha[i+1]);
        Pilha.removeAt(i);
        Pilha.removeAt(i);
        return ;
    }
    //    n=n1*(10^n2);

    //Pilha[i-1].SetNumero(n);


    //Pilha.RemoveAt(i,2);
    //Pilha.removeAt(i);
    //Pilha.removeAt(i);

}

void Calculadora::OperaRemoveParentesis(int i)
{
    if (Pilha[i].StrFuncao=="|")
    {
        //Complexo z(Pilha[i+1].real,Pilha[i+1].imag);
        //Pilha[i+1].SetNumero(cabs(z));

        Pilha[i+1]=abs(Pilha[i+1]);

    }

    //Pilha.RemoveAt(i+2,1);
    Pilha.removeAt(i+2);
    //Pilha.RemoveAt(i,1);
    Pilha.removeAt(i);
}

/*
void Calculadora::OperaFuncao(int i)
{
    QString str_aux;
    Complexo n1;

    n1.r=Pilha[i+1].real;
    n1.i=Pilha[i+1].imag;

    if (Pilha[i].StrFuncao=="-")
        n1=-n1;

    if (Pilha[i].StrFuncao=="+")
        n1=n1;




    switch(Flag_Graus_Rad_Grados)
    {
    case 0:
        n1=PI/180*n1; //graus
        break;
    case 1://radianos
        break;
    case 2:
        n1=PI/200*n1;//grados
        break;
    };

    if (!Pilha[i].StrFuncao.compare("sinc",Qt::CaseInsensitive))
        n1=sinc(n1);

    if (!Pilha[i].StrFuncao.compare("sin",Qt::CaseInsensitive))
        n1=sin(n1);

    if (!Pilha[i].StrFuncao.compare("cos",Qt::CaseInsensitive))
        n1=cos(n1);

    if (!Pilha[i].StrFuncao.compare("tan",Qt::CaseInsensitive))
        n1=tan(n1);

    if (!Pilha[i].StrFuncao.compare("cotg",Qt::CaseInsensitive))
        n1=cotg(n1);

    if (!Pilha[i].StrFuncao.compare("sinh",Qt::CaseInsensitive))
        n1=sinh(n1);

    if (!Pilha[i].StrFuncao.compare("cosh",Qt::CaseInsensitive))
        n1=cosh(n1);

    if (!Pilha[i].StrFuncao.compare("tanh",Qt::CaseInsensitive))
        n1=tanh(n1);

    if (!Pilha[i].StrFuncao.compare("cotgh",Qt::CaseInsensitive))
        n1=cotgh(n1);

    if (!Pilha[i].StrFuncao.compare("asin",Qt::CaseInsensitive))
        n1=asin(n1);

    if (!Pilha[i].StrFuncao.compare("acos",Qt::CaseInsensitive))
        n1=acos(n1);

    if (!Pilha[i].StrFuncao.compare("atan",Qt::CaseInsensitive))
        n1=atan(n1);

    if (!Pilha[i].StrFuncao.compare("acotg",Qt::CaseInsensitive))
        n1=acotg(n1);



    if (!Pilha[i].StrFuncao.compare("asin",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("acos",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("atan",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("acotg",Qt::CaseInsensitive))

    {
        switch(Flag_Graus_Rad_Grados)
        {
        case 0://graus
            n1=180/PI*n1;
            break;
        case 1://rad
            break;
        case 2://grados
            n1=200/PI*n1;
            break;
        };
    }

    if (!Pilha[i].StrFuncao.compare("asinh",Qt::CaseInsensitive))
        n1 = asinh(n1);

    if (!Pilha[i].StrFuncao.compare("acos",Qt::CaseInsensitive))
        n1=acosh(n1);


    if (!Pilha[i].StrFuncao.compare("atanh",Qt::CaseInsensitive))
        n1=atanh(n1);

    if (!Pilha[i].StrFuncao.compare("acotgh",Qt::CaseInsensitive))
        n1=acotgh(n1);

    Pilha[i].SetNumero(n1);
    //Pilha.RemoveAt(i+1,1);
    Pilha.removeAt(i+1);
}
*/

void Calculadora::OperaFuncao(int i)
{
    QString str_aux;
  //  Complexo n1;
    ComplexData degreeRad_Aux;
    //Complexo m1;
    //QList<Complexo> n1_array;

    //n1.r=Pilha[i+1].real;
    //n1.i=Pilha[i+1].imag;

    if (Pilha[i].StrFuncao=="-")
    {
        Pilha[i]=-Pilha[i+1];
        Pilha.removeAt(i+1);
        return ;
    }

    if (Pilha[i].StrFuncao=="+")
    {
        Pilha[i]=Pilha[i+1];
        Pilha.removeAt(i+1);
        return ;
    }


    if (!Pilha[i].StrFuncao.compare("log",Qt::CaseInsensitive))
    {
        Pilha[i]=log(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("ln",Qt::CaseInsensitive))
    {
        Pilha[i]=ln(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("abs",Qt::CaseInsensitive))
    {
        //n1=abs(n1);
        //Pilha[i].SetNumero(n1);
        //Pilha.removeAt(i+1);
        Pilha[i]=abs(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("cbrt",Qt::CaseInsensitive))
    {
        Pilha[i]=cbrt(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("sqrt",Qt::CaseInsensitive))
    {
        Pilha[i]=sqrt(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }


    if (!Pilha[i].StrFuncao.compare("conj",Qt::CaseInsensitive))
    {
        Pilha[i]=conj(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("real",Qt::CaseInsensitive))
    {
        //n1.r=real(n1);
        //n1.i=0;
        //Pilha[i].SetNumero(n1);
        Pilha[i]=real(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("imag",Qt::CaseInsensitive))
    {
        Pilha[i]=imag(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("exp",Qt::CaseInsensitive))
    {
        Pilha[i]=exp(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }



    switch(Flag_Graus_Rad_Grados)
    {
    case 0:
        //n1=PI/180*n1; //graus
        degreeRad_Aux.SetNumero(PI/180);
        Pilha[i+1]=degreeRad_Aux*Pilha[i+1];
        break;
    case 1://radianos
        break;
    case 2:
        degreeRad_Aux.SetNumero(PI/200);
        Pilha[i+1]=degreeRad_Aux*Pilha[i+1];
        //n1=PI/200*n1;//grados
        break;
    };

    if (!Pilha[i].StrFuncao.compare("sinc",Qt::CaseInsensitive))
    {
        Pilha[i]=sinc(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;

     //   n1=sinc(n1);
     //   Pilha[i].SetNumero(n1);
     //   Pilha.removeAt(i+1);
     //   return ;
    }

    if (!Pilha[i].StrFuncao.compare("sin",Qt::CaseInsensitive))
    {
        Pilha[i]=sin(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("cos",Qt::CaseInsensitive))
    {
        Pilha[i]=cos(Pilha[i+1]);
/*
        if (Pilha[i].array_xi.size() == 0)
        {
            n1=cos(n1);
            Pilha[i].SetNumero(n1);
        }
        else
        {
            QList<Complexo> ar=cos(Pilha[i+1].array_xi);
            Pilha[i].SetNumberArrai(ar);
        }*/
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("tan",Qt::CaseInsensitive))
    {
        Pilha[i]=tan(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("cot",Qt::CaseInsensitive))
    {
        Pilha[i]=cot(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("csc",Qt::CaseInsensitive))
    {
        Pilha[i]=csc(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("sec",Qt::CaseInsensitive))
    {
        Pilha[i]=sec(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("sinh",Qt::CaseInsensitive))
    {
        Pilha[i]=sinh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("cosh",Qt::CaseInsensitive))
    {
        Pilha[i]=cosh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("tanh",Qt::CaseInsensitive))
    {
        Pilha[i]=tanh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("coth",Qt::CaseInsensitive))
    {
        Pilha[i]=coth(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }


    if (!Pilha[i].StrFuncao.compare("csch",Qt::CaseInsensitive))
    {
        Pilha[i]=csch(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }


    if (!Pilha[i].StrFuncao.compare("sech",Qt::CaseInsensitive))
    {
        Pilha[i]=sech(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("asin",Qt::CaseInsensitive))
    {
        Pilha[i]=asin(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("acos",Qt::CaseInsensitive))
    {
        Pilha[i]=acos(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("atan",Qt::CaseInsensitive))
    {
        Pilha[i]=atan(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("acot",Qt::CaseInsensitive))
    {
        Pilha[i]=acot(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("acsc",Qt::CaseInsensitive))
    {
        Pilha[i]=acsc(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("asec",Qt::CaseInsensitive))
    {
        Pilha[i]=asec(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }



    if (!Pilha[i].StrFuncao.compare("asin",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("acos",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("atan",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("acot",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("acsc",Qt::CaseInsensitive)
            || !Pilha[i].StrFuncao.compare("asec",Qt::CaseInsensitive)
        )

    {
        switch(Flag_Graus_Rad_Grados)
        {
        case 0://graus
            //n1=180/PI*n1;
            degreeRad_Aux.SetNumero(180/PI);
            Pilha[i+1]=degreeRad_Aux*Pilha[i+1];

            break;
        case 1://rad
            break;
        case 2://grados
            //n1=200/PI*n1;
            degreeRad_Aux.SetNumero(200/PI);
            Pilha[i+1]=degreeRad_Aux*Pilha[i+1];
            break;
        };
    }

    if (!Pilha[i].StrFuncao.compare("asinh",Qt::CaseInsensitive))
    {
        Pilha[i]=asinh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("acosh",Qt::CaseInsensitive))
    {
        Pilha[i]=acosh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("atanh",Qt::CaseInsensitive))
    {
        Pilha[i]=atanh(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("acoth",Qt::CaseInsensitive))
    {
        Pilha[i]=acoth(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }


    if (!Pilha[i].StrFuncao.compare("acsch",Qt::CaseInsensitive))
    {
        Pilha[i]=acsch(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }

    if (!Pilha[i].StrFuncao.compare("asech",Qt::CaseInsensitive))
    {
        Pilha[i]=asech(Pilha[i+1]);
        Pilha.removeAt(i+1);
        return ;
    }


   // Pilha[i].SetNumero(n1);
   // Pilha.removeAt(i+1);
}



//ZEROS------------------------------------------------------------------


double Calculadora::zeros_find(QString f_x,QString x, double min,double max,
                                                           double incremento, double precisao)
{
        double i;
        double l;
        double fa,fb;

//	zeros.RemoveAll();


        for(i=min ; i<max ; i+=incremento)
        {

        //	if (fabs(i)< precisao)
        //		i=0;
                fa=fx(f_x,i,x).r;

                l=i+incremento;
        //	if (fabs(l)< precisao)
        //	l=0;

                fb=fx(f_x,l,x).r;


                if( fa*fb  <= 0)
                        zero(f_x,x,i,l,precisao);


        }

        return 1;
}



double Calculadora::zero(QString f_x, QString x, double a, double b, double precisao)
{
        double fa,fb,fa2,fb2, dist_fa1_fb1, dist_fa2_fb2;
        double fd,d;
        double a2, b2, dist2;
        int n;

        d=(a+b)/2;

        fa=fx(f_x,a,x).r;
        fb=fx(f_x,b,x).r;
        fd=fx(f_x,d,x).r;



        if ( fabs(b-a) <=precisao)
        {

                ///testa se o zero é verdadeiro ou se é uma descontinuidade (polo)
                //------
                dist2= sqrt(a*a+b*b)/2 * 1.1;

                a2= d-dist2;
                b2= d+dist2;

                fa2=fx(f_x,a2,x).r;
                fb2=fx(f_x,b2,x).r;

                dist_fa1_fb1 = sqrt(pow(b - a,2) + pow(fb - fa,2));
                dist_fa2_fb2 = sqrt(pow(b2 - a2,2) + pow(fb2 - fa2,2));

                if( dist_fa1_fb1 > dist_fa2_fb2 )
                        return 1;
                //------------


                //elimina zeros duplicados
                //-------------

                n=zeros.size();

                if (n)
                        if( fabs( fabs(zeros[n-1]) - fabs(d) ) < precisao)
                        {
                                double a1,a2;

                                a1=zeros[n-1];
                                a2=fabs(zeros[n-1] - fabs(d));
                                //zeros.Add(d);
                                return 1;
                        }
                //-------------

                zeros.append(d);
                return 1;
        }


        if (fa*fd<=0)
                return zero(f_x,x,a,d,precisao);
        else
                return zero(f_x,x,d,b,precisao);
}










//INTEGRAIS--------------------------------------------------------------


double Calculadora::Integral(QString f_x, QString x, double a, double b, double m)
{

        double h;
        double Isc;
        double i;
        bool par=true;

        if (a > b)
        {
                i=a;
                a=b;
                b=i;
        }

        h=(b-a)/m;

        Isc=h/3*fx(f_x,a,x).r + h/3*fx(f_x,b,x).r;

        for(i=a+h;i<b;i=i+h)
        {
                if (par==true)
                {
                        Isc=Isc+(h/3)*4*fx(f_x,i,x).r;
                        par=false;
                }
                else
                {
                        Isc=Isc+(h/3)*2*fx(f_x,i,x).r;
                        par=true;
                }
        }

        return Isc;
}

double Calculadora::IntegralArea(QString f_x, QString x, double a, double b, double h)
{

//	double h=(b-a)/m;
    bool par=true;

    double Isc;

    Isc=fabs(h/3*fx(f_x,a,x).r) + fabs(h/3*fx(f_x,b,x).r);


    for(double i=a+h;i<b;i=i+h)
    {
        if (par==true)
        {
                Isc=Isc+fabs((h/3)*4*fx(f_x,i,x).r);
                par=false;
        }
        else
        {
                Isc=Isc+fabs((h/3)*2*fx(f_x,i,x).r);
                par=true;
        }
    }

    return Isc;
}


double Calculadora::Integral_Duplo_Funcoes(QString func_xy, QString varx, QString vary,
                                        double Ax, double Bx,
                                        QString fAy ,QString fBy,double m)
{
    double hx;
    double hy;
    double ix,iy,i;
    double fay, fby;// fay, fby;
    bool par;
    double Isc=0;


    if ( Ax > Bx)//troca
    { i=Ax;Ax=Bx;Bx=i; }
    hx=(Bx-Ax)/m;

//	::fxy(QString str,double x,QString u,double y,QString v, double z, QString s)

    for(ix=Ax;ix<=Bx;ix+=hx)
    {
        par=true;
        fay=fx(fAy,ix,varx).r;
        fby=fx(fBy,ix,varx).r;

        if (fay > fby) //troca
        { i=fay;fay=fby;fby=i; }
        hy=(fby-fay)/m;


        iy=fay;
        Isc+= hy/3*fxyz(func_xy,fay,varx,iy,vary,1,"@").r
                + hy/3*fxyz(func_xy,fby,varx,iy,vary,1,"@").r ;

        for(iy=fay+hy;iy<fby;iy+=hy)
        {
                if (par==true)
                {
                        Isc+=hy*4/3*fxyz(func_xy,ix,varx,iy,vary,1,"@").r;
                        par=false;
                }
                else
                {
                        Isc+=hy*2/3*fxyz(func_xy,ix,varx,iy,vary,1,"@").r;
                        par=true;
                }
        }
        //Isc;
    }


    return Isc*hx;
}

double Calculadora::IntegralD(QString f_x, QString x, QString y,double a, double b
                                                          , double ay, double by, double m)
{
    double h=(b-a)/m;
    double hy=(by-ay)/m;
    bool par=true;
    //bool pary=true;
    double Isc=0;
    //double Iy=0;

    for(double yy=ay;yy<=by;yy+=hy)
    {
        Isc+=h/3*fxyz(f_x,a,x,yy,y,0,"@").r + h/3*fxyz(f_x,b,x,yy,y,0,"@").r;
        for(double xx=a+h;xx<b;xx+=h)
        {
            if (par==true)
            {
                Isc=Isc+(h/3)*4*fxyz(f_x,xx,x,yy,y,0,"@").r;
                par=false;
            }
            else
            {
                Isc=Isc+(h/3)*2*fxyz(f_x,xx,x,yy,y,0,"@").r;
                par=true;
            }
        }
    }

    return Isc*(by-ay)/m;
}


double Calculadora::IntegralDsc(QString f_x, QString x, QString y,double a, double b
                                                          , double ay, double by, double m)
{

    double h=(b-a)/m;
    double hy=(by-ay)/m;
    bool par=true;
    bool pary=true;
    double Isc=0;
    double Iy=0;


    for(double yy=ay;yy<=by;yy+=hy)
    {
        Isc=0;
        Isc=h/3*fxyz(f_x,a,x,yy,y,0,"@").r + h/3*fxyz(f_x,b,x,yy,y,0,"@").r;
        for(double xx=a+h;xx<b;xx+=h)
        {
            if (par==true)
            {
                    Isc=Isc+(h/3)*4*fxyz(f_x,xx,x,yy,y,0,"@").r;
                    par=false;
            }
            else
            {
                    Isc=Isc+(h/3)*2*fxyz(f_x,xx,x,yy,y,0,"@").r;
                    par=true;
            }
        }

        if (yy==ay || yy==by)
                Iy+=Isc*h/3;
        else
        {
            if (pary==true)
            {
                    Iy+=Isc*h*4/3;
                    pary=false;
            }
            else
            {
                    Iy+=Isc*h*2/3;
                    pary=true;
            }
        }
    }

    return Iy;
}

//-----------------------------------------------------------------------




//INTERPOLACAO-----------------------------------------------------------


double Calculadora::Interpolacao_Newton(double x,
                                        QVector<double> &xi,
                                        QVector<double> &yi)

{

        QVector<double> yy;
        QVector<double> xx;

        double px=yi[0];
        double mult_aux;
        double div_aux;

        int i;
        int n=xi.size();

        if (xi.size() != yi.size()) return 0;
        if (xi.size() == 0) return 0;
        if (yi.size()==1) return yi[0];


        xx=xi;
        yy=yi;


/*	for(i=n;i>1;i--)
        {
                xx.Copy(xi);
                yy.Copy(yi);

                yy.RemoveAt(i-1,n-i);
                xx.RemoveAt(i-1,n-i);

                div_aux=Interpolacao_Newton_fdiv(yy,xx);

                xx.RemoveAt(i-1,1);

                mult_aux=Interpolacao_Newton_mult(xx,x);

                px=px+mult_aux*div_aux;

        }*/



        for(i=1;i<n;i++)
        {
                xx=xi;
                yy=yi;



                //xx.RemoveAt(i+1, n-i-1);
                xx.remove(i+1,n-i-1);
                yy.remove(i+1, n-i-1);

                div_aux=Interpolacao_Newton_fdiv(yy,xx);

                xx.remove(i);

                mult_aux=Interpolacao_Newton_mult(xx,x);

                px=px+mult_aux*div_aux;
                //px=px+Interpolacao_Newton_mult(xx, x)*Interpolacao_Newton_fdiv(yy,xx);
        }


        return px;

}

double Calculadora::Interpolacao_Newton_mult(QVector<double> &xi, double x)
{
        QVector<double> xx;
        double aux;
        int n;

        n=xi.size();
        if (xi.size()==1)
                return (x-xi[0]);
        else
        {
                xx=xi;

                aux=x-xi[0];

                xx.remove(1);

                return aux*Interpolacao_Newton_mult(xx,x);

        }

}



double Calculadora::Interpolacao_Newton_fdiv(QVector<double> &yi,
                                             QVector<double> &xi)
{
        QVector<double> fx2, fx1;
        QVector<double> x2, x1;

        int n= xi.size();



        if (xi.size()==2)
                return  (yi[1]-yi[0]) / (xi[1]-xi[0]);
        else
        {
                fx2=yi;
                fx2.remove(0);

                x2=xi;
                x2.remove(0);


                fx1=yi;
                fx1.remove(n-1);

                x1=xi;
                x1.remove(n-1);



                return ( Interpolacao_Newton_fdiv(fx2,x2) - Interpolacao_Newton_fdiv(fx1,x1) )
                        / ( xi[n-1] - xi[0] );
        }

}






///Interpolacao LaGrange

double Calculadora::Interpolacao_LaGrange(double x,
                                          QList<double> &xi,
                                          QList<double> &yi)
{
    double px=0;
    int n;
    int i;

    n=xi.size();

    if (xi.size() != yi.size()) return 0;
    if (xi.size() == 0) return 0;
    if (yi.size()==1) return yi[0];

    for(i=0;i<n;i++)
    {
        px=px+yi[i]*Interpolacao_LaGrange_Ln(xi, x, i);
    }

    return px;
}

double Calculadora::Interpolacao_LaGrange_Ln(QList<double> &xi,
                                               double x, int i)
{
    double Lx=1;
    //double numerador=1;
    //double denominador=1;
    int n;
    int l;

    n=xi.size();

    for(l=0;l<n;l++)
    {
        /*if (l != i)
            numerador=numerador*(x-xi[l]);
        if (l != i)
            denominador=denominador*(xi[i]-xi[l]);*/

        //optimizacao
        if (l != i)
            Lx=Lx*(x-xi[l]) / (xi[i]-xi[l]);
    }

//	Lx=numerador/denominador;

    return Lx;
}

double Calculadora::Interpolacao_LaGrange_GetLNumerator(QList<double> &xi, int i)
{
    double Nx=1;

    int n=xi.size();
    int l;

    for(l=0;l<n;l++)
    {
        if (l != i)
            Nx=Nx * (xi[i]-xi[l]);
    }

    return Nx;
}

int Calculadora::Interpolacao_LaGrange_GetDenominator(QList<double> &xi,
                                            QList<double> &x_p_coef)
{


    return 1;

}

double Calculadora::Interpolacao_LaGrange_Combinacoes(QList<double> &xi, int n)
{
    double value=0;

    if (n==1)
    {
        for(int i=0;i<xi.size();i++)
        {
            value+=xi[i];
        }
        return value;
    }
/*
    if (n==2)
    {
        for(int i=0;;i)
        {}
    }
*/

    return 1;

}



//-----------------------------------------------------------------------


void Calculadora::keyPressEvent(QKeyEvent *event)
{
    flagAbortFunction=true;
}


//EQUA??ES---------------------------------------------------------------


Complexo Calculadora::equacao_resolve_procura(QString f1, QString f2,
                                        QString x, double min, double max,
                                        double incremento, double precisao)
{
    double i;
    double l;
    double fa,fb,fa1,fb1;
    double da,db,dab,dab1;//delta
  //  int contador = 0;
    QString str;

    double incremento_inicial=incremento;

    //double incremento_maximo=incremento; //debug porpuse
    //double incremento_minimo=incremento; //debug porpuse

    solucoes_equacao.clear(); //clear all previous solutions because we will start a solution search

    //----------------------------------------------------------------------------
    //this if will optimize the search
    //if the expression is of the type 'x=0' or 'x=3+7' it will skip the search and do the assignment
    QStringList ListVar_aux;
    if ( ( (f1 == x) || (f1 == "("+x+")") ) && (GetVariaveis(f2,ListVar_aux) == 0) )
    //if ( ( f1 == x ) && (GetVariaveis(f2,ListVar_aux) == 0) )
    {
        bool ok;
        Complexo y;
        y.r= f2.toDouble(&ok);
        if (ok) //if f2 is a number e.g. '7' save the solution
        {
            solucoes_equacao.append(y);  //save the solution
            return y;
        }
        else  // f2 is a expresion e.g '3+7'
        {
            y=f(f2); // then calculate it
            solucoes_equacao.append(y);  // save the solution
            return y;
        }
    }
    //---------------------------------------------------------------------


    i=min;
    fa=fx(f1,i,x).r;
    fb=fx(f2,i,x).r;

    QList<double> faxx;
    QList<double> fayy;
    QList<double> fbxx;
    QList<double> fbyy;


    flagCalculationEquation=true;
    flagAbortFunction=false;


    for(i=min ; i<=max ; i+=incremento)
    {
        l=i+incremento;
        fa1=fx(f1,l,x).r;
        fb1=fx(f2,l,x).r;


        // aux variables to draw debug graphs--------------------
       // faxx.append(i);
       // fayy.append(fa1);

      //  fbxx.append(i);
      //  fbyy.append(fb1);
     //------------------------------------------------------------


        QCoreApplication::processEvents();

        if (flagAbortFunction)
        {
            flagCalculationEquation=false;
            return 0;
        }

        /////evita funçoes trigonometrica com muitas soluçoes
      //  if (solucoes_equacao.size()>10)
      //  {
         //   str.sprintf("maximo=%lf\nminimo=%lf\ncontador=%d",incremento_maximo,incremento_minimo,contador);
         //   QMessageBox::about(0,"",str);
          //  return 10;
        //}



        /////incremento dinamico/////////////////////////
        //contador++;
        da=fabs(fa1-fa);
        db=fabs(fb1-fb);
        dab=fabs(fa-fb);
        dab1=fabs(fa1-fb1);


        if (da < db)
            da=db;

        if (dab < dab1)
            dab=dab1;

        if (da < 0.2*dab)
            incremento=incremento+incremento*0.05;//5%
        else
        {
            incremento=incremento_inicial;
            //if (incremento > 0.1*incremento_inicial) //10%
            //    incremento=incremento-incremento*0.1;//10%
        }
        ////////////////////////////////////////////////




        //---------------------------------------------------
        //uncomment the next four lines for debug porpuse
        //if (incremento > incremento_maximo)
        //    incremento_maximo=incremento;

        //if (incremento < incremento_minimo)
        //      incremento_minimo=incremento;
        //---------------------------------------------------



        //check if there is a complex(imaginary) solution when the real part is zero
       /* if ( (l < 0) && ( (l+incremento)>0 ) )
        {
            if ( cabs( fx(f1,0,x) - fx(f2,0,x) )  < precisao )
            {
                solucoes_equacao.append(0);
            }
        }
*/




        if (fb >= fa)
        {
            if (fb1 <= fa1)
                equacao_resolve(f1,f2,x,i,l,precisao);
        }
        else
        {
            if (fa1 < fb1)
                equacao_resolve(f1,f2,x,i,l,precisao);
        }
        fa=fa1;
        fb=fb1;
    }

    flagCalculationEquation=false;


    //---graph for debug porpuse-------------------------------
    /*
    GLGraph *graph_fa = new GLGraph();
    GLGraph *graph_fb = new GLGraph();


    graph_fa->SetGraph2D(faxx,fayy);
    graph_fa->showNormal();
    graph_fa->updateGL();

    graph_fb->SetGraph2D(fbxx,fbyy);
    graph_fb->showNormal();
    graph_fb->updateGL();
    */
    //-------------------------------------------------------------------



  //  str.sprintf("maximo=%lf\nminimo=%lf\ncontador=%d",incremento_maximo,incremento_minimo,contador);
  //  QMessageBox::about(0,"",str);

    return 1;
}


double Calculadora::equacao_resolve(QString f1, QString f2, QString x,
                                    double a, double b, double precisao)
{
    Complexo fa=fx(f1,a,x);
    Complexo fb=fx(f2,a,x);
   // double fa1=f(f1,b,x).r;
   // double fb1=f(f2,b,x).r;
    double d=(a+b)/2;
    Complexo fda=fx(f1,d,x);
    Complexo fdb=fx(f2,d,x);


    if (fda == fdb)
    {
        solucoes_equacao.append(d);
        return 1;
    }


    //double zzz = cabs(fda-fdb);
    if ( fabs(fda.r-fdb.r) <= precisao)
    {
        if (cabs(fda-fdb)<=precisao) // this is for the imaginary part
            solucoes_equacao.append(d);
        return 1;
    }


    if (fa.r > fb.r)
    {
        if (fda.r > fdb.r)
            return equacao_resolve(f1,f2,x,d,b,precisao);
        else
            return equacao_resolve(f1,f2,x,a,d,precisao);
    }
    else
    {
        if (fdb.r > fda.r)
            return equacao_resolve(f1,f2,x,d,b,precisao);
        else
            return equacao_resolve(f1,f2,x,a,d,precisao);
    }

}


/*
bool Calculadora::isEquation_Fx_equal_Gx(QString str_equation)
{
    //GetVariaveis(str_equation);

    int size = str_equation.split("=").size();
    //this->GetVariaveis(str_equation,list);

    //n_variaveis=calc.GetVariaveis(str_cmd_line, list_var);

    return false;
}*/
