
(function(){

	var width = 560;
	var height = 0;
	var streaming = false,
	video = null,
	canvas = null,
	photo = null,
	startbutton = null;

	function startup(){
		video = document.querySelector('#video'),
		canvas = document.querySelector('#canvas'),
		photo = document.querySelector('#photo'),
		startbutton = document.querySelector('#startbutton'),

		navigator.getMedia = (navigator.getUserMedia ||
			navigator.webkitGetUserMedia ||
			navigator.mozGetUserMedia ||
			navigator.msGetUserMedia);

			navigator.getMedia(
				{
					video: true,
					audio: false
				},
				function(stream){
					if (navigator.mozGetUserMedia){
						video.mozSrcObject = stream;
					}
					else{
						var vendorURL = window.URL || window.webkitURL;
						video.src = vendorURL.createObjectURL(stream);
					}
					video.play();
				},
				function(err){
					console.log("An error occured! " + err);
				}
			);

	video.addEventListener('canplay', function(ev){
		if (!streaming) {
			height = video.videoHeight / (video.videoWidth/width);
			video.setAttribute('width', width);
			video.setAttribute('height', height);
			canvas.setAttribute('width', width);
			canvas.setAttribute('height', height);
			streaming = true;
		}
	}, false);

	startbutton.addEventListener('click', function(ev){
		takepicture();
		ev.preventDefault();
	}, false);

	clearphoto();
}

	function clearphoto(){
		var context = canvas.getContext('2d');
		context.fillStyle = "#AAA";
		context.fillRect(0, 0, canvas.width, canvas.height);
		var data = canvas.toDataURL('image/png');
		photo.setAttribute('src', data);
	}

	function takepicture(){
		var context = canvas.getContext('2d');
		if (width && height){
		canvas.width = width;
		canvas.height = height;
		context.drawImage(video, 0, 0, width, height);
		var data = canvas.toDataURL('image/png');
		photo.setAttribute('src', data);
	}	else{
		clearphoto();
	}
	}

	window.addEventListener('load', startup, false);
})();
