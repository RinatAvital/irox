#pragma once
#include<mutex>

class Buffer
{
protected:
	unsigned char** buffer;
	int count;
	std::mutex m;

public:
	void addToBuffer(unsigned char* newMessege);
	unsigned char** getBuffer();
	void cleanBuffer();
	Buffer();
	~Buffer();





};


