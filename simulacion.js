// var boton_puntos = document.getElementById('btn-puntos');

// boton_puntos.addEventListener('click', ()=> {

//     var figura = document.getElementById('figura-select');

//     //Referencia del Canvas
//     var canvas = document.getElementById('simulacion-canvas');
//     var width = canvas.width;
//     var height = canvas.height;

//     var lista_coords = [];

//     if(figura.value == 'Rectangulo') {
        
//         let coord1_X = document.getElementById('Rec-Coord1-X').value;
//         let coord1_Y = document.getElementById('Rec-Coord1-Y').value;
//         let coord2_X = document.getElementById('Rec-Coord2-X').value;
//         let coord2_Y = document.getElementById('Rec-Coord2-Y').value;

//         lista_coords.push(coord1_X);
//         lista_coords.push(coord1_Y);
//         lista_coords.push(coord2_X);
//         lista_coords.push(coord2_Y);

//     }
//     else if(figura.value == 'Circulo') {

//         let coord1_X = document.getElementById('Circ-Coord1-X').value;
//         let coord1_Y = document.getElementById('Circ-Coord1-Y').value;
//         let radio = document.getElementById('radio').value;

//         lista_coords.push(coord1_X);
//         lista_coords.push(coord1_Y);
//         lista_coords.push(radio);

//     }

//     if(lista_coords.length == 4) {

//         var rec = canvas.getContext('2d');
    
//         rec.fillStyle = "#ffffff";
    
//         var x = lista_coords[0];
//         var y = lista_coords[1];
//         var rec_width = lista_coords[2] - lista_coords[0];
//         var rec_height = lista_coords[3] - lista_coords[1];
    
//         rec.fillRect(x,y,rec_width,rec_height);  

//     }
//     else if(lista_coords.length == 3) {

//         var circulo = canvas.getContext('2d');

//         circulo.fillStyle = "#ffffff";

//         var x = lista_coords[0];
//         var y = lista_coords[1];
//         var radio = lista_coords[2];

//         circulo.beginPath();
//         circulo.arc(x ,y, radio, 0, Math.PI*2);
//         circulo.fill();
//         circulo.stroke();
        
//     }


//     //Configuracion de puntos aleatorios
//     var radio_puntos_aleatorios = 1;
//     var num_puntos_aleatorios = document.getElementById('cantidad_aleatorios').value;

//     var max_width = width  - radio_puntos_aleatorios;
//     var max_height = height - radio_puntos_aleatorios;
    
//     var punto = canvas.getContext('2d');
//     for(let i = 0; i<num_puntos_aleatorios; i++) {

//         var centro_x = Math.floor(Math.random() * max_width);
//         var centro_y = Math.floor(Math.random() * max_height);
    
//         punto.fillStyle = "red";
//         punto.beginPath();
//         punto.arc(centro_x, centro_y, radio_puntos_aleatorios, 0, Math.PI*2);
//         punto.fill();
//         punto.stroke();

//     }


// });

