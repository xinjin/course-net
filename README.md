# EN.601.414/614: Computer Networks

## Logistics

- Instructor: [Xin Jin](http://www.cs.jhu.edu/~xinjin/)
- Teaching assistants: Zhihao Bai
- Course assistants: TBD
- Lecture time: Tuesday and Thursday, 1:30-2:45pm
- Location: Zoom
- Credits: 3 credits
- Course discussion: [piazza](TBD)
- Homework submission: [Gradescope](https://www.gradescope.com/), join the course with entry code TBD
- Office hours
  - Tuesday: 2:45-3:45pm, Zoom, Xin Jin
  - TBD: TBD, Zoom, Zhihao Bai

## Course Description

Topics covered will include application layer protocols (e.g. HTTP, FTP, SMTP), transport layer protocols (UDP, TCP), network layer protocols (e.g. IP, ICMP), link layer protocols (e.g. Ethernet) and wireless protocols (e.g. IEEE 802.11). The course will also cover routing protocols such as link state and distance vector, multicast routing, and path vector protocols (e.g. BGP). The class will examine security issues such as firewalls and denial of service attacks. We will also study DNS, NAT, Web caching and CDNs, peer to peer, and protocol tunneling. Finally, we will explore security protocols (e.g. TLS, SSH, IPsec), as well as some basic cryptography necessary to understand these. Grading will be based on hands-on programming assignments, homeworks and two exams.

## Prerequisites

EN.601.220 and EN.601.229 or permission. Students can only receive credits for one of 601.414/614.

## Announcements

- Monday, September 1: First day of class. Join [piazza](TBD).

## Course Syllabus

| Date    | Topics  | Readings | Notes   |
| :------ | :------ | :------  | :------ |
| Tue 09/01 | Introduction ([ppt](slides/lec01_introduction.pptx), [pdf](slides/lec01_introduction.pdf)) | | |
| Thu 09/03 | Basic ([ppt](slides/lec02_basic.pptx), [pdf](slides/lec02_basic.pdf)) | 1.1, 1.3, 1.4 | |
| Tue 09/08 | Protocol Layering ([ppt](slides/lec03_layering.pptx), [pdf](slides/lec03_layering.pdf)) | 1.5 | A1 Out |
| Thu 09/10 | HTTP and the Web ([ppt](slides/lec04_web.pptx), [pdf](slides/lec04_web.pdf)) | 2.2 | |
| Tue 09/15 | CDN and DNS ([ppt](slides/lec05_cdn.pptx), [pdf](slides/lec05_cdn.pdf)) | 2.4 | |
| Thu 09/17 | Exercise and Lab ([ppt](slides/lab01.pptx), [pdf](slides/lab01.pdf)) | | A1 Due |
| Tue 09/22 | Transport Layer ([ppt](slides/lec06_transport.pptx), [pdf](slides/lec06_transport.pdf)) | 3.1, 3.2, 3.3, 3.4 | |
| Thu 09/24 | TBD | | A2 Out |
| Tue 09/29 | TCP Basics ([ppt](slides/lec07_tcp.pptx), [pdf](slides/lec07_tcp.pdf)) | 3.5 | |
| Thu 10/01 | Flow and Congestion Control ([ppt](slides/lec08_flow_congestion.pptx), [pdf](slides/lec08_flow_congestion.pdf)) | 3.6 | |
| Tue 10/06 | More Congestion Control ([ppt](slides/lec09_congestion.pptx), [pdf](slides/lec09_congestion.pdf)) | 3.7 | |
| Thu 10/08 | Network Layer and IP ([ppt](slides/lec10_ip.pptx), [pdf](slides/lec10_ip.pdf)) | 4.1, 4.3 | A2 Due |
| Tue 10/13 | Midterm Review ([ppt](slides/Midterm_review.pptx), [pdf](slides/Midterm_review.pdf)) | | |
| Thu 10/15 | Midterm Exam | | |
| Tue 10/20 | TBD | | |
| Thu 10/22 | TBD | | |
| Tue 10/27 | IP Routers ([ppt](slides/lec11_ip_router.pptx), [pdf](slides/lec11_ip_router.pdf))| 4.2 | |
| Thu 10/29 | Routing Fundamentals ([ppt](slides/lec12_routing.pptx), [pdf](slides/lec12_routing.pdf)) | 5.1 | |
| Tue 11/03 | Routing Algorithms ([ppt](slides/lec13_routing_algorithms.pptx), [pdf](slides/lec13_routing_algorithms.pdf)) | 5.2, 5.3 | A3 Out |
| Thu 11/05 | Midterm Recap | 4.3.3 | |
| Tue 11/10 | IP Addressing and Inter-AS Routing ([ppt](slides/lec14_interdomain.pptx), [pdf](slides/lec14_interdomain.pdf)) | | |
| Thu 11/12 | BGP ([ppt](slides/lec15_bgp.pptx), [pdf](slides/lec15_bgp.pdf)) | | |
| Tue 11/17 | Programmable Networks ([ppt](slides/lec16_programmable.pptx), [pdf](slides/lec16_programmable.pdf)) | [TuringAward'17 Lecture](https://www.youtube.com/watch?v=3LVeEjsn8Ts) | A3 Due |
| Thu 11/19 | Link Layer ([ppt](slides/lec17_link.pptx), [pdf](slides/lec17_link.pdf)) | 5.4 | A4 Out |
| Tue 11/24 | Thanksgiving | | |
| Thu 11/26 | Thanksgiving | | |
| Tue 12/01 | Switched LAN ([ppt](slides/lec18_LAN.pptx), [pdf](slides/lec18_LAN.pdf)) | 6.1, 6.3| |
| Thu 12/03 | Wireless ([ppt](slides/lec19_wireless.pptx), [pdf](slides/lec19_wireless.pdf)) and Security ([ppt](slides/lec20_security.pptx), [pdf](slides/lec20_security.pdf)) | 4.4, 5.5, 8.1, 8.3, 8.6 | |
| Tue 12/08 | Misc ([ppt](slides/lec21_misc.pptx), [pdf](slides/lec21_misc.pdf)) | | |
| Thu 12/10 | Final Review ([ppt](slides/Final_review.pptx), [pdf](slides/Final_review.pdf)) | | A4 Due |
| TBD | Final Exam | | |

## Textbook

Computer Networking: A Top-Down Approach (7th edition), by Jim Kurose and Keith Ross. Earlier editions are fine.

## Programming Assignments

- [Assignment 1](https://github.com/xinjin/course-net-assignment/tree/master/assignment1): Socket programming.
- [Assignment 2](https://github.com/xinjin/course-net-assignment/tree/master/assignment2): Reliable transport.
- [Assignment 3](https://github.com/xinjin/course-net-assignment/tree/master/assignment3): Intra-domain routing algorithms.
- [Assignment 4](https://github.com/xinjin/course-net-assignment/tree/master/assignment4): Programmable networks.


## Policies

### Academic Integrity Policy

This course strictly enforces the university and department policies on academic integrity. The details can be found on the [department website](https://www.cs.jhu.edu/academic-integrity-code/).

### Late Policy

- Grace period: 96 hours for the entire semester.
- After the grace period, 25% off for each 24 hours late, rounded up.

## Grading

- Class participation: 5%
- Programming assignments: 40%
- Midterm exam: 25%
- Final exam: 30%
