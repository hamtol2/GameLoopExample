#include "Engine.h"
#include <Windows.h>
#include <iostream>
// Ctrl + -.

// ���� ���� ����.
Engine* Engine::instance = nullptr;

Engine::Engine()
{
	// �̱��� �ν��Ͻ� �ʱ�ȭ.
	instance = this;
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// �ϵ���� Ÿ�̸��� ���ļ��� ����.
	LARGE_INTEGER frequency;

	// ���ļ� ��������.
	QueryPerformanceFrequency(&frequency);

	// ������ ���.
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	QueryPerformanceCounter(&currentTime);

	previousTime = currentTime;

	// ��ǥ ������ �ӵ�.
	float targetFrameRate = 120.0f;

	// ��ǥ�ϴ� �� ������ �ð�.
	float oneFrameTime = 1.0f / targetFrameRate;

	// ���� ���� ����.
	while (true)
	{
		// ���� ���� Ȯ��.
		if (isQuit)
		{
			break;
		}

		// �Է� ó��.
		ProcessInput();

		// ������ �ð� ���.
		QueryPerformanceCounter(&currentTime);

		// ������ ���� ���.
		float deltaTime =
			static_cast<float>(currentTime.QuadPart - previousTime.QuadPart)
			/ static_cast<float>(frequency.QuadPart);

		// ��ǥ�ϴ� ������ �ӵ��� �����ϴ��� Ȯ��.
		if (deltaTime > oneFrameTime)
		{
			// ������Ʈ.
			// Ctrl + Home.
			Update(deltaTime);

			// �׸���.
			Draw();

			// Ű �Է� ����.
			for (int ix = 0; ix < 255; ++ix)
			{
				keyStates[ix].previousKeyDown = keyStates[ix].isKeyDown;
			}

			// ������ �ð� ���.
			previousTime = currentTime;
		}
	}
}

void Engine::Quit()
{
	// ���� �÷��� ����.
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
	// Ű �Է� ����.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].isKeyDown = GetAsyncKeyState(ix) & 0x8000 ? true : false;
	}

	// ESC Ű ����.
	if (GetKeyDown(VK_ESCAPE))
	{
		// ���� ����.
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