#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // 스택의 최대 크기 지정

typedef int element; // 데이터 자료형 지정
element stack[MAX]; // 1차원 배열
int top = -1;

// 스택 초기화 함수
void init() {
	for (int i = 0; i < MAX; i++) {
		stack[i] = 0;
	}
	top = -1;
}

// 스택 공백상태 검출 함수
int is_Empty() {
	return (top == -1);
}

// 스택 포화상태 검출 함수
int is_full() {
	// 가장 최근에 들어온 값의 인덱스를 지정하는 top이 최대크기-1과 같으면
	// 스택에 최대 크기만큼 인덱스에 접근했다는 의미
	return (top == (MAX - 1)); 
}

// 스택에 데이터를 삽입하는 함수
void push(element item) {
	// 스택이 포화상태라면
	if (is_full()) {
		printf("스택 포화 상태\n");
		return; // 함수 종료
	}
	else
		stack[++top] = item; // top은 -1로 시작하므로 전위증가 후 데이터 삽입
}

// 스택에 데이터를 삭제하는 함수
element pop() {
	// 스택이 공백상태라면
	if (is_Empty()) {
		printf("스택 공백 상태\n");
		exit(1); // 프로그램 종료
	}
	else
		return stack[top--]; // 최상위 값을 리턴 후 top 변수를 후위감소
}

void printStackElement() {
	for (int i = top; i >= 0; i--) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	int T = 0;
	element data = 0; // 스택에 삽입할 데이터

	// 테스트 케이스 입력
	for (scanf("%d", &T); T--;) {
		init();
		while (1) {
			scanf("%d", &data);

			// -1 입력 시 데이터 입력 종료
			if (data == -1)
				break;

			push(data);
		}
		printStackElement(); // 스택의 모든 요소 출력, LIFO 방식
	}
}
