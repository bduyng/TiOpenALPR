// This is a test harness for your module
// You should do something interesting in this harness
// to test out the module and to provide instructions
// to users on how to use it by example.

// TODO: write your module tests here
var TiOpenALPR = require('com.bduyng.tiopenalpr');
Ti.API.info('module is => ' + TiOpenALPR);

// open a single window
var win = Ti.UI.createWindow({
  backgroundColor: 'white',
});

var camera = TiOpenALPR.createALPRCamera({
  top: 0,
  bottom: 100,
  width: Ti.UI.FILL,
});
// camera.zoomFactor = 1.5;
win.add(camera);

var label = Ti.UI.createLabel({ bottom: 50, text: 'Zoom 2.0', color: 'black', zIndex: 99999 });
win.add(label);

label.addEventListener('click', function (e) {
  camera.zoomFactor = 1.5;
});
win.open();
