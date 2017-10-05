// TODO: implement the main entry point for synth here
#include "catch.hpp"

#include "track.hpp"
#include "instrument.hpp"
#include <fstream>
#include <sstream>
#include "test_config.hpp"
#include "midi.hpp"
#include "signal.hpp"
#include "synthesizer.hpp"
#include "wav.hpp"
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		auto Tracks = readMIDIFromFile(argv[1]);
		intmax_t count = 0;
		for (auto it = Tracks.begin(); it != Tracks.end(); it++)
		{
			auto name = string(argv[2]) + "-" + to_string(count) + ".wav";
			auto sample = synthesize(*it);
			bool temp = write_wav(sample, name);
			if ( temp == false)
			{
				return EXIT_FAILURE;
			}
			count++;
		}
	}
	else
	{
		cout << "Need two arguments" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
