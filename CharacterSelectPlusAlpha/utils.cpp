#include "SA2ModLoader.h"
#include "Trampoline.h"
#include <string>

BOOL WriteString(int writeAddress, std::string data)
{
	return WriteData((void*)writeAddress, &data, data.size() + 1);
}

void JumpTo(int destination)
{
	__asm   push    destination
}

void PopBytes(int number)
{
	__asm   add     esp, number
}

int addr(Trampoline* trampoline)
{
	return (int)(byte*)trampoline->Target();
}

int Repair(Trampoline* trampoline)
{
	const auto target = (int)(byte*)trampoline->Target();
	const auto offset = (int)*(int*)trampoline - target;
	const auto length = trampoline->OriginalSize() - 4;

	// Skip over the first byte since it's fixed by Trampoline itself.
	for (unsigned int i = 1; i < length; i++)
	{
		// Assume the current byte is the the first byte of an x86 instruction.
		const auto instruction = (byte*)(target + i);
		const auto opcode = instruction[0];

		if (opcode == 0xE8 || opcode == 0xE9)
		{
			// If the instruction is a call or a jump, check four bytes ahead --
			// that'll be the most significant byte of the jump offset.
			const auto msb = instruction[4];

			// My crappy heuristic -- if the most significant byte is all ones/zeroes,
			// then this is probably a 24-bit offset that needs fixing.
			if (msb == 0x00 || msb == 0xFF)
			{
				const auto operand = (int*)&instruction[1];
				*operand += offset;
			}
		}

	}

	return target;
}
