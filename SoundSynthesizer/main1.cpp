#include<iostream>

using namespace std;

#include"olcNoisemaker.h"

atomic<double> dFrequencyOutput = 0.0;



double MakeNoise(double dTime) {
	double dOutput =  1.0 * sin(dFrequencyOutput * 2 * 3.14159 * dTime);

	if (dOutput > 0.0)
	{
		return 0.2;
	}
	else {
		return -0.2;
	}




}

int main() {
	wcout << " Sound Synthesizer Part 1 : basic notes" << endl;

	// get all sound  hardware

	vector<wstring>devices = olcNoiseMaker <short>::Enumerate();

	// display findings

	for (auto d :  devices) wcout << " Found output devices" << d << endl;

	// to create sound machine

	olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

		// link noise with sound machine

		sound.SetUserFunction(MakeNoise);

		while (1) {

			//get a keyboard

			if (GetAsyncKeyState('A' )&& 0x8000) {

				dFrequencyOutput = 440.0;
			}
			else {
				dFrequencyOutput = 0.0;
			}

			return 0;
		}






}





