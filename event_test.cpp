/** \file Unit tests for Event Module
*/
#include "catch.hpp"
#include "event.hpp"
#include <iostream>
using namespace std;

TEST_CASE( "TODO", "[event]" ) {
	SECTION("testing Tempo")
	{

		TempoEvent Tempo;
		TempoEvent Tempo2(10000000);
		REQUIRE(Tempo.getTempo() == 500000);
		REQUIRE(Tempo2.getTempo() == 10000000);
	}
	SECTION("TESTING NOTEEVENT")
	{
		bool on = true;
		int8_t notenum = 40;
		int8_t notevelocity = 30;
		NoteEvent Note(on, notenum, notevelocity);
		REQUIRE(Note.getNoteOn() == true);
		REQUIRE(Note.getNoteNumber() == notenum);
		REQUIRE(Note.getNoteVelocity() == notevelocity);
	}
	SECTION("TESTING MIDIEVENT")
	{
		TempoEvent tempo(10000);
		MIDIEvent Tempo(tempo, 2);
		REQUIRE(Tempo.isTempoEvent() == true);
		REQUIRE(Tempo.getTickTime() == 2);
		REQUIRE(Tempo.asTempoEvent().getTempo() == 10000);
		EndTrackEvent end;
		REQUIRE(end.stop() == false);
		MIDIEvent End(end, 4);
		REQUIRE(End.isEndTrackEvent() == true);
		REQUIRE(End.getTickTime() == 4);
		NoteEvent note(true, 26, 50);
		MIDIEvent Note(note, 6);
		REQUIRE(Note.isNoteEvent() == true);
		REQUIRE(Note.getTickTime() == 6);
		REQUIRE(Note.asNoteEvent().getNoteOn() == true);
		REQUIRE(Note.asNoteEvent().getNoteNumber() == 26);
		REQUIRE(Note.asNoteEvent().getNoteVelocity() == 50);
	}
	
}


