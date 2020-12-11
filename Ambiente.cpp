#include "Ambiente.h"


Ambiente::Ambiente(string Z, bool max, bool noNeg, bool cero, int precision, int pob, int ind, bool reem){
    this->Z=Z;
    this->max= max;
    this->noNeg=noNeg;
    this->cero=cero;
    this->precision=precision;
    this->nPoblaciones=pob;
    this->nIndividuos=ind;
    this->reemplazo=reem;
}

//Expresión completa, ejemplo: a+b<=4000
void Ambiente::agregarRestriccion(string expresion){
    restricciones.push_back(Restriccion(expresion));
}

void Ambiente::imprimirMejorIndividuo(){
    //Igual y no se usa, aún no sé
}

string Ambiente::getZ(){
    return Z;
}
    

bool Ambiente::verificar(){
    bool valido=false;
    double* ajbjx= calcAjBj('x');
    double* ajbjy= calcAjBj('y');
    int mjx= mj(ajbjx[0], ajbjx[1]);
    int mjy= mj(ajbjy[0], ajbjy[1]);

    if( 
        pow(2, mjx-1)<=(ajbjx[1]-ajbjx[0])*pow(10, (double)precision) && 
        pow(10, (double)precision)<=pow(2, mjx)-1 &&
        pow(2, mjy-1)<=(ajbjy[1]-ajbjy[0])*pow(10, (double)precision) && 
        pow(10, (double)precision)<=pow(2, mjy)-1
        )
        valido=true;

    return valido;
}

//Límite inferior de x o de y
double* Ambiente::calcAjBj(char variable){
    double* ajbj= (double*)malloc(2*sizeof(double));
    vector<double> auxCompara;
    //Tabla implícita de restricciones contra x,y
    for(int i=0; i<restricciones.size(); i++)
        if(variable=='x')
            auxCompara.push_back( restricciones[i].valSiY0() );
        else if(variable=='y')
            auxCompara.push_back( restricciones[i].valSiX0() );
    
    if(cero)
        ajbj[0]=0;
    else
        ajbj[0]= calcMin(auxCompara);

    ajbj[1]= calcMax(auxCompara);

    return ajbj;
}

//cálculo de mjx y mjy
int* Ambiente::calcBitsXY(){
    int* bitsXY= (int*)malloc(2*sizeof(int));
    double* ajbj;
    
    ajbj= calcAjBj('x');
    bitsXY[0]= mj( ajbj[0], ajbj[1] );
    ajbj= calcAjBj('y');
    bitsXY[1]= mj( ajbj[0], ajbj[1] );

    return bitsXY;
}

int Ambiente::mj(double aj, double bj){
    return (int)ceil( log10((bj-aj)*pow(10, precision)) / log10(2) );
}

double Ambiente::generarAleatorio(){
    return 0;
}

double Ambiente::calcMin(vector<double> lista){
    double minimo= lista[0];
     for(int i=1; i<lista.size(); i++)
        if(minimo>lista[i])
            minimo=lista[i];

    return minimo;
}

double Ambiente::calcMax(vector<double> lista){
    double maximo= lista[0];
     for(int i=1; i<lista.size(); i++)
        if(maximo<lista[i])
            maximo=lista[i];

    return maximo;
}

vector<Restriccion> Ambiente::obtRestriccciones(){
    return restricciones;
}
