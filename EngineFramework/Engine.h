#pragma once

// Ctrl + K / Ctrl + O.
class Engine
{
	// 키 입력 처리를 위한 구조체.
	struct KeyState
	{
		// 현재 프레임에 키가 눌렸는지 알려주는 변수.
		bool isKeyDown = false;

		// 이전 프레임에 키가 눌렸는지 알려주는 변수.
		bool previousKeyDown = false;
	};

public:
	// 함수.
	Engine();
	~Engine();

	// 실행 함수.
	void Run();

	// 종료 함수.
	void Quit();

	// 키 입력 확인 함수.
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	// 싱글톤 인스턴스를 반환하는 함수.
	static Engine& Get();

protected:
	// 엔진 루프.
	void ProcessInput();
	void Update(float deltaTime);
	void Draw();

private:
	// 변수.
	// 싱글톤을 위한 정적 변수.
	static Engine* instance;

	// 키 입력 상태를 저장하는 배열.
	KeyState keyStates[255];

	// 엔진 종료 플래그.
	bool isQuit = false;
};