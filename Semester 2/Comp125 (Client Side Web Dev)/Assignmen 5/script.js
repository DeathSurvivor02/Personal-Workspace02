

// canvas Creation
var canvas = document.createElement("canvas");
var ctx= canvas.getContext("2d");   //!unsre
canvas.width = 900;
canvas.height = 600;
document.body.appendChild(canvas);

// description: Background Image
var bgReady = false;
var bgImage = new Image();
bgImage.onload = function(){
    bgReady = true;
};
bgImage.src = "background.png";

//game objects 
var squish = 
{
    x: 0,
    y: 0
}
var squishCaught = 0;


//~ Player input (Touch input)
document.addEventListener("click", function (event) {
    const target = document.getElementById("yourElementId"); // Replace with your element's ID
    if (target && target.contains(event.target)) {
        console.log("Clicked on the object!");
    }
});



document.addEventListener("click", function(event)
{

});


// Update game objects  
 var update  =  function ( modifier)
 {

 }