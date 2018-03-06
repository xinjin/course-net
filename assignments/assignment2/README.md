# Assignment 2: Video Streaming via CDN

### Due: March 9th, 2018 at 11:59 PM

## Overview

Video traffic dominates the Internet. In this project, you will explore how video content distribution networks (CDNs) work. In particular, you will implement adaptive bitrate selection, DNS load balancing, and an HTTP proxy server to stream video at high bit rates from the closest server to a given client.

<img src="real-CDN.png" title="Video CDN in the wild" alt="" width="350" height="256"/>

### Video CDNs in the Real World
The figure above depicts a high level view of what this system looks like in the real world. Clients trying to stream a video first issue a DNS query to resolve the service's domain name to an IP address for one of the CDN's content servers. The CDN's authoritative DNS server selects the “best” content server for each particular client based on
(1) the client's IP address (from which it learns the client's geographic location) and
(2) current load on the content servers (which the servers periodically report to the DNS server).

Once the client has the IP address for one of the content servers, it begins requesting chunks of the video the user requested. The video is encoded at multiple bitrates; as the client player receives video data, it calculates the throughput of the transfer and requests the highest bitrate the connection can support.

### Video CDN in this Assignment
Implementing an entire CDN is difficult; instead, you'll focus on a simplified version. First, your entire system will run on one host and rely on mininet to run several processes with arbitrary IP addresses on one machine. Mininet will also allow you to assign arbitrary link characteristics (bandwidth and latency) to each pair of “end hosts” (processes).

<img src="our-CDN.png" title="Video CDN in assignment 2" alt="" width="330" height="111"/>

You'll write the Proxy in the figure above for this assignment.

**Browser.** You'll use an off-the-shelf web browser (Firefox) to play videos served by your CDN (via your proxy).

**Proxy.** Rather than modify the video player itself, you will implement adaptive bitrate selection in an HTTP proxy. The player requests chunks with standard HTTP GET requests; your proxy will intercept these and modify them to retrieve whichever bitrate your algorithm deems appropriate. To simulate multiple clients, you will launch multiple instances of your proxy.

**Web Server.** Video content will be served from an off-the-shelf web server (Apache). As with the proxy, you will run multiple instances of Apache on different IP addresses to simulate a CDN with several content servers.


To summarize, this assignment has the following components:

* [Part 1](#part1): Bitrate Adaptation in HTTP Proxy
* [Submission Instructions](#submission-instr)

## Learning Outcomes

After completing this programming assignment, students should be able to:

* Explain how HTTP proxies and video CDNs work
* Create topologies and change network characteristics in Mininet to test networked systems

## Clarifications

* For the proxy you implement in part 1, you will need to parse some HTTP traffic. To make your life easier for this project, you don't need to be concerned about parsing all the information in these HTTP messages. There are only two things that you need to care about searching for: "\r\n\r\n" and "Content-Length:". The former is used to denote the end of an HTTP header, and the latter is used to signify the size of the HTTP body in bytes.

* While testing the proxy you implement in part 1, you may notice that one browser may sometimes open multiple connections to your proxy server. Your proxy should still continue to function as expected in this case. In order to account for these multiple connections, you may use the browser IP address to uniquely identify each connection (this implies that while testing your proxy server, each browser will have a unique IP address. For example, only one browser will have an IP address of 10.0.0.2).

<a name="part1"></a>

## Environment setup

[We are providing a VM](http://www.cs.jhu.edu/~hzhu/proj2.ova) that has all the components you need to get started on the assignment. This VM includes mininet, Apache, and all the files we will be streaming in this project. Both the username and password for this VM are `proj2`. To start the Apache server, simply run the python script we provide by doing the following:

`python start_server.py <host_number>`

Here `<host_number>` is a required command line argument that specifies what host you are running on Mininet. This is important as if you're running on h1 in Mininet (which is given the IP address 10.0.0.1), passing in `1` into the `<host_number>` argument will help ensure that the Apache server instance will be bound to the 10.0.0.1 IP address. The `<host_number>` argument must be between 1 and 8.

If you are testing locally, and simply wish to launch the server locally, you can run the following command:

`/usr/local/apache2/bin/apachectl start`

For this project, we will be using an off the shelf browser (in this case, it is Firefox). To launch Firefox for this project, run the following command:

`python launch_firefox.py <profile_num>`

Here `<profile_num>` is a required command line argument that specifies the instance of Firefox you are launching. We support launching profiles 1-8, however, should you feel the need to test more thoroughly, you can launch it with a different number and simply create a new profile as needed. To ensure a separate connection for each instance of Firefox, we recommend that you launch Firefox with a different profile number (otherwise you might notice that different Firefox instances will sometimes share a connection with your proxy browser).

**NOTE:** For this project, we are disabling caching in the browser. If you do choose to create a new profile, please be sure to go to the `about:config` page and set both `browser.cache.disk.enable` and `browser.cache.memory.enable` to `false`.

## Part 1: Bitrate Adaptation in HTTP Proxy

Many video players monitor how quickly they receive data from the server and use this throughput value to request better or lower quality encodings of the video, aiming to stream the highest quality encoding that the connection can handle. Instead of modifying an existing video client to perform bitrate adaptation, you will implement this functionality in an HTTP proxy through which your browser will direct requests.

You are to implement a simple HTTP proxy, `miProxy`. It accepts connections from web browsers, modifies video chunk requests as described below, opens a connection with the content server, and forwards the modified request to the server. Any data (the video chunks) returned by the server should be forwarded, *unmodified*, to the browser.

`miProxy` should listen for browser connections on `INADDR_ANY` on the port specified on the command line. It should then connect to web servers specified on the command line (see below).

<img src="proxy-overview.png" title="Video CDN in the wild" alt="" width="534" height="171"/>

It should accept multiple concurrent connections using `select()` or multithread and be able to handle the required HTTP 1.1 requests for this assignment (e.g., HTTP `GET`). It only needs to handle tcp connections from only one firefox instance. You should run multiple instances of your proxy and browsers on different hosts to simulate multiple clients.
*Note: A good resource to remind you of socket programming is [Beej's Guide to Network Programming Using Internet Sockets](http://beej.us/guide/bgnet/).*

### Throughput Calculation

Your proxy should estimate each stream's throughput once per chunk. Note the start time of each chunk request when your proxy receives a request from the player and save another timestamp when you have finished receiving the chunk from the server. Given the size of the chunk, you can now compute the throughput by dividing chunk size by time window.

Each video is a sequence of chunks. To smooth your throughput estimation, you should use an exponentially-weighted moving average (EWMA). Every time you make a new measurement (as outlined above), update your current throughput estimate as follows:

`T_cur = alpha * T_new + (1 - alpha) * T_cur`

The constant `0 ≤ alpha ≤ 1` controls the tradeoff between a smooth throughput estimate (`alpha` closer to 0) and one that reacts quickly to changes (`alpha` closer to 1). You will control `alpha` via a command line argument. When a new stream starts, set `T_cur` to the lowest available bitrate for that video.

### Choosing a Bitrate

Once your proxy has calculated the connection's current throughput, it should select the highest offered bitrate the connection can support. For this project, we say a connection can support a bitrate if the average throughput is at least 1.5 times the bitrate. For example, before your proxy should request chunks encoded at 1000 Kbps, its current throughput estimate should be at least 1.5 Mbps.

Your proxy should learn which bitrates are available for a given video by parsing the manifest file (the ".f4m" initially requested at the beginning of the stream). The manifest is encoded in XML; each encoding of the video is described by a `<media>` element, whose bitrate attribute you should find.

Your proxy replaces each chunk request with a request for the same chunk at the selected bitrate (in Kbps) by modifying the HTTP request’s `Request-URI`. Video chunk URIs are structured as follows:

`/path/to/video/<bitrate>Seg<num>-Frag<num>`

For example, suppose the player requests fragment 3 of chunk 2 of the video `big_buck_bunny.f4m` at 500 Kbps:

`/path/to/video/500Seg2-Frag3`

To switch to a higher bitrate, e.g., 1000 Kbps, the proxy should modify the URI like this:

`/path/to/video/1000Seg2-Frag3`

**IMPORTANT:** When the video player requests `big_buck_bunny.f4m`, you should instead return `big_buck_bunny_nolist.f4m`. This file does not list the available bitrates, preventing the video player from attempting its own bitrate adaptation. You proxy should, however, fetch `big_buck_bunny.f4m` for itself (i.e., don’t return it to the client) so you can parse the list of available encodings as described above. Your proxy should keep this list of available bitrates in a global container (not on a connection by connection basis).

### Running `miProxy`
To operate `miProxy`, it should be invoked as follows:

`./miProxy <log> <alpha> <listen-port> <www-ip>`

* `log` The file path to which you should log the messages as described below.
* `alpha` A float in the range [0, 1]. Uses this as the coefficient in your EWMA throughput estimate.
* `listen-port` The TCP port your proxy should listen on for accepting connections from your browser.
* `www-ip` Your proxy should accept an argument specifying the IP address of the web server from which it should request video chunks.

###Logging
`miProxy` must create a log of its activity in a very particular format. After each request, it should append the following line to the log:

`<duration> <tput> <avg-tput> <bitrate> <server-ip> <chunkname>`

* `duration` A floating point number representing the number of seconds it took to download this chunk from the server to the proxy.
* `tput` The throughput you measured for the current chunk in Kbps.
* `avg-tput` Your current EWMA throughput estimate in Kbps.
* `bitrate` The bitrate your proxy requested for this chunk in Kbps.
* `server-ip` The IP address of the server to which the proxy forwarded this request.
* `chunkname` The name of the file your proxy requested from the server (that is, the modified file name in the modified HTTP GET message).

### Testing
To play a video through your proxy, you can simply launch a local instance of the Apache server, launch Firefox (see above), and point the browser on your VM to the URL `http://localhost:<listen-port>/index.html`.


<a name="submission-instr"></a>
## Submission Instructions

You zip file to be submitted to Gradescope must include the following:

* `Makefile`(s) to compile `miProxy` 
* The source code for `miProxy`: all source files for `miProxy` should be in a folder called `miProxy`
* If you use third-party libraries, include them in a folder `lib` and explain how to install them in a `README` file

## Acknowledgements
This programming assignment is based on Mosharaf Chowdhury's Assignment 2 from UMich EECS 489: Computer Networks.
