#include "signal.hpp"
Signal::Signal(unsigned int sampleRate)
{
	signal.clear();
	Rate = sampleRate;
}

unsigned int Signal::getSampleRate()
{
	return Rate;
}

void Signal::normalize()
{
	double max = 0;
	double min = 0;
	double higher = 0;
	double top = numeric_limits<int16_t>::max();
	double bot = numeric_limits<int16_t>::min();
	for (size_t i = 0; i < Size; i++)
	{
		if (signal[i] > max)
		{
			max = signal[i];
		}
		if (signal[i] < min)
		{
			min = signal[i];
		}
	}
	if (max > top || min < bot)
	{
		higher = max + min;
		if (higher > 0)
		{
			for (size_t i = 0; i < Size; i++)
			{
				double k = signal[i];
				k = k * top / max;
				// k = round(k);
				double temp = round(k);
				signal[i] = temp;
			}
			//scaleFactor = top / max;
		}
		else if (higher < 0)
		{
			for (size_t i = 0; i < Size; i++)
			{
				double k = signal[i];
				k = k * bot / min;
				//k = round(k);
				double temp = round(k);
				signal[i] = temp;
			}
			// scaleFactor = bot / min;
		}
	}
	else
	{
		for (size_t i = 0; i < Size; i++)
		{
			double k = signal[i];
			k = round(k);
			//  int16_t temp = k;
			signal[i] = k;
		}
	}

}

void Signal::push_back(double value)
{
	signal.push_back(value);
	Size = Size + 1;
}

std::size_t Signal::size()
{
	return Size;
}

double Signal::operator[](std::size_t index)
{
	//  if (index > Size - 1)
	//{
	///  throw range_error("OUT OF RANGE");
	//	  }
	return signal[index];
}


// TODO
