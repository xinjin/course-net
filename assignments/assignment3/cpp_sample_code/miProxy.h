#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#define BACKLOG 10

using namespace std;

bool check_video_data(string str);
string get_value(string str, string key);
string recv_response(int server_sd);
string get_chunkname(string request);
