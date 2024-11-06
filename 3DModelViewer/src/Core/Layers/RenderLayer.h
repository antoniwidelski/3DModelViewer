#pragma once

#ifndef V_RENDERLAYER
#define V_RENDERLAYER

#include "Layer.h"

class RenderLayer : public Layer
{
	RenderLayer();
	virtual void Create() override;
	virtual void OnUpdate() override;
};

#endif