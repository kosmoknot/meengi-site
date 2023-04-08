var answers = {
  "21p1": "2689c3565458bf11077f0a27089791f01f435e28b28da9e844632d034778a2a6",
  "21p2": "de2e69bcace528b5da282acc9f99cfe2794d7d242ce67b64b457baf87214c336",
};

const colCorrect = "#baffc9";
const colIncorrect = "#ffb3ba";

function CheckEnigmaAnswer() {
  var button = event.target;
  var id = button.parentElement.id;
  var input = button.parentElement.getElementsByClassName("EnigmaAnswer")[0];

  if (CryptoJS.SHA256(input.value) == answers[id]) {
    input.style.backgroundColor = colCorrect;
  } else {
    input.style.backgroundColor = colIncorrect;
  }
}
