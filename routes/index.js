"use strict";
var express = require('express');
var router = express.Router();
var path = require('path');
var SerialPort = require('serialport');
var serialData = [];
var ukeExists;

router.get('/', function(req,res,next) {
  res.render('index.html');
});

SerialPort.list(function (err,results) { //list all available ports
  if (err) {
    throw err;
  }
  console.log(results);
});

//constructing a SerialPort object immediately opens a port
var port = new SerialPort('/dev/tty.usbmodem1411', {
  baudRate: 9600
  }, (err) => {
  if (err) {
    console.log('Error', err.message);
    ukeExists = false;
  }
  else {
    ukeExists = true;
  }
});

port.on('data', function(data) {
	// console.log(data[0].toString());
  var str = data.toString();
  if (str.includes('255')) {
    //start putting the data in serialData array
  }
  // serialData.push(data.toString());
  // console.log(serialData);
  // console.log(data.toString());
}, function(err) {
  if (err) {
    console.log("Error: " + err.message);
  }
});

// port.on('readable', function() {
// 	console.log(port.read());
// });


module.exports = router;
