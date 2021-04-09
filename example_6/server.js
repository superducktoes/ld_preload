var http = require("http");

var server = http.createServer(function(req,res) {

    if(req.method === "GET") {
	if (req.url == "/command") {
	    res.writeHead(200, {"Content-Type": "text/html"});
	    res.write("ls");
	    res.end();
	} else {
	    res.end("There's nothing here!");
	}
    } else if(req.method === "POST") {
	let body = "";

	req.on("data", function(chunk) {
	    body += chunk;
	});

	console.log("POST DATA");
	
	req.on("end", function() {
	    console.log(body);
	    res.end(body);
	});
	
    }   
});
			     
server.listen(5001);

console.log("server is listening on port 5001");
