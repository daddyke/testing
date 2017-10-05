/** \file Unit tests for WAV Module
 */
#include "catch.hpp"

#include "wav.hpp"
#include "test_config.hpp"
#include "signal.hpp"
#include "midi.hpp"
TEST_CASE( "TODO5", "[wav]" ) {
	Signal store(44100);
	bool temp = write_wav(store, "testing.wav");
	REQUIRE(temp == true);
}
