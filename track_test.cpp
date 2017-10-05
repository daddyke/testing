/** \file Unit tests for Track Module
*/
#include "catch.hpp"
#include "track.hpp"
#include <iostream>
using namespace std;
TEST_CASE( "TODO4", "[track]" ) {
	SECTION("Testing Constructor")
	{
		intmax_t ticks_per_beat = 1500000;
		Track track(ticks_per_beat);
		REQUIRE(track.begin() == track.end());
		REQUIRE(track.getTicksPerBeat() == 1500000);
		track.addEndEvent(4);
		REQUIRE(track.begin()->getTickTime() == 4);
		REQUIRE(track.begin()->isEndTrackEvent() == true);
		track.addTempoEvent(10000, 6);
		vector<MIDIEvent>::const_iterator it = track.begin();
		it++;
		REQUIRE(it->getTickTime() == 6);
		REQUIRE(it->isTempoEvent() == true);
		TempoEvent temp = it->asTempoEvent();
		REQUIRE(temp.getTempo() == 10000);
		uint8_t a = 8;
		uint8_t b = 10;
		uint8_t c = 20;
		intmax_t d = 9;
		track.addNoteEvent(a, b, c, d);
		vector<MIDIEvent>::const_iterator it1 = track.begin();
		it1++;
		it1++;
		REQUIRE(it1->getTickTime() == 9);
		REQUIRE(it1->isNoteEvent() == true);
		REQUIRE(it1->asNoteEvent().getNoteOn() == false);
		REQUIRE(it1->asNoteEvent().getNoteNumber() == 10);
		REQUIRE(it1->asNoteEvent().getNoteVelocity() == 20);
		track.addNoteEvent(9, b, 0, d);
		vector<MIDIEvent>::const_iterator it2 = track.begin();
		it2++;
		it2++;
		it2++;
		REQUIRE(it2->asNoteEvent().getNoteOn() == false);

	}
}
