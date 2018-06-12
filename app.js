var express = require('express')
var path = require('path');
var app = express()
var engines = require('consolidate');

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
