#include "track.hpp"

// TODO
Track::Track(intmax_t ticks_per_beat)
{
	track.clear();
	secondPerbeat = ticks_per_beat;
}

intmax_t Track::getTicksPerBeat() const
{
	return secondPerbeat;
}

vector<MIDIEvent>::const_iterator Track::begin() const
{
	return track.cbegin();
}

vector<MIDIEvent>::const_iterator Track::end() const
{
	return track.cend();
}

void Track::addEndEvent(intmax_t tick_time)
{
	EndTrackEvent temp;
	MIDIEvent EndEvent(temp, tick_time);
	track.push_back(EndEvent);
}

void Track::addTempoEvent(intmax_t tempo, intmax_t tick_time)
{
	TempoEvent temp(tempo);
	MIDIEvent TempoEvent(temp, tick_time);
	track.push_back(TempoEvent);
}

void Track::addNoteEvent(uint8_t code, uint8_t data1, uint8_t data2, intmax_t tick_time)
{
	bool ONorOFF;
	if (code == 8)
	{
		ONorOFF = false;
	}
	else if (code == 9 && data2 != 0)
	{
		ONorOFF = true;
	}

	else if (code == 9 && data2 == 0)
	{
		ONorOFF = false;
	}
	else
	{
		return;
	}
	NoteEvent temp(ONorOFF, data1, data2);
	MIDIEvent NoteEvent(temp, tick_time);
	track.push_back(NoteEvent);
}

