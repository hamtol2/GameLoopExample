#pragma once

// Ctrl + K / Ctrl + O.
class Engine
{
	// Ű �Է� ó���� ���� ����ü.
	struct KeyState
	{
		// ���� �����ӿ� Ű�� ���ȴ��� �˷��ִ� ����.
		bool isKeyDown = false;

		// ���� �����ӿ� Ű�� ���ȴ��� �˷��ִ� ����.
		bool previousKeyDown = false;
	};

public:
	// �Լ�.
	Engine();
	~Engine();

	// ���� �Լ�.
	void Run();

	// �̱��� �ν��Ͻ��� ��ȯ�ϴ� �Լ�.
	static Engine& Get();

protected:
	// ���� ����.
	void ProcessInput();
	void Update(float deltaTime);
	void Draw();

private:
	// ����.
	// �̱����� ���� ���� ����.
	static Engine* instance;

	// Ű �Է� ���¸� �����ϴ� �迭.
	KeyState keyStates[255];
};