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
    defDominio();
}

//getter del valor de la ecuación si y=0
double Restriccion::valSiY0(){
    return siY0;
}

//getter del valor de la ecuación si x=0
double Restriccion::valSiX0(){
    return siX0;
}

bool Restriccion::evaluar(Individuo ind){
    bool ret=false;
    double evaluacion= evaluar(ladoIzq, ind.obtFenotipo().x, ind.obtFenotipo().y);
    switch(condicion){
        case 0: //<=
            if( evaluacion <= ladoDer )
                ret=true;
            break;

        case 1: //=
            if( evaluacion == ladoDer )
                ret=true;
            break;

        case 2: //>=
            //cout << ladoIzq << "\t" << ind.obtFenotipo().x << "\t" << ind.obtFenotipo().y << "\t" << evaluacion << endl;
            if( evaluacion >= ladoDer )
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
    ladoDer= stod(exprPartes[1]);
}

//Evalúa la expresión que se obtuvo al definir atributos con los parámetros x,y
double Restriccion::evaluar(string expr, double x, double y){
    expr+="|"; //Separador para elimirar el excedente
    //sustituir correctamente valores
    stringstream sb;
    vector<string> separacion;
    separacion= separar(expr, "x");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << x;
    expr= sb.str();
    
    sb.str("");
    separacion= separar(expr, "y");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << y;
    expr= sb.str();
    sb.str("");

    //Quitar caracteres extras
    int indSep=0;
    for(int i=0; i<expr.length(); i++)
        if(expr[i]=='|'){
            indSep=i;
            break;
        }
    expr.replace(expr.begin()+indSep, expr.end(), "");

    
    //cout << expr << endl;
    Evaluador eva(expr);

    return eva.getResultado();
}





double Restriccion::evaluar(double x, double y){
    string expr= ladoIzq;
    expr+="|"; //Separador para elimirar el excedente
    //sustituir correctamente valores
    stringstream sb;
    vector<string> separacion;
    separacion= separar(expr, "x");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << x;
    expr= sb.str();
    
    sb.str("");
    separacion= separar(expr, "y");
    for(int i=0; i<separacion.size(); i++)
        sb << separacion[i] << y;
    expr= sb.str();
    sb.str("");

    //Quitar caracteres extras
    int indSep=0;
    for(int i=0; i<expr.length(); i++)
        if(expr[i]=='|'){
            indSep=i;
            break;
        }
    expr.replace(expr.begin()+indSep, expr.end(), "");

    
    //cout << expr << endl;
    Evaluador eva(expr);

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

void Restriccion::defDominio(){
    int xoy=0;
    char xy[]={'x', 'y'};
    double coefX= coeficiente('x');
    double coefY= coeficiente('y');

    //Calcular x si y=0
    //Obtener coeficiente de X
    ///encontrar x
    while(xoy<1){
        double eval;
        //<<"coefY "<<coefY<<" coefX "<<coefX<<endl;
        if(coefY==0&&coefX!=0){
            /*
            if(coefY==0&&coefX!=0){
                //siY0=0;
                cout <<"sin y, x="<<siY0<<endl;
            }
            else{*/
                eval= evaluar(ladoIzq, 1, 0);//<-Cambio (1,0)
                if(eval==0) eval=1;
                //cout<<"eval X "<<eval<<endl;
                siY0= ladoDer/eval;            
                //if(siY0==INFINITY) siY0=0;
                //cout <<"si y=0, x="<<siY0<<endl;
            //}
            
        }
        else{
            /*
            if(coefX==0&&coefY!=0){
                siX0=0;
                cout<<"sin x, y= "<<siX0<<endl;
            }
            else{*/
                eval= evaluar(ladoIzq, 0, 1);//<- Cambio 0,1
                if(eval==0) eval=1;
                //cout<<"eval Y "<<eval<<endl;
                siX0= ladoDer/eval;
                //if(siX0==INFINITY) siX0=0;
                //cout<<"six=0, y= "<<siX0<<endl;
            //}
            
        }

        xoy+=1;
    }
}

double Restriccion::coeficiente(char xoy){
    //xoy: coeficiente de x o de y
    //Entendiendo que en la expresión del lado izquierdo hay solo una vez x y y /////!!!!!!!!!!!
    int indice=0;
    string coefInv="";
    string coef="";
    double coeficiente=1;

    coefInv="";
    coef="";
    //Buscar la variable y obtener su índice
    for(int i=0; i<ladoIzq.length(); i++)
        if(ladoIzq[i]==xoy){
            indice=i;
            break;
        }
    indice-=2; //Para que tome los números, no la letra ni el símbolo *
    //Sacar su coeficiente, pero saldrá invertido
    while( ((int)ladoIzq[indice]>=48 && (int)ladoIzq[indice]<=57) || ladoIzq[indice]=='.' ){//Mientras haya números (coeficiente)
        coefInv+=ladoIzq[indice];
        indice-=1;
    } 
    //Regresar el coeficiente a su forma original
    indice=0;
    for(int i=coefInv.length()-1; i>=0; i--){
        coef+=coefInv[i];
        indice+=1;
    }
    coeficiente= stod(coef);

    return coeficiente;
}

