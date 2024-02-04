function restartGame() {
    var canvas = document.getElementById("8ball");
    var defaultIntensity = 10; // Default intensity
    var shakeDuration = 2000; // 2 seconds
    var imageChangeDelay = 2000; // 2 seconds delay before changing the image
    var startTime = null;
    const goButton = document.getElementById("startButton");
    const restartButton = document.getElementById("waitingButton");

    // Preload alternative images
    var alternativeImages = [
        "8BallYes.png",
        "8BallNo.png",
        "8BallPerhaps.png",
        "8BallAgain.png",
        "8BallNotToday.png",
        "8BallNotObviously.png"
    ];

    // Set the default intensity
    var shakeIntensity = defaultIntensity;

    function preloadAlternativeImage() {
        var randomIndex = Math.floor(Math.random() * alternativeImages.length);
        var alternativeImage = new Image();
        alternativeImage.src = alternativeImages[randomIndex];
        return alternativeImage.src;
    }

    function shakeBall(timestamp) {
        if (!startTime) {
            startTime = timestamp;
            canvas.style.backgroundImage = "url('8BallEmpty.png')";
            goButton.style.display = "none";
            restartButton.style.display = "inline-block";
            // Wait for 2 seconds before changing the background image
            setTimeout(function () {
                // Preload an alternative image and set it as the background
                var alternativeImagePath = preloadAlternativeImage();
                canvas.style.backgroundImage = "url('" + alternativeImagePath + "')";
            }, imageChangeDelay);
        }

        var progress = timestamp - startTime;
        var completionRatio = Math.min(progress / shakeDuration, 1);

        var randomX = (Math.random() - 0.5) * shakeIntensity * 2; // Adjust the intensity of the shake in the X axis
        var randomY = (Math.random() - 0.5) * shakeIntensity * 2; // Adjust the intensity of the shake in the Y axis

        canvas.style.position = "relative";
        canvas.style.left = randomX + "px";
        canvas.style.top = randomY + "px";

        if (completionRatio < 1) {
            requestAnimationFrame(shakeBall);
        } else {
            canvas.style.position = "static";
            canvas.style.left = "0px";
            canvas.style.top = "0px";
            goButton.style.display = "inline-block";
            restartButton.style.display = "none";

            startTime = null;
        }
    }

    requestAnimationFrame(shakeBall);
}
