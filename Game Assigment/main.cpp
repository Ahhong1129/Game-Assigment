#include "GWindow.h"
#include"GGraphics.h"
#include<d3d9.h>
#include <d3dx9.h>

//	use int main if you want to have a console to print out message
int main()
//	use WinMain if you don't want the console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GameWindows* gWin = GameWindows::getInstance();
	gWin->init();

	GGraphic* gGraphic = new GGraphic;



	LPDIRECT3DTEXTURE9 texture = NULL;
	LPD3DXSPRITE sprite = NULL;

	//	Create sprite. Study the documentation. 
	D3DXCreateSprite(gGraphic->d3dDevice, &sprite);
	D3DXCreateTextureFromFile(gGraphic->d3dDevice, "pointer.png", &texture);

	int x = 0;

	RECT spriteRect;
	spriteRect.left = 0;
	spriteRect.top = 0;
	spriteRect.right = 24;
	spriteRect.bottom = 24;

	while (gWin->isWindowsRunning())
	{
		/*if (gWin->keyPressed == 70 && d3dPP.Windowed == true)
		{
			d3dPP.Windowed = false;
			gGraphic->d3dDevice->Reset(&d3dPP);
		}
		else if (gWin->keyPressed == 69 && d3dPP.Windowed == false) {

			d3dPP.Windowed = true;
			gGraphic->d3dDevice->Reset(&d3dPP);
		}
	*/
		if (gWin->keyPressed == 39) {//left
			x++;
		}
		else if (gWin->keyPressed == 37) {//right
			x--;
		}

		gGraphic->begin();

		//Sprite
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		//	Sprite rendering. Study the documentation.
		sprite->Draw(texture, NULL, NULL, &D3DXVECTOR3(gWin->mouseX, gWin->mouseY, 0), D3DCOLOR_XRGB(255, 255, 255));
		//	End sprite drawing
		sprite->End();

		gGraphic->end();
	}

	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;

	delete gGraphic;

	gWin->releaseInstance();

	return 0;
}
//--------------------------------------------------------------------

