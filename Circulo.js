import { Coordenada } from "./Coordenada";  // Importamos la clase coordenada

export class Circulo{
    constructor(x,y,r){
        this.origin = new Coordenada(x,y)
        this.r = r;
    }

    getOrigin(){
        return this.origin;
    }

    getArea(){
        return Math.PI*Math.pow(this.r,2);
    }
}