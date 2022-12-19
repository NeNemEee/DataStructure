#pragma once

/*
* ������ ũ�⸦ ���� ����
* �ε��� ��ȣ�� �����Ϳ� ���� ����(O(1) ����)
* 
* �迭�� ũ�� ������ ����(O(n))
*/

struct Array {
	void* data = NULL;
	UINT length = 0;

	void SetLength(UINT n) {
		
		length = n;
		data = new int[length];

		for (UINT i = 0; i < length; i++) {
			((int*)data)[i] = i;//�迭 ������ �ش� �ε��� ��ȣ�� ���ڸ� �����ͷ� �־���
		}
	}

	void Print() {
		for (UINT i = 0; i < length; i++) {
			printf("%d\n", ((int*)data)[i]);//��� ������ ���
		}
	}

	int* GetData() {
		return (int*)data;//������ ��ȯ
	}

	UINT Length() {
		return length;//�迭�� ���� ��ȯ
	}

	void Delete() {
		delete[] data;//������ ����
	}
};