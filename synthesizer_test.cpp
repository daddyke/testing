/** \file Integration tests for synthesizer function.
*/
#include "catch.hpp"

#include "track.hpp"
#include "synthesizer.hpp"
#include "test_config.hpp"
#include "signal.hpp"
#include "midi.hpp"
TEST_CASE( "TODO3", "[synthesizer]" ) { 
	Signal store(44100);
	string fname = TEST_FILE_DIR + "/test4.mid";

	auto tracks = readMIDIFromFile(fname);
	auto sample = synthesize(*tracks.begin());

}
