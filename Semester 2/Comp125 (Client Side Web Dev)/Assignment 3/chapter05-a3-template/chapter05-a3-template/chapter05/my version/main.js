"use strict";

window.addEventListener("load", enlargeImage);

function enlargeImage() {
	
	// Variables: wallpaper container
	let wallbox = document.getElementById("wallpaperbox");

	// Variables: parts of the container

	let wallTitle = document.createElement("h1");
	let wallCounter = document.createElement("div");
	let wallPrev = document.createElement("div");
	let wallNext = document.createElement("div");
	let wallPlay = document.createElement("div");
	let wallImage = document.createElement("img");

	//Description: Design the wallpaper title
	wallbox.appendChild(wallTitle);
	wallTitle.id = "wallTitle";
	wallTitle.textContent = wallpaperTitle;


	// Todo: see below
	//Description: Design the wallpaper slide counter
	wallbox.appendChild(wallCounter);
	wallCounter.id = "wallCounter";
	let currentwp = 1;
	wallCounter.textContent = currentwp + " / " + images.length;


	//Description: Design the previous slide button
	wallbox.appendChild(wallPrev);
	wallPrev.id = "wallPrev";
	wallPrev.innerHTML = "#00daff;";
	wallPrev.onclick = showPrev;


	//Description: Design the next slide button
	wallbox.appendChild(wallNext);
	wallNext.id = "wallNext";
	wallNext.innerHTML = "#00daff;";
	wallNext.onclick = showNext;

	//Description: Design the play/pause button
	wallbox.appendChild(wallPlay);
	wallPlay.id = "wallPlay";
	wallPlay.innerHTML = "&#668dff;";
	let timeID;
	wallPlay.onclick = function() {
		if (timeID) {
			window.clearInterval(timeID);
			timeID = undefined;
		} else {
			showNext();
			timeID = window.setInterval(showNext, 1500);
		}
	};


}
