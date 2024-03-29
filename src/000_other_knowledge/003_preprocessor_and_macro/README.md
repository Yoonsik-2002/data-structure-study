# 매크로와 선행 처리
매크로와 선행처리에 대해 알아보자. 먼저, 선행처리란 무엇일까? 선행처리는 소스파일에서 실행파일을 생성하는 '실행파일 생성과정'의<br>
여러 단계 중 하나로, 컴파일을 하기전에 진행되는 과정이다.<br>
<br>


## 실행파일 생성 과정
실행파일은 '선행처리' 라는 과정을 거친 뒤, 컴파일과 링크의 과정을 거쳐서 만들어진다. 이 과정들을 통틀어 **실행파일 생성 과정** 이라 한다.<br>
각 과정에서 선행처리는 선행처리기에 의해, 컴파일은 컴파일러에 의해, 링크는 링커에 의해 진행된다. <br>

이러한 실행파일 생성과정을 그림으로 나타내면 다음과 같다.<br>

![B9190FFB-3D74-47CE-A4F0-9C5A7BF2125E](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/4308c4a0-7212-4afb-a40a-e7f0f7b11a3e)<br>

이 그림을 보면, 선행처리된 소스파일이 컴파일러를 거쳐, 컴파일 되면, 기존 소스파일은 컴퓨터가 읽을 수 있는 기계어로 번역되어, <br>
바이너리 데이터로 이루어진 오브젝트 파일로 생성되는 것을 알 수 있다.<br>

그럼, 이전 단계인 맨 처음에 소스파일이 선행처리기를 통해 선행처리가 되면, 어떠한 형태의 파일로 생성될까?<br>

답은 선행처리 과정을 거치고 나서 생성된 소스파일 또한 그냥 소스파일일 뿐이다. 그럼 변화가 없는 것인가?<br>
아니다. 소스파일의 일부 내용이 소스파일 내, **선행처리 명령문** 대로 수정되게 된다.<br>
<br>

### 실행파일 생성과정 - 선행처리 과정
선행처리에서 '선행' 이란, 컴파일 과정 이전의 처리를 의미한다. 때문에, 선행처리 명령문은 '컴파일 과정 이전 단계인 선행처리 과정에서<br>
선행처리기에 의해 처리되는 소스파일 내 명령문' 이라고 할 수 있겠다.<br>

아주 간단한 선행처리 명령문의 예시를 들어보겠다. 선행처리 명령문은 다음과 같은 형태를 띈다.<br>

**`#define  PI   3.14`**<br>

이처럼, 선행처리 명령문은 **`#`** 으로 시작하며, 컴파일러가 아닌 선행처리 과정에서 선행처리기에 의해 처리되는 명령문이기 때문에, <br>
끝에 세미콜론(**`;`**)이 붙지 않는다.<br>

그럼, 위의 선행처리 명령문의 예시가 의미하는 바는 무엇일까? 바로, *'해당 소스파일 내에서 `PI` 를 만나게 되면 무조건 3.14로 치환 하세요!'*<br>
라는 의미이다.<br> 

이러한 선행처리 명령문이 포함되어 있는 소스파일은 실행파일의 생성 과정 중, 선행 처리 과정에서 다음 그림과 같은 방식으로 변환되게 된다.<br>

![69C9A1F5-6CAC-41E2-81CE-DE7061683C21](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f1be3112-a3ac-414f-bc40-3a60b7c29ec8)<br>

소스파일이 선행처리기에 의해 선행처리 되면서, `PI`는 3.14로 치환되고, 소스파일 상단에 있던 선행처리 명령문은 사라지게 된다.<br>

> `#include <stdio.h>` 또한 선행처리 명령문이다.<br>
  `stdio.h`파일은 C언어가 기본적으로 제공하는 표준 라이브러리 내에서, 표준 입출력(Standard Input/Output)에 대한 선언을 모아놓은 헤더파일이다.<br>
  이 `#include <stdio.h>` 선행처리 명령문은 `stdio.h` 파일의 내용을 해당 명령문의 위치에 가져다 놓으라는 뜻이 된다.<br>
  결국 stdio.h 파일 안의 내용을 그대로 `#include <stdio.h>` 선행처리 명령문의 위치에 옮겨다 놓는 것이랑 똑같은 효과가 일어나게 된다!<br>
  
<br><br>

## 선행처리 명령문
선행처리가 무엇인지 알아보았으니, 선행처리 시, 선행처리기가 처리하게 되는 선행처리 명령문에 대해 알아보도록 하겠다.<br>
<br>

### `#define: Object-like macro`(오프젝트와 유사한 매크로, 매크로 상수)
위에서 앞서 정의한 선행처리 명령문(`#define  PI   3.1415`)을 가지고 선행처리 명령문의 구성에 대해 알아보도록 하겠다.<br>
선행처리 명령문의 구조는 아래 그림과 같다.<br>

![E3DEFDF2-F39F-4BB8-A948-10CF0EFCA3B1](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/3166cd40-6924-47b8-aadc-69e924d89528)<br>

먼저, 선행처리 명령문에서 첫 번째로 등장하는 `#define`을 가리켜, '지시자'라고 부른다. 컴파일 전, 선행처리를 수행하는 선행처리기가<br>
이 '지시자'를 보고 프로그래머가 지시하는 바를 파악한다. (이러한 매크로 지시자는 #define 말고도 여러 종류가 존재한다!)<br>

위 선행처리 명령문에서 매크로를 정의하는 역할을 하는 지시자 `#define`은 선행처리기에게 다음과 같은 프로그래머의 지시를 전달한다.<br>
*'이어서 나오는 매크로를 매크로 몸체로 치환해라'*<br>

그리고, 지시자 다음으로 선행처리 명령문을 구성하는 요소 2가지를 각각 순서대로 '매크로', '매크로 몸체' 라고 한다. <br>
따라서 결론적으로, 위 선행처리 명령문은 선행처리기에 다음과 같은 지시를 하게 된다.<br>
*'매크로 `PI`를 메크로 몸체 3.1415로 전부 치환해라'*<br>

결과적으로 매크로 `PI`는 그 자체로 변경할 수 없는 상수 3.1415가 된다. 이러한 매크로(여기서는 `PI`)를 가리켜, **오브젝트와 유사한 매크로**, <br>
또는 간단하게 **매크로 상수** 라고 한다.<br>

이러한 매크로의 이름은 일반적으로, 대문자로 정의한다. 대문자로 정의함으로써 이 식별자가 매크로라는 사실을 부각시킬 수 있기 때문이다.<br>
<br>

### `#define: Function-like macro`(함수와 유사한 매크로, 매크로 함수)
매크로는 매개변수가 있는 형태로도 선언이 가능하다. 이렇게 매개변수가 있는 매크로의 경우, 작동방식이 함수와 유사하여, Function-like macro,<br>
함수와 유가한 매크로 혹은 매크로 함수 라고 부른다.<br>

매크로 함수의 예는 아래 그림과 같다.<br>

![D1B0B4F9-FD09-402F-BB0F-B6126AA85AC2](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/3daf6128-1163-48b7-9704-0ae81df1bda4)<br>

이렇게 정의된 매크로를 접한 선행처리기는 *'`SQUARE(X)`와 같은 패턴을 만나면 `X*X` 로 치환해라!'* 라는 프로그래머의 지시를 매크로를 통해<br>
전달받고, 그대로 `SQUARE(X)`와 같은 패턴을 만나게 되면, `X*X` 로 치환해 버린다.<br>

이런 `SQUARE(X)` 매크로가 정의된 후, 선행처리 과정에 선행처리기가 다음과 같은 매크로 함수를 만나게 되면, 그 다음 아래 그림과 같은 변환이 일어난다.<br>
```c
SQUARE(10);
SQUARE(num);
```
<br>

![25104E05-D460-406A-A375-983823FD3E91](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f85b7fc3-7e6a-472c-b10e-ec0936818c4f)<br>

이렇게 선행처리기에 의해서 변환되는 과정 자체를 **매크로 확장(Macro Expansion)** 이라고 한다.<br>
<br>

## 매크로 함수 정의시 주의할 점
다음은 이 매크로 함수를 이용한 간단한 프로그램이다. 해당 프로그램에서는 비정상적인 출력이 일어나는데 해당 이유를 분석해보도록 하겠다.<br>
```c
#include <stdio.h>

#define SQUARE(X) X*X

void main()
{
	int num = 7;
	
	// 정상적인 출력
	printf("square of num : %d\n", SQUARE(num));
	printf("square of 20 : %d\n", SQUARE(20));
	printf("square of -5 : %d\n", SQUARE(-5));
	
	// 비정상적인 출력
	printf("square of 3+5 : %d\n", SQUARE(3+5));
}
```
*[macro_function.c 의 실행결과]*
```
square of num : 49
square of 20 : 400
square of -5 : 25
square of 3+5 : 23
```

위 코드에서, 비정상적인 출력이 일어난 `printf("square of 3+5 : %d\n", SQUARE(3+5));` 코드에 주목해 보겠다.<br>
매크로 함수 `SQUARE(3+5)`를 우리가 잘 아는 일반 함수의 관점으로 보면, 인자로 전달되는 `3+5`는 먼저 선행처리기에 의해 계산이 되어,<br>
8로 `SQUARE` 함수에 전달이 되어야 한다.<br>
그리고, `SQUARE(8)`과 같은 패턴은 위에서 선언된 대로 `8*8`로 치환되어, 결과는 `64`가 나와야 한다.<br>
하지만, 해당 매크로 함수의 결과는 보다시피, `23`이 된다. 어떻게 이런 결과가 나온 것일까?<br>

답은 **선행처리기의 역할**에 있다. 위에서 함수의 관점으로 매크로 함수 `SQUARE(3+5)`를 설명하였을 때, 인자로 전달되는 `3+5`는 선행처리기에 의해<br>
계산이 된다고 하였다. 이 설명은 틀린설명이다!<br>

**위 설명과 같이 함수의 인자로 전달된 수식을 미리 계산하고, 해당 연산 결과를 가지고 함수를 호출해주는 것은 컴파일러의 역할이지, 선행처리기가<br>
수행하는 역할이 아니다!**<br>

선행처리기는 매크로 함수가 선언된 대로 어떠한 패턴(`매개변수가 있는 매크로(매크로 함수)`)을 미리 정의한 수식(`매크로 몸체`)으로 치환해줄 뿐이지,<br>
컴파일러처럼 전달된 수식 형태의 인자를 미리 계산하여 함수를 호출해주지 않는다.<br>

결국, 실질적으로 해당 코드에서 매크로 함수 `SQUARE(3+5)`는 선행처리기에 의해 아래와 같은 수식으로 치환되게 된다. <br>
```c
3+5*3+5
```
이러한 이유 때문에, `SQUARE(3+5)`의 결과가 `23`이 나오게 된것이다.<br>

그렇다면, 매크로 함수 `SQUARE(3+5)`의 결과가 우리가 의도한 `64`가 되도록 하려면 어떻게 해야 할까?<br>
먼저, 첫 번째로 가장 단순한 방법으로는 `SQUARE((3+5))`로 호출해주면, 해당 매크로 함수는 실행파일 생성 과정에서, 선행처리기에 의해<br>
`(3+5)*(3+5)` 로 치환되어 `64`라는 결과가 나오게 된다.<br> 

하지만 이러한 방법은 안정적인 형태라 할 수 없다.<br>

그렇다면, 애초에 `SQUARE`함수를 정의할 때 매크로 몸체에 괄호처리를 한 상태로 정의해보면 어떨까?<br>
아래와 같이 정의해 보면, 이미 매크로 몸체에 괄호처리가 되어있기 때문에 `SQUARE(3+5)`로 호출해도 `64`라는 결과를 얻을 수 있다.<br>
```c
#define  SQUARE(X)   (X)*(X)
```
하지만, 위 코드도 완벽한 해답은 아니다.<br>

예를 들어보겠다. `int num = 120 / SQUARE(1+1)`의 경우, 변수 `num`에는 우리가 의도한 `30`이 초기화 되는 것이 아니라, `120`이 초기화 된다.<br>
이유는 다음과 같다. 해당 매크로 함수 선행처리기에 의해서 매크로 몸체로 치환되면, 다음과 같은 수식이 이루어진다.<br>
```c
int num = 120 / (1+1)*(1+1);
```
120을 2로 나누고, 다시 2를 곱해주는 꼴이 되는 것이다.<br>

이러한 문제를 해결하기 위해서는 **매크로 함수를 정의할 때 매크로 몸체를 구성하는 요소(전달인자)마다 괄호처리를 해 주고, 메크로 몸체 전체에 한번 더 
괄호를 쳐 주어야 한다.**<br>

최종적으로 이러한 규칙을 반영하여 매크로 함수 `SQUARE`을 정의하면 다음과 같다.<br>
```c
#define  SQUARE(X)   ((X)*(X))
```
이렇게 정의해둔 상태에서 문제의 `int num = 120 / SQUARE(1+1)`은 선행처리기에 의해 아래와 같은 코드를 완성하게 되고, 변수 `num`에는 `30`이<br>
초기화 되게 된다.<br>
```c
int num = 120 / ((1+1)*(1+1));
```
> **매크로 함수를 정의할 때에는 매크로 몸체를 구성하는 요소(전달인자, 이번 예시에서는 `X`)마다 괄호처리를 해 주고, 메크로 몸체 전체를 한번 더 
괄호로 묶어 주어야 한다는 것을 잊지 말자!**<br>
<br>

### 길이가 긴 매크로를 정의하는 경우 - 매크로를 두 줄에 걸쳐서 정의하기
매크로를 정의할 때에는 기본적으로 1줄로 정의하는 것이 원칙이다. 하지만, 정의하는 매크로의 길이가 길어지는 경우 1줄로 정의 시, 가독성이 떨어진다는<br>
단점이 생기게 된다.<br>

이를 해결하기 위해 길이가 긴 매크로를 정의할 때 두 줄에 걸쳐서 정의하기도 한다. 이때, 아까 말했듯이, 매크로 정의시 기본적으로 한 줄로 정의하는 것이<br>
원칙이기 때문에, 매크로를 두 줄에 걸쳐서 정의하기 위해서는 줄이 바뀌었다는 표시를 직접 명시해 주어야 한다.<br>

해당 (줄이 바뀌었다는)표시는 `\`로 가능하고, 매크로를 두 줄로 정의한 모습은 다음과 같다.<br>
```c
#define   SQUARE(X)  \
	  ((X)*(X))
```
<br>

### 먼저 정의한 매크로를 사용하여 매크로 정의하기
매크로 정의 시, 먼저 정의한 매크로를 사용하여 새로운 매크로를 정의하는 것도 가능하다. 이러한 원리를 이용하여<br>
간단한 원의 넓이를 구해주는 프로그램을 작성해 보겠다.<br>
```c
#include <stdio.h>

#define   PI  3.14
#define   PRODUCT(X, Y)  ((X)*(Y))
#define   CIRCLE_AREA(R)  (PRODUCT((R), (R))*(PI))

void main()
{
  double rad = 2.1;
  
  printf("반지름 %g인 원의 넓이 : %g\n", rad, CIRCLE_AREA(rad));
}
```
해당 코드를 보면, 매크로 `CIRCLE_AREA`가 먼저 정의된 매크로 `PI`와 `PRODUCT`를 사용하여 정의된 것을 알 수 있다.<br>
이처럼, **먼저 정의된 매크로는 새로운 매크로를 정의하는데 사용할 수 있다.**<br>
<br>

## 매크로 함수의 장/단점
매크로 함수를 공부하면서 드는 생각이 있다. *굳이 매크로함수를 사용하는 이유가 뭘까?* 매크로 함수를 정의하는 것은 일반 함수를<br>
정의하는 것 보다 복잡할 뿐더러, 크기가 큰 매크로 함수를 정의하고자 하는 경우, 애초에 매크로로 정의하는 것 자체가 불가능 할<br>
때도 있다.<br>

이렇게 매크로 함수를 사용하는 이유를 알아보고자, 매크로 함수 사용 시 발행하는 장/단점을 정리해 보려 한다.<br>

- ### 매크로 함수 사용 시 장점
  #### 1. 매크로 함수는 일반 함수에 비해 실행속도가 빠르다.<br>
  
  일반 함수의 경우, 해당 함수를 호출하면 아래와 같은 과정이 동반된다.<br>
  **`호출된 함수를 위한 Stack메모리 할당`** -> **`실행 위치의 이동과 해당 함수의 매개변수(파라미터)로 인자 전달`** -> **`return`**
  
  반면, 매크로 함수의 경우, 선행 처리기에 의해 해당 매크로 함수의 함수 몸체 부분이 함수의 호출 부분을 대신하게 된다.<br>
  (선행처리 과정에서 선행처리기가 소스코드 내에서 매크로 함수 호출 부분(`매크로 함수(인자)`형태)을 찾아, 그 부분을<br> 
  해당 매크로 함수의 함수 몸체로 치환해줌. 이렇게 치환된 함수 몸체 부분이 함수의 호출 부분을 대신함.)<br>
  
  그렇기 때문에, 매크로 함수를 사용하면 위에서 언급한 일반 함수 호출 시, 동반되는 과정들이 필요 없어진다. 이러한 이유로,<br>
  매크로 함수를 사용하는 것이 일반 함수를 사용하는 것 보다, 실행속도 측면에서는 유리하다.<br>
  
  #### 2. 자료형에 따라서 별도로 함수를 호출해주지 않아도 된다.
  
  일반 함수의 경우, 해당 함수의 return 되는 결과의 자료형(반환형, return type)에 따라 별도로 함수를 호출해 주어야 한다.<br> 
  반면, 매크로 함수의 경우, 소스 코드 내, 매크로 함수 호출 부분이 매크로 몸체로 단순히 치환되는 방식이기 때문에, 자료형에 따라서<br>
  별도로 함수를 호출해주지 않아도 된다.<br>
  이는 위에서 작성한 `macro_function.c`프로그램에서도 확인해 볼 수 있다.<br>
  ```c
  #include <stdio.h>

  #define SQUARE(X) X*X

  void main()
  {
    int num = 7;
	
     // 정상적인 출력
     printf("square of num : %d\n", SQUARE(num));
     printf("square of 2.5 : %g\n", SQUARE(2.5));
     printf("square of -5 : %d\n", SQUARE(-5));
     
     // 비정상적인 출력
     printf("square of 3+5 : %d\n", SQUARE(3+5));
   }
   ```
   
   *[macro_function.c 의 실행결과]*
   ```
   square of num : 49
   square of 2.5 : 6.25
   square of -5 : 25
   square of 3+5 : 23
   ```
   
   해당 코드의 실행결과와 매크로 함수 호출부분, `SQUARE(2.5)`, `SQUARE(-5)`, `SQUARE(num)` 등을 보면, 전달인자의 자료형에<br>
   상관없이 정상적으로 치환되는 것을 알 수 있다.<br>
   이것이 가능한 이유는, 매크로 함수의 동작 방식자체가 선행처리기에 의해, 코드상의 매크로 함수 호출부분이 단순히 해당 매크로 함수의<br>
   몸체로 치환되는 방식이기 때문에 가능하다.<br>
   <br>
- ### 매크로 함수 사용 시 단점
  #### 1. 정의하기가 까다롭다.
  매크로 함수를 정의하는 것이 일반함수를 정의하는 것 보다 얼마나 까다로운지는 직접 매크로 함수를 정의해 보면 알 수 있다.<br>
  다음은 매개변수의 인자로 전달된 두 수의 차를 반환하는 함수 `Diff_ABS`이다. 이때 해당 함수의 조건은 *'반환되는 값은 두 값의<br>
  차에 대한 절대 값 이여야 한다.'* 이다.<br>
  
  결국, 인자로 전달받은 두 수중 더 큰 값을 골라 더 큰 값 - 더 작은 값을 해주면 된다. 일반 함수의 경우, 조건문을 이용하면<br>
  다음과 같이 쉽게 구현할 수 있다.<br>
  ```c
  int DiffABS (int a, int b) {
    if(a > b) 
      return a - b;
    else
      return b - a;
  }
  ```
  <br>

  이제, `DiffABS`함수를 매크로 함수로 변환하여 정의해 보도록 하겠다.<br>
  
  일반함수일 경우, 이렇게 `if ~ else`문을 이용하여 간단하게 정의할 수 있는 함수를 매크로 함수를 구현하고자 하면, 뭔가 까다롭게<br>
  느껴진다. 특히 `if ~ else`문의 형태를 그대로 유지하고자 하면 더욱 부담스럽게 느껴진다.<br>

  이런 경우, 조건 연산자를 사용하면 그나마 쉽게 정의가 가능하다.<br>
  ```c
  // 조건 연산자(삼항 연산자)
  조건 ? TRUE : FALSE;
  ```
  ```c
  #define DIFF_ABS(X, Y) ( (X) > (Y) ? (X) - (Y) : (X) - (Y) )
  ```
  <br>
  
  매크로 함수 특성상, 정상적인 작동을 위해서는 매크로 함수 몸체의 각 요소마다 하나하나씩 `()`처리를 해 주어야 한다.<br>
  일반 함수 `DiffABS`함수를 매크로 함수로 변환해 보면서, 매크로 함수를 정의할 때, 요소마다 `()`처리를 해주는 과정에서<br>
  오타 실수가 발생할 수도 있고(실제로 오타가 발생함), 확실히 일반함수의 정의 보단 부답스럽다는 것을 느낄 수 있었다.<br> 

  #### 2. 디버깅하기가 쉽지 않다.
  매크로를 잘못 정의했을 경우, 에러 메세지는 선행처리 이전의 소스파일을 기준으로 출력되지 않고, 선행처리 이후의 소스파일을 기준으로<br>
  출력이 된다. 때문에, 일반적인 에러 메세지보다 이해하기 힘들다는 단점이 있다.<br>
<br>

이러한 매크로 함수의 장/단점을 종합해보면, 다음과 같은 특성을 지닌 함수를 매크로의 형태로 표현하는 것이 옳다는 결론이 나온다.<br>
- 작은 크기의 함수
- 호출의 빈도수가 높은 함수

복잡하고 크기가 큰 함수일수록, 매크로 함수로 표현하는 것이 까다롭고 힘들다. 때문에, 정의하기 쉬운 작은 크기의 함수를 매크로<br>
함수로 표현하는 것이 바람직하다.<br>

또, 매크로 함수는 실행속도가 빠르다는 장점이 있다. 이러한 장점을 극대화 하기 위해서는 호출의 빈도수가 높은 함수를 매크로 함수로<br>
표현하는 것이 바람직하다. 

즉, 매크로함수로 표현하기 좋은 함수의 특징은 다음과 같다고 할 수 있다.<br>
*"크기가 작으며, 호출의 빈도수가 높은 함수!"* <br>
<br>

## 조건부 컴파일(Conditional Compilation)을 위한 매크로
> 매크로 지시자 중에는 특정 조건에 따라 소스코드의 일부를 삽입하거나 삭제할 수 있도록 디자인된 지시자가 존재한다.<br>
해당 지시자의 종류로는 어떤것들이 있는지 알아보도록 하겠다.<br>
<br>

### `#if...#endif`: 참 이라면
우리가 흔히 사용하는 `if`문은 조건에 따른 실행을 위한 것이었다. `#if...#endif`는 조건에 따른 코드 삽입 및 삭제를 위한 지시어이다.<br>
`#if`문의 뒤에는 반드시 `#endif`문(이름 그대로, 해당 `#if`문이 끝난다는 의미)이 등장해야 한다.<br>
```c
#if
  // 소스코드
#endif
```
두 매크로 지시자(`#if`, `#endif`) 사이에 존재하는 코드는 조건에 따라서, 매크로가 처리되는 선행처리 과정에서 선행처리기에 의해<br>
소스파일에 삽입되거나 삭제된다.<br>

다음 코드를 보면 쉽게 이해할 수 있다.<br>
```c
#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더파일

#define ADD true
#define MIN false

void main()
{
	int num1, num2;
	printf("두 개의 정수를 입력 : ");
	scanf("%d %d", &num1, &num2);
	
	#if ADD // ADD가 참이라면 두 지시어 사이의 코드 삽입
		printf("%d + %d = %d", num1, num2, num1 + num2);
	#endif 
	
	#if MIN // MIN이 참이라면 두 지시어 사이의 코드 삽입
		printf("%d - %d = %d", num1, num2, num1 - num2);
	#endif
}
```
*[conditional_compilation_ex01.c 의 실행결과]*
```
두 개의 정수를 입력 : 24 3
24 + 3 = 27
```
위 코드를 보면, 매크로 `ADD`의 매크로 몸체는 `true`이고, `Min`의 매크로 몸체는 `false`인 것을 알 수 있다.<br>
이때, 선행처리 과정에서 해당 코드에서의 `ADD`는 `true`로 치환되고, `Min`은 `false`로 치환되게 된다.<br>

결국, 이 두 매크로는 `#if...#endif` 지시자 사이에 있는 코드를 소스코드에 삽입할지, 삭제할지 정해주는 조건이 된다.<br>
(`ADD`가 참(true)이라면 이에 해당하는 두 지시어 사이의 코드가 삽입되고, 거짓이면 삭제된다. `MIN`의 경우도 마찬가지.)<br>

해당 코드에서는 `ADD`가 `true`로 치환되어 참이 되고, `MIN`이 `false`로 치환되어 거짓이 되므로, `#if...#endif`에 의해<br>
조건이 참인 `printf("%d + %d = %d", num1, num2, num1 + num2);` 코드가 삽입되고,<br>
`MIN`에 해당하는 코드는 삭제되게 된다.<br>
<br>

### `#ifdef...#endif`: 정의되었다면
`#if...#endif`의 경우, 참이냐, 거짓이냐를 기준으로 동작하였었다. 이번에 다뤄볼 `#ifdef...#endif`는 매크로가 정의 되었느냐,<br>
정의되지 않았느냐에 따라 동작한다.<br>
이때, 정의된 매크로의 값(매크로 몸체)는 상관 없이 오직 '매크로가 정의되었느냐 아니냐' 만을 동작한다는 것을 명심하자.<br>

이전 `conditional_compilation_ex01.c`를 약갼 변형하여 예시코드를 작성해 보았다. 해당 코드는 다음과 같다.<br>
```c
#include <stdio.h>
#include <stdbool.h>

// #define ADD true
#define MIN false

void main()
{
  int num1, num2;
  printf("두 개의 정수를 입력 : ");
  scanf("%d %d", &num1, &num2);

  #ifdef ADD
    printf("%d + %d = %d", num1, num2, num1 + num2);
  #endif

  #ifdef MIN
    printf("%d - %d = %d", num1, num2, num1 - num2);
  #endif
}
```
*[conditional_compilation_ex02.c 의 실행결과]*
```
두 개의 정수를 입력 : 10 1
10 - 1 = 9
```
해당 코드를 보면, 위에서 설명했던 것과 같이, 매크로 `MIN`이 정의되어 있기 때문에, `매크로`MIN`이 정의되었다면` 에 해당하는<br>
`#ifdef...#endif`지시자 사이의 코드가 선행처리 과정 중 소스코드에 삽입되고,<br>
주석처리 되어, 정의가 되지 않은 매크로 `ADD`에 관한 지시자`#ifdef...#endif`와 그 사이의 코드는 삭제된 것을 알 수 있다.<br>

추가적으로, `#ifdef...#endif`지시자를 사용하는 경우, 조건으로 사용할 매크로 의 값(매크로 몸체)은 동작하는데 중요한 사항이 아니기<br>
때문에, 아래와 같이 생략해서 정의가 가능하다.<br>
```c
#define ADD
#define MIN
```
이렇게 정의된 값이 없는 매크로는 선행처리 과정에서 그냥 공백으로 치환된다.(그냥 소멸된다.)<br>
<br>

### `#ifndef...#endif`: 정의되지 않았다면
`#ifdef...#endif`지시자의 경우, 조건이 되는 매크로가 정의되어 있으면, 동작하고(코드가 삽입되고) 정의되어있지 않으면, 동작하지<br>
않았었다(코드가 삭제됨).<br>
`#ifndef...#endif`의 경우는 그 반대라고 생각하면 된다. `#ifndef`에서 `n`은 `not`을 의미한다.<br>

그렇다면, `#ifndef...#endif`지시자를 `conditional_compilation_ex02.c`에 적용하면 어떤 결과가 발생할까?<br>
반대의 결과가 나올 것이다.<br>

매크로 `MIN`은 정의가 되어있는 상태이고, `ADD`는 주석처리가 되어 정의가 되어있지 않은 상태이기 때문에, 정의가 되지 않은 매크로를<br>
조건으로 하였을 시 이어지는 코드를 삽입해주는 `#ifndef...#endif`지시자에 의해<br>
`printf("%d + %d = %d", num1, num2, num1 - num2);` 코드가 선행처리과정에서 삽입되어 실행되게 된다.<br>
<br>

### `#elif`의 삽입: `#if`에만 해당
우리가 흔히 조건문 `if`를 사용할 때, `else if`를 여러 번 추가 할 수 있었듯이, 지시자 `#if`에도 `#elif`추가가 가능하다.<br>
또, `else if`의 끝을 `else`로 마무리 지을 수 있었듯이, `#elif`도 `#else`로 마무리 지을 수 있다.<br>

해당 지시자의 예시코드는 다음과 같다.<br>
```c
#include <stdio.h>

#define HIT_NUM 7

void main()
{
  #if HIT_NUM==5
	printf("매크로 상수 HIT_NUM은 5입니다.");
  #elif HIT_NUM==6
  	printf("매크로 상수 HIT_NUM은 6입니다.");
  #elif HIT_NUM==7
  	printf("매크로 상수 HIT_NUM은 7입니다.");
  #else
  	printf("매크로 상수 HIT_NUM은 5, 6, 7이 아닙니다.");
  #endif
}
```
*[conditional_compilation_ex02.c 의 실행결과]*
```
매크로 상수 HIT_NUM은 7입니다.
```
조건이 참이면, 해당 지시자 사이에 존재하는 코드를 소스코드 안에 삽입하는 `#if...#endif`지시자와 조건을 더 추가할 수 있게 해주는 `#elif`<br>
지시자를 활용하여 조건을 추가해, 결국 참이 되는 조건을 지닌 지시자 사이의 코드를 삽입하는 간단한 프로그램이였다.<br>















