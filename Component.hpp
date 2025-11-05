#pragma once
#include <vector>
#include <memory.h>
class Component
{
public:
	virtual void InitializeComponent() {}   // only virtual, not pure virtual (abstract)
};