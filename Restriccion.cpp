/*
PROYECTO SEGUNDO PARCIAL. MÉTODOS CUANTITATIVOS PARA LA TOMA DE DESICIONES.
AUTORES:
    Benítez Morales Manuel Emilio
    Castillo Rodríguez David Israel
    García García Cano Ivan

    3CM8

Algoritmo genético para la maximización/minimización
VERSIÓN: 1.0

Diciembre 2020.
*/

#include "Restriccion.h"
Restriccion::Restriccion(string expresion){
    defAtributos(expresion);
}

//getter del valor de la ecuación si y=0
int Restriccion::valSiY0(){
    return siY0;
}

//getter del valor de la ecuación si x=0
int Restriccion::valSiX0(){
    return siX0;
}

bool Restriccion::evaluar(Individuo ind){
    bool ret=false;
    switch(condicion){
        case 0: //<=
            if( evaluar(ind.fenotipo().x, ind.fenotipo().y) <= ladoDer )
                ret=true;
            break;

        case 1: //=
            if( evaluar(ind.fenotipo().x, ind.fenotipo().y) == ladoDer )
                ret=true;
            break;

        case 2: //>=
            if( evaluar(ind.fenotipo().x, ind.fenotipo().y) >= ladoDer )
                ret=true;
            break;
    }
    return ret;
}

void Restriccion::defAtributos(string expresion){
    vector<string> exprPartes;
    int numPart=0;


    //Verificar si es <=, =, >= para la futura evaluación; asignar condición
    if( separar(expresion, " <= ").size() == 2 ){
        condicion=0;
        exprPartes= separar(expresion, " <= ");
    }
    else if( separar(expresion, " = ").size() == 2 ){
        condicion=1;
        exprPartes= separar(expresion, " = ");
    }
    else if( separar(expresion, " >= ").size() == 2 ){
        condicion=2;
        exprPartes= separar(expresion, " >= ");
    }

    //Asignar ambos lados
    ladoIzq= exprPartes[0];
    minusculas(&ladoIzq);
    ladoDer= stoi(exprPartes[1]);
    
}

//Evalúa la expresión que se obtuvo al definir atributos con los parámetros x,y
double Restriccion::evaluar(double x, double y){
    ladoIzq+="|"; //Separador para elimirar el excedente
    //sustituir correctamente valores
    stringstream sb;
    vector<string> separacion;
    separacion= separar(ladoIzq, "x");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << x;
    ladoIzq= sb.str();
    
    sb.str("");
    separacion= separar(ladoIzq, "y");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << y;
    ladoIzq= sb.str();
    sb.str("");

    //Quitar caracteres extras
    int indSep=0;
    for(int i=0; i<ladoIzq.length(); i++)
        if(ladoIzq[i]=='|'){
            indSep=i;
            break;
        }
    ladoIzq.replace(ladoIzq.begin()+indSep, ladoIzq.end(), "");

    
    cout << ladoIzq << endl;
    Evaluador eva(ladoIzq);

    return eva.getResultado();
}

vector<string> Restriccion::separar(string str, string sep){
    vector<string> elementos;
    string auxSubWord="", assignedWord="";
    int inicio=0, fin=0+sep.length(), posOfAssignment=0;
    
    while(fin<=str.length()){
        auxSubWord="";
        
        //Get the sub word
        for(int i=inicio; i<fin; i++)
            auxSubWord+=str[i];
        
        //Delete the matches
        if(auxSubWord==sep)
            for(int i=inicio; i<fin; i++)
                str[i]='\0';
            
        inicio+=1;
        fin=inicio+sep.length();
    }
    
    //Introduce words at vector
    for(int i=0; i<str.length(); i++){
        if(!(str[i]=='\0')){
            assignedWord=""; //Reiniciar cadena
            posOfAssignment=i;
            while(!(str[posOfAssignment]=='\0')){
                assignedWord+= str[posOfAssignment];
                posOfAssignment+=1;
            }
            elementos.push_back(assignedWord);
            i=posOfAssignment;
        }
    }
    
    return elementos;
}

void Restriccion::minusculas(string* cadena){
    for(int i=0; i<(*cadena).length(); i++)
        if( (int)(*cadena)[i]>=65 && (int)(*cadena)[i]<=90 )
           (*cadena)[i]= (char)( (int)(*cadena)[i]+32 );
}

