#pragma once
#include <Windows.h>

// QueryPerformanceCounter() ���g�������Ԍv���^�C�}�[ �N���X
class TimerElapsed
{
private:
	LARGE_INTEGER freq;
	LARGE_INTEGER start, end;

public:
	TimerElapsed()
	{
		QueryPerformanceFrequency(&freq);
		restart();
	}

	void restart()
	{
		QueryPerformanceCounter(&start);        // �v���J�n���Ԃ�ۑ�
	}

	double elapsed()    // ���X�^�[�g����̕b����Ԃ�
	{
		QueryPerformanceCounter(&end);
		return (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	}
};
