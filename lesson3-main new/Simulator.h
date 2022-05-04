#pragma once
#include "Camera.h"
#include<thread>
#include<stdio.h>
#include<iostream>

#define NUM2 5
class Simulator
{
	protected:
		Camera** arrCamera;
		
	public:
		Simulator();
		void ThreadRunCamera();
		void printValueAllCamera();
		void ReadDataJSON();
};

