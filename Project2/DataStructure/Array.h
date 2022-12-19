#pragma once

/*
* 정적인 크기를 갖고 있음
* 인덱스 번호로 데이터에 접근 가능(O(1) 접근)
* 
* 배열의 크기 조절이 힘듦(O(n))
*/

struct Array {
	void* data = NULL;
	UINT length = 0;

	void SetLength(UINT n) {
		
		length = n;
		data = new int[length];

		for (UINT i = 0; i < length; i++) {
			((int*)data)[i] = i;//배열 생성시 해당 인덱스 번호의 숫자를 데이터로 넣어줌
		}
	}

	void Print() {
		for (UINT i = 0; i < length; i++) {
			printf("%d\n", ((int*)data)[i]);//모든 데이터 출력
		}
	}

	int* GetData() {
		return (int*)data;//데이터 반환
	}

	UINT Length() {
		return length;//배열의 길이 반환
	}

	void Delete() {
		delete[] data;//데이터 삭제
	}
};