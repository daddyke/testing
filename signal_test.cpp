/** \file Unit tests for Signal Module
*/
#include "catch.hpp"
#include "test_config.hpp"
#include "signal.hpp"
#include "midi.hpp"
#include "instrument.hpp"
#include <iostream>
using namespace std;
TEST_CASE( "TODO2", "[signal]" ) {
	SECTION("TESTING SIGNAL")
	{
		Signal store(44100);
		string fname = TEST_FILE_DIR + "/test4.mid";

		auto tracks = readMIDIFromFile(fname);

		DefaultInstrument instrument(*tracks.begin());
		while (instrument.halted() == false)
		{
			double temp = instrument.sample(1.0 / 44100.0);
			store.push_back(temp);			
		}
		store.normalize();
		REQUIRE(store.size() == 124033);
		REQUIRE(store.getSampleRate() == 44100);
		REQUIRE(store[0] == 0);	
	}
	SECTION("TESTING NORMALIZE")
	{
		Signal signal(44100);
		signal.push_back(40000);
		signal.normalize();
		signal.push_back(-50000);
		signal.normalize();
	}
}
