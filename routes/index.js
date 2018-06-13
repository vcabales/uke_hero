"use strict";

var express = require('express');
var router = express.Router();
var path = require('path');
var SerialPort = require('serialport');

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
  }
});

var portlist = SerialPort.list();
console.log(portlist, function(err) {
	if (err) {
		console.log('Error: ', err.message);
	}
});

port.on('data', function(data) {
	console.log(data.toString());
  // console.log(data);
});

// port.on('readable', function() {
// 	console.log(port.read());
// });


module.exports = router;
