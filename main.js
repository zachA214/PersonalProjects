
// Define the darkenScreen function
function darkenScreen() {
    var screenMesh = document.getElementById("screenMesh");

    if (screenMesh) {
        screenMesh.style.opacity = 0.75;
        screenMesh.style.transition = "0.75s";
        screenMesh.style.zIndex = 3;
    }
}

// Add an event listener to the side panel for the hover event
document.querySelector('.sidePanel').addEventListener('mouseenter', darkenScreen);

// Define a function to reset styles when the hover ends
function resetScreen() {
    var screenMesh = document.getElementById("screenMesh");

    if (screenMesh) {
        screenMesh.style.opacity = 0;
        screenMesh.style.zIndex = 1;
    }
}

// Add an event listener to the side panel for when the hover ends
document.querySelector('.sidePanel').addEventListener('mouseleave', resetScreen);
