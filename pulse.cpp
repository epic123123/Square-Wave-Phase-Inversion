#include <wiringPi.h>
#include <sys/time.h>
#include <iostream>

bool pinState1 = false;
bool pinState2 = true;
float interval = 20.0f;

void _switch(int pin1, int pin2)
{
	pinMode(pin1, !pinState1);
	pinState1 = !pinState1;
	pinMode(pin2, !pinState2);
	pinState2 = !pinState2;
}

void SendSignal(int pin1, int pin2)
{
	if(pinState1) { digitalWrite(0, HIGH); digitalWrite(2, LOW);}

	if(pinState2) { digitalWrite(2, HIGH); digitalWrite(0, LOW);}
}

int main()
{
	wiringPiSetup();

	float phaseLength1 = 0.0f;
	float phaseLength2 = 0.0f;

	std::cout << "Enter period 1: ";
	std::cin >> phaseLength1;

	std::cout << "Enter period 2: ";
	std::cin >> phaseLength2;
	
	int i = 1;
	bool firstPhase = true;

	while(true)
	{
		float currentPhaseLength = firstPhase ? phaseLength1 : phaseLength2;

		while(currentPhaseLength > 0)
		{
			_switch(0, 2);
			SendSignal(0, 2);

			if(currentPhaseLength < 1)
			{
				delay(currentPhaseLength * interval);
				currentPhaseLength = 0;
				continue;

			} 
			if (pinState1) {currentPhaseLength -= 1;}
			
			delay(interval);
		}
		firstPhase = !firstPhase;
	}

	return 0;
}