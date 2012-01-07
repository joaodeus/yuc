#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QString>
#include <QList>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>
//#include "complexo.h"
#include "complexdata.h"
//#include <QGLWidget>
#include <QKeyEvent>

           //3.1415926535897932384626433832795
#define PI 3.1415926535897932384


/*
#define M_E		2.7182818284590452354
#define M_LOG2E		1.4426950408889634074
#define M_LOG10E	0.43429448190325182765
#define M_LN2		0.69314718055994530942
#define M_LN10		2.30258509299404568402
#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define M_PI_4		0.78539816339744830962
#define M_1_PI		0.31830988618379067154
#define M_2_PI		0.63661977236758134308
#define M_2_SQRTPI	1.12837916709551257390
#define M_SQRT2		1.41421356237309504880
#define M_SQRT1_2	0.70710678118654752440
*/





class Calculadora //: QKeyEvent
{
public:

    Calculadora();
    virtual ~Calculadora();

    //  Calculadora(const Calculadora &);




    //--functions to determinate the type of expressions


    bool isExpression(QString &expression);//return true if it's a mth expression, i.e. "2+3*5.2"
    bool isEquation(QString &expression);//return true if it's a equation like "2x^2=3x+2"

    bool isEquation_assignment(QString &expression);
    //return true if it's a equation and assignment like "x=4+2"

    bool isConvertion_equation(QString &expression, QStringList &list_var);
    //return true if it's a convertion equation, with 2 variables,
    //and the first member is equal to one of the variables
    //i.e. "Celsius = Kelvin - 273.15"  or "Kelvin = Celsius + 273.15"
    // or "kilometer = 1000 * meter" or "meter = 0.001 * kilometer"
    //return's the 2 variables in list_var





    Complexo WichExpressionIsThis(QString expression);





    //FUNCAO F(X)--------------------------------------------------
    //calculates a expression i.e. "4+2*3+2i" , return's 10+2i
    Complexo f(QString /*f_exp*/);

    //calculates a expresison with a variable i.e  str="2*x+3", valor=2, x="x", return's 7 (2*2+3)
    Complexo fx(QString str, double valor,QString x);
    Complexo resolvePilhaaux(QList<ComplexData>   /*QString &fx*/);

    Complexo fxy(QString str/*expressao*/,
                  double v/*valor*/,QString x/*variavel*/,
                  double v1/*valor*/,QString x1/*variavel*/);

    Complexo fxyz(QString /*str*/,
                 double /*valor1*/,QString /*x1*/,
                 double /*valor2*/,QString /*x2*/,
                 double /*valor3*/,QString /*x3*/);



    Complexo f_n_variaveis(QString str,
                           QList<double> &xi,
                           QList<QString> &xn);

    Complexo f_n_variaveis(QString str,
                           QList<double> &xi, //variable value
                           QList<QString> &xn, //variabke name
                           QString var_arrai_xi, QList<double> &arrai_xi,
                           QString var_arrai_yi, QList<double> &arrai_yi,
                           QList<Complexo> &arrai_zi);

    //Complexo f_n_variaveis(QString f, QList<double> &vn, QList<QString> &xn);


    //solves functions of type yi=f(xi), where yi and xi are arrays's
    Complexo f_array_x(QString str, QString var_x, QList<double> &xi, QList<Complexo> &yi);


    //same as above but with the time t variable; yi=f(xi,t), t-time, xi and yi are array's
    //bool f_array_x_t(QString str, QString var_x, QList<double> &xi, QList<double>   &yi, double t, QString var_t);
    Complexo f_array_x_t(QString str, QString var_x, QList<double> &xi, QList<Complexo> &yi,double t, QString var_t);

    Complexo f_array_xy_t(QString str,
                          QString var_x, QList<double> &xi, QString var_y, QList<double> &yi,
                          QList<Complexo> &zi, double t, QString var_t);


    // array
    QList<double> array(double min, double max, double step);
    QList<double> array(double min, double max);

  //  Complexo fxy_array(QString str,QString x, QList<Complexo>& x_array,
    //                               QString y, QList<Complexo>& y_array,
      //                             QList<Complexo>& solution);

//    QString f_substitui_var(QString f, QList<QString> &xi,
  //                          QList<QString> &vi);

    QString f_substitui_var(QString f, QStringList xi,
                            QStringList vi);


    QString f_substitui_var_caracter(QString /*f*/, QList<QString> &/*xi*/,
                                     QList<QString> &/*vi*/,
                                     QString /*?*/);


    QString f_substitui_var(QString /*f*/, QString /*xi*/, QString /*vi*/);

    void ShowPilha();
    double e;
    bool ERRO;
    int Flag_Graus_Rad_Grados;
    QList<ComplexData> Pilha;

private:
    bool ValidaPilhaAnterior(int );
    bool ValidaPilhaSeguinte(int );
    bool ValidaPilhaAnterior2(int );
    bool ValidaPilhaSeguinte2(int );
    void opera(int);
    void OperaFuncao(int);
    void OperaRemoveParentesis(int);
    double SacaNumero(QString str_numero, int &);
    QString SacaFuncao(QString str_funcao, int &);
    QList<Complexo> SacaNumberArrai(QString str_arraiNumber, int &);
    ComplexData ResolvePilha();

public:

    //check if f has variables, returns the nunbers of variables and stores them in Var
    //i.e. f=2*x+y, return 2, stores x and y in QStringList Var
    int GetVariaveis(QString f, QStringList &Var);

    //check if f have a time variable "t", if so return true
    bool has_time_variable(QString f);

//-------------------------------------------------------------

//ZEROS DE FUNCAO-------------------------------------------
public:
    //guarda os zeros encontrados
    QList<double> zeros;
    //procura zeros numa funcao
    double zeros_find(QString /*fx*/,QString /*x*/,double /*min*/,
                      double /*max*/,double /*incremento*/,double /*precisao*/);
private:
    //refina a precisao do zero
    double zero(QString /*fx*/,QString /*x*/,double /*a*/,double /*b*/,
                                        double /*precisao*/);
//------------------------------------------------------------------


//INTEGRAIS---------------------------------------------------------
public:
    double Integral(QString /*fx*/, QString /*x*/, double /*a*/,
                    double /*b*/, double /*m*/);
    double IntegralArea(QString, QString, double, double, double);
    double IntegralD(QString, QString, QString, double, double, double,double,double);
    double IntegralDsc(QString, QString, QString, double, double, double,double,double);
    double Integral_Duplo_Funcoes(QString /*fxy*/, QString /*varx*/, QString /*vary*/,
                                  double /*Ax*/, double /*Bx*/,
                                  QString /*y=fa(x)*/ ,QString /*y=fb(x)*/,double /*m*/);

//------------------------------------------------------------------



//INTERPOLACAO------------------------------------------------------
public:

    //Interpolacao Newton
    double Interpolacao_Newton(double /*x*/,
                               QVector<double> &/*xi*/,
                               QVector<double> &/*yi*/);

    double Interpolacao_Newton_fdiv(QVector<double> &/*xi*/,
                                    QVector<double> &/*yi*/);

    double Interpolacao_Newton_mult(QVector<double> &/*xi*/, double /*x*/);


    //Interpolacao Lagrange
    double Interpolacao_LaGrange(double /*x*/,
                                 QList<double> &/*x*/,
                                 QList<double> &/*y*/);

private:
    double Interpolacao_LaGrange_Ln(QList<double> &/*xi*/,
                                      double /*x*/, int /*i*/);
public:


    double Interpolacao_LaGrange_GetLNumerator(QList<double> &/*xi*/, int /*i*/);
    int Interpolacao_LaGrange_GetDenominator(QList<double> & /*xi*/,
                                            QList<double> & /*x_p_coef*/);

    double Interpolacao_LaGrange_Combinacoes(QList<double>& /*xi*/, int /*n*/);



//------------------------------------------------------------------
protected:
    void keyPressEvent(QKeyEvent *event);



//EQUAÇÕES----------------------------------------------------------
public:
    //guarda as solucoes encontradas da equacao _resolve()
    QList<Complexo> solucoes_equacao;
    Complexo equacao_resolve_procura(QString,QString,QString,double,double,double,double);
    bool flagCalculationEquation;
    bool flagAbortFunction;
    //bool isEquation_Fx_equal_Gx(QString str_equation);
private:
    double equacao_resolve(QString,QString,QString,double,double,double);


//------------------------------------------------------------------

};

QString groupDigits(QString str, bool bGroup);
QString ComplexoToQString(const Complexo &z, bool bPrecision, int precision, char format, bool bGroup);
QString ComplexoToQString( const Complexo &z);
QString ComplexoToQString( const Complexo &z, const int &precision);


#endif // CALCULADORA_H
