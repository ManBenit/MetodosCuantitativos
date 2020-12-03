
var figura = document.getElementById('figura-select');
var boton_puntos = document.getElementById('btn-puntos');

var grupo_rectangulo = document.getElementById('rectangle-group');
var grupo_circulo = document.getElementById('circle-group');
var grupo_marco = document.getElementById('frame-group');

figura.addEventListener('change', ()=>{

    document.getElementById('Puntos').style.display = "block";

    switch(figura.value) {

        case 'Rectangulo':
            grupo_circulo.style.display = "none";
            grupo_marco.style.display = "none";
            grupo_rectangulo.style.display = "block";
        break;

        case 'Circulo':
            grupo_rectangulo.style.display = "none";
            grupo_marco.style.display = "none";
            grupo_circulo.style.display = "block";
        break;

        case 'Marco':
            grupo_rectangulo.style.display = "none";
            grupo_circulo.style.display = "none";
            grupo_marco.style.display = "block";
        break;

        default:
            console.log('No existe esa opción.');
    }
});



// boton_puntos.addEventListener('click', ()=>{

//     document.getElementById('Evolutivo').style.display = "block";
// });

