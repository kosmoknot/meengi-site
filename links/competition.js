var cur = 0;
let qBank = [
  {
    qst: "What is inside the scam can?",
    ans: "fleabagtshirt",
    img: "2",
  },
  { qst: "Name this exquisite place", ans: "coromandelcafe", img: "" },
];

function checkAnswer() {
  console.log("check!");
  var curAns = document.getElementById("ans").value;
  if (curAns == qBank[cur].ans) {
    document.getElementById("status").src = "correct";
    cur++;
    time;
    document.getElementById("qst");
  }
}

function wait(time) {
  return new Promise((resolve) => {
    setTimeout(resolve, time);
  });
}

const yourFunction = async () => {
  await wait(5000);
  console.log("Waited 5s");

  await wait(5000);
  console.log("Waited an additional 5s");
};
