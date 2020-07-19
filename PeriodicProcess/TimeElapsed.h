#pragma once
#include <Windows.h>

// QueryPerformanceCounter() を使った時間計測タイマー クラス
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
		QueryPerformanceCounter(&start);        // 計測開始時間を保存
	}

	double elapsed()    // リスタートからの秒数を返す
	{
		QueryPerformanceCounter(&end);
		return (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	}
};
