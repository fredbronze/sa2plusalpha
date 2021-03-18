#include "Trampoline.h"
#include <string>

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
