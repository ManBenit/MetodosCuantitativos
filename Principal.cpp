#include "Ambiente.h"
using namespace std;

//CLASE PRONCIPAL DE PRUEBA, NO ESTÁ EN REPOSITORIO
class Principal{
    //ATRIBUTOS/////////////////////
    public:
        /*string Z= "0.2*x+0.5*y"; 
        bool max=true, noNeg=true, cero=true, reem=false; 
        int precision=0, pob=3, ind=5;*/

        //PRimer problema exmaen
        string Z= "11.5*x+4*y+3.09"; 
        bool max=false, noNeg=false, cero=false, reem=true; 
        int precision=0, pob=1, ind=10000;
        
    ////////////////////////////////

    //MÉTODOS///////////////////////
    public:
        void menu(){
            int opc;
            cout << "Ingrese funcion Z: ";
            getline(cin, Z);
            fflush(stdin);
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
            cout << "Ingrese precision del algoritmo: (0 o 1) ";
            cin >> precision;
            cout << "Numero de poblaciones: ";
            cin >> pob;
            cout << "Numero de individuos por poblacion: " ;
            cin >> ind;
            cout << "Algoritmo con reemplazo? (si=1, no=0) ";
            cin >> opc;
            opc==0 ? reem=false : reem=true;
        }

        void desplegarEncabezado(){
            cout << "Instituto Politecnico Nacional" << endl << "Escuela Superior de Computo" << endl;
            cout << "Metodos cuantitativos para la toma de desiciones" << endl << "Proyecto/Examen 2o Parcial" << endl;
            cout << "Prof.: Ariel Lopez Rojas" << endl;
            cout << "Benitez Morales Manuel Emilio" << endl << "Castillo Rodriguez David Israel" << endl << "Garcia Garcia Cano Ivan" << endl;
            cout << "3CM8" << endl << "08/12/2020" << endl;
        }

        void hacerZNeg(string* Z){
            //Primer caracter de la expresión (- o num)
            if( (int)(*Z)[0]>=48 && (int)(*Z)[0]<=57 ){
                stringstream aux;
                aux << "-" << (*Z);
                (*Z)= aux.str();
            }
            else if( (*Z)[0]=='-' )
                (*Z)[0]='\0';

            //Al encontrar signos + y - en el resto de la cadena
            int iAux;
            (*Z)[0]=='-' ? iAux=1 : iAux=0;
            for(int i=iAux; i<(*Z).size(); i++)
                if((*Z)[i]=='-')
                    (*Z)[i]='+';
                else if((*Z)[i]=='+')
                    (*Z)[i]='-';
        }

    ////////////////////////////////

};

int main(){
    //srand(rand(NULL));
    srand ((unsigned)time(NULL));
    //Ambiente ambiente("0.2*x+0.5*y", true, true, true, 0, 3, 5, false);
    Ambiente ambiente("11.5*x+4*y+3.09", false, false, false, 0, 1, 10000, true); //Primer problema examen
    //FO primer problema
    //Ambiente ambiente("11.5*x+4*y+3.09", false, false, false, 0, 3, 5, true);
    Principal principal;
    vector<vector<Individuo>> poblacion;
    unsigned t0, t1; //Medición de tiempo de ejecución
    string restric; 
    int nrest, i=0;
    int contadorInd=0, contadorPob=0;
    double aj, bj;
    //principal.desplegarEncabezado();
    //principal.menu();
    cout << endl;
    /*Ambiente ambiente(
        principal.Z, 
        principal.max, 
        principal.noNeg, 
        principal.cero, 
        principal.precision, 
        principal.pob, 
        principal.ind, 
        principal.reem
    );*/

    /*cout << "Cuantas restricciones debe cumplir? ";
    cin >> nrest;
    getline(cin, restric);
    while(true){
        cout << "r" << i+1 << ": ";
        getline(cin, restric);
        fflush(stdin);
        ambiente.agregarRestriccion(restric);

        i+=1;
        if(i==nrest)
           break;        
    }*/

    /*ambiente.agregarRestriccion("0.1*x+0.6*y <= 2000");
    ambiente.agregarRestriccion("1*x+1*y <= 6000");
    ambiente.agregarRestriccion("1*x+0*y <= 4000");
    if(principal.noNeg){
        ambiente.agregarRestriccion("1*x+0*y >= 0");
        ambiente.agregarRestriccion("0*x+1*y >= 0");
    }*/

    double sumaX=0;
    int puntos=0;
    double* valores_x = NULL;
    double* valores_y = NULL;
    cout<<"Introduzca la cantidad de puntos a evaluar: ";
    cin>> puntos;
    valores_x =  new double[puntos];
    valores_y =  new double[puntos];
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

    double mLin=0; //m de la función lineal
    double b=0, kGaus=0;

    //sigma_de_x
    for(int j=0; j<sizeof(valores_x)/sizeof(double); j++ )
        sumaX+=valores_x[j];

    ////valor de m para la función gaussiana
    double mGaus=0; //m de la función gaussiana
    for(int j=1;j<puntos;j++){
        if(valores_y[i-1]<valores_y[i])
            mGaus=valores_x[i];
    }


    



    //Restricciones problema 1 Examen (restricciones de m y b)
    ambiente.agregarRestriccion( "1*x+0*y >= -100" );
    ambiente.agregarRestriccion( "1*x+0*y <= 100" );
    ambiente.agregarRestriccion( "0*x+1*y >= "+to_string((-1)*pow(sumaX, 2)) );
    ambiente.agregarRestriccion( "0*x+1*y <= "+to_string(pow(sumaX, 2)) );
    if(principal.noNeg){
        ambiente.agregarRestriccion("1*x+0*y >= 0");
        ambiente.agregarRestriccion("0*x+1*y >= 0");
    }

    double* ajbjx= ambiente.calcAjBj('x'); //representando m
    double* ajbjy= ambiente.calcAjBj('y'); //representando b
    
    int* numBits= ambiente.calcBitsXY();
    cout << "Bits de X: " << numBits[0] << endl;
    cout << "Bits de Y: " << numBits[1] << endl;
    cout << "Se cumple? " << ambiente.verificar() << endl;
    
    bool cumple=false;
    
    /*for(int j=0; j<principal.ind; j++){
        Individuo indi(aux[0], aux[1]);

        cout << indi.imprimir();
        for(int k=0; k<ambiente.obtRestriccciones().size(); k++)
            cout << "\t" << ambiente.obtRestriccciones()[k].evaluar(indi);
        cout << endl;
    }*/

    t0=clock();
    //GENERAR POBLACIONES (comprobar restricciones de m y b)
    while(poblacion.size()<principal.pob){
        vector<Individuo> indis;

        //GENERAR INDIVIDUOS
        while(true){ //Mientras no se cumplan las restricciones,
            Individuo indi( numBits[0], numBits[1]); //genera otro,
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++){ //debe cumplir todas las restricciones,
                cumple= ambiente.obtRestriccciones()[k].evaluar(indi);
                if(!cumple) //con una que no cumpla,
                    break; //generamos otro.
            }

            if(cumple){
                /*cout << indi.imprimir();
                for(int k=0; k<ambiente.obtRestriccciones().size(); k++)
                    //cout << "\t1";
                    cout << "\t" <<ambiente.obtRestriccciones()[k].evaluar(indi);
                cout << endl;*/
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


    


    //cout << poblacion.size() << endl ;
    /*double z1;
    double z2=0;
    int pos[poblacion.size()];*/
    /*for(int j=0; j<poblacion.size(); j++){
        for(int n=0; n<poblacion[j].size(); n++){
            cout << poblacion[j][n].imprimir();
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++){
                cout << "\t" << ambiente.obtRestriccciones()[k].evaluar(poblacion[j][n]);
                
            }
                //cout << "\t1";
            cout << endl;
        }
        cout << endl;
    }*/


    double z1;
    double z2=0;
    int pos[poblacion.size()];
    for(int j=0; j<poblacion.size(); j++){
        for(int n=0; n<poblacion[j].size(); n++){
            //cout << poblacion[j][n].imprimir();
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++)
            {
                z1=ambiente.obtRestriccciones()[k].evaluar(ambiente.getZ(),poblacion[j][n].obtFenotipo().x,poblacion[j][n].obtFenotipo().y);
                if(z1>z2)
                {
                    z2=z1;                  
                }
            }
        }          
    }
    
    Individuo mejorI;
    //Imprimir Mejor Vector
    for(int j=0; j<poblacion.size(); j++){
        for(int n=0; n<poblacion[j].size(); n++){
            //cout << poblacion[j][n].imprimir();
            for(int k=0; k<ambiente.obtRestriccciones().size(); k++){
                //cout << "\t" << ambiente.obtRestriccciones()[k].evaluar(poblacion[j][n]);
                //cout << "\t1";
                if(z2==ambiente.obtRestriccciones()[k].evaluar(ambiente.getZ(),poblacion[j][n].obtFenotipo().x,poblacion[j][n].obtFenotipo().y))
                {
                    mejorI= poblacion[j][n];
                    //cout << "\nA ver: " << ( poblacion[j][n].obtFenotipo().x*RandomXORShft(rand()).randFloat() )/100 << endl;
                    //cout << "A ver2: " << ( poblacion[j][n].obtFenotipo().y*RandomXORShft(rand()).randFloat() )/100 << endl;
                    cout<<endl;
                    break;

                }
            }
        }
    }

    cout <<"El mejor individuo \n"<< mejorI.imprimir();

    int entK= mejorI.binDec(mejorI.obtGenotipo().cromosomas);

    kGaus= ajbjx[0]+ entK * ( (ajbjx[1]-ajbjx[0]) / (pow(2, (numBits[0]+numBits[1])-1)) );
    mLin= ajbjx[0]+ mejorI.obtFenotipo().x * ( (ajbjx[1]-ajbjx[0]) / (pow(2, numBits[0]-1)) );
    b= ajbjy[0]+ mejorI.obtFenotipo().y * ( (ajbjy[1]-ajbjy[0]) / (pow(2, numBits[1]-1)) );


    cout << "kGaus: " << kGaus << endl;
    cout << "mLin: " << mLin << endl;
    cout << "b: " << b << endl;
    cout << "mGaus: " << mGaus << endl;


    
    t1 = clock();
    
    //cout<< "La funcion Gaussiana es : y=e^(-" << ValorDeiteracion << "(-"<< m << "+x)^2)";
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de procesamiento: " << tiempo << "s" << endl;


    


    return 0;
}