# System Calls: Networking

## TCP/IP

Two ends: __client__ and __server__

A client needs to know an __ip address__ and a __port__ for a service running on a server

A client also has its own __ip address__ and a __port__ for the connection service it runs

We use this protocol called __TCP__ to send __packets__ over the network
- TCP has a control mechanism: makes sure every packet is sent/received correctly

## URLs

http://xavier.h4x0r.space:9234/cgi-bin/hello.sh?name=pnutzh4x0r

"http://" - __protocol__ \
"xavier.h4x0r.space" - __domain__ \
":9234" - __port__ \
"/cgi-bin/hello.sh" - __path resource__ \
"?name=pnutzh4x0r" - __query string__

## Sockets + Echo Client

__Client__
- `getaddrinfo()` - talks to DNS
- `socket()` - creates a network socket to the server
- `connect()` - establish connection to the server
- __write__ (in some function) - send message to the server
- __read__ (in some function) - receive message from the server
- __close__ (in some function) - shut down and clean up connection with the server

