#include "Simulator.h"

//#include <iostream>
//#include <string.h>
//#include <exception>
//#include <boost/property_tree/json_parser.hpp>
//#include <boost/property_tree/ptree.hpp>
//#include "json.hpp"
//using namespace std;
//using json = nlohmann::json;
//namespace pt = boost::property_tree;



Simulator::Simulator()
{
	arrCamera = (Camera**)malloc(sizeof(Camera*) * N);
	for (int i = 0; i < N; i++)
	{
		arrCamera[i] = new Camera(char(i+'a'));
	}
	
}



void Simulator::ThreadRunCamera()
{
	char c;
	std::thread threadCameraGenerate[N];
	std::thread threadCameraSend[N];
	//std::thread* threadCamera = (std::thread*)malloc(sizeof(std::thread) * N);
	for (int i = 0; i < N; i++)
	{
		threadCameraGenerate[i]= std::thread(&Camera::run, *(arrCamera[i]));
		threadCameraSend[i] = std::thread(&Camera::sendToServer, *(arrCamera[i]));
		 //threadCamera[i].join();
	}

	std::cin >> c;

	for (int i = 0; i < N; i++)
	{
		arrCamera[i]->stop();
		threadCameraGenerate[i].detach();
	}
	
	
}

void Simulator::printValueAllCamera()
{
	for (int i = 0; i < N; i++)
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

//void Simulator::ReadDataJSON()
//{
//	pt::ptree root;
//	pt::read_json("file.json", root);  // Load the json file in this ptree
//	int roll = root.get<int>("roll no");  //read and save the roll no in *roll*
//	string  name = root.get<string>("name");  //read and save the name in *name*
//	string class1 = root.get<string>("class");  //read and save the class in *class1*
//	cout << "name : " << name << endl;      //getting the output of all
//	cout << "roll no : " << roll << endl;
//	cout << "class : " << class1 << endl << "address : " << endl << endl;
//	for (pt::ptree::value_type& v : root.get_child("address"))
//	{
//		cout << v.first << endl;
//		cout << "  " << v.second.data() << endl;
//	}
//	return 0;
//}
