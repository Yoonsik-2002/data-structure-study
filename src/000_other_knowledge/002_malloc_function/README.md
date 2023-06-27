## 형(Type)이 존재하지 않는 `void 형 포인터`
`void 형 포인터` 는 다음과 같이 선언된다.<br>
```c
void * ptr;
```
이러한 `void 형 포인터`는 **'무엇이든 담을 수 있는 바구니'** 로 비유가 가능하다. `void 형 포인터 변수` 에는 어떠한 변수의 주소값이든 <br>
담을 수 있기 때문이다. 심지어 아래 예시코드와 같이 함수의 주소값도 담을 수 있다.<br>
```c
#include <stdio.h>

void simpleFunc(void)
{
	printf("simple function");
}

void main()
{
	void * ptr; // void 형 포인터 선언
	
	int num = 20;
	float score = 4.5;
	char mark = 'A';
	
	ptr = &num;
	printf("%p \n", ptr);
	ptr = &score;
	printf("%p \n", ptr);
	ptr = &mark;
	printf("%p \n", ptr);
	
	ptr = simpleFunc;
	printf("%p \n", ptr);
}
```
**[실행결과]**<br>
```c
0x7fff6ba7a708
0x7fff6ba7a70c
0x7fff6ba7a707
0x560e568f3685
```
이렇게 어떠한 변수든 간에 상관 없이 주소값을 저장할 수 있는 `void 형 포인터`가 마냥 좋아보일 수는 있지만, 해당 포인터의 단점 또한 존재한다.<br>
`void 형 포인터`로는 아무런 포인터 연산도 하지 못한다. 또 값의 변경이나 참조 또한 불가능 하다.<br>

이유는 `void 형 포인터 변수`에는 가리키는 대상의 어떠한 type 정보도 담겨있지 않기 때문이다.<br>
```c
int num = 7;
void * ptr = &num;
```
위 경우, 포인터 `ptr` 에는 `num` 즉, 7이 메모리에서 차지하는 모든 주소들의 위치가 들어가는 것이 아니라, 이 주소들 중, <br>
첫 번째 주소값이 들어가게 된다. <br>

따라서, 이 상태에서 `*ptr` 이라고 했을 때, 컴퓨터는 해당 포인터가 가리키는 대상의 형 정보를 모르기 때문에,<br>
시작주소로부터 얼만큼을 읽어들여야 할 지를 모르게된다.<br>
(만약, `int * ptr = &num` 인 경우, `*ptr`은 시작주소로 부터 4byte만큼 읽어들여 가리키는 대상의 값을 가져옴)<br>

따라서, 이러한 **`void 형 포인터`는 일단 먼저 주소값에만 의미를 두고, 포인터 형은 나중에 결정하는 상황**에 유용하게 사용한다.<br>

<br><br>


## 자유 저장소(힙 영역)의 메모리 공간 할당과 해제
자유 저장소(힙 영역)는 자동 저장소(스택 영역)와는 달리, 프로그래머가 원하는 시점에 자유롭게 메모리 공간을 할당하고 해제하는 것이 가능하다.<br>

이를 통해 함수가 매번 호출될 때마다 할당되고, 또 함수를 빠져나가도 직접 해제하기 전 까지는 유지가 되는, 생성과 소멸의 시기가 지역변수나 <br>
전역변수와는 완전히 다른 유형의 변수를 만들 수 있다!<br>

이렇게 자유 저장소의 메모리 공간을 할당하기 위해서는 `malloc()` 함수를 사용하고, 해제하기 위해서는 `free()` 함수를 사용한다.<br>
이 두 함수의 사용법에 대해 알아보겠다.<br><br>

- #### `malloc()` 함수와 `free()` 함수의 기능
  - **`malloc()`** 함수는 인자로 전달받은 정수 값 만큼에 해당하는 바이트 크기의 메모리 공간을 자유 저장소(힙 영역)에 할당한다.<br>
    그리고, 해당 메모리 공간의 주소 값(할당된 메모리 공간의 첫 번째 바이트의 주소값)을 반환한다.<br>
  
  - **`free()`** 함수는 `malloc()` 함수를 통해 힙 영역에 할당된 메모리 공간을 해제한다.<br>
<br>

- #### `malloc()` 함수와 `free()`함수의 사용
  ```c
  void main()
  {
    void* ptr1 = malloc(4);
    void* ptr2 = malloc(8);  
    ...
    free(ptr1);
    free(ptr2);
  }
  ```
  **`void* ptr1 = malloc(4);`** - 힙 영역에 4byte 만큼의 메모리 공간을 할당하고 해당 공간의 주소값(첫 번째 바이트의 주소값)<br>
  을 포인터 변수 `ptr1`에 반환<br>
  
  **`void* ptr2 = malloc(8);`** - 힙 영역에 8byte 만큼의 메모리 공간을 할당하고 해당 공간의 주소값(첫 번째 바이트의 주소값)<br>
  을 포인터 변수 `ptr2`에 반환<br>
  
  **`free(ptr1)`** - 포인터 변수 `ptr1`이 가리키고 있는 `malloc()` 함수를 이용하여 힙 영역에 할당한 메모리 공간을 해제한다.<br>
  
  **`free(ptr2)`** - 포인터 변수 `ptr2`가 가리키고 있는 `malloc()` 함수를 이용하여 힙 영역에 할당한 메모기 공간을 해제한다.<br><br>
  
- #### `malloc()` 함수의 반환형
  위의 예시코드를 잘 보면, `malloc()` 함수가 반환한 메모리의 주소값을 저장하는 포인터 변수 `ptr1`의 자료형이 `void형 포인터`인 것을 알 수 있다.<br>
  그 이유는 `malloc()` 함수의 반환형이 `void형 포인터` 이기 때문이다.<br>
  따라서 `malloc()` 함수는 특별한 자료형 없이, 메모리의 첫 번째 바이트의 주소값만 반환한다.<br>
  
  - #### `void형 포인터`의 특성
    - 주소값이라면 무엇이든 담을 수 있는 만능상자이다.
    - type 정보가 없기 때문에 접근(포인터 연산)이 불가능하다. 포인터 연산이 가능하게 하려면 다음과 같은 형변환을 해주어야 한다.<br>
    
      ```c
      void* ptr1 = malloc(4);  *ptr1 = 20; // type 정보가 없기 때문에 포인터 연산 불가능
      int* ptr1 = (int*)malloc(sizeof(4));  *ptr1 = 20; // 포인터 연산 가능
      ```
<br>

- #### `malloc()` 함수의 반환형이 `void형 포인터`인 이유
  `malloc()` 함수의 반환형이 `void형 포인터`인 이유는 `malloc()`함수의 일반적인 호출 형태와 `sizeof()`연산이 이루어진 후,<br>
  실질적으로 이루어지는 `malloc()` 함수의 호출을 보면 알 수 있다.<br>
  
  - #### malloc 함수의 일반적인 호출 형태
    ```c
    void * ptr1 = malloc(sizeof(int));
    void * ptr2 = malloc(sizeof(double));
    void * ptr3 = malloc(sizeof(int)*7);
    void * ptr4 = malloc(sizeof(double)*9);
    ```
  - #### sizeof 연산 이후 실질적인 malloc 함수 호출
    ```c
    void * ptr1 = malloc(4);
    void * ptr2 = malloc(8);
    void * ptr3 = malloc(28);
    void * ptr4 = malloc(72);
    ```
  결국 전달받은 바이트크기만큼 메모리를 할당하는 malloc함수 입장에서는 sizeof 연산 후 실질적으로는 달랑 숫자정보밖에 전달받지 못한다. <br>
  때문에, 할당하는 메모리의 용도가 int형인지, float형인지, char형 배열인지 도무지 알 수가 없다.<br>
  
  그렇기 때문에 일단은 어떤 주소값이든 담을 수 있는 void형 포인터로 반환한다.<br>
  
  malloc 함수는 원하는 크기만큼 heap영역에 메모리 공간을 할당하고, 그 메모리의 주소값(메모리의 첫 번째 byte의 주소값)을 void형 포인터로 반환한다.<br>
  따라서 프로그래머는 void형으로 반환되는 주소값을 원하는 type으로 적절히 형변환하여 할당된 메모리 공간에 접근해야 한다.<br><br>
  
- #### 형 변환을한 malloc 함수의 호출 형태
  ```c
  int * ptr1 = (int*)malloc(sizeof(int));
  double * ptr2 = (double*)malloc(sizeof(double));
  int * ptr3 = (int*)malloc(sizeof(int)*7);
  double * ptr4 = (double*)malloc(sizeof(double)*9);
  ```
<br><br>

---
