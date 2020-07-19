#include <iostream>
#include "TimeElapsed.h"

int main(int argc, char *argv[])
{
	// コマンドライン引数を数値変換
	int pps = strtol(argv[1], nullptr, 10);
	// 指定された秒間処理回数から1枚あたり時間算出(秒単位の実数)
	// (誤差を考慮して0.5ゲタを履かせる)
	double duration = 1000.0 / (pps + 0.5) / 1000;

    std::cout << "pps = " << pps << std::endl;
    std::cout << "duration = " << duration << std::endl;

	char buff[32] = { 0 };

	// 処理毎の時間計測用
	TimerElapsed durationPerProc;
	// トータル時間計測用
	TimerElapsed totalDuration;

	totalDuration.restart();
	for (int cnt = 0; cnt < pps; cnt++)
	{
		// 計測開始
		durationPerProc.restart();
		// 処理を行う
		//std::cout << cnt << std::endl;
		// 1処理あたりの時間が経過するまで待ち
		while (durationPerProc.elapsed() < duration)
		{
			Sleep(0);
		}
	}
	snprintf(buff, sizeof(buff), "%f", totalDuration.elapsed());
	std::cout << "total duration = " << buff << std::endl;
}
