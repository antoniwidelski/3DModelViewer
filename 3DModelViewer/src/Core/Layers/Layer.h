#pragma once

#ifndef V_LAYER
#define V_LAYER

class Layer
{
	virtual void Create() {}
	virtual void OnUpdate() {}
};

#endif