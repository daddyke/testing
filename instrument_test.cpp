/** \file Unit tests for DefaultInstrument Module
*/
#include "catch.hpp"

#include "track.hpp"
#include "instrument.hpp"
#include <fstream>

#include "test_config.hpp"
#include "midi.hpp"
using namespace std;
TEST_CASE( "TODO1", "[instrument]" ) {
	SECTION("testing Instrument")
	{
		string fname = TEST_FILE_DIR + "/test4.mid";
		auto tracks = readMIDIFromFile(fname);
		DefaultInstrument instrument(*tracks.begin());
		vector<double> store;
		int n = 0;
		double duration = 0.0;
		while (instrument.halted() == false)
		{
			double temp = instrument.sample(1.0 / 44100.0);
			n++;
			store.push_back(temp);
		}	
	}
	SECTION("TESTING DIFFERENT NOTENUMBER")
	{
		for (int i = 0; i < 118; i++)
		{
			Track tracks(44100);
			tracks.addNoteEvent(9, i, 10, i + 1);
			DefaultInstrument instrument(tracks);
		}
	}
}
