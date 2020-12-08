#include "Ambiente.h"


Ambiente::Ambiente(string Z, bool max, bool noNeg, bool cero, int presicion, int pob, int ind, bool reem){
    this->Z=Z;
    this->max= max;
    this->noNeg=noNeg;
    this->cero=cero;
    this->presicion=presicion;
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
    

bool Ambiente::verificar(){
    bool valido=false;
    double ajbjx= calcAjBj('x');
    double ajbjy= calcAjBj('y');
    int mjx= mj(ajbjx[0], ajbjx[1]);
    int mjy= mj(ajbjy[0], ajbjy[1]);

    if( 
        pow(2, mjx-1)<=(ajbjx[1]-cjbjx[0])*pow(10, (double)precision) && 
        pow(10, (double)precision)<=pow(2, mjx)-1 &&
        pow(2, mjy-1)<=(ajbjy[1]-cjbjy[0])*pow(10, (double)precision) && 
        pow(10, (double)precision)<=pow(2, mjy)-1
        )
        valido=true;

    return valido;
}

//Límite inferior de x o de y
double* Ambiente::calcAjBj(char variable){
    double ajbj[2];
    vector<double> auxCompara;
    //Tabla implícita de restricciones contra x,y
    for(int i=0; i<restricciones.size(); i++)
        if(variable=='x')
            auxCompara.push_back( restricciones[i].valSiY0() );
        else if(variable=='y')
            auxCompara.push_back( restricciones[i].valSiX0() );
    
    if(cero)
        ajbj=[0];
    else
        ajbj[0]= calcMin(auxCompara);

    ajbj[1]= calcMax(auxCompara);

    return ajbj;
}

//cálculo de mjx y mjy
int* Ambiente::calcBitsXY(){
    int bitsXY[2];
    double* ajbj;
    
    ajbj= calcAjBj('x');
    bitsXY[0]= mj( ajbj[0], ajbj[1] );
    ajbj= calcAjBj('y');
    bitsXY[1]= mj( ajbj[0], ajbj[1] );

    return bitsXY;
}

int mj(double aj, double bj){
    return (int)ceil( log10((bj-aj)*pow(10, (double)precision)) / log10(2) );
}

int Ambiente::generarAleatorio(){}

double Ambiente::calcMin(vector<double> lista){
    double minimo= lista[0];
    for(int i=0; i<sizeof(lista)/sizeof(*lista); i++)
        if(minimo>lista[i])
            minimo=lista[i];
    return minimo;
}

double Ambiente::calcMax(vector<double> lista){
    double maximo= lista[0];
    for(int i=0; i<sizeof(lista)/sizeof(*lista); i++)
        if(maximo<lista[i])
            maximo=lista[i];
    return maximo;
}
