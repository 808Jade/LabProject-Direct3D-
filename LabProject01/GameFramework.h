#pragma once

#include "Player.h"
#include "Scene.h"
#include "Timer.h"

class CGameFramework
{
public:
	CGameFramework() { }
	~CGameFramework() { }

private:
	HINSTANCE					m_hInstance = NULL;
	HWND						m_hWnd = NULL;

	RECT						m_rcClient;					// ���� �������� Ŭ���̾�Ʈ ������ ��Ÿ���� �簢��

    HDC							m_hDCFrameBuffer = NULL;	// hdc:���� �������� Ŭ���̾�Ʈ ������ ����ϱ����� Ŭ���̾�Ʈdc
    HBITMAP						m_hBitmapFrameBuffer = NULL;
    HBITMAP						m_hBitmapSelect = NULL;

	CPlayer*					m_pPlayer = NULL;			// �÷��̾� ������Ʈ

	CScene*						m_pScene = NULL;			// ���� ������Ʈ���� ����Ʈ

	CGameTimer					m_GameTimer;

	POINT						m_ptOldCursorPos;

public:
	void OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	void OnDestroy();

	void BuildFrameBuffer();
	void ClearFrameBuffer(DWORD dwColor);
	void PresentFrameBuffer();

	void BuildObjects();
	void ReleaseObjects();

	void ProcessInput();
	void AnimateObjects();
	void FrameAdvance();

	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

