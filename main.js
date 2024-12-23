const endpoint = "http://192.168.100.244";
function getKamar() {
  fetch(endpoint + "/kamar", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledKamar.style.background = "red";
        imgKamar.src = "./assets/led-on.png";
        ledKamar.text = "Turn On";

      } else {
        ledKamar.style.background = "blue";
        imgKamar.src = "./assets/led-off.png";
        ledKamar.text = "Turn OFF";

      }
    });
}

function getDapur() {
  fetch(endpoint + "/dapur", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledDapur.style.background = "red";
        ledDapur.src = "./assets/led-on.png";
        ledDapur.text = "Turn ON";

      } else {
        ledDapur.style.background = "blue";
        imgDapur.src = "./assets/led-off.png";
        ledDapur.text = "Turn OFF";

      }
    });
}

function getDepan() {
  fetch(endpoint + "/depan", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledDepan.style.background = "red";
        imgDepan.src = "./assets/led-on.png";
        ledDepan.text = "Turn ON";

      } else {
        ledDepan.style.background = "blue";
        imgDepan.src = "./assets/led-off.png";
        ledDepan.text = "Turn OFF";

      }
    });
}

function getBelakang() {
  fetch(endpoint + "/belakang", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if (result == "ON") {
        ledBelakang.style.background = "red";
        imgBelakang.src = "./assets/led-on.png";
        ledBelakang.text="Turn ON"
      } else {
        ledDepan.style.background = "blue";
        imgDepan.src = "./assets/led-off.png";
        ledBelakang.text="Turn OFF"

      }
    });
}

function setKamar() {
  fetch(endpoint + "/kamar", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => {
      location.reload();
    });
}
function setDapur() {
  fetch(endpoint + "/dapur", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => {
      location.reload();
    });
}
function setDepan() {
  fetch(endpoint + "/depan", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => {
      location.reload();
    });
}
function setBelakang() {
  fetch(endpoint + "/belakang", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => {
      location.reload();
    });
}

getKamar();
getBelakang();
getDepan();
getDapur();
