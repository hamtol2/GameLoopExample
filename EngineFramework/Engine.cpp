#include "Engine.h"
#include <Windows.h>
#include <iostream>
// Ctrl + -.

// 정적 변수 정의.
Engine* Engine::instance = nullptr;

Engine::Engine()
{
	// 싱글톤 인스턴스 초기화.
	instance = this;
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// 하드웨어 타이머의 주파수를 저장.
	LARGE_INTEGER frequency;

	// 주파수 가져오기.
	QueryPerformanceFrequency(&frequency);

	// 프레임 계산.
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	QueryPerformanceCounter(&currentTime);

	previousTime = currentTime;

	// 목표 프레임 속도.
	float targetFrameRate = 120.0f;

	// 목표하는 한 프레임 시간.
	float oneFrameTime = 1.0f / targetFrameRate;

	// 엔진 루프 구성.
	while (true)
	{
		// 엔진 종료 확인.
		if (isQuit)
		{
			break;
		}

		// 입력 처리.
		ProcessInput();

		// 프레임 시간 계산.
		QueryPerformanceCounter(&currentTime);

		// 프레임 간격 계산.
		float deltaTime =
			static_cast<float>(currentTime.QuadPart - previousTime.QuadPart)
			/ static_cast<float>(frequency.QuadPart);

		// 목표하는 프레임 속도를 만족하는지 확인.
		if (deltaTime > oneFrameTime)
		{
			// 업데이트.
			// Ctrl + Home.
			Update(deltaTime);

			// 그리기.
			Draw();

			// 키 입력 정리.
			for (int ix = 0; ix < 255; ++ix)
			{
				keyStates[ix].previousKeyDown = keyStates[ix].isKeyDown;
			}

			// 프레임 시간 기록.
			previousTime = currentTime;
		}
	}
}

void Engine::Quit()
{
	// 종료 플래그 설정.
	isQuit = true;
}

bool Engine::GetKey(int keyCode)
{
	return keyStates[keyCode].isKeyDown && keyStates[keyCode].previousKeyDown;
}

bool Engine::GetKeyDown(int keyCode)
{
	return keyStates[keyCode].isKeyDown && !keyStates[keyCode].previousKeyDown;
}

bool Engine::GetKeyUp(int keyCode)
{
	return !keyStates[keyCode].isKeyDown && keyStates[keyCode].previousKeyDown;
}

Engine& Engine::Get()
{
	return *instance;
}

void Engine::ProcessInput()
{
	// 키 입력 저장.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].isKeyDown = GetAsyncKeyState(ix) & 0x8000 ? true : false;
	}

	// ESC 키 종료.
	if (GetKeyDown(VK_ESCAPE))
	{
		// 엔진 종료.
		Quit();
	}
}

void Engine::Update(float deltaTime)
{
	std::cout 
		<< "Update() deltaTime: " << deltaTime 
		<< ", FPS: " << (1.0f / deltaTime) 
		<< "\n";
}

void Engine::Draw()
{
}