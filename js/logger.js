Logger = function () {
	
	this.msg_counter = 0;
	this.html = document.getElementById('log');
	
	this.log_implant = function (implant_out, implant_in) {
		if (implant_out != null && implant_in != null) {
			var msg = "[" + (++this.msg_counter) + "] " + implant_out.name + " [ql" + implant_out.slotted_with_ql + "/" + implant_out.slotted_with_req + "] swapped with " + implant_in.name + " [ql" + implant_in.slotted_with_ql + "/" + implant_in.slotted_with_req + "].";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else if (implant_out != null && implant_in == null) {
			var msg = "[" + (++this.msg_counter) + "] " + implant_out.name + " [ql" + implant_out.slotted_with_ql + "/" + implant_out.slotted_with_req + "] removed.";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else if (implant_out == null && implant_in != null) {
			var msg = "[" + (++this.msg_counter) + "] " + implant_in.name + " [ql" + implant_in.slotted_with_ql + "/" + implant_in.slotted_with_req + "] equipped.";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else {alert('else');}
		this.html.scrollTop = this.html.scrollHeight;
	}
	
	this.log_item = function (item_out, item_in) {
		if (item_out != null && item_in != null) {
			var msg = "[" + (++this.msg_counter) + "] " + item_out.name + " swapped with " + item_in.name + ".";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else if (item_out != null && item_in == null) {
			var msg = "[" + (++this.msg_counter) + "] " + item_out.name + " removed.";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else if (item_out == null && item_in != null) {
			var msg = "[" + (++this.msg_counter) + "] " + item_in.name + " equipped.";
			var p = document.createElement('p');
			p.innerHTML = msg;
			this.html.appendChild(p);
		}
		else {alert('else');}
		this.html.scrollTop = this.html.scrollHeight;
	}
	
	this.custom_msg_keydown = function (event) {
		if (event.keyCode == 13 && document.getElementById('custom_msg').value != "") {
			var p = document.createElement('p');
			p.innerHTML = "[" + (++this.msg_counter) + "] " + document.getElementById('custom_msg').value;
			document.getElementById('custom_msg').value = "";
			this.html.appendChild(p);
		}
	}
	
	this.delete_last_entry = function () {
		if (this.msg_counter !== 0) {
			this.html.removeChild(this.html.getElementsByTagName('p')[--this.msg_counter]);
		}
	}
}