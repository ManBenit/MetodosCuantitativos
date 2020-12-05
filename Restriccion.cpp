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

//getter del límite inferior
int Restriccion::limInf(){

}

// getter del límite superior
int Restriccion::limSup(){

}

bool Restriccion::evaluar(int individuo){

}

void Restriccion::defAtributos(string expresion){
    
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
