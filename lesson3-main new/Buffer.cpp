#include "Buffer.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mutex>

Buffer::Buffer()
{
	buffer = NULL;
	count = 0;
	
}

void Buffer::addToBuffer(unsigned char* newMessege)
{
	m.lock();
	buffer = (unsigned char**)realloc(buffer, sizeof(unsigned char*) * (++count));
	buffer[count - 1] = newMessege;
	m.unlock();
}

unsigned char** Buffer::getBuffer()
{
	return buffer;
}

void Buffer::cleanBuffer()
{
	m.lock();
	free(buffer);
	count = 0;
	m.unlock();

}

int Buffer::getCount()
{
	return this->count;
}




