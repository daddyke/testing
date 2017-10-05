#include "wav.hpp"
bool write_wav(Signal & sound, const std::string &filename)
{
	struct WavHead {
		int8_t   ChunkID[4]; //0 - 4
		int32_t  ChunkSize;  // 4 -8
		int8_t   Format[4];  // 8 - 12
		int8_t   Subchunk1ID[4]; //12 - 16
		int32_t  Subchunk1Size; //16 - 20
		int16_t  AudioFormat; //20 - 22
		int16_t  NumChannels; //22 - 24
		int32_t  SampleRate; //24 - 28
		int32_t  ByteRate;  //28 - 32
		int16_t  BlockAlign;//32-34
		int16_t  BitsPerSample;//32-36
		int8_t   Subchunk2ID[4];//36-40
		int32_t  Subchunk2Size; //40 - 44
								//int16_t  Data[NUMSAMPLES];

	};
	WavHead head = { { 'R','I','F','F' },0,{ 'W','A','V','E' },{ 'f','m','t',' ' },16,
		1,1,44100,88200,2,16,{ 'd','a','t','a' },
		0 };
	head.ChunkSize = 36 + 2 * sound.size();
	head.Subchunk2Size = 2 * sound.size();
	ofstream ocout;
	ocout.open(filename, ios::out | ios::binary);
	ocout.write(reinterpret_cast<std::fstream::char_type*>(&head), sizeof head);
	for (size_t i = 0; i < sound.size(); i++) {
		int16_t temp = sound[i];
		ocout.write(reinterpret_cast<std::fstream::char_type*>(&temp), sizeof temp);
	}
	ocout.close();
	return true;
}
// TODO

