# EN.601.414/614: Computer Networks

## Logistics

- Instructor: [Xin Jin](http://www.cs.jhu.edu/~xinjin/)
- Teaching assistants: Zhihao Bai, Hang Zhu
- Course assistants: Yixiao Luo, Rishabh Singh
- Lecture time: Monday and Wednesday, 3:00-4:15pm
- Location: Shaffer 301
- Credits: 3 credits
- Course discussion: [piazza](https://piazza.com/jhu/spring2019/en601414614)
- Homework submission: [Gradescope](https://www.gradescope.com/), join the course with entry code 95KRDN
- Office hours
  - Monday: 4:15-5:15pm, Malone 235, Xin Jin
  - Wednesday: 4:15-5:15pm, Malone 235, Hang Zhu
  - Friday: 4:15-5:15pm, Malone 235, Zhihao Bai

## Course Description

Topics covered will include application layer protocols (e.g. HTTP, FTP, SMTP), transport layer protocols (UDP, TCP), network layer protocols (e.g. IP, ICMP), link layer protocols (e.g. Ethernet) and wireless protocols (e.g. IEEE 802.11). The course will also cover routing protocols such as link state and distance vector, multicast routing, and path vector protocols (e.g. BGP). The class will examine security issues such as firewalls and denial of service attacks. We will also study DNS, NAT, Web caching and CDNs, peer to peer, and protocol tunneling. Finally, we will explore security protocols (e.g. TLS, SSH, IPsec), as well as some basic cryptography necessary to understand these. Grading will be based on hands-on programming assignments, homeworks and two exams.

## Prerequisites

EN.601.220 and EN.601.229 or permission. Students can only receive credits for one of 601.414/614.

## Announcements

- Wednesday, May 1: [Assignment 4](https://github.com/xinjin/course-net-assignment/tree/master/assignment4) is due.
- Wednesday, April 17: [Assignment 4](https://github.com/xinjin/course-net-assignment/tree/master/assignment4) is out.
- Monday, April 15: [Assignment 3](https://github.com/xinjin/course-net-assignment/tree/master/assignment3) is due.
- Monday, April 1: [Assignment 3](https://github.com/xinjin/course-net-assignment/tree/master/assignment3) is out.
- Tuesday, March 12: Please fill the [midterm survey](https://goo.gl/forms/zLQX7SYm7BzK0hGC3).
- Friday, March 8: [Assignment 2](https://github.com/xinjin/course-net-assignment/tree/master/assignment2) is due.
- Wednesday, February 20: [Assignment 2](https://github.com/xinjin/course-net-assignment/tree/master/assignment2) is out.
- Friday, February 15: [Assignment 1](https://github.com/xinjin/course-net-assignment/tree/master/assignment1) is due.
- Sunday, February 3: [Assignment 1](https://github.com/xinjin/course-net-assignment/tree/master/assignment1) is out.
- Monday, January 28: First day of class. Join [piazza](https://piazza.com/jhu/spring2019/en601414614).

## Course Syllabus

| Date    | Topics  | Readings | Notes   |
| :------ | :------ | :------  | :------ |
| Mon 01/28 | Introduction ([ppt](slides/lec01_introduction.pptx), [pdf](slides/lec01_introduction.pdf)) | | |
| Wed 01/30 | Basic ([ppt](slides/lec02_basic.pptx), [pdf](slides/lec02_basic.pdf)) | 1.1, 1.3, 1.4 | |
| Mon 02/04 | Protocol Layering ([ppt](slides/lec03_layering.pptx), [pdf](slides/lec03_layering.pdf)) | 1.5 | A1 Out |
| Wed 02/06 | HTTP and the Web ([ppt](slides/lec04_web.pptx), [pdf](slides/lec04_web.pdf)) | 2.2 | |
| Mon 02/11 | CDN and DNS ([ppt](slides/lec05_cdn.pptx), [pdf](slides/lec05_cdn.pdf)) | 2.4 | |
| Wed 02/13 | Exercise and Lab ([ppt](slides/lab01.pptx), [pdf](slides/lab01.pdf)) | | A1 Due |
| Mon 02/18 | Transport Layer ([ppt](slides/lec06_transport.pptx), [pdf](slides/lec06_transport.pdf)) | 3.1, 3.2, 3.3, 3.4 | |
| Wed 02/20 | School Closed | | A2 Out |
| Mon 02/25 | TCP Basics ([ppt](slides/lec07_tcp.pptx), [pdf](slides/lec07_tcp.pdf)) | 3.5 | |
| Wed 02/27 | Flow and Congestion Control ([ppt](slides/lec08_flow_congestion.pptx), [pdf](slides/lec08_flow_congestion.pdf)) | 3.6 | |
| Mon 03/04 | More Congestion Control ([ppt](slides/lec09_congestion.pptx), [pdf](slides/lec09_congestion.pdf)) | 3.7 | |
| Wed 03/06 | Network Layer and IP ([ppt](slides/lec10_ip.pptx), [pdf](slides/lec10_ip.pdf)) | 4.1, 4.3 | A2 Due |
| Mon 03/11 | Midterm Review ([ppt](slides/Midterm_review.pptx), [pdf](slides/Midterm_review.pdf)) | | |
| Wed 03/13 | Midterm Exam | | |
| Mon 03/18 | Spring Break | | |
| Wed 03/20 | Spring Break | | |
| Mon 03/25 | IP Routers ([ppt](slides/lec11_ip_router.pptx), [pdf](slides/lec11_ip_router.pdf))| 4.2 | |
| Wed 03/27 | Routing Fundamentals ([ppt](slides/lec12_routing.pptx), [pdf](slides/lec12_routing.pdf)) | 5.1 | |
| Mon 04/01 | Routing Algorithms ([ppt](slides/lec13_routing_algorithms.pptx), [pdf](slides/lec13_routing_algorithms.pdf)) | 5.2, 5.3 | A3 Out |
| Wed 04/03 | Midterm Recap | 4.3.3 | |
| Mon 04/08 | IP Addressing and Inter-AS Routing ([ppt](slides/lec14_interdomain.pptx), [pdf](slides/lec14_interdomain.pdf)) | | |
| Wed 04/10 | BGP ([ppt](slides/lec15_bgp.pptx), [pdf](slides/lec15_bgp.pdf)) | | |
| Mon 04/15 | Programmable Networks ([ppt](slides/lec16_programmable.pptx), [pdf](slides/lec16_programmable.pdf)) | [TuringAward'17 Lecture](https://www.youtube.com/watch?v=3LVeEjsn8Ts) | A3 Due |
| Wed 04/17 | Link Layer ([ppt](slides/lec17_link.pptx), [pdf](slides/lec17_link.pdf)) | 5.4 | A4 Out |
| Mon 04/22 | Switched LAN ([ppt](slides/lec18_LAN.pptx), [pdf](slides/lec18_LAN.pdf)) | 6.1, 6.3| |
| Wed 04/24 | Wireless ([ppt](slides/lec19_wireless.pptx), [pdf](slides/lec19_wireless.pdf)) and Security ([ppt](slides/lec20_security.pptx), [pdf](slides/lec20_security.pdf)) | 4.4, 5.5, 8.1, 8.3, 8.6 | |
| Mon 04/29 | Misc ([ppt](slides/lec21_misc.pptx)) | | |
| Wed 05/01 | Final Review | | A4 Due |
| Wed 05/08 | Final Exam | | 6pm-7:30pm, Shaffer 301 |

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
