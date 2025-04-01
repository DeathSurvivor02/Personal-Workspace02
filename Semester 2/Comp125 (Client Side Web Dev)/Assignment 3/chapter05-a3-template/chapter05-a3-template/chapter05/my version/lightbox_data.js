"use strict";

window.addEventListener("load", createLightbox);

let imgFiles = [
  "./image1.jpg", 
  "./image2.jpg", 
  "./image3.jpg", 
  "./image4.jpg",
  "./image5.jpg"
];

let imgCaptions = new Array(5);
imgCaptions[0] = "Image 1";
imgCaptions[1] = "Image 2"; 
imgCaptions[2] = "Image 3"; 
imgCaptions[3] = "Image 4"; 
imgCaptions[4] = "Image 5";

function createLightbox() {
   let lightBox = document.getElementById("lightbox");
   let lbTitle = document.createElement("h1");
   let lbCounter = document.createElement("div");
   let lbPrev = document.createElement("div");
   let lbNext = document.createElement("div");
   let lbPlay = document.createElement("div");
   let lbImages = document.createElement("div");

   // Design the lightbox title
   lightBox.appendChild(lbTitle);
   lbTitle.id = "lbTitle";
   lbTitle.textContent = "Photo Viewer";

   // Design the lightbox slide counter
   lightBox.appendChild(lbCounter);
   lbCounter.id = "lbCounter"; 
   let currentImg = 1;
   lbCounter.textContent = currentImg + " / " + imgFiles.length;

   // Design the lightbox previous slide button
   lightBox.appendChild(lbPrev);
   lbPrev.id = "lbPrev"; 
   lbPrev.innerHTML = "&#9664;";
   lbPrev.onclick = showPrev;

   // Design the lightbox next slide button
   lightBox.appendChild(lbNext);
   lbNext.id = "lbNext";
   lbNext.innerHTML = "&#9654;";
   lbNext.onclick = showNext;

   // Design the lightbox Play-Pause button
   lightBox.appendChild(lbPlay);
   lbPlay.id = "lbPlay"; 
   lbPlay.innerHTML = "&#9199;";
   let timeID;
   lbPlay.onclick = function() {
      if (timeID) {
         window.clearInterval(timeID);
         timeID = undefined;
      } else {
         showNext();
         timeID = window.setInterval(showNext, 1500);
      }
   }

   // Design the lightbox images container
   lightBox.appendChild(lbImages);
   lbImages.id = "lbImages";
   for (let i = 0; i < imgFiles.length; i++) {
      let image = document.createElement("img");
      image.src = imgFiles[i];
      image.alt = imgCaptions[i];
      image.onclick = createOverlay;
      lbImages.appendChild(image);
   }

   function showNext() {
      lbImages.appendChild(lbImages.firstElementChild);
      (currentImg < imgFiles.length) ? currentImg++ : currentImg = 1;
      lbCounter.textContent = currentImg + " / " + imgFiles.length;
   }

   function showPrev() {
      lbImages.insertBefore(lbImages.lastElementChild, lbImages.firstElementChild);
      (currentImg > 1) ? currentImg-- : currentImg = imgFiles.length;
      lbCounter.textContent = currentImg + " / " + imgFiles.length;
   }

   function createOverlay() {
      let overlay = document.createElement("div");
      overlay.id = "lbOverlay";

      let figureBox = document.createElement("figure");
      overlay.appendChild(figureBox);

      let overlayImage = this.cloneNode(true);
      figureBox.appendChild(overlayImage);

      let overlayCaption = document.createElement("figcaption");
      overlayCaption.textContent = this.alt;
      figureBox.appendChild(overlayCaption);

      let addToFavButton = document.createElement("button");
      addToFavButton.textContent = "Add to Favorites";
      addToFavButton.onclick = addToFavorites;
      figureBox.appendChild(addToFavButton);

      let closeBox = document.createElement("div");
      closeBox.id = "lbOverlayClose";
      closeBox.innerHTML = "&times;";
      closeBox.onclick = function() {
         document.body.removeChild(overlay);
      }
      overlay.appendChild(closeBox);

      document.body.appendChild(overlay);
   }
}

let imgFavourites = [3];

function addToFavorites() {
   const overlayImage = document.querySelector("#lbOverlay figure img");
   const imgSrc = overlayImage.src;
   const imgAlt = overlayImage.alt;
   if (imgFavourites.length < 3) {
      imgFavourites.push({ src: imgSrc, alt: imgAlt });
      updateFavorites(); 
      document.body.removeChild(document.querySelector("#lbOverlay"));
   } else {
      alert("You can only have up to 3 favorites. Remove one favourite first.\nEan Bynoe");
   }
}

function updateFavorites() {
   let favoritesDiv = document.getElementById("favorites");
   favoritesDiv.innerHTML = ''; 

   imgFavourites.forEach(function(fav) {
      let favImg = document.createElement("img");
      favImg.src = fav.src;
      favImg.alt = fav.alt;

      let removeButton = document.createElement("button");
      removeButton.textContent = "Remove";
      removeButton.onclick = function() {
         removeFromFavorites(fav.src);
      };

      let favItem = document.createElement("div");
      favItem.textContent = fav.alt;
      favItem.appendChild(removeButton);

      favoritesDiv.appendChild(favImg);
      favoritesDiv.appendChild(favItem);
   });
}

function removeFromFavorites(imgSrc) {
   imgFavourites = imgFavourites.filter(function(fav) {
      return fav.src !== imgSrc;
   });
   updateFavorites();
}