#pragma once

#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>

using namespace std;

struct request
{
	int x;
	int y;
	char op;
};

struct response
{
	int status;
	int result;
};
