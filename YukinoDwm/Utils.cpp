#include "Utils.h"

BOOL PatternCheck(PCSTR data, PCSTR pattern, PCSTR mask) {
    
    auto len = strlen(mask);

    for (auto i = 0ui64; i < len; i++)  {

        if (data[i] == pattern[i] || mask[i] == '?') continue; else return FALSE;
    }
    return TRUE;
}

UINT64 FindPattern(UINT64 address, UINT64 size, PCSTR pattern, PCSTR mask) {

    size -= strlen(mask);

    for (auto i = 0ui64; i < size; i++) if (PatternCheck((PCSTR)address + i, pattern, mask)) return address + i;

    return 0;
}

UINT64 FindPatternImage(UINT64 ImageBase, PCSTR Pattern, PCSTR Mask) {

    auto DosHeader = (IMAGE_DOS_HEADER*)ImageBase;

    auto NtHeaders = (PIMAGE_NT_HEADERS64)(ImageBase + DosHeader->e_lfanew);

    auto Section = IMAGE_FIRST_SECTION(NtHeaders);

    for (auto i = 0; i < NtHeaders->FileHeader.NumberOfSections; i++) {

        if (!strcmp((PCSTR)Section[i].Name, ".text")) {

            return FindPattern(ImageBase + Section[i].VirtualAddress, Section[i].Misc.VirtualSize, Pattern, Mask);
        }
    }
    return 0;
}