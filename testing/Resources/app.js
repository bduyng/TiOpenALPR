var TiOpenALPR = require('com.bduyng.tiopenalpr');

Ti.Gesture.addEventListener('orientationchange', function onOrientationChange(e) {
  console.error('orientationchange', e.orientation);
  tiopenalprWindow.orientationModes = [e.orientation];
});

var tiopenalprWindow = Ti.UI.createWindow({
  backgroundColor: 'white',
  top: 0,
  bottom: 0,
  left: 0,
  right: 0,
  barColor: '#000000',
  title: 'HAKA Live',
  statusBarStyle: Ti.UI.iOS.StatusBar.LIGHT_CONTENT,
  tintColor: '#FFFFFF',
  titleAttributes: {
    color: '#fffffff',
  },
  // orientationModes: [Ti.UI.LANDSCAPE_RIGHT],
});
var camera = TiOpenALPR.createALPRCamera({
  top: 0,
  bottom: 0,
  left: 0,
  right: 0,
  country: 'eu',
  zoomFactor: 1.0,
  borderColor: '#FF0000',
});
// var camera2 = Ti.UI.createView({
//   top: 0,
//   bottom: 0,
//   left: 0,
//   right: 0,
//   // width:height,
//   // height:width,
//   country: 'eu',
//   zoomFactor: 2.0,
//   borderColor: '#FF0000',
//   backgroundColor: '#000000',
// });
// var matrix = Ti.UI.createMatrix2D({
// rotate: -90
// });
// camera2.transform = matrix;
// tiopenalprWindow.addEventListener('open', function (e) {
//   var currentOrientation = tiopenalprWindow.orientation;
//   console.error('currentOrientation', currentOrientation);
//   tiopenalprWindow.orientationModes = [currentOrientation];
// });
camera.addEventListener('plateRecognized', function (e) {
  console.error('plateRecognized:', e);
});
tiopenalprWindow.add(camera);

var label = Ti.UI.createLabel({
  bottom: 20,
  text: 'START',
  fontSize: 20,
  color: 'white',
});
tiopenalprWindow.add(label);

tiopenalprWindow.open();
