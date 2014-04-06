/*
 * dsp.h
 *
 *  Created on: Feb 17, 2014
 *      Author: mreut
 */

#ifndef DSP_H_
#define DSP_H_

#include <stdint.h>

//*****************************************************************************
//
// defines
//
//*****************************************************************************
#define SIZE_NOTE_ARRAY 	    8
#define VALUE_SAMPLE_RATE 	48000
#define NOTE_OFF 		0x00
#define NOTE_ON			0x01

#define FILTER_LOW_PASS         0x01
#define FILTER_HIGH_PASS        0x02;
#define FILTER_BAND_PASS        0x03;
#define FILTER_NOTCH_PASS       0x04;

typedef struct
{
	uint8_t ui8State;		// on/off state of note
	uint16_t ui16Sample;	// output sample DAC
	float fFrequency;		// note frequency
	float fIncrement;
	float fPosition;		// wave table position
	float fSample;			// output sample float
}Note;

typedef struct
{
    float fCutoff;
    float fDamping;
    float fLow;
    float fHigh;
    float fBand;
    float fNotch;
    float fDelay[2];
    uint8_t ui8Type;
}FilterParameters;


//*****************************************************************************
//
// function prototypes
//
//*****************************************************************************
void NoteIncrement(Note* CurrentNote);
void NoteInitialize(Note* CurrentNote, float fFrequency);
void NoteInterpolate(Note* CurrentNote);
void NoteOn(Note* CurrentNote);
void NoteOff(Note* CurrentNote);
void NotePlay(Note* CurrentNote);
void NoteSet(Note* CurrentNote, float fFrequency);

void SineInitialize();
void SquareInitialize();
void SawtoothInitialize();

void FilterInitialize();
void FilterSetCutoff(float fCutoff);
void FilterSetDamping(float fDamping);
void FilterProcess(float fInput);
float FilterOutputLow();
float FilterOutputHigh();
float FilterOutputBand();

#endif /* DSP_H_ */