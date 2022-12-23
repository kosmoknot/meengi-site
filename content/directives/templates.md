// $ChildList(ChildListItem) is a special template.It is used to render the grid.
// Each item in ChildList is rendered as ChildListItem(name). Where name is automatically taken as page name.
// $PageName()$ fetches the name of the current page.
// DO NOT DELETE THESE ------>

// When calling childlist, "items" argument is automatically populated and should not be removed/replaced only pass extra arguments you have added manually when calling the childList like ChildList(5) if you want 5 columnCount in this case
# $ChildList(items,columnCount)
<div class="childlist" style="grid-template-columns: repeat($$columnCount$$,auto);">
$$items$$
</div>
#

# $ChildListItem(name)
<div><a href="$$name$$.html"><figure><img style="width:150px;" alt="$$name$$" onmouseover="onHover();" onmouseleave="onOut()" src="/links/images/$$name$$.png"></figure>$$name$$<caption></caption></a>
</div>
#

# $NavigList(items)
<div class="NavigList">$$items$$
<div class="NavigItem"><a href="Sitemap.html">Sitemap</a></div>
</div>
#

# $NavigItem(name)
<div class="NavigItem"><a href="$$name$$.html">$$name$$</a></div>
#

//Use TreeMapPartial to get treemap starting from current node
# $TreeMap(map)
<ul class="TreeMap">
$$map$$
</ul>
#

//This is the top level title can be customised to look different
# $TreeMapTitle1(name,childMap)
<li id="TreeMapTopLvl"><details open>
<summary><a href="$$name$$.html">$$name$$</a></summary>
<ul>
$$childMap$$
</ul>
</details>
#

//This is used for everything except top level title can be customised to look different
# $TreeMapTitle2(name,childMap)
<li id="TreeMapNotTopLvl"><details open>
<summary><a href="$$name$$.html">$$name$$</a></summary>
<ul>
$$childMap$$
</ul>
</details>
#

//<------ DO NOT DELETE THESE

# $Header():
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="description" content="Digital garden of kosmoknot">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
    <title>kosmoknot - $PageName()$ </title>
    <link rel="icon" href="/links/images/icon.png" type="image/icon type">
    <link href="/links/style.css" rel="stylesheet" type="text/css" media="all">
    <script src="/links/script.js"></script>
</head>
<body>
$NavigList()$
<div class="bodyContainer">
#

# $Footer():
</div>
</body>
<footer>
    <div class="footerContainer">
        <div class="footer">
            <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">
                <img id="cc" alt="Creative Commons License" src="/links/images/creative_commons_min.webp" />
            </a>
            <a rel="meengi" href="https://github.com/kosmoknot/meengi">
                <img id="meengi" src="/links/images/meengi_light.png" />
            </a>
            <a rel="github" href="https://github.com/kosmoknot">
                <img id="git" src="/links//images/github.webp" />
            </a>
            <a rel="neocities" href="https://neocities.org/site/kosmoknot">
                <img id="neo" src="/links/images/neocities.webp" />
            </a>
                <a rel="mastodon" href="https://mas.to/@kosmoknot">
                <img id="masto" src="/links/images/mastadon.png" />
            </a>
        </div>
        <div class="footer_text">
            <p>KosmoKnot Ⓒ 2022 — BY-NC-SA 4.0</p>
        </div>
    </div>
</footer>

</html>
#

# $hr():
<div class="hrcls">
<hr>
</div>
#

# $searchbox():
<div style="text-align: center;">
<input id="searchBox" placeholder="Search.." style="text-align: center; font-size: 18px;" oninput="log_search()">
</div>
#

# $logsListStart(name,description):
<h1>Logs - $$name$$</h1>
<div class="description">
$$description$$
<p id="logsCount"></p>
</div>
$searchbox()$
<div class="logs">
<ol id="logsList">
#

# $logsListEnd():
</ol>
</div>
<script>
showLogCount()
</script>
#

# $logsItemStart(name,details):
<li>
<details>
<summary>
<ins>$$name$$</ins>
<br>$$details$$
</summary>
<p>
#

# $logsBooksItemStart(name,author,language,published,readDate,rating)
<li>
<details>
<summary>
<ins>$$name$$</ins>
<br>$$author$$
<br>$$language$$
<br>First Published: $$published$$
<br>Read Date: $$readDate$$
<br>$$rating$$/10
</summary>
<p>
#

# $logsMoviesItemStart(name,director,language,released,watchDate,rating)
<li>
<details>
<summary>
<ins>$$name$$</ins>
<br>Director: $$director$$
<br>$$language$$
<br>Released: $$released$$
<br>Watch date: $$watchDate$$
<br>$$rating$$/10
</summary>
<p>
#

# $logsItemEnd():
</p>
</details>
</li>
#

# $link(name,href):
<a href="$$href$$">$$name$$</a>
#

# $description(content):
<div class="description">
$$content$$
</div>
#
