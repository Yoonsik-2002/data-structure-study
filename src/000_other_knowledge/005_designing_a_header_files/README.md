# 헤더파일의 디자인과 활용
헤더파일의 이해를 위해, **`#include`** 지시자의 의미에 대해 알아보도록 하겠다. 다음 예시코드를 한번 봐 보자.

#### [ex_header_file01.h]
```c
{
  printf("Hello World!");
```
#### [ex_header_file02.h]
```c
  printf("Hello Yoonsik!");
}
```
#### [example01.c]
```c
#include <stdio.h>

int main()
#include "ex_header_file01.h"
#include "ex_header_file02.h"
```
해당 코드내에 **`#include`** 지시자를 사용한 부분의 의미를 설명하면 다음과 같다. 

**`#include "ex_header_file01.h"`** - *이 부분에 해당 파일 (`ex_header_file01.h`) 에 저장된 내용을 포함해주세요.*<br>
**`#include "ex_header_file02.h"`** - *이 부분에 해당 파일 (`ex_header_file02.h`) 에 저장된 내용을 포함해주세요.*<br>

그렇다. **`#include`** 지시자는 이름과 같이 해당 지시자의 위치에 파일에 저장된 내용을 포함 시켜주는 용도로 사용한다.<br>
그리고, 이 **`#include`** 지시어의 내용은 선행처리기에 전달되어 컴파일 전에 수행되게 된다.<br>

위 코드의 선행처리가 이루어지면 다음과 같은 코드가 완성된다. 
#### [example01.c]
```c
#include <stdio.h>

int main()
{
  printf("Hello World!\n");
  printf("Hello Yoonsik!");
}
```
이렇게 완성된 코드를 보면 다음과 같은 이해가 가능하다. **"`#include` 지시어가 있는 자리에 지정한 헤더파일의 내용이 포함되는구나!"**<br>
<br>

## 헤더파일을 include 하는 두 가지 방법
헤더파일을 include 하는 두 가지 방법은 다음과 같다.<br>

**`include <헤더파일 이름>`** 이를 첫 번째 방법이라 하겠다.<br>

**`include "헤더파일 이름"`** 이를 두 번째 방법이라 하겠다.<br>

이 두가지 방법의 차이점을 무엇일까? 해당 질문에 대한 설명은 다음과 같다.<br>
<br>

### 헤더 파일을 include 하는 첫 번째 방법 - `include <헤더파일 이름>`
이 첫 번째 방법을 사용하면, 표준 헤더파일을 저장하고 있는 디렉터리에서 파일을 찾게 된다.<br>
때문에, 이 방법은 `stdio.h`, `stdlib.h`, `string.h`와 같은 표준 헤더파일을 포함 시킬 때 사용한다.<br>
<br>

### 헤더 파일을 include 하는 두 번째 방법 - `include "헤더파일 이름"`
해당 두 번째 방법을 사용하면, 이 문장(`include "헤더파일 이름"`)을 포함한 소스파일이 저장되어 있는 <br>
디렉터리에서 헤더파일을 찾는다.<br>
때문에, 이 방법은 프로그래머가 직접 정의한 헤더파일을 포함시킬 때 사용하는 방법이다.<br>
이를 위해선, 헤더파일의 이름 뿐만아니라, 해당 파일의 절대경로 혹은 상대경로까지 명시해 주어야 한다.<br>

- #### 절대경로
  절대경로는 다음과 같이 드라이브명과 디렉터리, 헤더파일 이름을 포함한 모든 경로(완전경로)를 명시하는 방법이다.<br>
  `#include "C:\CPower\MyProject\header.h"  // 절대경로를 이용한 헤더파일 include의 예`
  
  절대경로는 말 그대로 '절대 경로가 변경되지 않는 경로' 라고 생각하면 이해하기 쉽다.<br>
  절대경로는 컴퓨터를 옮겨도 처음 지정해논 대로 유지되어 바뀌지 않는다는 특성이 있다.<br>

  이러한 특성 때문에, 절대경로를 지정해서 헤더파일을 선언하면, 다른 컴퓨터에서 컴파일 하는 과정이 매우 번거로워진다는<br>
  단점이 있다.<br>
  초기에 헤더파일을 선언한 내 컴퓨터의 환경과 해당 프로그램을 컴파일 하는 다른 컴퓨터의 환경이 다르기 때문이다.<br>
  그래서, `#include`문에서는 절대경로를 사용하지 않는다. 대신에 상대경로를 사용한다.<br>

  ```c
  #include "C:\CPower\MyProject\header.h"  // Windows 상에서의 절대경로 지정
  #include "/CPower/MyProject/header.h"  // Linux 상에서의 절대경로 지정
  ```
  

- #### 상대경로 
  절대경로와는 반대로, 상대경로는 상대적인 경로, 실행하는 컴퓨터의 환경에 따라서 경로가 바뀌는 경로이다.<br>
  예를 들어, 다음과 같이 헤더파일을 포함시켰다고 해보자.<br>
  `#include "header.h"`

  만약 이 문장을 포함하고 있는 소스파일이 `C:\AAA`에 저장되어 있다면, 이 문장의 헤더파일 검색경로도 `C:\AAA`가 된다.<br>
  그리고, 이 문장을 포함하고 있는 소스파일이 `C:\AAA\BBB`에 저장되어 있다면, 해당 문장의 헤더파일 검색경로도 `C:\AAA\BBB`가 된다.<br>
  
  (두 번째 방법인 `#includ 헤더파일 이름`을 사용하면, 해당 문장을 포함하고 있는 소스파일이 저장되어 있는 디렉터리에서<br>
  헤더파일을 탐색함. 그리고, 이때 상대경로를 사용하면, 해당 위치가 헤더파일의 겸색경로가 됨)

  또 다음과 같이, 상위 디렉터리를 의미하는 `..`을 활용한 상대경로 지정도 가능하다.<br>

  `#include "Release\header0.h"`
  > 이 문장을 포함하고 있는 소스파일이 저장되어 있는 디렉터리의 하위 디렉터리인 `Release`디렉터리에 존재하는<br>
  `header0.h`를 포함하여라<br>

  `#include "..\Cprog\header1.h"`
  > 해당 문장을 포함한 소스파일을 저장하고 있는 디렉터리의 한 단계 상위 디렉터리의 하위 디렉터리인 `Cprog`에 존재하는<br>
  `header1.h`를 포함하여라<br>

  `#include "..\..\MyHeader\header2.h`
  > 두 단계 상위 디렉터리의 하위 디렉터리인 `Myheader`에 존재하는 `header2.h`를 포함하여라<br>

  **이렇게 상대경로를 이용하여 헤더파일을 선언하면, 드라이브 명이나, 디렉터리 위치에 덜 영향을 받는다.** <br>

  추가적으로, 리숙스 상에서 상대경로를 지정할 시, 현재 디렉터리와 부모디렉터리는 다음과 같이 표시 할 수 있다.<br>
  >  - 현재 디렉터리 : **`./`** 
  >  - 부모 디렉터리 : **`../`** <br>
<br>

## 헤더파일에는 어떤 내용을 담는가?
헤더파일에는 기본적으로 다음과 같은 유형의 선언을 담는다.<br>
```c
extern int num;
extern int GetNum(void);  // 함수가 외부에 정의되었음을 헤더파일에서 알릴 때에는 extern키워드를 생략 가능하다. 
```
위와 같은 유형의 선언들은 컴파일러에게 외부에 특정 변수나 함수가 선언/정의 되어 있음을 알려, 외부에 선언된 변수에 접근하거나<br>
외부에 선언된 함수를 호출하기 위한 선언이다.<br>
이와 같은 선언은 여러개의 소스파일로 이루어진 프로그램에 있어, 필수적으로 필요한 선언이다.<br>

하지만, 필요할 때마다 매번 해당 선언들을 삽입하는 것은 매우 번거로운 일이다.<br>

이러한 번거로움을 해결하기 위해 우리는 헤더파일에 위와 같은 유형의 선언들을 모아두고, 필요할 때마다 헤더파일을 포함시키는<br>
방법을 사용한다.<br>

> 매크로의 명령문도 파일단위로만 유효하기 때문에 (선행처리기도 파일단위로 선행처리를 한다)<br>
매크로에 대한 정의 또한 헤더파일에 들어가는 내용 중 하나이다.<br>

이러한 헤더파일을 만들 때, 주의할 점이 존재하는데, 바로 **"만들고자 하는 헤더파일의 이름과 해당 헤더파일과 대응되는 소스파일<br>
(헤더파일에 선언된 함수들을 정의 해놓은 소스파일)의 이름이 같아야 한다."** 이다.<br>
헤더파일과 그 헤더파일과 대응되는 소스파일의 이름이 같아야 컴파일러가 인식할 수 있기 때문이다.<br>
<br>

## 구조체의 선언 및 정의는 헤더파일과 소스파일 중, 어디에 두어야 할까?
**"컴파일러는 파일단위로 컴파일을 진행한다."** 이러한 컴파일러의 특성에 의해 우리는 `extern` 키워드를 사용하여, 현재 파일 외부에<br>
선언 혹은 정의되어 있는 변수/함수가 있다는 것을 컴파일러에게 알려, 이러한 외부 파일에 존재하는 변수나 함수를 사용하는 것이<br>
가능하게 된다.<br>

또, 매크로나 `extern`키워드를 이용한, 외부에 특정 변수나 함수가 선언/정의 되어 있음을 알리는 선언들을 모아두는 방식으로,<br>
헤더파일을 작성하고, 이렇게 만들어진 헤더파일은 해당 함수나 변수들을 필요로 하는 소스파일에 `include`하여 사용이 가능하다.<br>

그럼, 구조체의 선언 및 정의는 헤더파일과 소스파일 중, 어디에 두어야 할까?<br>

다음은 헤더파일을 사용하지 않고, 두 개의 소스파일 `intdiv.c`파일과 `main.c`파일에서 동일한 구조체 `Div`를 사용하는 예제 코드이다.<br>
`intdiv.c` 파일은 구조체`Div`타입의 `int_div`함수가 정의되어 있는 소스파일이고, `main.c`파일은 외부에 선언된 이 구조체`Div`타입의<br>
`int_div` 함수를 호출하여 사용하는 소스코드이다.<br>

##### [intdiv.c]
```c
typedef struct def {
  int quotient;
  int remainder;
} Div;

// 구조체 Div타입의 int_div 함수 정의
Div int_div (int num1, int num2) {
  Div div;  // 구조체 Div 타입의 구조체 변수 div 선언
  div.quotient = num1 / num2;
  div.remainder = num1 % num2;
}
```
##### [main.c]
```c
#include <stdio.h>

/* 컴파일러는 파일단위로 컴파일을 하기 때문에, 외부 파일에 존재하는 구조체의 선언 및 정의를 참조하여 컴파일을 진행하지 않는다.
때문에, intdiv.c 파일에 정의되어 있는 구조체 Div를 사용하고 싶으면, 해당구조체에 대한 선언을 이 main.c 파일에서도 해주어야 한다. */

typedef struct def {
  int quotient;  // 몫
  int remainder;  // 나머지
} Div;

extern Div int_div(int num1, int num2);  // 해당 파일(main.c) 외부에 정의되어 있는 함수 int_div를 사용하기 위해 extern 키워드를 이용하여 int_div 함수를 선언.

void main()
{
  Div val = int_div(3, 8);

  printf("몫: %d\n", val.quotient);
  pritnf("나머지: %d\n", val.remainder);
}
```

위 예시코드를 보면 알 수 있듯이, 구조체 타입의 함수를 정의하는 소스파일과 외부파일에 정의된 구조체 타입의 함수를 호출하여 사용하는<br>
소스파일 모두, 해당 구조체의 정의가필요하다.<br>

왜냐하면, 컴파일러는 파일단위로 컴파일을 진행하는 특성을 가지고 있기 때문이다.<br>
(`intdiv.c`파일에서 구조체`Div`가 정의되어 있다고 해서, 똑같은 `Div`구조체를 사용하는 `main.c`파일에서 `Div`구조체를 정의하지 않는다면,<br>
파일 단위로 컴파일을 진행하는 컴파일러 입장에서는 `main.c`파일에는 해당 파일에서 사용하는 구조체`Div`가 정의되어있지 않다고 받아들이기<br> 
때문에 제대로 작동하지 않는다.)<br> 

그렇기 때문에, 헤더파일을 사용하지 않고, 두 개의 소스파일 `intdiv.c`파일과 `main.c`파일에서 동일한 구조체 `Div`를 사용하였던 위 예제코드<br>
에서는 아무리 동일한 구조체더라도, 두 소스파일에 각가 구조체 `Div`의 선언 및 정의를 해 주어야 하였다.<br>

이때, 우리는 헤더파일을 만들어서 `Div`의 선언 및 정의가 프로그램 내에서 하나만 존재하도록 개선시킬 수 있다.<br>
동일한 구조체의 선언 및 정의가 두 군데 이상 존재하면, 구조체의 수정 및 확장에 불편함이 생기고, 해당 구조체를 사용하는 소스파일 마다 일일이<br>
똑같은 선언 및 정의문을 삽입하는 것은 비합리적이다. 때문에, 헤더파일을 활용한 아래와 같은 구조는 필수라고 할 수 있다.<br>

다음은 헤더파일을 적용시킨 예시 코드이다.<br>

##### [stdiv.h]
```c
typedef struct def {
  int quotient;
  int remainder;
} Div;
```

##### [intdiv.c]
```c
#include "stdiv.h"

Div int_div(int num1, num2) {
  Div div;

  div.quotient = num1 / num2; 
  div.remainder = num1 % num2;
}
```

##### [main.c]
```c
#include "stdiv.h"
#include <stdio.h>

extern int_div(int num1, int num2);

void main()
{
  Div val = int_div(6, 8);

  printf("몫 : %d\n", val.quotient);
  printf("나머지 : %d\n", val.remainder);
}
```

위 예시코드에서 알 수 있듯이, 구조체의 선언 및 정의는 헤더파일에 삽입하는 것이 좋다. <br>
그러나, 하나의 소스파일 내에서만 사용이 되는 구조체라면, 소스파일에 정의하는 것도 괜찮다.<br>
<br> 

## 헤더파일의 중복삽입 문제
일단은, 위 예시를 통해 구조체의 선언 및 정의는 헤더파일에 삽입해야 한다는 결론을 내릴 수 있었다.<br> 
그러나, 이는 자칫하면 컴파일 에러를 발생시킬 수 있다.<br> 

다음 예시코드를 통해 한번 알아보도록 하자.<br> 

##### [stdiv.h]
```c
// Div 구조체의 선언 및 정의문

typedef struct def {
  int quotient;
  int remainder;
} Div;
```

##### [intdiv3.h]
```c
// 헤더파일 stdiv.h에서 선언되어 있는 구조체 Div를 활용한 함수 int_div의 선언

#include "stdiv.h"

Div int_div(int num1, int num2); 
```

##### [intdiv3.c]
```c
// 헤더파일 stdiv.h에 정의되어 있는 구조체 Div를 활용한 함수인 int_div의 정의

#include "stdiv.h"

Div int_div(int num1, int num2) {
  Div div;

  div.quotient = num1 / num2;
  div.remainder = num1 % num2;

  return div;
}
```

##### [main.c]
```c
/* 헤더파일 intdiv3.h 에서 선언하고 있는 함수 int_div를 해당 소스파일에서 호출하기 때문에
intdiv3.h 헤더파일을 include 하였다.
또, 해당 함수의 반환형이 구조체 Div 타입이기 때문에, 해당 구조체의 선언 및 정의문을 포함하고
있는 헤더파일 stdiv.h를 include 하였다. */

#include <stdio.h>
#include "stdiv.h"
#include "intdiv3.h"

Div val = Div int_div(6, 8);  

printf("quotient : %d", val.quotient);
printf("remainder : %d", val.remainder);
```
<br>

![Slide13](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f9164d82-15d3-425e-97d6-e890f3ce9d25)<br>




