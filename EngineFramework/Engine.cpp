#include "Engine.h"
#include <Windows.h>

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
	// 엔진 루프 구성.
	while (true)
	{
		// 입력 처리.
		ProcessInput();

		// 업데이트.
		Update(1.0f / 60.0f);

		// 그리기.
		Draw();

		// 키 입력 정리.
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].previousKeyDown = keyStates[ix].isKeyDown;
		}
	}
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
}

void Engine::Update(float deltaTime)
{
}

void Engine::Draw()
{
}