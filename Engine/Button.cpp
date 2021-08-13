#include "Button.h"


Button::Button(string _normalPath, string _hoveringPath, string _keepDownPath, function<void(void)> _upEvent)
{
	SetTexture(_normalPath);
	
	if (_upEvent != nullptr)
		onMouseUp = [=]()->void {SetTexture(_normalPath); _upEvent(); };

	if (_hoveringPath != "")
		onMouseHovering = [=]()->void {SetTexture(_hoveringPath); };

	if (_keepDownPath != "")
		onMouseKeepDown = [=]()->void {SetTexture(_keepDownPath); };
	
	onMouseExit = [=]()->void {SetTexture(_normalPath); };

	if (_hoveringPath == "" && _keepDownPath == "")
	{
		onMouseNothing = [=]()->void
		{
			D3DXVec2Lerp(&scale, &scale, &Vec2(1.0f, 1.0f), 0.1f);
			D3DXColorLerp(&color, &color, &D3DXCOLOR(1.f, 1.f, 1.f, 1.0f), 0.1f);
		};

		onMouseHovering = [=]()->void
		{
			D3DXVec2Lerp(&scale, &scale, &Vec2(1.5f, 1.5f), 0.1f);
			D3DXColorLerp(&color, &color, &D3DXCOLOR(1.f, 1.f, 1.f, 1.0f), 0.1f);
		};

		onMouseKeepDown = [=]()->void
		{
			D3DXVec2Lerp(&scale, &scale, &Vec2(1.5f, 1.5f), 0.1f);
			D3DXColorLerp(&color, &color, &D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f), 0.1f);
		};
	}
}

Button::~Button()
{
}
