#pragma once
#include <d3d9.h>
class GGraphic
{
public:
	IDirect3D9* direct3D9;
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9* d3dDevice;
	GGraphic();
	~GGraphic();

	void begin();
	void end();
};

