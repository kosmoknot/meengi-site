<!DOCTYPE html>
<html>

  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
    <link rel="icon" href="../links/images/logo.png" type="image/icon type">
    <link href="../links/style.css" rel="stylesheet" type="text/css" media="all">
  <script src="../links/script.js"></script>
  <style media="screen">
    html {
      cursor: url(../links/images/point.ico), default;
      background: black;
    }

    .enter {
      width: 0px;
      height: 0px;
      text-align: center;
      line-height: .8em;
      position: absolute;
      top: 0;
      bottom: 0;
      left: 0;
      right: 0;
      margin: auto;
      z-index: 100;
    }

    .top {
      display: block;
      padding-left: 30px;
      padding-right: 30px;
      border: whitesmoke;
      border-style: solid;
      border-width: thin;
      position: absolute;
      left: 0;
      right: 0;
      font-family: "Menlo", "Meslo LG", monospace;
    }

    #launcher {
      text-align: center;
      display: block;
      border: none;
      background-color: transparent;
      color: white;
      font-size: 35px;
      width: 150px;
      height: 100px;
      background-image: url("../links/images/pointer.png");
      background-position: center;
      background-repeat: no-repeat;
      background-size: 100px 100px;
      text-shadow: 1px 5px 5px black;
      text-shadow: 2 2 5 black;
      font-family: 'Montserrat', Arial, sans-serif;

    }

    .enter button:hover {
      cursor: url(../links/images/hand.ico), auto;
    }

    #promt {
      color: white;
      text-align: center;
      font-size: 30px;
    }

    #c {
      overflow: hidden;
      z-index: 0;
      display: block;
    }
  </style>
</head>

<body style="margin: 0;">
  <div class="top">
    <p id="promt">????????????????</p>
  </div>

  <div class="enter">
    <button id="launcher" name="button" onclick=""></button>
  </div>
  <canvas id="c"></canvas>

  <script type="module">
    import * as THREE from '../links/three/three.module.js';
    import { OrbitControls } from '../links/three/OrbitControls.js';
    var gallary, resources, articles, index, projects, logs;
    let camera, renderer, scene, intersects, controls;
    let HomeSphere, ProjectSphere, LogSphere, ArticleSphere, GallarySphere, ResourcesSphere;
    const raycaster = new THREE.Raycaster();
    const mouse = new THREE.Vector2();
    const loader = new THREE.TextureLoader();

    init();
    animate();

    var link = '';

    function init() {
      scene = new THREE.Scene();
      //cubemap
      const path = '../links/images/MilkyWay/dark-s_';
      const format = '.jpg';
      const urls = [
        path + 'px' + format, path + 'nx' + format,
        path + 'py' + format, path + 'ny' + format,
        path + 'pz' + format, path + 'nz' + format
      ];

      const refractionCube = new THREE.CubeTextureLoader().load(urls);
      refractionCube.mapping = THREE.CubeRefractionMapping;
      scene.background = refractionCube;

      var Geo = new THREE.SphereGeometry(2, 32, 32);
      var Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/earth.png'), side: THREE.DoubleSide });
      HomeSphere = new THREE.Mesh(Geo, Mat);
      scene.add(HomeSphere)
      HomeSphere.position.set(-7, 0, 0);

      Geo = new THREE.SphereGeometry(3, 32, 32);
    Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/moon.png'), side: THREE.DoubleSide });
      ResourcesSphere = new THREE.Mesh(Geo, Mat);
      scene.add(ResourcesSphere)
      ResourcesSphere.position.set(0, -8, 0);
      ResourcesSphere.rotation.z = Math.PI / 2.5;

      Geo = new THREE.SphereGeometry(3, 32, 32);
      Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/mars.png'), side: THREE.DoubleSide });
      ProjectSphere = new THREE.Mesh(Geo, Mat);
      scene.add(ProjectSphere)
      ProjectSphere.position.set(0, 0, -8);
      ProjectSphere.rotation.y = -Math.PI / 4;

      Geo = new THREE.SphereGeometry(3, 32, 32);
      Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/sun.png'), side: THREE.DoubleSide });
      GallarySphere = new THREE.Mesh(Geo, Mat);
      scene.add(GallarySphere)
      GallarySphere.position.set(0, 11, 0);
      GallarySphere.rotation.z = -Math.PI / 2;

      Geo = new THREE.SphereGeometry(1.5, 32, 32);
      Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/saturn.png'), side: THREE.DoubleSide });
      LogSphere = new THREE.Mesh(Geo, Mat);
      scene.add(LogSphere)
      LogSphere.position.set(0, 0, 8);
      LogSphere.rotation.y = Math.PI / 2;

      Geo = new THREE.SphereGeometry(5, 32, 32);
      Mat = new THREE.MeshBasicMaterial({ map: loader.load('../links/images/articles.png'), side: THREE.DoubleSide });
      ArticleSphere = new THREE.Mesh(Geo, Mat);
      scene.add(ArticleSphere)
      ArticleSphere.position.set(13, 0, 0);
      ArticleSphere.rotation.y = Math.PI / 1.5;

      camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
      renderer = new THREE.WebGLRenderer({ canvas: c });
      renderer.setSize(window.innerWidth, window.innerHeight);
      document.body.appendChild(renderer.domElement);

      const tloader = new THREE.FontLoader();
      tloader.load('../links/three/fonts/CF_glitch_City_Regular.json', function (font) {

        const color = 0x000000;

        const matDark = new THREE.LineBasicMaterial({
          color: color,
          side: THREE.DoubleSide
        });

        var message = "WHO";
        var shapes = font.generateShapes(message, 0.4);
        var geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        var xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        gallary = new THREE.Mesh(geometry, matDark);
        gallary.position.y = 8;
        gallary.rotation.x = Math.PI / 2;
        scene.add(gallary);

        message = "IS"
        shapes = font.generateShapes(message, 0.4);
        geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        index = new THREE.Mesh(geometry, matDark);
        index.position.x = -5;
        index.rotation.y = Math.PI / 2;
        scene.add(index);

        message = 'VIBGYOR'
        shapes = font.generateShapes(message, 0.4);
        geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        resources = new THREE.Mesh(geometry, matDark);
        resources.position.y = -5;
        resources.rotation.x = -Math.PI / 2;
        scene.add(resources);

        message = 'WHO'
        shapes = font.generateShapes(message, 0.6);
        geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        articles = new THREE.Mesh(geometry, matDark);
        articles.position.x = 8;
        articles.rotation.y = -Math.PI / 2;
        scene.add(articles);

        message = 'IS'
        shapes = font.generateShapes(message, 0.4);
        geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        logs = new THREE.Mesh(geometry, matDark);
        logs.position.z = 6.5;
        logs.rotation.y = -Math.PI;
        scene.add(logs);

        message = 'VIBGYOR';
        shapes = font.generateShapes(message, 0.4);
        geometry = new THREE.ShapeGeometry(shapes);
        geometry.computeBoundingBox();
        xMid = - 0.5 * (geometry.boundingBox.max.x - geometry.boundingBox.min.x);
        geometry.translate(xMid, 0, 0);
        projects = new THREE.Mesh(geometry, matDark);
        projects.position.z = -5;
        scene.add(projects);

      });

      camera.position.set(2.5, 0, 0);

      controls = new OrbitControls(camera, renderer.domElement);
      controls.listenToKeyEvents(window);
      controls.enableDamping = true;
      controls.dampingFactor = 0.05;

      controls.enableZoom = false;
      controls.autoRotate = true;
      controls.autoRotateSpeed = 0.5;
      window.addEventListener('resize', onWindowResize);
      window.addEventListener('mousemove', onMouseMove, false);

      window.requestAnimationFrame(render);

    }

    function animate() {
      requestAnimationFrame(animate);
      controls.update();
      render();
    }

    function onWindowResize() {
      camera.aspect = window.innerWidth / window.innerHeight;
      camera.updateProjectionMatrix();
      renderer.setSize(window.innerWidth, window.innerHeight);
    }
    function onMouseMove(event) {
      mouse.x = (event.clientX / window.innerWidth) *2 - 1;
mouse.y = - (event.clientY / window.innerHeight)* 2 + 1;
    }

    function render() {
      renderer.render(scene, camera);
      raycaster.setFromCamera(mouse, camera);
      intersects = raycaster.intersectObjects(scene.children);
      if (intersects[0].object == HomeSphere) {
        document.getElementById('launcher').innerHTML = "Who";
      }
      else if (intersects[0].object == LogSphere) {
        document.getElementById('launcher').innerHTML = "is";
      }
      else if (intersects[0].object == ArticleSphere) {
        document.getElementById('launcher').innerHTML = "VIBGYOR";
      }
      else if (intersects[0].object == ProjectSphere) {
        document.getElementById('launcher').innerHTML = "Who";
      }

      else if (intersects[0].object == GallarySphere) {
        document.getElementById('launcher').innerHTML = "is";
      }
      else if (intersects[0].object == ResourcesSphere) {
        document.getElementById('launcher').innerHTML = "VIBGYOR";
      }
    }

  </script>

</body>

</html>
