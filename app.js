var express = require('express')
var path = require('path');
var app = express()
var engines = require('consolidate');
var WebSocketServer = require('websocket').server;
var http = require('http');

var server = http.createServer(function(req,res) {

});

server.listen(1337, function() {
  console.log("server is listening on port 1337");
});

var wsServer = new WebSocketServer({
  httpServer: server
});

wsServer.on('request', (req) => {
  var connection = request.accept(null, request.origin);
  connection.on('message', (message) => {
    if (message.type === 'utf8') {
      //process websocket message
    }
  });

  connection.on('close', (connection) => {
    // close user connection
  });
});

app.set('views', path.join(__dirname, 'views'));
app.use(express.static(__dirname + '/public'));
app.engine('html', engines.swig);
app.set('view engine', 'html');
var indexRouter = require('./routes/index');

app.use('/',indexRouter);


app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
});

module.exports = app;
