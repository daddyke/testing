#include "synthesizer.hpp"
Signal synthesize(Track & track)
{
	Signal signal(44100);
	DefaultInstrument instrument(track);
	while (instrument.halted() == false)
	{
		double temp = instrument.sample(1.0 / 44100.0);
		signal.push_back(temp);
	}
	signal.normalize();
	return signal;
}
// TODO
