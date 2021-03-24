#include "Trampoline.h"
#include <string>

static const char* c_escap1_adx  = (char*)0x8BA098;
static const char* c_escap3_adx  = (char*)0x8BA078;
static const char* objtex_common = (char*)0x8BAB18;
static const char* zanki_amy     = (char*)0x8B9B24;
static const char* zanki_metal   = (char*)0x8B9B18;
static const char* zanki_chao    = (char*)0x8B9B0C;
static const char* zanki_dchao   = (char*)0x8B9B00;
static const char* zanki_tical   = (char*)0x8B9AF4;
static const char* zanki_chaos0  = (char*)0x8B9AE4;
static const char* zanki_big0    = (char*)0x8B9930;
static const char* zanki_big1    = (char*)0x8B9924;

static short &CheckpointFlag = *(short*)0x1934B8A;
static byte &CurrentStory = *(byte*)0x1DEB320;

BOOL WriteString(int writeAddress, std::string data);

/// <summary>Performs an x86 jump to an arbitrary destination address.</summary>
void JumpTo(int destination);

/// <summary>Pops an arbitrary number of bytes from the x86 stack.</summary>
void PopBytes(int number);

#define FIXUPS
#ifdef FIXUPS

/// <summary>Repairs the relative addresses in a trampoline using bad heuristics.</summary>
/// <returns>The address of the original code.</returns>
int Repair(Trampoline* trampoline);

#else

int addr(Trampoline* trampoline);

#endif
