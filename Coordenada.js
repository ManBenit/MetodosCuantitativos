export class Coordenada{
    constructor(x,y){
        this.x = x;     	// Coordenada X
        this.y = y;     	// Coordeanda Y
		this.distance = 0;  // Distancia de un punto a una coordenada
    }

    getX(){         // Obtener coordenada X
        return this.x;
    }
    
    getY(){         // Obtener coordeanda Y
        return this.y;
    }

    getDistance(centro){
        let x0 = centro.getX();
        let y0 = centro.getY();
        this.distance = Math.sqrt(Math.pow((x0-this.x),2)+Math.pow((y0-this.y),2))
    }
}