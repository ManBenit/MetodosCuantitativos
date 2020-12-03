const nj = require('@aas395/numjs');

class Particle{
    constructor(figura,rango){
        this.figure = figura;       // Figura a hacer
        this.length = 0
        this.rango = rango
        /*
            position
            r = (x1,y1,x2,y2)
            c = (x,y,r)
        */
        this.position = [];     // Posicion de la particula
        this.velocity = [];     // Velocidad de particula
        switch(figura){
            case 'r':               // Rectángulo
                this.length = 4;
                this.initRect();
            break;
            case 'c':               // Ciruculo
                this.length = 3;
                this.initCirc();
            break;
        }
        this.position = nj.array(this.position);    // Se pasa de Array a Numjs
        this.velocity = nj.array(this.velocity);
        this.score = 0;
        this.diference = 0;
        this.best_score = 0;   // Mejor puntuacion 
        this.best_dif_area = 100e10; // Mejor area
        this.bp = nj.zeros(this.length)   // Vector de posicion con mejor puntacion
    }

    initRect(){
        for(let i=0;i<this.length;i++){
            this.position[i] = Math.random()*this.rango;   // Posicion aleatorio
            this.velocity[i] = Math.random();       // Velocidad aleatorio
        }
        // Se ordenan las coordenadas con las restricciones de un rectangulo
        if(this.position[0] > this.position[2]){
            let aux = this.position[0];
            this.position[0] = this.position[2];
            this.position[2] = aux;
        }
        if(this.position[1] < this.position[3]){
            let aux = this.position[1];
            this.position[1] = this.position[3];
            this.position[3] = aux;
        }
    }

    initCirc(){
        for(let i=0;i<this.length-1;i++){
            this.position[i] = Math.random()*this.rango;   // Posicion aleatorio
            this.velocity[i] = Math.random();       // Velocidad aleatorio
        }
        this.position[this.length-1] = Math.random()*(this.rango/2);
        this.velocity[this.length-1] = Math.random();
    }

    // funcion para calcular el puntaje de la paticula
    score_function(p,q,area){
        // Función objetivo
        this.score = (this.countPoints(p,q));// + 0.2*Math.abs(area - this.getArea());
        let area_2 = this.getArea();
        this.diference = Math.abs(area - area_2);
        this.score = 0.9 * this.score - 0.1 * this.diference; 
        if(this.score>this.best_score /*&& this.diference<this.best_dif_area*/){   // Maximizar coincidencia en puntos
            this.best_score = this.score;
            this.bp = this.position;
            this.best_dif_area = this.diference;
        }
    }

    // Obtiene el area de la particula
    getArea(){
        let result = 0;
        switch(this.figure){
            case 'r':
                let w = (this.position.get(2) - this.position.get(0));
                let h = (this.position.get(1) - this.position.get(3));
                result = w*h;
            break;
            case 'c':
                result = Math.PI*Math.pow(this.position.get(2),2);
            break;
        }
        return result;
    }

    // Cuenta los puntos que coinciden con el area de la particula
    countPoints(pos,neg){
        let aciertos = 0;
        switch(this.figure){
            case 'r':
                aciertos = this.rectPoints(pos,neg);
            break;
            case 'c':
                aciertos = this.circPoints(pos,neg);
            break;
        }
        return aciertos;
    }

    rectPoints(pos,neg){
        /*
            En esta funcion se cuentan los puntos positivos que coinciden,
            es decir, los que están dentro de la particula iguales a la figura original.
            Y se cuentan los puntos negativos que coinciden, es decir, los puntos
            que tiene por igual la particula y la figura original.
        */
        let x1 = this.position.get(0);
        let y1 = this.position.get(1);
        let x2 = this.position.get(2);
        let y2 = this.position.get(3);
        let coin = 0;
        
        // Puntos positivos
        for(let point of pos){
            if(point[0]>Math.min(x1, x2) && point[0]<Math.max(x1, x2) && point[1]>Math.min(y1, y2) && point[1]<Math.max(y1, y2))
                coin++;
        }
        // Puntos negativos
        for(let point of neg){
            if((point[0]<Math.min(x1, x2) || point[0]>Math.max(x1, x2)) && (point[1]<Math.min(y1, y2) || point[1]>Math.max(y1, y2)))
                coin++;
        }
        return coin;
    }

    circPoints(pos,neg){
        /*
            En esta funcion se cuentan los puntos positivos que coinciden,
            es decir, los que están dentro de la particula iguales a la figura original.
            Y se cuentan los puntos negativos que coinciden, es decir, los puntos
            que tiene por igual la particula y la figura original.
        */
        let h = this.position.get(0);
        let k = this.position.get(1);
        let r = this.position.get(2);
        let coin = 0;
        for(let point of pos){
            if(Math.pow(point[0]-h, 2) + Math.pow(point[1]-k, 2) < r*r)
                coin++;
        }
        for(let point of neg){
            if(Math.pow(point[0]-h, 2) + Math.pow(point[1]-k, 2) > r*r)
                coin++;
        }
        return coin;
    }

    /*
        Calcular la velocidad de la particula
        v=α(bp−p)+β(gbp−p)
        v=v+[α*rand1*(bp−p)]+[β*rand2*(gbp−p)]
    */
    calculate_velocity(gbp,alpha,beta){
        let ran;
        ran = Math.random();
        let a = (this.bp.subtract(this.position)).multiply(alpha*ran);
        ran = Math.random();
        let b = (nj.array(gbp).subtract(this.position)).multiply(beta*ran);
        this.velocity = this.velocity.add(a.add(b));
        this.position = this.position.add(this.velocity);
    }
}

export class PSO{
    constructor(num,genera,figura,rango){
        this.figure = figura;       // Figura a aprender
        this.best_score = -100e10;        // Mejor puntaje
        this.gbp = []               // Mejor posicion global
        this.num_population = num;  // Tamanio de la poblacion
        this.population = [];       // particles
        this.generations = genera;  // Numero de genraciones
        this.rango = rango          // Rango de ventana
        this.three_best_in_generation = [];  // Los mejores tres en la generación [posicion, score]
    }

    run_pso(positives,negatives,areaFig,ra1,ra2){
        var scores = [];        // Puntuaciones de la particula [score,posicion]
        var best_scores = [];   // Mejores puntuaciones
        var i;
        // Generación de la poblacion
        for(i=0;i<this.num_population;i++)
            this.population.push(new Particle(this.figure,this.rango));
        
        // Corriendo el algoritmo
        i=0;
        while(i<this.generations){
            // Se calcula el socre de cada particula
            for(let p of this.population){
                p.score_function(positives,negatives,areaFig);
                scores.push([p.score,p.position,p.getArea()]);
            }
            /*
                Obtenemos el mejor puntaje de la poblacion
                Maximizar el problema
                Se ordena la puntuación mayor a la menor
            */
            scores.sort((aa,bb)=>{
                let a = aa[0];
                let b = bb[0];
                return b-a;
            });
            best_scores.push(scores[0][0]);
            if(scores[0][0]>this.best_score){
                this.best_score = scores[0][0];
                this.gbp = scores[0][1];
            }
            this.three_best_in_generation.push([[scores[0][1].tolist(),scores[0][0],scores[0][2]],
                                                [scores[1][1].tolist(),scores[1][0],scores[1][2]],
                                                [scores[2][1].tolist(),scores[2][0],scores[2][2]]])
            // Calculamos las velocidades de cada particula
            for(let p of this.population)
                p.calculate_velocity(this.gbp,ra1,ra2);
            scores = [];
            i++;
        }
    }
}