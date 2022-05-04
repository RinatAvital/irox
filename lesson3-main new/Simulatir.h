#pragma once
#include "baseMessage.h"
#include <stdlib.h>
#include "StatusMesseage.h"
#include "DiscoverMessege.h"
#define buffer1 10
class Simulatir
{
	protected:
		baseMessage* buffer[buffer1];
	public:
		StatusMesseage* createStatusMessage();
		DiscoverMessege* createDiscoverMessage();
		void generateAndSendMessage();

};

