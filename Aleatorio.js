export class Aleatorio{
    constructor(arrayCoord, pantTamX, pantTamY, numPuntos){
        this.defTamVentana(pantTamX, pantTamY);
        this.nPuntos = numPuntos;
        this.rangoPos = [];
        this.rangoNeg = [];

        if(arrayCoord.length==4)
            this.genRectNums(arrayCoord[0], arrayCoord[1], arrayCoord[2], arrayCoord[3]);
        else if(arrayCoord.length==3)
            this.genCircNums(arrayCoord[0], arrayCoord[1], arrayCoord[2]);
        else if(arrayCoord.length==8){
            console.log("Es un marco");
        }
        else
            console.log("Error de coordenadas");
    }

    //V E N T A N A//////////////////////////////////////////////////////////////////
    //Definición del tamaño de ventana
    defTamVentana(tamX, tamY){
        this.tamX= tamX;
        this.tamY= tamY;
    }
    /////////////////////////////////////////////////////////////////////////////////



    //R E C T Á N G U L O////////////////////////////////////////////////////////////
    //Cuadro ingresado con x1, y1 y x2, y2
    genRectNums(x1, y1, x2, y2){
        this.numGeneradosR= [];
        var x, y, bndPos=0;
        
        for(var i=0; i<this.nPuntos; i++){
            bndPos= 0; //Suponemos que el punto está dentro
            x= Math.random()*this.tamX;
            y= Math.random()*this.tamY;
            if(x>Math.min(x1, x2) && x<Math.max(x1, x2) && y>Math.min(y1, y2) && y<Math.max(y1, y2)){
                bndPos=1;
                this.rangoPos.push([x,y]);
            }
            else{
                bndPos=-1;
                this.rangoNeg.push([x,y])
            }

            this.numGeneradosR.push([[x, y], bndPos]);
        }
    }

    obtenerNumerosRectangulo(){
        return this.numGeneradosR;
    }
    /////////////////////////////////////////////////////////////////////////////////



    //C Í R C U L O//////////////////////////////////////////////////////////////////
    //Círculo ingresado con x, y, r
    genCircNums(h, k, r){
        this.numGeneradosC= [];
        var x, y, bndPos=0;

        for(var i=0; i<this.nPuntos; i++){
            x= Math.random()*this.tamX;
            y= Math.random()*this.tamY;

            if(Math.pow(x-h, 2) + Math.pow(y-k, 2) < r*r){
                bndPos= 1;
                this.rangoPos.push([x,y]);
            }
            else{
                bndPos= -1;
                this.rangoNeg.push([x,y]);
            }
               
            this.numGeneradosC.push([[x, y], bndPos]);
        }
    }

    obtenerNumerosCirculo(){
        return this.numGeneradosC;
    }
    /////////////////////////////////////////////////////////////////////////////////


    printArray(arreglo){
        for(var i=0; i<arreglo.length; i++)
            console.log(arreglo[i]);
    }

}


//MAIN
var tamXPant=6;
var tamYPant=5;
var coordRec= [1, 3, 4, 1]; //x1, y1, x2, y2
var coordCir= [3, 2, 1]; //x, y, r
//var coordMar= [2, 2, 3, 3, 1, 1, 4, 4]; //(x1, y1, x2, y2)<=interior, (x3, y3, x4, y4)<=exterior
var numDePuntos= 5;

/*al= new Aleatorio(coordRec, tamXPant, tamYPant, numDePuntos);
generados= al.obtenerNumerosRectangulo();
al.printArray(generados);
var pos=0, neg=0;
for(var i=0; i<generados.length; i++){
    if(generados[i][1]<0)
        neg+=1;
    else
        pos+=1;
}
console.log();
console.log("Positivos: "+pos);
console.log("Negativos: "+neg);*/

/*al= new Aleatorio(coordCir, tamXPant, tamYPant, numDePuntos);
generados= al.obtenerNumerosCirculo();
al.printArray(generados);
var pos=0, neg=0;
for(var i=0; i<generados.length; i++){
    if(generados[i][1]<0)
        neg+=1;
    else
        pos+=1;
}
console.log();
console.log("Positivos: "+pos);
console.log("Negativos: "+neg);*/



