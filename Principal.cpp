#include "Ambiente.h"
using namespace std;

class Principal{
    public:
       string Z; 
        bool max, noNeg, cero, reem; 
        int precision, pob, ind;
        

    /*
        Menú para introducir la función objetivo y restricciones
    */
    public:
        void menu(){
            int opc;
            cout << "Va a minimizar(0) o maximizar(1)? ";
            cin >> opc;
            opc==0 ? max=false : max=true;
            if(!max) hacerZNeg(&Z);
            cout << "Considerar variables como no negativas? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? noNeg=false : noNeg=true;
            cout << "Los rangos de las restricciones seran considerados desde cero? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? cero=false : cero=true;
            cout << "Ingrese precision del algoritmo: ";
            cin >> precision;
            cout << "Numero de poblaciones: ";
            cin >> pob;
            cout << "Numero de individuos por poblacion: " ;
            cin >> ind;
        }

        void desplegarEncabezado(){
            cout << "Instituto Politecnico Nacional" << endl << "Escuela Superior de Computo" << endl;
            cout << "Metodos cuantitativos para la toma de desiciones" << endl << "Proyecto/Examen 2o Parcial" << endl;
            cout << "Prof.: Ariel Lopez Rojas" << endl;
            cout << "Benitez Morales Manuel Emilio" << endl << "Castillo Rodriguez David Israel" << endl << "Garcia Garcia Cano Ivan" << endl;
            cout << "3CM8" << endl << "08/12/2020" << endl;
        }

        /*
            Volver negativa una función objetivo
        */
        void hacerZNeg(string* Z){
            if( (int)(*Z)[0]>=48 && (int)(*Z)[0]<=57 ){
                stringstream aux;
                aux << "(" << (*Z) << ")" << "*(0-1)";
                (*Z)= aux.str();
            }
            else if( (*Z)[0]=='-' ){
                (*Z)[0]='\0';

                for(int i=1; i<(*Z).size(); i++)
                    if((*Z)[i]=='-')
                        (*Z)[i]='+';
                    else if((*Z)[i]=='+')
                        (*Z)[i]='-';
            }
        }

};

int main(){
    Principal principal;
    srand ((signed)time(NULL));
    vector<vector<Individuo>> poblacion;
    /*
        Variables para calcular tiempo de ejecución y generación de la población
    */
    unsigned t0, t1; 
    string restric; 
    int nrest, i=0;
    int contadorInd=0, contadorPob=0;
    double aj, bj;

    /*
        Desplegar menú para introducción de datos
    */
    principal.desplegarEncabezado();
    principal.menu();
    cout << endl;

    double sumaX=0;
    int puntos=0;
    cout<<"Introduzca la cantidad de puntos a evaluar: ";
    cin>> puntos;

    double valores_x[puntos];
    double valores_y[puntos];

    if(puntos>5 || puntos<3 )
        cout<< "No esta en el rango los puntos a evaluar";
    else{
        for(int i=0;i<puntos;i++){
            cout<< i+1 <<". Introduzca el valor de x: ";
            cin>> valores_x[i];
            cout<< i+1 <<". Introduzca el valor de y: ";
            cin>> valores_y[i];
        }
    }

    
    /*
        Transformación de la función objetivo en términos numéricos
    */
    stringstream FO;
    FO << "(";
    for(int i=0; i < puntos; i++)
        FO << valores_x[i] << "*x+y-" << valores_y[i] << ")+(";
    principal.Z= FO.str();
    principal.Z[principal.Z.size()-1]='\0';
    principal.Z[principal.Z.size()-2]='\0';

    Ambiente ambiente(
        principal.Z, 
        principal.max, 
        principal.noNeg, 
        principal.cero, 
        principal.precision, 
        principal.pob, 
        principal.ind, 
        false
    );

    /*
        Variables para el cálculo de m, b y k
    */
    double mLin=0; 
    double b=0, kGaus=0;    
    double mGaus=0; 

    for(int j=0; j<sizeof(valores_x)/sizeof(*valores_x); j++ )
        sumaX+=valores_x[j];

    for(int j=1;j<puntos;j++){
        if(valores_y[i-1]<valores_y[i])
            mGaus=valores_x[i];
    }

    /*
        Restricciones de m
    */
    ambiente.agregarRestriccion( "1*x+0*y >= -100" );
    ambiente.agregarRestriccion( "1*x+0*y <= 100" );
    
    /*
        Restricciones de b
    */
    ambiente.agregarRestriccion( "0*x+1*y >= "+to_string((-1)*pow(sumaX, 2)) );
    cout<<"To string expre aj: "<<to_string((-1)*pow(sumaX, 2))<<endl;
    ambiente.agregarRestriccion( "0*x+1*y <= "+to_string(pow(sumaX, 2)) );
    cout<<"To string expre bj: "<<to_string(pow(sumaX, 2))<<endl;
    if(principal.noNeg){
        ambiente.agregarRestriccion("1*x+0*y >= 0");
        ambiente.agregarRestriccion("0*x+1*y >= 0");
    }

    /*
        Calculo de límites y bits
    */
    double* ajbjx= ambiente.calcAjBj('x'); 
    double* ajbjy= ambiente.calcAjBj('y'); 
    
    int* numBits= ambiente.calcBitsXY();
    cout << "Bits de X: " << numBits[0] << endl;
    cout << "Bits de Y: " << numBits[1] << endl;
    cout << "Se cumple? " << ambiente.verificar() << endl;
    
    bool cumple=false;
    
    t0=clock();
    /*
        Generación de población
    */
    while(poblacion.size()<principal.pob){
        vector<Individuo> indis;

        /*
            GENERAR INDIVIDUOS
        */            
        while(true){ 
            Individuo indi( numBits[0], numBits[1]); 
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++){ 
                cumple= ambiente.obtRestriccciones()[k].evaluar(indi);                
                if(!cumple) 
                    break; 
            }

            if(cumple){
                indis.push_back(indi);
                contadorInd+=1;
            }


            if(contadorInd==principal.ind)
                break;
        }

        contadorInd=0;
        poblacion.push_back(indis);
        indis.clear();
    }

    /*
        Obtención del mejor individuo y cálculo de m,b y k
    */
    double z1;
    double z2;
    double zAux;
    int pos[poblacion.size()];    
    Restriccion rAux;

    vector<string> Zpartes=  rAux.separar(ambiente.getZ(), ")+(");
    Zpartes[0].replace(0, 1, "");
    Zpartes[Zpartes.size()-1].replace( Zpartes[Zpartes.size()-1].size()-1, Zpartes[Zpartes.size()-1].size(), "" );
    for(int z=0; z<Zpartes.size(); z++)
        cout << Zpartes[z] << endl;

    for(int j=0; j<poblacion.size(); j++){
        for(int s=0; s<Zpartes.size(); s++)
            zAux+= abs( ambiente.obtRestriccciones()[0].evaluar(Zpartes[s],poblacion[j][0].obtFenotipo().x,poblacion[j][0].obtFenotipo().y) );
        z2=zAux;
        zAux=0;
        for(int n=0; n<poblacion[j].size(); n++){
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++)
            {                
                for(int s=0; s<Zpartes.size(); s++)
                    zAux+= abs( ambiente.obtRestriccciones()[k].evaluar(Zpartes[s],poblacion[j][n].obtFenotipo().x,poblacion[j][n].obtFenotipo().y) );
                z1=zAux;
                zAux=0;
                if(z1<z2)
                {
                    z2=z1;     
                }
            }
        }          
    }
    
    Individuo mejorI;

    for(int j=0; j<poblacion.size(); j++){
        for(int n=0; n<poblacion[j].size(); n++){
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++){
                for(int s=0; s<Zpartes.size(); s++)
                   zAux+= abs( ambiente.obtRestriccciones()[k].evaluar(Zpartes[s],poblacion[j][n].obtFenotipo().x,poblacion[j][n].obtFenotipo().y) );

                if(z2==zAux)
                {
                    mejorI= poblacion[j][n];
                    break;
                }
                zAux=0;
            }
        }
    }

    cout <<"El mejor individuo \n"<< mejorI.imprimir()<<endl;
    cout<<"ajbjx[0] "<<ajbjx[0]<<" ajbjx[1] "<<ajbjx[1]<<" numBits[0] "<<numBits[0]<<endl;
    cout<<"ajbjy[0] "<<ajbjy[0]<<" ajbjy[1] "<<ajbjy[1]<<" numBits[1] "<<numBits[1]<<endl;

    int entK= mejorI.binDec(mejorI.obtGenotipo().cromosomas);

    kGaus= ajbjx[0]+ entK * ( (ajbjx[1]-ajbjx[0]) / (pow(2, (numBits[0]+numBits[1]))-1) );
    mLin= ajbjx[0]+ mejorI.obtFenotipo().x * ( (ajbjx[1]-ajbjx[0]) / (pow(2, numBits[0])-1) );
    b= ajbjy[0]+ mejorI.obtFenotipo().y * ( (ajbjy[1]-ajbjy[0]) / (pow(2, numBits[1])-1) );

    cout << "kGaus: " << kGaus << endl;
    cout << "mLin: " << mLin << endl;
    cout << "b: " << b << endl;
    cout << "mGaus: " << mGaus << endl;

    t1 = clock();
    
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de procesamiento: " << tiempo << "s" << endl;

    return 0;
}