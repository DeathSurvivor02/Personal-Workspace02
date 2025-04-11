let images = [];
let currentIndex = 0;
let timer = null;

// Load image list from JSON using Fetch API
async function loadImageList(file) {
  try {
    const response = await fetch(file);
    const data = await response.json();
    images = data.images;
    currentIndex = 0;
    showImage();
  } catch (error) {
    console.error("Failed to load image list:", error);
  }
}

// Show one image with animation and set timer for next
function showImage() {
  if (images.length === 0) return;

  clearTimeout(timer);
  const current = images[currentIndex];
  const imgElement = $("#gallery-image");

  imgElement.fadeOut(1000, function () { // Increased fade-out duration to 1000ms
    imgElement
      .attr("src", current.filename)
      .on("error", function () {
        console.error("Image not found:", current.filename);
        $(this).attr("src", "images/placeholder.jpg"); // Fallback image
      })
      .fadeIn(2000); // Increased fade-in duration to 1000ms
  });

  timer = setTimeout(() => {
    nextImage();
  }, current.displayTimeMs + 2000); // Added extra time to account for slower transitions
}

// Show next image
function nextImage() {
  currentIndex = (currentIndex + 1) % images.length;
  showImage();
}

// Show previous image
function prevImage() {
  currentIndex = (currentIndex - 1 + images.length) % images.length;
  showImage();
}

// Set up event listeners
$(document).ready(() => {
  loadImageList("image_list.json");

  $("#next-btn").click(() => nextImage());
  $("#prev-btn").click(() => prevImage());
  $("#load-btn").click(() => loadImageList("image_list2.json"));
});
