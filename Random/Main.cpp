#include <iostream>
#include <time.h>

// 나눗셈을 활용한 랜덤.
int RandomRange(int min, int max) 
{
	// 범위의 차이
	int diff = (max - min) + 1;

	// 나눗셈을 이용해서 원하는 범위의 랜덤 변환.
	// rand() / (RAND_MAX + 1) -> 0 또는 1만 나오는 난수 발생기.
	// 따라서 이걸 범위의 차이만큼 곱하면 0 ~ diff만 나오는 난수 발생기가 된다.
	// 이후 뒤에 최소 범위를 더 해주면 min ~ max 난수 발생기가 완성된다.
	return ((diff * rand()) / (RAND_MAX + 1)) + min;

}

// 나눗셈을 이용한 랜덤(부동소수점-flaot)
float RandomPercent()
{
	// 0~1사이의 부동소수점 값을 반환하는 랜덤 함수.
	return rand() / static_cast<float>(RAND_MAX);
}

// 범위를 지정해 사용하는 랜덤 함수(부동소수형).
float RandomRange(float min, float max)
{
	// min-max 사이의 차 구하기.
	float diff = max - min;
	return (RandomPercent() * diff) + min;
}

int main()
{
	// 종자값(Seed) 설정.
	// srand(100);
	srand(static_cast<unsigned int>(time(nullptr)));

	std::cout << "Random : " << RandomRange(1.0f,10.0f) << "\n";
	std::cout << "Random : " << RandomRange(1.0f, 10.0f) << "\n";
	std::cout << "Random : " << RandomRange(1.0f, 10.0f) << "\n";

	std::cin.get();
}