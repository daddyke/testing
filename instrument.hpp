/** \file The DefaultInstrument Module
*/
#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP
#define _USE_MATH_DEFINES
#include "event.hpp"
#include "track.hpp"
#include <math.h>
#define noteLength 0.25
/** The default instrument. A simple fixed length note instrument using a
* a sinusoid weighted by an envelope function.
*/
class DefaultInstrument {
public:

	/** No default constructor. A DefaultInstrument must have an associated
	* track.
	*/
	DefaultInstrument() = delete;

	/** Cannot be copied.
	*/
	DefaultInstrument(const DefaultInstrument &) = delete;

	/** Cannot be assigned.
	*/
	DefaultInstrument & operator=(const DefaultInstrument &) = delete;

	/** Construct a Default Instrument using the specified track.
	* \param track the track to read events from.
	*/

	DefaultInstrument(const Track & track);
	/** Returns true of the DefaultInstrument has stopped processing events.
	* This can occu e.g. if all events have been consumed or a EndTrackEvent
	* has been processed.
	*/
	bool halted();

	/** Return the sample after the (real) time increment. Samples the
	* instrument based on its state after processing all events prior
	* to this time.
	* \param deltaT the time increment in seconds.
	*/
	double sample(double deltaT);
private:
	struct data
	{
		intmax_t counting = 0;
		intmax_t tempo = 0;
		intmax_t noteNumber = 0;
		intmax_t noteVelocity = 0;
		double noteElapseTime = 0;
		double start = 0;
		bool ONorOFF = 0;
	};
	intmax_t tempo = 0;
	intmax_t ticks_per_beat = 0;
	vector<data> v;
	double totalLength = 0;
	double sampleLine = 0;
	intmax_t count = 0;
	// TODO
};


#endif
