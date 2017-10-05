#include "event.hpp"
TempoEvent::TempoEvent()
{
	t = 500000;
}

TempoEvent::TempoEvent(intmax_t tempo)
{
	t = tempo;
}
intmax_t TempoEvent::getTempo() const
{
	return t;
}

EndTrackEvent::EndTrackEvent()
{
	End = false;
}

bool EndTrackEvent::stop()
{
	return End;
}

NoteEvent::NoteEvent(bool on, int8_t notenum, int8_t notevelocity)
{
	ONorOFF = on;
	noteNumber = notenum;
	noteVelocity = notevelocity;
}

bool NoteEvent::getNoteOn()
{
	return ONorOFF;
}

int8_t NoteEvent::getNoteNumber() const
{
	return noteNumber;
}

int8_t NoteEvent::getNoteVelocity() const 
{
	return noteVelocity;
}

MIDIEvent::MIDIEvent()
{
	type = NONTYPE;
}

MIDIEvent::MIDIEvent(TempoEvent e, intmax_t ticktime)
{
	type = TEMPO;
	tickTime = ticktime;
	Data.tempo = e.getTempo();
}

MIDIEvent::MIDIEvent(EndTrackEvent e, intmax_t ticktime)
{
	type = ENDTRACK;
	tickTime = ticktime;
	Data.stop = e.stop();
}

MIDIEvent::MIDIEvent(NoteEvent e, intmax_t ticktime)
{
	type = NOTE;
	tickTime = ticktime;
	Data.ONorOFF = e.getNoteOn();
	Data.noteNumber = e.getNoteNumber();
	Data.noteVelocity = e.getNoteVelocity();
}

bool MIDIEvent::isTempoEvent() const
{
	if (type == TEMPO)
	{
		return true;
	}
	return false;
}

bool MIDIEvent::isEndTrackEvent() const
{
	if (type == ENDTRACK)
	{
		return true;
	}
	return false;
}

bool MIDIEvent::isNoteEvent() const
{
	if (type == NOTE)
	{
		return true;
	}
	return false;
}

intmax_t MIDIEvent::getTickTime() const
{
	return tickTime;
}

TempoEvent MIDIEvent::asTempoEvent() const
{
	TempoEvent temp;
	if (isTempoEvent() == true)
	{
		temp = TempoEvent(Data.tempo);
	}
	return temp;
}

NoteEvent MIDIEvent::asNoteEvent() const
{
	NoteEvent temp(Data.ONorOFF, Data.noteNumber, Data.noteVelocity);
	return temp;
}


// TODO
