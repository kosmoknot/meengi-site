$Header()$
<script src="../links/competition.js"></script>

<h1>Here We Go!</h1>
$ArticleStart()$

<p style="text-align:center;" id="qst">Are you ready?</p>

<img id="img" style="display: block;margin-left: auto;margin-right: auto;" width="350" src="/links/images/Books.png"></img><br>
<div style="text-align: center;display:none;" id="gift">
<a href="../links/bday.pdf">Here is your gift as promised!</a>
</div>
<div style="text-align:center;" id="answerDiv">

Answer: <input id="ans"></input>

<button id="checkButton" onclick="checkAnswer()">Check</button>

<img style="margin-left:10px; vertical-align: middle;" width="40" id="statusImg" src="/links/images/bday/correct.png"></img>

<br>
<br>
<b style="text-align: center;">All small no space, enjoy the fireworks!</b>
<br>
<i style="text-align: center;">For any hints please contact on +91-9923774284</i> <br>
</div>
<canvas style="display: block;position: fixed;top: 0;left: 0;width: 100%;height: 100%;z-index: -1;"id="fireworksCanvas"></canvas>
<script src="../links/fireworks.js"></script>
<script>checkAnswer();</script>
$ArticleEnd()$
$Footer()$