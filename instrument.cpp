#include "instrument.hpp"
DefaultInstrument::DefaultInstrument(const Track & track)
{
	tempo = 500000;
	ticks_per_beat = track.getTicksPerBeat();
	for (auto it = track.begin(); it != track.end(); it++)
	{
		if (it->isEndTrackEvent() == true)
		{
			totalLength = it->getTickTime() * tempo / (1000000.0 * ticks_per_beat);
			return;
		}
		else if (it->isTempoEvent() == true)
		{
			tempo = it->asTempoEvent().getTempo();
		}
		else if (it->isNoteEvent() == true)
		{
			if (it->asNoteEvent().getNoteOn() == true)
			{
				data store;
				store.noteNumber = it->asNoteEvent().getNoteNumber();
				store.noteVelocity = it->asNoteEvent().getNoteVelocity();
				store.start = it->getTickTime() * tempo / (1000000.0 * ticks_per_beat);
				store.tempo = tempo;
				store.noteElapseTime = 0;
				store.counting = 0;
				store.ONorOFF = true;
				v.push_back(store);
			}
			else if (it->asNoteEvent().getNoteOn() == false)
			{
				for (auto temp = v.begin(); temp != v.end(); temp++)
				{
					if (temp->noteNumber == it->asNoteEvent().getNoteNumber() && temp->ONorOFF == true)
					{
						temp->ONorOFF = false;
					}
				}
			}
		}
	}
}

bool DefaultInstrument::halted()
{
	if (sampleLine > totalLength)
	{
		v.clear();
		return true;
	}
	return false;
}

double DefaultInstrument::sample(double deltaT)
{
	sampleLine = count * deltaT;
	count++;
	double sum = 0;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (sampleLine >= it->start && it->noteElapseTime <= noteLength)
		{
			double frequency = 0;
			if (it->noteNumber == 60)
			{
				frequency = 261.63;
			}
			else if (it->noteNumber == 61)
			{
				frequency = 277.18;
			}
			else if (it->noteNumber == 62)
			{
				frequency = 293.66;
			}
			else if (it->noteNumber == 63)
			{
				frequency = 311.13;
			}
			else if (it->noteNumber == 64)
			{
				frequency = 329.63;
			}
			else if (it->noteNumber == 65)
			{
				frequency = 349.63;
			}
			else if (it->noteNumber == 66)
			{
				frequency = 369.994;
			}
			else if (it->noteNumber == 67)
			{
				frequency = 392.0;
			}
			else if (it->noteNumber == 68)
			{
				frequency = 415.305;
			}
			else if (it->noteNumber == 69)
			{
				frequency = 440.0;
			}
			else if (it->noteNumber == 70)
			{
				frequency = 466.164;
			}
			else if (it->noteNumber == 71)
			{
				frequency = 493.88;
			}
			else if (it->noteNumber == 0 || it->noteNumber == 12 || it->noteNumber == 24 || it->noteNumber == 36 || it->noteNumber == 48 || it->noteNumber == 72 || it->noteNumber == 84 || it->noteNumber == 96 || it->noteNumber == 108 || it->noteNumber == 120)
			{
				frequency = 261.63 * pow(2.0, (it->noteNumber - 60) / 12.0);
			}
			else if (it->noteNumber == 1 || it->noteNumber == 13 || it->noteNumber == 25 || it->noteNumber == 37 || it->noteNumber == 49 || it->noteNumber == 73 || it->noteNumber == 85 || it->noteNumber == 97 || it->noteNumber == 109 || it->noteNumber == 121)
			{
				frequency = 277.18 * pow(2.0, (it->noteNumber - 61) / 12.0);
			}
			else if (it->noteNumber == 2 || it->noteNumber == 14 || it->noteNumber == 26 || it->noteNumber == 38 || it->noteNumber == 50 || it->noteNumber == 74 || it->noteNumber == 86 || it->noteNumber == 98 || it->noteNumber == 110 || it->noteNumber == 122)
			{
				frequency = 293.66 * pow(2.0, (it->noteNumber - 62) / 12.0);
			}
			else if (it->noteNumber == 3 || it->noteNumber == 15 || it->noteNumber == 27 || it->noteNumber == 39 || it->noteNumber == 51 || it->noteNumber == 75 || it->noteNumber == 87 || it->noteNumber == 99 || it->noteNumber == 111 || it->noteNumber == 123)
			{
				frequency = 311.13 * pow(2.0, (it->noteNumber - 63) / 12.0);
			}
			else if (it->noteNumber == 4 || it->noteNumber == 16 || it->noteNumber == 28 || it->noteNumber == 40 || it->noteNumber == 52 || it->noteNumber == 76 || it->noteNumber == 88 || it->noteNumber == 100 || it->noteNumber == 112 || it->noteNumber == 124)
			{
				frequency = 329.63 * pow(2.0, (it->noteNumber - 64) / 12.0);
			}
			else if (it->noteNumber == 5 || it->noteNumber == 17 || it->noteNumber == 29 || it->noteNumber == 41 || it->noteNumber == 53 || it->noteNumber == 77 || it->noteNumber == 89 || it->noteNumber == 101 || it->noteNumber == 113 || it->noteNumber == 125)
			{
				frequency = 349.63 * pow(2.0, (it->noteNumber - 65) / 12.0);
			}
			else if (it->noteNumber == 6 || it->noteNumber == 18 || it->noteNumber == 30 || it->noteNumber == 42 || it->noteNumber == 54 || it->noteNumber == 78 || it->noteNumber == 90 || it->noteNumber == 102 || it->noteNumber == 114 || it->noteNumber == 126)
			{
				frequency = 369.994 * pow(2.0, (it->noteNumber - 66) / 12.0);
			}
			else if (it->noteNumber == 7 || it->noteNumber == 19 || it->noteNumber == 31 || it->noteNumber == 43 || it->noteNumber == 55 || it->noteNumber == 79 || it->noteNumber == 91 || it->noteNumber == 103 || it->noteNumber == 115 || it->noteNumber == 127)
			{
				frequency = 392.0 * pow(2.0, (it->noteNumber - 67) / 12.0);
			}
			else if (it->noteNumber == 8 || it->noteNumber == 20 || it->noteNumber == 32 || it->noteNumber == 44 || it->noteNumber == 56 || it->noteNumber == 80 || it->noteNumber == 92 || it->noteNumber == 104 || it->noteNumber == 116)
			{
				frequency = 415.305 * pow(2.0, (it->noteNumber - 68) / 12.0);
			}
			else if (it->noteNumber == 9 || it->noteNumber == 21 || it->noteNumber == 33 || it->noteNumber == 45 || it->noteNumber == 57 || it->noteNumber == 81 || it->noteNumber == 93 || it->noteNumber == 105 || it->noteNumber == 117)
			{
				frequency = 440.0 * pow(2.0, (it->noteNumber - 69) / 12.0);
			}
			else if (it->noteNumber == 10 || it->noteNumber == 22 || it->noteNumber == 34 || it->noteNumber == 46 || it->noteNumber == 58 || it->noteNumber == 82 || it->noteNumber == 94 || it->noteNumber == 106 || it->noteNumber == 118)
			{
				frequency = 466.164 * pow(2.0, (it->noteNumber - 70) / 12.0);
			}
			else if (it->noteNumber == 11 || it->noteNumber == 23 || it->noteNumber == 35 || it->noteNumber == 47 || it->noteNumber == 59 || it->noteNumber == 83 || it->noteNumber == 95 || it->noteNumber == 107 || it->noteNumber == 119)
			{
				frequency = 493.88 * pow(2.0, (it->noteNumber - 71) / 12.0);
			}
			//double frequency = 261.63 * pow(2.0, (it->noteNumber - 60) / 12.0);
			it->noteElapseTime = it->counting * deltaT;
			it->counting++;
			if (it->noteElapseTime >= 0 && it->noteElapseTime <= 0.0625)
			{
				sum = sum + 200 * it->noteVelocity*(it->noteElapseTime / 0.0625)*sin(2 * M_PI*frequency*it->noteElapseTime);
			}
			else if (it->noteElapseTime > 0.0625 && it->noteElapseTime <= 0.1125)
			{
				sum = sum + 200 * it->noteVelocity*(1 - (it->noteElapseTime - 0.0625))*sin(2 * M_PI*frequency*it->noteElapseTime);
			}
			else if (it->noteElapseTime > 0.11252 && it->noteElapseTime <= 0.2)
			{
				sum = sum + 200 * it->noteVelocity*0.8*sin(2 * M_PI*frequency*it->noteElapseTime);
			}
			else if (it->noteElapseTime > 0.2 && it->noteElapseTime <= 0.25)
			{
				sum = sum + 200 * it->noteVelocity *(0.8 - 16.0*(it->noteElapseTime - 0.2))*sin(2 * M_PI*frequency*it->noteElapseTime);
			}
		}
	}
	return sum;
}
// TODO
