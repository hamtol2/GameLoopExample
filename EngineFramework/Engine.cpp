#include "Engine.h"
#include <Windows.h>

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
	// ���� ���� ����.
	while (true)
	{
		// �Է� ó��.
		ProcessInput();

		// ������Ʈ.
		Update(1.0f / 60.0f);

		// �׸���.
		Draw();

		// Ű �Է� ����.
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
	// Ű �Է� ����.
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