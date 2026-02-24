#include <iostream>

// 실패 오류 값.
#define FAIL -1

// 재귀적 이진 탐색.
// array : 자료를 가진 배열.
// target : 찾으려는 값.
// start : 검색 시작 인덱스.
// end : 검색 끝 인덱스.
int RecursiveBinarySearch(
	int* array,
	int target,
	int start,
	int end)
{
	// 종료 조건
	if (start > end)
	{
		return -1;
	}

	// 중간 인덱스
	int mid = (start + end) / 2;

	// 검색 성공 여부 확인. 인덱스를 반환.
	if (array[mid] == target)
	{
		return mid;
	}

	// 왼쪽 부분 배열 검색.
	else if (array[mid] > target)
	{
		RecursiveBinarySearch(array, target, start, mid - 1);
	}

	// 오른쪽 부분 배열 검색.
	else
	{
		RecursiveBinarySearch(array, target, mid + 1, end);
	}

}

// 반복적 이진 탐색 함수.
int IterativeBinarySearch(
	int* array,
	int target,
	int start,
	int end)
{
	// 조건부 무한 루프
	while (start <= end)
	{
		// 중간 인덱스 구하기.
		int mid = (start + end) / 2;

		// 찾았는지 확인.
		if (array[mid] == target)
		{
			return mid;
		}

		// 왼쪽 검색.
		if (array[mid] > target)
		{
			end = mid - 1;
		}
		
		// 오른쪽 탐색
		else if(array[mid] < target)
		{
			start = mid + 1;
		}
	}
	// 못 찾은 경우 실패.
	return FAIL;
}

int main()
{
	// 배열.
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 찾을 값.
	int target = 9;

	// 배열 길이 (end 인덱스).
	int length = sizeof(array) / sizeof(array[0]);


	// 이진 탐색.
	//int targetIndex = RecursiveBinarySearch(array, target, 0, length - 1);
	int targetIndex = IterativeBinarySearch(array, target, 0, length - 1);


	if (targetIndex != FAIL)
	{
		std::cout << "Value : " << target << "\nfound index : " << targetIndex << "\n";
	}
	else
	{
		std::cout << "Value " << target << " not found\n";
	}
	
	std::cin.get();
}