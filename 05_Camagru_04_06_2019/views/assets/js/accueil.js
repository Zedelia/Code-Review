function timeDifference(current, previous, offset) {
	var msPerMinute = 60 * 1000;
	var msPerHour = msPerMinute * 60;
	var msPerDay = msPerHour * 24;
	var msPerMonth = msPerDay * 30;
	var msPerYear = msPerDay * 365;
	var elapsed = current - previous;
	var timezone = new Date (elapsed);
	if (timezone < msPerMinute) {
		if(Math.round(timezone / 1000) == 1)
			return 'Il y a ' + Math.round(timezone / 1000) + ' seconde';
		else
			return 'Il y a ' + Math.round(timezone / 1000) + ' secondes';
	}
	else if (timezone < msPerHour) {
		if (Math.round(timezone / msPerMinute) == 1)
			return 'Il y a ' + Math.round(timezone / msPerMinute) + ' minute';
		else
			return 'Il y a ' + Math.round(timezone / msPerMinute) + ' minutes';
	}
	else if (timezone < msPerDay) {
		if(Math.round(timezone / msPerHour) == 1)
			return 'Il y a ' + Math.round(timezone / msPerHour) + ' heure';
		else
			return 'Il y a ' + Math.round(timezone / msPerHour) + ' heures';
	}
	else if (timezone < msPerMonth) {
		if(Math.round(timezone / msPerDay) == 1)
		return 'Il y a environ ' + Math.round(timezone / msPerDay) + ' jour';
		else
			return 'Il y a environ ' + Math.round(timezone / msPerDay) + ' jours';
	}
	else if (timezone < msPerYear) {
		return 'Il y a environ ' + Math.round(timezone / msPerMonth) + ' mois';
	}
	else {
		if (Math.round(timezone / msPerYear) == 1)
			return 'Il y a environ ' + Math.round(timezone / msPerYear) + ' an';
		else
			return 'Il y a environ ' + Math.round(timezone / msPerYear) + ' ans';
	}
}
function load(url, element) {
    req = new XMLHttpRequest();
    req.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
			element.innerHTML = req.responseText;
			
			var now = new Date(Date.now()).getTime();
			var offset = new Date(Date.now()).getTimezoneOffset();

			var timestamp = element.getElementsByClassName("timestamp");
			for (var i = 0; i < timestamp.length; i++) {
				var date = timestamp[i].innerHTML;

				var t = date.split(/[- :]/);
				var d = new Date(Date.UTC(t[0], t[1]-1, t[2], t[3], t[4], t[5]));
				d = d.getTime();

				timestamp[i].innerHTML = timeDifference(now, d, offset);
			}
        }
    };
    req.open("GET", url, true);
    req.send(null); 
}

function close_modal(){
    modal = document.getElementById("modal").classList.remove("is-active");
    document.body.classList.remove("is-clipped");
}

function open_modal(id){
    load("/index.php/Profile/picture/" + id, document.getElementById("picture_modal"));
    document.getElementById("modal").classList.add("is-active");
    document.body.classList.add("is-clipped");
}
function like(id){
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
	if (this.readyState == 4 && this.status == 200) {
		element = document.getElementById("picture_modal");
		element.innerHTML = this.responseText;
		var now = new Date(Date.now()).getTime();
		var offset = new Date(Date.now()).getTimezoneOffset();

		var timestamp = element.getElementsByClassName("timestamp");
		for (var i = 0; i < timestamp.length; i++) {
			var date = timestamp[i].innerHTML;

			var t = date.split(/[- :]/);
			var d = new Date(Date.UTC(t[0], t[1]-1, t[2], t[3], t[4], t[5]));
			d = d.getTime();

			timestamp[i].innerHTML = timeDifference(now, d, offset);
		}
	}
	};
	xhttp.open("GET", '/index.php/Profile/picture/' + id + '?like=true', true);
	xhttp.send();
}

function unlike(id){
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
	if (this.readyState == 4 && this.status == 200) {
		element = document.getElementById("picture_modal");
		element.innerHTML = this.responseText;
		var now = new Date(Date.now()).getTime();
		var offset = new Date(Date.now()).getTimezoneOffset();

		var timestamp = element.getElementsByClassName("timestamp");
		for (var i = 0; i < timestamp.length; i++) {
			var date = timestamp[i].innerHTML;

			var t = date.split(/[- :]/);
			var d = new Date(Date.UTC(t[0], t[1]-1, t[2], t[3], t[4], t[5]));
			d = d.getTime();

			timestamp[i].innerHTML = timeDifference(now, d, offset);
		}
	}
	};
	xhttp.open("GET", '/index.php/Profile/picture/' + id + '?unlike=true', true);
	xhttp.send();
}

function delete_picture(id){
	if ( confirm( "Êtes vous sur de vouloir supprimer cette image ? Cette action est irreversible." ) ) {
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
			document.location.reload();
		}
		};
		xhttp.open("GET", '/index.php/Profile/picture/' + id + '?delete=true', true);
		xhttp.send();
	}
}

function comment(id)
{
	var comment = encodeURIComponent(document.getElementById('comment_content').value.trim());
	if(comment!= '')
	{
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200) {
			element = document.getElementById("picture_modal");
			element.innerHTML = this.responseText;
			var now = new Date(Date.now()).getTime();
			var offset = new Date(Date.now()).getTimezoneOffset();

			var timestamp = element.getElementsByClassName("timestamp");
			for (var i = 0; i < timestamp.length; i++) {
				var date = timestamp[i].innerHTML;

				var t = date.split(/[- :]/);
				var d = new Date(Date.UTC(t[0], t[1]-1, t[2], t[3], t[4], t[5]));
				d = d.getTime();

				timestamp[i].innerHTML = timeDifference(now, d, offset);
			}
		}
		};
		xhttp.open("GET", '/index.php/Profile/picture/' + id + '?comment=' + comment, true);
		xhttp.send();
	}
}

function key_comment(event, id)
{
	key = event.keyCode;
	textarea = document.getElementById('comment_content');
	button = document.getElementById('button_comment');
	if(textarea.value != '')
	{
		if(key == 91)
			comment(id);
		
		button.disabled = false;
	}
	else
		button.disabled = true;
}