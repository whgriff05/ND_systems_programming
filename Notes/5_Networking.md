# Networking

## What is the internet?

A computer sends packets to a router, which can distribute those packets to their destination: other computers connected to the router.\
This network comprised of a single router is called a __LAN__ (local area network).

If the destination is not on the LAN, the router contacts the ISP (internet service provider), and the ISP connects to the destination routers/servers. This all takes place on a __WAN__ (wide area network).

The internet is a __network of networks__.

### What is the client-server model?

To contact a server from a client, you need to know the server's __ip address__. To get your own ip address, run the command `ip addr` (To get a summarized output, run `ip -br addr`)

There are different types of ip addresses:
- __localhost__ (`127.0.0.1`)
- __private__ ip addresses (usually `192.168.x.x`)
- __public__ ip addresses

Instead of using an ip address, you can also use a __hostname__ to reference a machine (the hostname references the ip address).\
This uses __DNS__ (domain name system) to match a hostname to an ip address.
- NOTE: domain name does not map one-to-one with ip address; you can have __multiple__ names for the same ip address AND __multiple__ ip addresses for one domain name

Finally, different applications on a server listen for different requests on different __ports__

Common ports
- 80: HTTP
- 22: SSH
- 443: HTTPS

To see what ports are being used on your machine, use `ss -tlpn` (`-t`: TCP | `-l`: list | `-p`: port | `-n`: number) to list all programs using ports on your machine

To see what ports are being used on __another__ machine, use `nmap -Pn -p <address/hostname>`

## Bandwidth versus Latency

__Bandwidth__ - How much data is carried over time \
__Latency__ - How much delay between sending data packets

To measure bandwidth, use a command to download some file.

To measure latency, use the `ping <ip/hostname>` command or `traceroute <ip/hostname>` command (`traceroute` also tracks what servers the request goes through)

## Transfer files between machines

- Use `sftp` to open a semi-shell on the remote machine, use `get` to transfer the remote file to the local machine
- Use `scp` to secure shell copy a file from one machine to another


