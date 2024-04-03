#pragma once

#include "GameObject.h"
#include "Camera.h"

class CScene
{
public:
	CScene();
	virtual ~CScene();

private:
	int							m_nObjects = 0;				// 오브젝트의 갯수
	CGameObject					**m_ppObjects = NULL;		// 게임 오브젝트들의 배열로 처리

public:
	virtual void BuildObjects();
	virtual void ReleaseObjects();

	virtual void Animate(float fElapsedTime);					// Anumate 하고
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);	// 그리고

	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

