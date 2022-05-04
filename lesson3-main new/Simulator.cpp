#include "Simulator.h"




Simulator::Simulator()
{
	arrCamera = (Camera**)malloc(sizeof(Camera*) * NUM2);
	for (int i = 0; i < NUM2; i++)
	{
		arrCamera[i] = new Camera(char(i+'a'));
	}
	
}



void Simulator::ThreadRunCamera()
{
	char c;
	std::thread threadCameraGenerate[NUM2];
	std::thread threadCameraSend[NUM2];
	
	for (int i = 0; i < NUM2; i++)
	{
		threadCameraGenerate[i]= std::thread(&Camera::run, *(arrCamera[i]));
		threadCameraSend[i] = std::thread(&Camera::sendToServer, *(arrCamera[i]));
		 //threadCamera[i].join();
	}

	std::cin >> c;

	for (int i = 0; i < NUM2; i++)
	{
		arrCamera[i]->stop();
		threadCameraGenerate[i].detach();
	}
	
	
}

void Simulator::printValueAllCamera()
{
	for (int i = 0; i < NUM2; i++)
	{
		unsigned char** results = arrCamera[i]->getBufferValue();
		std::cout << std::endl;
		std::cout << "camera number: " << i << std::endl;
		for (int j = 0; j < 4; j++)
		{
			std::cout << j + 1<<": " << results[j] << std::endl;
		}
		
	}
}

