function redeemCode() {
  var code = document.getElementById("code").value;
  if (code == "HBAV2024") {
    console.log("success");
    window.location.href = "../links/bday.pdf";
  }
}
