#include "Evaluador.h"

Evaluador::Evaluador(string strComplexChain){
    hacerExpresionSimple(strComplexChain);
    makePostFija();
    evalPostFija(); //Aquí contiene las llamadas a la distribución de operaciones
}

void Evaluador::makePostFija(){
    //char[] c= cadenaSimple.toCharArray();
    for(int i=0; i<cadenaSimple.length(); i++){
        switch (cadenaSimple[i]) {
            case '+':
            case '-':
                if(pila.empty()){
                    pila.push_back(cadenaSimple[i]);
                }
                else{
                    //Si al última posición es + o -
                    while(!pila.empty() && (pilaTope()=='+' || pilaTope()=='-' || pilaTope()=='*' || pilaTope()=='/' || pilaTope()=='^')){
                        expresionPosfija << pilaTope();
                        pila.pop_back();
                    }
                    pila.push_back(cadenaSimple[i]);
                    
                    
                    if(pilaTope()=='('){
                        pila.push_back(cadenaSimple[i]);
                    }
                }
                break;
                
            case '*':
            case '/':
                if(pila.empty()){
                    pila.push_back(cadenaSimple[i]);
                }
                else{
                    while(!pila.empty() && (pilaTope()=='*' || pilaTope()=='/' || pilaTope()=='^')){
                        expresionPosfija << pilaTope();
                        pila.pop_back();
                    }
                    pila.push_back(cadenaSimple[i]);
                    
                    if(pilaTope()=='+' || pilaTope()=='-'){
                        pila.push_back(cadenaSimple[i]);
                    }
                    
                    
                    else if(pilaTope()=='('){
                        pila.push_back(cadenaSimple[i]);
                    }
                }
                break;
                
            case '^':
                if(pila.empty()){
                    pila.push_back(cadenaSimple[i]);
                }
                else{
                    if(pilaTope()=='^'){
                        expresionPosfija << pilaTope();
                        pila.pop_back();
                        pila.push_back(cadenaSimple[i]);
                    }
                    else if(pilaTope()=='*' || pilaTope()=='/' || pilaTope()=='+' || pilaTope()=='-'){
                        pila.push_back(cadenaSimple[i]);
                    }
                    else if(pilaTope()=='('){
                        pila.push_back(cadenaSimple[i]);
                    }
                }
                break;
                
            case '(':
                pila.push_back(cadenaSimple[i]);
                break;
                
            case ')':
                while(true){
                    expresionPosfija << pilaTope();
                    pila.pop_back();
                    
                    if(pilaTope()=='('){
                        pila.pop_back();
                        break;
                    }
                }
                break;
                
            default:
                expresionPosfija << cadenaSimple[i];
                break;
        }
    }
    if(!pila.empty()){
        while(pila.size()>0){
            expresionPosfija << pilaTope();
            pila.pop_back();
        }
    }
}

void Evaluador::evalPostFija(){
    string pf= getPostFija();
    int indexVal=0;
    double res=0;
    stringstream s;

    for(int i=0; i<pf.length(); i++){
        switch (pf[i]) {
            case '+':
                s.str("");
                res= pilaResTope();
                pilaResultado.pop_back();
                res+= pilaResTope();
                //Modificar valor
                pilaResultado.pop_back();
                pilaResultado.push_back(res);
                break;
            
            case '-':
                s.str("");
                res= pilaResTope();
                pilaResultado.pop_back();
                res= pilaResTope() - res;
                //Modificar valor
                pilaResultado.pop_back();
                pilaResultado.push_back(res);
                break;
            
            case '*':
                s.str("");
                res= pilaResTope();
                pilaResultado.pop_back();
                res*= pilaResTope();
                //Modificar valor
                pilaResultado.pop_back();
                pilaResultado.push_back(res);
                break;
            
            case '/':
                s.str("");
                res= pilaResTope();
                pilaResultado.pop_back();
                res= pilaResTope() / res;
                //Modificar valor
                pilaResultado.pop_back();
                pilaResultado.push_back(res);
                break;
            
            case '^':
                s.str("");
                res= pilaResTope();
                pilaResultado.pop_back();
                res= pow(pilaResTope(), res);
                //Modificar valor
                pilaResultado.pop_back();
                pilaResultado.push_back(res);
                break;
            
            default:
                pilaResultado.push_back(valoresPila[indexVal]);
                indexVal+=1;
                break;
        }
    }
    resultado= pilaResTope();
    pilaResultado.pop_back();
    if(!pilaResultado.empty()){
        cout << "ERROR AL EVALUAR" << endl;
    }
}


void Evaluador::hacerExpresionSimple(string complexChain){
    int index=0;
    stringstream numero;
    stringstream se;
    
    for(int i=0; i<complexChain.length(); i++){
        if((complexChain[i]>47 && complexChain[i]<58) || complexChain[i]=='.')
            numero << complexChain[i];
        else{
            if(numero.str().length()==0 && complexChain[i]!='|')
                se << complexChain[i];
            else if(complexChain[i]=='|'){
                int iAux=i+2;
                numero << complexChain[i+1];//Colocar el signo '-' en en string
                while((complexChain[iAux]>47 && complexChain[iAux]<58) || complexChain[iAux]=='.'){
                    numero << complexChain[iAux];
                    iAux+=1;
                }
                i= iAux-1;
            }
            else{
                valoresPila.push_back(stod(numero.str()));
                numero.str("");
                se << letras[index];
                se << complexChain[i];
                index+=1;
            }
        }
    }
    if(!(numero.str()==")" || numero.str().length()==0)){
        se << letras[index];
        valoresPila.push_back(stod(numero.str()));
    }
    
    cadenaSimple= se.str();
}

char Evaluador::pilaTope(){
    return pila[pila.size()-1];
}

double Evaluador::pilaResTope(){
    return pilaResultado[pilaResultado.size()-1];
}

string Evaluador::getPostFija(){
    return expresionPosfija.str();
}

double Evaluador::getResultado(){
    return resultado;
}

