#pragma once
#include "main.h"

BOOL PatternCheck(PCSTR data, PCSTR pattern, PCSTR mask);

UINT64 FindPattern(UINT64 address, UINT64 size, PCSTR pattern, PCSTR mask);

UINT64 FindPatternImage(UINT64 ImageBase, PCSTR Pattern, PCSTR Mask);