import { Coordenada } from "./Coordenada";  // Importamos la clase coordenada

export class Rectangulo{
    constructor(x1,y1,x2,y2){
        this.superiorIzq = new Coordenada(x1,y1);       // Coordenada superior izquierda
        this.inferiorDer = new Coordenada(x2,y2);       // Coordenada inferior derecha
        this.center = new Coordenada((x1+x2)/2,(y1+y2)/2);
    }

    getSupIzq(){
        return this.superiorIzq;
    }

    getInfDer(){
        return this.inferiorDer;
    }

    getArea(){
        let alto = this.getSupIzq().getY() - this.getInfDer().getY();
        let ancho = this.getInfDer().getX() - this.getSupIzq().getX();
        return (alto*ancho);
    }
}