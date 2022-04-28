#include "Camera.h"
#include<stdio.h>
#include<stdlib.h>
#include "DiscoverMessege.h"
#include "StatusMesseage.h"
#include <thread>
#include<mutex>
#include <iostream>
using namespace std::literals::chrono_literals;



Camera::Camera(char cameraId)
{
	this->cameraId = cameraId;
	indexMessage = -1;
	bufferMessage = NULL;
	buffer = new Buffer();
	isActive = true;
	std::mutex mutexBuffer;
}

StatusMesseage* createStatusMessage()
{
	static int id = 0;
	id++;
	return new StatusMesseage(id, 1, rand() % 3 + 1);

}

DiscoverMessege* createDiscoverMessage()
{
	static int id = 99;
	id++;
	return new DiscoverMessege(id, 2, (float)(rand() % 9500 + 500), (float)(rand() % 361), (float)(rand() % 1001));
}



Camera::~Camera()
{
	free(buffer);
	free(bufferMessage);
}

void Camera::generate()
{
	int count = rand() % 6 + 1;
	baseMessage* base;
	
	for (int i = 0; i < count; i++)
	{
		std::cout << "generate " << std::endl;
		bufferMessage = (baseMessage**)realloc(bufferMessage, sizeof(baseMessage*) * (++indexMessage + 1));
		(rand() % 2 + 1 == 1) ? base = createStatusMessage() : base= createDiscoverMessage();
		bufferMessage[indexMessage] = base;
		bufferMessage[i]->print();
		std::cout << "\n" << std::endl;

	}
}

void Camera::sendToBuffer()
{
	std::cout << "moove to buffer" << std::endl;
	for (int i = 0; i <= indexMessage; i++)
	{
		bufferMessage[i]->parseBack();
		buffer->addToBuffer(bufferMessage[i]->getMessageBuffer());
		//bufferMessage[i]->~baseMessage();
		bufferMessage[i]->print();
		free(bufferMessage[i]);
	}
	free(bufferMessage);
	bufferMessage = NULL;
	numOfMessege += indexMessage;
	indexMessage = -1;

}

void Camera::run()
{
	while (isActive)
	{
		generate();
		sendToBuffer();
	}
}

void Camera::stop()
{
	isActive = false;
}

unsigned char** Camera::getBufferValue()
{
	return buffer->getBuffer();
}

int Camera::getOfNumOfMessege()
{
	return numOfMessege;
}

void Camera::sendToServer()
{

	while (isActive)
	{
		std::this_thread::sleep_for(3s);
		std::cout << "send to server" << std::endl;
		buffer->cleanBuffer();
	}

	
}



