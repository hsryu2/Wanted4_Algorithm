#include <iostream>
#include <Windows.h>

// 삽입 정렬 함수.
void InsertionSort(int* array, int length)
{
	// 예외 처리.
	if (length <= 1)
	{
		return;
	}

	// 배열 순회.
	for (int i = 1; i < length; i++)
	{
		// 현재 삽입할 값.
		int key = array[i];
		int j = i - 1;

		// key보다 큰 값은 오른쪽으로 배치.
		// key값을 따로 빼놔서 바로 바꿔도 문제없음.
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}

		// 적절한 위치에 삽입.
		// while에서 이미 j를 하나 빼놨기 때문에 하나 더해준다.
		array[j + 1] = key;
	}
}


// 배열 항목 출력 함수.
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i];

		// 마지막 원소 전까지는 콤마 출력.
		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 항목 개수 구하기.
	int length = ARRAYSIZE(array);

	// 정렬 전 배열 출력
	std::cout << "정렬 전 배열 : ";
	PrintArray(array, length);

	InsertionSort(array, length);

	std::cout << "정렬 후 배열 : ";
	PrintArray(array, length);


}