# 추상자료형(Abstract Data Type)
> 구체적인 기능의 완성과정을 언급하지 않고, 순수하게 기능이 무엇인지를 나열한 것을 가리켜, 추상자료형 또는 ADT 라고한다.

- 예시) 지갑의 추상자료형
    - 카드의 삽입
    - 카드의 추출
    - 지폐의 삽입
    - 지폐의 추출

기능의 진행(완성)되는 과정을 언급하지 않고 기능이 무엇인지만 나열하였다. <br>
(`‘이런기능이 있고 이런 기능이 있어’` 기능의 명세!)<br>
<br>

### 자료형의 정의
완전한 자료형의 정의로 인식되기 위해서는 해당 자료형과 관련이 있는 연산이 함께 정의 되어야 한다.<br>
(c언어에서는 이러한 연산을 함수를 이용하여 정의한다.)

```c
Ex.1

// 구조체 기반 자료형 Wallet의 정의

typedef struct _Wallet
{
    int coin100Num;
    int bill5000Num;
} Wallet;

// Wallet을 기반으로 제공할 수 있는 기능 관련 연산의 정의

int TakeOutMoney(Wallet * pw, int coinNum, int billNum);     // 돈을 꺼내는 연산
void PutMoney(Wallet * pw, int coinNum, int billNum);    // 돈을 넣는 연산 
```
‘자료형’의 정의에 ‘기능’ 혹은 ‘연산’과 관련된 내용을 명시할 수 있다.  따라서 추상 자료형이라 하여 그것에 기능 또는<br>
연산과 관련된 내용을 명시할 수 없다는 생각은 버려야 한다.<br>
<br>

### Wallet의 추상 자료형(ADT)
- `int TakeOutMoney(Wallet * pw, int coinNum, int billNum);`
	 
    - 첫 번째 인자로 전달돤 주소의 지갑에서 돈을 꺼낸다.
    - 두 번째 인자로 꺼낼 동전의 수, 세 번째 인자로 꺼낼 지폐의 수를 전달한다.
    - 꺼내고자 하는 돈의 총액이 반환된다. 그리고 그만큼 돈은 차감된다.<br/><br/>
    
- `void PutMoney(Wallet * pw, int coinNum < int billNum);`
    - 첫 번째 인자로 전달된 주소이 지갑에 돈을 넣는다.
    - 두 번째 인자로 넣을 동전의 수, 세 번째 인자로 넣을 지폐의 수를 전달한다.
    - 넣은 만큼 동전과 지폐의 수가 증가한다.<br/><br/>
    
추상 자료형을 명시하는데 있어 명시해야 할 정보인 **기능**을 충분히 묘사하고 있다면 위와 같은 방법도 괜찮다.<br>
추상 자료형에 중요한 정보라면 무엇이든 추가할 수 있으며, 그 방법에는 제한이 없다. 하지만 불필요한 것을<br>
포함시키는 것은 바람직하지 못하다.<br>

코드 레벨 에서의 자료구조 구현 중심의 학습을 위해서는, 이 ADT를 어떻게 잘 정의하고, 이를 어떻게 일반화 시켜서<br>
자료구조를 정의하고 앞서 만든 자료구조를 뒤에서 잘 활용할 수 있을지에 초점을 두어서 공부해야 한다. <br>

---
<br>

# 리스트(List)
먼저, 리스트 자료구조를 학습하는데 있어, 다음 순서를 따라 학습해 나가려 한다.<br>

> 1. 리스트 자료구조의 ADT를 정의한다.<br>
> 2. ADT를 근거로 리스트 자료구조를 활용하는 `main` 함수를 정의한다.<br>
> 3. ADT를 근거로 리스트를 구현한다.<br>
<br>

### 리스트의 이해
*"리스트는 연결리스트를 의미하는 말인가?"* <br>

해당 질문에 대한 답은 '아니다' 라고 할 수 있다. 리스트(List) 라는 자료구조는 구현 방법에 따라 다음과 같이 크게 두 가지로 나눌 수 있다.<br> 

- #### 순차 리스트(Sequential List)
  배열을 기반으로 구현된 리스트<br>

- #### 연결 리스트(Linked List)
  메모리의 동적할당(`malloc` 함수를 통한 Heap 영역으로의 원하는 시점에서 자유로운 메모리 할당)을 기반으로 구현된 리스트<br>
<br>

이러한 두 리스트는 구현 방법에서의 차이에 따라 나눠진 것이기 때문에, 이 두 자료구조의 순수한 기능을 정의하는 ADT가 동일하더라도<br>
이는 문제가 되지 않는다.<br>

하지만, 또, 각 자료구조의 특성적 차이에 의한 ADT의 차이를 두기도 한다.<br>

결국, 해당 자료구조의 기본적인 특성에서 벗어나지 않는 선에서 필요에 따라 ADT에도 차이가 난다. 자료구조의 순수한 기능을 정의하는<br>
ADT라고 해서, 각종 자료구조들의 ADT는 무조건 표준이라 할 수 없다.<br>

이러한 리스트의 ADT를 정의하는데 있어 중요한, 리스트라는 자료구조의 기본적인 특성은 다음과 같다.<br>

**"데이터를 나란히 저장하고, 이러한 데이터들의 중복을 막지 않는다(허용한다)."** <br>
<br>

### 리스트의 ADT
**리스트의 ADT -** *'리스트라는 자료구조가 제공해야할 기능들은 무엇인가?'* 이를 나열한다.<br>

이때, 리스트라는 자료구조의 기본적이면서도 중요한 특성(데이터 나란히 저장, 중복 O)을 기반으로 제공해야할 기능들을 정의해야 한다!<br>
*'어떤 기능을 통해 리스트가 데이터를 나란히 저장하고, 중복을 허용하여 데이터들을 저장하게 할까?'* 이러한 접근이 중요!<br>

---
<br>

# 순차 리스트 (Sequential List)
순차 리스트란, 순차적인 메모리 공간을 할당하여 구현하는 리스트로, 보통 배열을 기반을 구현된다.<br>

- #### 순차 리스트의 장/단점
  | 장점 | 단점 | 
  |:-----|:-----|
  |정렬 기능을 사용하기 용이하다.|중간에 데이터를 삽입, 삭제하기 힘들다|
  |데이터를 특정 기준으로 관리하기 쉽다.|데이터를 삽입하고 삭제할 때마다, 데이터의 이동이 발생한다.|
  |인덱스(index)값을 통한 데이터 조회가 편리하다.|
<br>

이러한, 배열을 기반으로 구현되는 순차 리스트를 구조체를 이용하여, 코드로 나타내 보도록 하겠다.<br> 
```c
#define LIST_LEN 100;

typedef int LData;

typedef struct __ArrayList
{
  LData arr[LIST_LEN];
  int Num;
  int Current;
} ArrayList;

typedef ArrayList List;
```
<br>

다음 코드를 보면, 해당 구조체는 멤버변수로, 실질적인 데이터들을 저장하는 배열 `arr`과 해당 배열에 저장되어 있는 데이터의 개수를<br>
저장하는 `int`형 변수 `Num`, 배열의 현재 인덱스를 저장하는 `int`형 변수 `Current`로 이루어져 있는 것을 알 수 있다.<br>

이러한 순차 리스트 자료구조 모델을 그림으로 표현하면 다음과 같다.<br>

![sequential list](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/1d254584-1902-4f46-80eb-a8fe4afafe4f) <br>
<br>

이러한 형태를 띄는 순차 리스트의 ADT(순수한 기능)는 어떻게 될까?<br>
데이터를 나란히 저장하고, 이러한 데이터들의 중복을 허용하는 해당 자료구조의 기본적인 특성을 기반으로, 순차 리스트의 ADT를 한번 <br>
정의해 보도록 하겠다.<br>
<br>

### 순차 리스트의 ADT
앞으로 구현해 볼 순차 리스트의 ADT를 정의해 보도록 하겠다.<br>

이러한 ADT는 해당 자료구조를 구현할 프로그래밍 언어에 종속적으로 정의가 가능한데, 이러한 경우, 어떠한 프로그래밍 언어를 사용하느냐<br>
에 때라, 해당 ADT의 내용이 달라지기도 한다.<br>

먼저, C 라는 언어는 내가 변수를 생성한다고 해서, 자동으로 초기화 해주는 함수가 호출되지 않는다. 때문에, 초기화의 과정을 별도로 명령<br>
해야 한다. 즉, '초기화' 라는 기능(초기화를 담당하는 함수) 또한 ADT에 추가해야 한다는 것이다.<br>

반면, Java와 같은 객체지향 언어의 경우, '생성자' 라는 개념이 존재하여, 이러한 생성자를 통해 변수에 대응하는 인스턴스를 생성하면, 자동<br>
적으로 생성자 라는 함수가 호출되면서, 초기화의 기회를 자동적으로 제공받게 된다.<br>

때문에 이러한 객체지향 언어같은 경우, C언어와 같이, 초기화라는 기능을 별도로 ADT에 추가할 필요가 없어지게 된다.<br>

다음은 Java에서의 생성자에 의한 인스턴스의 자동적인 초기화를 다룬 예시 코드이다.<br>
```java
public class Car {
  String name;
  String price;

  public Car(String name, String price) {
    this.name = name;
    this.price = price;
  /*
  생성자는 해당 클래스의 인스턴스가 new 연산자를 통해 생성될 때,
  호출되어, 해당 인스턴스를 자동적으로 초기화 해주는 '인스턴스 초기화 메서드' 이다.
  */
  }
}
```

```java
public static void main(String[] args) {
  Car mercedes = new Car("E-Class", "88,000,000");
  // 인스턴스 생성과 동시에, 생성자를 통해, 해당 인스턴스에 대한 초기화의 기회가 자동적으로 주어짐.

  System.out.println("name : " + Car.name);
  System.out.pritnln("price : " + Car.price);
}
```
<br>

이러한, 프로그래밍 언어의 특성에 따른 차이점이 존재하기에, 프로그래밍 언어에 종속적인 ADT를 정의하는 경우, 같은 자료구조라도 해당<br>
ADT의 내용에선 차이가 생길 수 있다.<br>

일단, 나는 C언어를 이용하여 이 순차리스트 라는 자료구조의 ADT를 정의해 볼 것이기 때문에, 해당 ADT에는 초기화를 담당하는 함수에 대한<br>
내용을 해당 ADT에 추가할 것 이다.<br>
<br>

> - #### 기능 1) 순차 리스트의 생성 및 초기화<br>
>   **`void ListInit(List* pList);`**<br><br>
>   새로 생성한 구조체 변수 `list`의 주소값을 인자로 전달해 준다.<br>
>   리스트가 생성된 후, 가장 먼저 호출되어야 할 함수로, 생성된 리스트의 초기화를 담당한다.<br>
>   (위에서 설명하였듯이, C언어의 경우, 어떠한 변수가 생성되었다고 해서 이를 자동으로 초기화 해주지 않기 때문에, <br>
>   이러한 초기화를 담당하는 기능을 ADT에 명시하여야 한다.)<br><br>
>   `list`에는(`list` 뿐만 아니라, 모든 자료구조에는) 데이터를 저장하는 저장공간 뿐만 아니라, 해당 데이터를 효율적으로<br>
>   저장 및 참조하기 위한 정보들도 담기기 마련이다. 따라서, 이러한 정보를 저장하는 변수들을 초기화 해주는 작업이 필요한데,<br>
>   이를 담당하는 함수가 바로 `ListInit`인 것이다.<br><br>
>   이 `ListInit`함수는 리스트가 생성된 뒤 호출되면, 해당 리스트의 데이터 참조위치와 데이터의 개수를 저장하는 변수들을<br>
>   모두 초기값으로 초기화 해준다. 
>   
> - #### 기능 2) 생성된 리스트에 데이터 저장<br>
>   **`void ListInsert(List* pList, LData data);`**<br><br>
>   데이터를 저장할 `list`의 주소값과, 저장할 데이터의 값을 인자로서, 매개변수 `pList`와 `data`에 각각 전달해 준다.<br>
>   결국, 데이터를 어디에(`list`) 저장하고, 어떠한 데이터를 저장할지에 대한 정보를 리스트에 데이터를 저장하는 함수인<br>
>   `ListInsert`에 전달하는 것이다.<br>
>   즉, 매개변수`pList`를 통해 주소값을 전달받은 리스트에 매개변수 `data`를 통해 전달받은 값을 저장한다.<br><br>
> - #### 기능 3) 저장된 데이터의 탐색 및 탐색 초기화<br>
>   해당 기능은 첫 번째 데이터를 탐색하여 초기화 해주는 `LFirst` 함수와, 첫 번째 데이터 이후의 데이터를 탐색하여 초기화<br>
>   해주는 `LNext` 함수. 이 두 개의 함수를 통해 구현이 가능하다.<br><br>
>   이렇게 '저장된 데이터의 탐색 및 탐색 초기화' 라는 기능을 '첫 번째 데이터를 탐색하여 초기화 해주는 기능(`LFirst`)'과<br>
>   '첫 번째 데이터 이후의 데이터를 탐색하여 초기화 해주는 기능(`LNext`)'으로 나누어서 구현하는 이유는 다음과 같다.<br><br>
>   *'`LNext`함수를 호출할 때마다, 다음에 저장된 데이터를 얻을 수 있다.'* 이것이 가능한 이유는, 리스트 내에서 '데이터의<br>
>   참조위치'를 기록하기 때문이다.<br><br>
>   따라서, 처음부터 참조를 새롭게 시작하기 위해서는 바로, 이 정보(데이터의 참조위치)를 초기화 해 주어야 한다.<br>
>   그 처음 이라는 기준점이 되는 것이 바로, 첫 번째 데이터를 반환하는 아래의 `LFirst` 함수이다.<br>
>
>   ![Slide14](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f29143b3-d313-4771-b311-b1e80411bcd0)
>
>   첫 번째 데이터 이후의 데이터를 탐색하여 반환하고 싶은 경우, `LNext` 함수를 사용한다.<br>
>   이 `LNext` 함수를 실행하기 위해서는 우선적으로, `LFirst` 함수가 먼저 실행되어야 한다.<br>
>     - #### 기능 3-1) 저장된 데이터들 중, 첫 번째 데이터 반환<br>
>       **`int LFirst(List* pList, LData* pData);`**<br><br>
>       리스트에 저장되어 있는 데이터 중, 첫 번째 데이터를 탐색하여 `pData`가 가리키는 메모리에 저장한다.<br>
>       데이터의 참조를 위한 초기화가 진행된다.`*pData = pList -> arr[0];`<br>
>       참조 성공 시 `TRUE(1)`, 참조 실패 시 `FALSE(0)`를 반환한다.<br><br>
>       보통적으로 C언어 자료구조에서는 어떠한 함수를 통해서 반환받을 데이터를 저장할 메모리 공간을 할당한 다음,<br>
>       해당 메모리의 주소값을 인자로 전달한다.<br>
>       함수 `LFirst`의 경우도, 해당 함수를 통해 리턴되는 값을 반환받을 메모리의 주소값인 pData를 매개변수로 두어,<br>
>       반환할 리스트의 첫번째 데이터를 pData가 가리키고 있는 메모리에 저장하는 식으로 값을 반환한다.<br><br>
>       ```c
>       // 반환받을 메모리의 주소값을 참조하고 있는 포인터 매개변수에 함수의 결과가 되는 데이터 저장
>       
>       /* 이것이 C언어 자료구조의 일반적인 반환 방식이다.
>       
>       ADT에서 초기화 라는 기능이 명시되는 이유는, 이렇게 함수의 결과를
>       [*반환받을 메모리의 주소값을 참조하고 있는 포인터 매개변수] 에게 초기화 하는 방식으로
>       반환을 하기 때문이다.
>       
>       ADT에서 명시한 초기화와 지금 설명한 초기화는 같은 초기화를 의미하는 것이다. 
>       */ 
>       ```
>     - #### 기능 3-2) 저장된 데이터들 중, 첫 번째 데이터의 다음 데이터들을 반환<br>
>       **`int LNext(List* pList, LData* pData);`**<br><br>
>       참조된 데이터의 다음 데이터가 pData가 가리키고 있는 메모리에 저장된다.      
>       순차적인 참조를 위해서, 반복 호출이 가능하다.<br>
>       참조를 새로 시작하기 위해선, `LFirst`함수를 먼저 호출해야 한다.<br><br>
> - #### 기능 4) 바로 이전에 반환이 이뤄진 데이터의 삭제<br>
>   **`LData LRemove(List* pList);`**<br>
>   저장되어 있는 데이터를 반환하는 함수 `LFirst`나 <br>
>   `LNext`를 통해 마지막으로 반환된 데이터를 삭제한다.<br>
>   삭제된 데이터를 반환한다.<br><br>
> - #### 기능 5) 저장되어 있는 데이터의 수를 반환<br>
>   **`int LCount(List* pList);`**<br>
>   리스트에 저장되어 있는 데이터의 수를 반환한다.<br>

<br>

다음 링크는  해당 ADT를 이용하여 구현한 배열 기반 리스트 프로그램이다.<br>
[array list program](https://github.com/Yoonsik-2002/data-structure-study/tree/main/src/004_linked_list/01_sequential_list/array_list_program)<br>

---
<br>

# 구조체 변수를 저장하는 리스트 프로그램 구현하기 - `point list program`
이번에는, 구조체 변수를 저장하는 리스트 프로그램을 구현해 보도록 하겠다.<br>
보통 구조체는 멤버 변수가 여러 개 들어있어서, 크기가 큰 편이다. 그래서 구조체 변수를 일일이 선언해서 사용하는 것보다는 포인터에<br> 메모리를 할당해서 사용하는 편이 효율적이다.<br>

일단, 이 점을 기억하고, 구조체 데이터를 저장하는 리스트 프로그램을 구현해 보도록 하자.<br>
<br><br>

## 리스트에 구조체 변수 저장하기 I : 구조체 Point와 관련 함수들의 정의 - `Point.h`, `Point.c`
실제로, 리스트에는 구조체 변수를 비롯한 각종 데이터들이 저장된다.<br>
따라서 이번에는 리스트에 구조체 변수의 주소값을 저장해 보려 한다.<br>

이를 위해, 아래와 같은 구조체를 정의해 보았다.<br>

```c
typedef struct _Point {
  int xpos;
  int ypos;
} Point;
```
<br>

해당 구조체를 다루는 함수는 다음과 같다.<br>
- **`void SetPointPos(Point * ppos, int xpos, int ypos); // 구조체 변수에 xpos, ypos 값을 저장`<br>**
- **`void ShowPointPos(Point* ppos); // 정보 출력`<br>**
- **`void PointComp(Point * pos1, Point * pos2); // Point 타입의 구조체 변수 pos1과 pos2에 저장되어 있는 값을 비교.`<br><br>**
    - `두 Point 변수의 멤버 xpos만 같으면 1 반환`
    - `두 Point 변수의 멤버 ypos만 같으면 2 반환`
    - `둘 다 같으면 0 반환`
    - `둘 다 다르면 -1 반환`
<br>

해당 내용을 가지고, 구조체 `Point`의 선언과 해당 구조체를 다루는 함수(`SetPointPos`, `ShowPointPos`, `PointComp`)메서드의<br>
선언은 `Point.h`헤더파일에 담았고, `Point`구조체를 다루는 함수들의 정의는 `Point.c`소스파일에 담아 주었다.<br>

완성된 `Point.h`파일과 `Point.c`파일은 아래와 같다.<br>
  **[`Point.h`](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/01_sequential_list/point_list_program/Point.h)**
  **[`Point.c`](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/01_sequential_list/point_list_program/Point.c)** <br>
<br><br>

## 리스트에 구조체 변수 저장하기 II : 구조체 Point와 관련 함수들의 정의 - `ArrayList.h`, `ArrayList.c` 
그리고, 기존에 만들어둔 배열 기반 리스트의 헤더파일(`ArrayList.h`)과 소스파일(`ArrayList.c`)에 담겨있는 코드가 `Point`구조체<br>
변수를 저장할 수 있도록 변경해 보도록 하겠다.<br>
<br>

### 어디에 구조체 데이터를 저장하는가?
먼저, 무엇을 변경하면 좋을까? 이는, 우리가 해당 배열기반 리스트 프로그램에서 데이터를 저장하는 곳이 어디인지<br>
생각해보면 알 수 있다.<br>

바로, `ArrayList.h`헤더파일에 선언되어 있는 구조체 `ArrayList`의 멤버인 `LData arr[LIST_LEN]`이라고 할 수 있다.<br>

구조체 `ArrayList`는 데이터를 저장하는 공간 `arr[LIST_LEN]`과 해당 데이터들의 관리를 도와주는 변수 `numOfData`,<br>
`curPosition`을 멤버로 가지며, 해당 멤버들을 이용하여, 데이터들을 효율적으로 관리한다.<br>
<br>

### `typedef`를 통해 구조체 데이터를 저장할 수 있도록 `ArrayLIst`구조체의 멤버 arr의 자료형 변경하기 
이때, `arr[LIST_LEN]`앞의 `LData`는 무엇인가? `typedef`를 통해, 우리가 자유자재로 정의해 줄 수 있는 자료형이다.<br>

`typdedef int LData`의 경우, int형이 `LData`로 정의되는 것이고, `typedef double LData`의 경우, double형이 `LData`로 정의되는 <br>
것이다.<br>

자, 그럼 우리는 구조체 데이터가 저장되는 `ArrayList`구조체의 멤버 `arr[LIST_LEN]`의 타입을 기존 int형 에서(`typedef int LData`)<br>
`typedef`를 통해 무엇으로 정의해주면 좋을까?<br>
<br>

### 구조체를 동적할당해서 사용하자 - 메모리 효율성📈
위에서 언급하였듯이, 멤버의 개수가 많은 구조체는 일반적으로 크기가 크고, 메모리를 많이 차지하는 데이터 타입이다.<br>
동적할당을 통해 필요한 만큼의 메모리를 할당하면(사용하고자 하는 구조체의 크기만큼 Heap영에 메모리를 할당하고, 그 메모리의 주소값을<br>
구조체 포인터 변수에 반환받아 사용) 메모리 사용을 최적화 하는 것이 가능하다.<br>

필요한 시점에, 필요한 만큼 메모리를 할당하고 해제하여 메모리 효율정을 높일 수 있는 것이다.<br>
때문에, 구조체 변수를 일일이 선언해서 사용하는 것보다는 포인터에 메모리를 할당하여 사용하는 것이 효율적이라 할 수 있다.<br>

때문에, 우리는 `malloc()`함수를 이용하여 메모리의 생성과 소멸이 자유로운 자유 메모리(Heap 영역)에 구조체의 크기만큼 메모리를 할당<br>
해 놓은 뒤, 반환받은 해당 메모리 공간의 주소값을 해당 구조체의 주소값을 저장하는 구초제 포인터 변수(`Point *`)에 저장하여 사용할<br>
예정이다.<br>

그리고, 이렇게 Heap영역에 할당되어 있는 구조체 메모리의 주소값을 저장하고 있는 구조체 포인터 변수들을 `arr[LIST_LEN]`에 저장해<br>
줄 것이다.<br>

그렇다면, 이 `arr[LIST_LEN]`은 무슨 타입의 배열이 되어야 할까?<br>

그렇다. Heap영역에 메모리 공간을 할당한 구조체의 주소값을 저장하고 있는, 구조체 포인터 변수들을 저장하는 `Point *`타입의 구조체<br>
포인터 배열이 되어야 한다.<br>

따라서, 해당 배열의 타입인 `LData`는 `typedef Point * LData`를 통해, `Point *`타입으로 변경해 주어야 한다.<br>
이제 `LData arr[LIST_LEN]`은 `Point`구조체를 가리키는 `Point *`타입의 구조체 포인터 변수를 저장할 수 있다.<br>

마지막으로, `ArrayLIst.h`파일에 새로운 `Point`라는 구조체의 이름이 등장하였으니, 해당 구조체가 선언되어 있는 `Point.h`헤더<br>
파일을 `ArrayList.h`헤더파일에 반드시 include하여 추가해 주어야 한다.<br>

이러한 헤더파일에 선언되어 있는 자원들을 사용하여 함수들을 정의하는 `ArrayList.c`소스파일은 따로 변경해주지 않아도 된다.<br>
(재대로 구현 했다면)<br>

- #### [헤더파일 `ArrayList.h`와 소스파일 `ArrayList.c`]
  **[`ArrayList.h`](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/01_sequential_list/point_list_program/ArrayList.h)**
  **[`ArrayLIst.c`](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/01_sequential_list/point_list_program/ArrayList.c)** <br>
<br><br>

## main 함수 작성하기 - `PointListMain.c`
자, 이제 `point list program`의 실행을 위한 main 함수를 작성해 보도록 하겠다.<br>
<br>

### 1) `PointListMain.c` 파일을 실행시키는데 필요한 표준 라이브러리 + 헤더파일 포함시키기
- `<stdio.h>` 표준 라이브러리(header file) 추가
- `<stdlib.h>` 표준 라이브러리(header file) 추가
- `ArrayList.h` 헤더파일 추가
- `Point.h` 헤더파일 추가
<br>

```c
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"
```
<br>

먼저, 위와 같이 `PointListMain.c`소스파일을 작성하는데 필요한 표준 라이브러리(header file) `<stdio.h>`, `<stdlib.h>`를 포함<br>
시켜 주었다.<br>

  > #### `<stdlib.h>`
  > `<stdlib.h>`는 C언어에서 기본적으로 제공해주는 표준 라이브러리(header file)중 하나로, 해당 헤더파일에는 메모리 관리, 난수 생성<br>
  > 문자열 변환 등과 같은 유용한 함수들이 포함되어 있다.<br>
  > 해당 함수들 중, 우리가 사용할 함수로는 **메모리 관리 : `malloc()`, `free()` 함수가 있다.**<br>

<br>

그리고, 배열 기반 리스트(Array List)를 구현하는데 필요한 매크로 정의, `LData`에 대한 `typedef`선언, `ArrayList`구조체의<br>
선언과 해당 구조체를 다루는 함수들의 선언이 들어있는 `ArrayList.h`헤더파일을 포함해 주었다.<br>

마지막으로는, 우리가 `ArrayList`에 저장하고자 하는 `Point`구조체의 선언, 해당 구조체의 멤버들을 초기화 하고, 구조체 변수의<br>
멤버에 저장되어 있는 값을 출력해주고, 두 구조체 변수의 비교를 해주는, 즉, `Point`구조체를 다루는 여러 함수들의 선언까지 포함된<br>
`Point.h`헤더파일을 포함시켜 주었다.<br>
<br>

### 2) `point list program`에 쓰이는 구조체 변수, 구조체 포인터 변수의 생성 그리고 구조체 변수의 초기화
- `LData arr[LIST_LEN]`, `numOfData`, `curPosition` 멤버들을 지닌 구조체 데이터를 저장하고 관리하는 `List`구조체의<br>
  구조체 변수 `list` 생성
- `Point`구조체의 구조체 변수 `compPos` 생성
- Heap영역에 할당받은 구조체 크기 메모리의 주소값을 저장하는 `Point`구조체의 구조체 포인터 변수 `ppos` 생성
- `ListInit`함수를 통한 구조체 변수 `list`의 초기화
> **참고:** 구조체 변수는 결국 해당 구조체의 인스턴스라 할 수 있다.
<br>

```c
int main(void)
{
  List list;
  Point compPos;
  Point * ppos;

  ListInit(&list);
```
<br>

#### `Point`구조체 포인터 변수 `ppos`의 사용
위에서도 언급 하였듯이, 멤버의 개수가 많은 구조체는 일반적으로 크기가 크고, 메모리를 많이 차지하는 데이터 타입이다.<br>
때문에, 이러한 구조체는 `<stdlib.h>`표준 라이브러리에서 제공하는 `malloc`함수를 통해 프로그램이 실행되는(러닝타임) 중,<br>

원하는 시점에, 딱 필요한 만큼의, 구조체의 크기에 해당하는 메모리 공간을 메모리의 할당과 소멸 시점이 자유로운 Heap 영역에<br>
할당받고, 해당 메모리 공간의 주소값을 구조체 포인터 변수에 저장하는 방식으로 사용하는 것이, 메모리 관리 측면에서 효율적이라<br>
할 수 있다.<br>

우리도 이러한 방식을 사용하여, `malloc`함수를 통해 Heap영역에 `Point`구조체 크기만큼의 메모리 공간을 할당한 뒤, 반환되는 해당<br>
메모리 공간의 주소값을 `Point`구조체 포인터 변수 `ppos`에 저장하여 구조체 데이터를 다룰 예정이다.<br>
<br>

#### `Point`구조체 포인터 변수 `ppos`와 `list`구조체의 `LDaa arr[LIST_LEN]의 관계
이러한 구조체 데이터를 저장하는 구조체, `list`의 멤버로는 `LData arr[LIST_LEN]`이 있는데, 해당 멤버의 자료형은 `Point *`로,<br>(`typedef Point * LData`)<br>

이 `arr[LIST_LEN]`은, `Point`구조체의 주소값을 저장하는 구조체 포인터 변수들을 각 배열요소에 저장하는 구조체 포인터 배열이라<br> 할 수 있다.<br>

결국 해당 프로그램은 `malloc`함수를 통해, Heap영역에 구조체 `Point`크기 만큼의 메모리 공간을 할당하고, 해당 메모리 공간의<br>
주소를 `Point`구조체 포인터 변수 `ppos`에 저장한 뒤, `ppos`의 값을 `list`객체의 멤버인 `Point *`타입의 구조체 포인터 배열<br>
`arr[LIST_LEN]`의 요소에 저장하는 방식으로 구조체 데이터를 저장한다는 것을 유추해 볼 수 있다.<br>
<br>

#### 구조체 `list`의 멤버들의 초기화 - `ListInit(&list)`
마지막으로, `list`구조체를 통해 직접 `Point`구조체 데이터를 저장하고 관리하기 전에, `list`의 멤버들을 초기값으로 초기화<br>
해주는 작업을 `ListInit`함수를 통해 실행하여준다.<br>

`list`구조체의 멤버로는, 구조체 데이터를 실질적으로 저장하는 `LData arr[LIST_LEN]` 배열 뿐만 아니라, 현재 배열에서 참조하고<br>
있는 데이터의 위치를 저장하는 멤버, `curPosition`과 현재 저장되어 있는 데이터의 수를 저장하는 멤버 `numOfData`가 존재한다.<br>

이러한 `curPosition`과 `numOfdata`는 배열기반 리스트에서의 데이터 저장 및 관리를 수월하게 할 수 있도록 도와준다.<br>
<br>


### 3) `list`구조체에 4개의 데이터 저장하기 
- 3-1) `malloc`함수를 통해 Heap영역에 `Point`구조체 크기의 메모리 공간을 할당하고, 해당 메모리 공간의 주소값을 `Point`구조체<br>
  포인터 변수 `poss`에 저장
- 3-2) `Point.c`파일에 정의되어 있는 `SetPointPos` 함수를 호출하여, 구조체 포인터 변수 `ppos`가 가리키고 있는 Heap영역에 <br>
  생성된 구조체의 멤버 `ppos -> xpos`, `ppos -> ypos`를 매개변수로 전달받은 값으로 초기화 해줌
- 3-3) `LInsert`함수를 통해 구조체 `list`의 멤버, 구조체 포인터 배열 `arr[LIST_LEN]`에 `ppos`값을 저장
> Heap영역에 구조체 생성 및 `ppos`에 주소값 저장 -> 해당 구조체의 멤버(`ppos -> xpos`, `ppos -> ypos`)의 초기화 -> 초기화<br>
된 구조체의 주소값(ppos)을 `list`의 멤버, 구조체 포인터 배열 `LData arr[LIST_LEN]`의 요소로 저장
<br>

```c
ppos = (Point*)malloc(sizeof(Point));
SetPointPos(ppos, 2, 1);
LInsert(&list, ppos);
```
<br>

해당 코드의 동작 방식은 코드 위 설명만 읽어도 충분히 이해가 가능하다 생각한다.<br>

위 코드에서 사용되는 함수 `SetPointPos`, `LInsert`는 각각 `Point.c`소스파일, `ArrayLIst.c`소스파일에 정의되어 있는<br>
함수이다.<br>

두 소스파일에 정의되어 있는 함수들이 하나의 소스파일에 등장하다 보니 헷갈릴 수 있다.<br>

이때, 두 소스파일의 쓰임에 대해 명확히 이해해두면, 수월하게 이해하는 것이 가능하다.<br>

- **`Point.h` 헤더파일은 우리가 실질적으로 저장할 구조체 데이터인 `Point`구조체와 해당 구조체를 다루는 함수들이 선언되어 있다.<br>**
  **`Point.c` 소스파일은 `Point.h`헤더파일에 선언되어 있는 함수들을 정의해준다.<br><br>**
  우리는 `Point.c`소스파일에 정의되어 있는 함수들을 통해 `Point`구조체를 초기화하고, 해당 구조체의 멤버의 값을 출력하고, <br>
  `Point`구조체를 비교하는 작업을 할 수 있다.<br>
  
  > 결국, `PointListMain.c` 프로그램에서 저장하고자 하는 구조체 데이터인 `Point`구조체와 관련된 작업을 수행할 때 `Point.h`,<br>
  `Point.c`가 사용됨

<br>

- **`ArrayList.h`헤더파일은 데이터를 저장하는 `ArrayList`구조체와 관련 자료형의 `typedef`정의, `ArrayList`구조체를 다루는 <br>
  함수들이 선언되어 있다.<br>**
  **`ArrayLIst.c`소스파일은 이렇게 `ArrayList.h`헤더파일에 선언되어 있는 함수들을 정의해준다.<br><br>**
  우리는 `ArrayList.c`소스파일에 정의되어 있는 함수들을 통해 `list`구조체를 생성 및 초기화 하고, 데이터를 저장하고, 데이터를<br>
  탐색하여 반환하고, 저장되어 있는 데이터를 삭제하고, 저장공간에 존재하는 데이터의 개수를 반환할 수 있다.
  
  > 결국, `PointListMain.c` 프로그램에서 `list`구조체의 생성 및 초기화, `list`구조체에 데이터 저장, 데이터 탐색, 저장된<br>
  데이터를 삭제하는 등, 전제적인 배열기반 리스트의 동작과 관련된 작업을 수행할 때 `ArrayList.h`, `ArrayLIst.c`가 사용됨

<br>

### 4) 데이터 탐색 및 저장된 데이터의 출력
- 4-1) `ArrayList.c`소스파일에 정의되어 있는 리스트에 저장되어 있는 데이터의 수를 반환해주는 `LCount`메서드를 통해 현재<br>
  데이터의 수를 출력해준다.<br>
- 4-2) `ArrayList.c`소스파일에 정의되어 있는, `LFirst`함수를 사용하여, 구조체 `list`의 구조체 데이터를 저장하는 멤버<br>
  `Point *` 타입의 구조체 포인터 배열 `arr[LIST_LEN]`의 첫 번째 인덱스인,<br>
  
  `arr[list -> curposition] // curPosition = 0`에 저장되어 있는 Heap 영역에 할당된 구조체의 주소값을 `Point`구조체<br>
  포인터 변수 `ppos`가 가리키게 한다.<br>
  
  그리고, `Point.c`소스파일에 정의되어 있는 `ShowPointPos`함수를 이용하여, `ppos`가 가리키고 있는 `arr[LIST_LEN]`<br>
  첫 번째 인덱스에 주소값이 저장되어 있는 구조체의 멤버 `xpos`,`ypos`값을 출력해준다.<br>
- 4-3) `ArrayList.c`소스파일에 정의되어 있는, `LNext`함수를 사용하여, 구조체 `list`의 구조체 데이터를 저장하는 멤버<br>
  `Point *` 타입의 구조체 포인터 배열 `arr[LIST_LEN]`의 첫번째 인덱스 이후, 두 번째 인덱스인,<br>
  
  `arr[list -> curPotision] // curPotition = 1`에 저장되어 있는 Heap 영역에 할당된 구조체의 주소값을 `Point`구조체<br>
  포인터 변수 `ppos`가 가리키게 한다.<br>

  그리고, `Point.c`소스파일에 정의되어 있는 `ShowPointPos`함수를 이용하여, `ppos`가 가리키고 있는 `arr[LIST_LEN]`<br>
  에 주소값이 저장되어 있는 구조체의 멤버 `xpos`와 `ypos`의 값을 출력해준다.<br>
  
  해당 과정은, 현재 `ppos`가 가리키고 있는 구조체 포인터 배열 `arr[LIST_LEN]`의 인덱스를 의미하는 `curPosition`값이<br>
  총 저장된 데이터의 수를 의미하는 `numOfData`에 -1을 한 값과 같거나 커지면, 종료된다.<br>
<br>

```c
if(LFirst(&list, &ppos) {
  ShowPointPos(ppos)

  while(LNext(&list, &ppos) {
    ShowPointPos(ppos)
  }
}

printf("\n");
```
<br>

해당 작업이 코드상에서 어떻게 동작하는지 한번, 정리해 보도록 하겠다.<br>
필요한 코드는 다음과 같다.<br>

- `ArrayList.c`소스파일에서의 `LFirst`함수의 정의
- `Point.c`소스파일에서의 `ShowPiontPos`함수의 정의
<br>

#### `ArrayList.c` - `LFirst`함수의 동작
먼저, 해당 함수는 `PointListMain.c`파일에서 아래 호출문을 통해 호출된다.<br>

```c
if(LFirst(&list, &ppos)
```
<br>

자, 그럼 이제 `LFirst`함수가 어떻게 정의 되어있는지 한번 보도록 하자.<br>
해당 코드는 아래와 같다.<br>

```c
void LFirst(List * plist, Ldata * pdata) {
  if(plist -> numOfData == 0) {
    printf("리스트에 데이터가 존재하지 않습니다.\n");
    return False;
  }

  (plist -> curPosition) = 0;

  *pdata = plist -> arr[plist -> curPosition];
  return True;
}
```
<br>

먼저, 매개변수 부터 보자.<br>
- `List * plist` - 구조체 `List`타입의 구조체 포인터 변수 `plist`이다. 구조체 변수 `list`의 주소값을 전달받는다.<br>
- `LData * pdata`-  `Point **` 타입의 구조체 이중 포인터 변수 `pdata`이다. 구조체 포인터 `ppos`의 주소값을 전달받는<br>
  구조체 이중 포인터 변수이다.<br>
  (`LData`는 `ArrayList.h`헤더파일에서, `typedef Point * LData`문에 의해, 기본적으로 `Point`구조체 포인터 변수로 <br>
  자료형이 정의되어있다. 이 상태에서 `LData * pdata`는 결국, `Point ** pdata`를 뜻하게 된다.)
<br>

`LFirst`함수는 리스트 내에 데이터가 존재하는 경우, `list`구조체의 멤버 구조체 포인터 배열 `arr`의 인덱스 0에 위치하는,<br>
첫 번째 구조체 데이터(Heap영역에 할당된 구조체 크기 만큼의 메모리 공간의 주소값)를 반환해준다.<br>

이때, 반환방식을 보면, 구조체 포인터 변수 `ppos`를 가리키는 구조체 이중 포인터 변수 `pdata`를 이용하여, `*pdata`에<br>
`arr`의 첫번째 인덱스에 저장되어 있는 구조체 데이터(구조체의 주소값)를 저장시키는 방식으로,<br>
`ppos`가 해당 구조체의 주소값을 저장하여 가리키게 한다.<br>

왜 `ppos`의 주소값을 매개변수에 전달받아 사용하는 방식으로 `ppos`가 `arr`의 첫 번째 인덱스에 저장되어 있는 구조체의<br>
주소값을 저장하게 하는지는 몇 번 다뤄본 비슷한 주제이긴 하지만, 간단히 설명해 보도록 하겠다.<br>

왜 `ppos`를 그냥 매개변수에 전달해주지 않고, `ppos`의 주소값을 전달해 주는 것일까?<br>

해당 질문에 대한 답은 매개변수에 값을 전달 할 때, 해당 값은 복사되어 전달된다는 점에 있다.<br>

`LFirst`함수를 조금 변경하여 다음과 같의 정의했다고 하였을 때, 발생하는 문제점이 무엇인지 알아보자.<br>

```c
void LFirst(List * plist, LData pdata) {
 // ...

 (plist -> curPosition) = 0;

 pdata = plist -> arr[plist -> curPosition];
 return True;
}
```
<br>

위에서도 언급하였다시피, 매개변수에 인자값을 전달 할 때, 해당 값은 복사되어 매개변수에 전달되게 된다.<br>
이때, `Point *`타입의 매개변수 `pdata`에 `&ppos`가 아닌, `ppos`를 전달하였다고 해 보자.<br>

이 경우, `ppos`가 저장하고 있는 구조체의 주소값이 복사되어서 매개변수 `pdata`에 저장되게 된다.<br>
복사되어 전달되기 때문에, `ppos`와 매개변수`pdata`는 같은 구조체의 주소값을 저장하고 있는 구조체 포인터<br>
변수일 뿐이지, 별개의 서로 독립적인 구조체 포인터의 관계라고 볼 수 있다.<br>

즉, `pdata`가 다른 구조체의 주소값을 새로 저장한다고 해서 `ppos`도 자동으로 해당 구조체를 가리키게되는<br>
관계가 아닌 각각 `pdata`는 해당 새 구조체의 주소값을 저장하고, `ppos`는 그냥 그대로 기존 구조체의 주소<br>
값을 저장하는 독립적인 관계라는 것이다.<br>

그렇기 때문에, `pdata = plist -> arr[plist -> curPosition];`에 의해 `pdata`가 첫 번째 인덱스의 구조체<br>
주소값을 저장하게 된다고 해도, 해당 함수 밖에 있는(자신이 저장하고 있는 구조체의 주소값을 복사하여 전달<br>
해주기만 한) `ppos`에게는 아무런 영향을 미치지 못하게 된다.<br>

그리고, `LFirst`함수의 매개변수인 `pdata`는 해당 함수가 종료되면 소멸 되어버리는 지역변수이다.<br>

`LFirst`함수가 호출되어, 해당 함수의 코드 블록 내에서 선언됨에 따라, 자동메모리(stack 영역)에 저장되었다가<br>
코드 블록의 끝(함수의 종료)시, 자동으로, 소멸되게 된다.<br>

결국, 매개변수 `pdata`는 `LFirst`라는 함수의 코드 블록 내에서 선언되어 Stack메모리에 저장되고, `List` 구조체의 멤버 `arr`의<br>
첫 번째 인덱스에 저장되어 있는 구조체의 주소값을 (함수 종료 시까지) 가리키고 있다가 해당 함수가 종료되면 자동으로 소멸되어 버린다.<br>

`LFirst`함수 외부에 선언되어 있는 구조체 포인터 변수 `ppos`는 `pdata`와는 별개의 구조체 포인터 변수로, `LFirst`함수를 호출하기<br>
전, 그 상태 그대로 있게 된다.<br>

그래서, 우리는 `ppos`구조체 포인터 변수의 주소값을 구조체 이중 포인터 타입의 매개변수 `pdata`에 전달하여, 결과적으로 `ppos`가<br>
직접 `arr`의 첫 번째 구조체의 주소값을 저장할 수 있도록 하였다.<br>
<br>

### 5) `xpos`가 2인 모든 데이터 삭제
- 5-1) 먼저, `xpos`가 2인 `Point`구조체 `compPos`를 생성하고, 해당 값으로 초기화 해준다.<br>
  (`compPos -> xpos = 2; , compPos -> ypos = 0`)
- 5-2) `ArrayList.c`소스파일에 정의되어 있는 `LFirst`함수를 통해, `list`구조체의 멤버, `arr`의 첫번째 인덱스에 저장되어 있는<br>
  Heap영역에 할당되어 있는 `Point`구조체의 주소값을 구조체 포인터 변수 `ppos`가 저장하게 한다.<br>
- 5-3) `Point.c`소스파일에 정의되어 있는 `PointComp`함수를 통해, `xpos`값이 2로 초기화 되어 있는 구조체 `compPos`의 `xpos`값과<br>
  `ppos`가 가리키고 있는 구조체의 멤버 `xpos`의 값을 비교하여, 리턴된 값이 1인 경우<br>
  (compPos -> xpos == ppos -> xpos로, `ppos`가 가리키고 있는 구조체의 멤버 `xpos`값이 2인 경우)<br>
  
  `ppos`가 가리키고 있는 구조체의 주소값을 `list`의 `arr`에서 삭제한 뒤, Heap영역에서도 할당받은 해당 구조체의 메모리 공간을<br>
  소멸시켜준다.<br>

- 5-4) `ArrayList.c`소스파일에 정의되어 있는 `LNext`함수를 통해, `list`의 `arr`의 첫 번째 이후(두번째) 인덱스에 저장되어 있는<br>
  구조체의 주소값을 `Point`구조체 포인터 변수 `ppos`가 저장하게하고, `Point.c`소스파일에 정의되어 있는 `PointComp`함수를 통해<br>
  구조체 `compPos`의 `xpos`값과 `ppos`가 가리키고 있는 구조체의 `xpos`값을 비교하여, 리턴되는 값이 1인 경우,<br>
  
  `ppos`가 가리키고 있는 구조체의 주소값을 `list`의 `arr`에서 삭제한 뒤, Heap영역에서도 할당받은 해당 구조체의 메모리 공간을<br>
  소멸시켜주는 과정을 현재 `ppos`가 가리키고 있는 구조체 포인터 배열 `arr[LIST_LEN]`의 인덱스를 의미하는 `curPosition`값이<br>
  총 저장된 데이터의 수를 의미하는 `numOfData`에 -1을 한 값보다 작을동안 다음 인덱스로 넘어가며 반복해준다.<br>
<br>

```c
// compPos 구조체 초기화
compPos -> xpos = 2;
compPos -> ypos = 0;

if(LFirst(&list, &ppos)) // arr의 첫 번째 구조체 데이터(구조체 주소값)를 탐색
{
  if(PointComp(ppos, &compPos) == 1) // PointComp의 리턴값이 이면,(탐색한 구조체의 xpos값이 2라면)
  {
    ppos = LRemove(&list); // 해당 구조체의 주소값을 arr에서 삭제하고, 삭제한 구조체의 주소값을 ppos에 리턴
    free(ppos); // 리턴받은 Heap영역의 구조체 메모리 공간을 `free`함수로 소멸(완전히 삭제)
  }

  while(LNext(&list, &ppos))
  {
    if(PointComp(ppos, &compPos) == 1)
    {
      ppos = LRemove(&list);
      free(ppos);
    }
  }
}
```
<br>

해당 기능이 무슨 기능인가? 구조체데이터가 담겨있는 `list`구조체의 멤버 `arr`에서 멤버 `xpos`값이 2인 구조체를 탐색하여 해당<br>
구조체의 주소값을 `arr`에서 삭재한 후, Heap영역에서 해당 구조체 메모리를 free함수로 소멸 시켜줌으로써, `xpos`값이 2인 구조체<br>
를 완전히 삭제 시켜주는 기능이다. <br>

- 구조체 데이터(구조체 주소값)를 저장하는 `list`의 멤버 구조체 포인터 배열 `arr`에서 `xpos`값이 2인 구조체의 주소값을 탐색 후 삭제
- 해당 주소값에 해당하는 Heap영역에 할당된 구조체 메모리 공간을 `free`함수를통해 완전히 소멸
> 즉, 배열기반 리스트 자료구조 `list`에서의 삭제 + 실질적인 메모리 공간에서의 삭제(메모리 소멸) = 완전히 삭제
<br>

#### `list`의 멤버 `arr`에서 첫 번재 인덱스에 저장되어 있는 구조체 데이터
먼저, 해당 자료구조의 탐색 과정은 먼저, `LFirst`함수를 통해 첫번째 인덱스에 존재하는 구조체 데이터를 탐색하고, 그 다음 `LNext`<br>
함수를 통해 두번째 인덱스에 존재하는 구조체 데이터부터 순차적으로 탐색해 나가는 방식이다.<br>

즉, `LNext`함수를 호출하기 위해서는 필수적으로 `LFirst`함수를 호출해 주어야 한다.<br>

`LFirst`함수가 해당 리스트의 첫번째 지점임을 의미하는 함수이기 때문이다. 데이터를 처음부터 탐색해 나가야 하는 경우가 빈번한 해당<br>
자료구조 에서는, 이러한 기능(리스트의 현재 위치를 첫 번째 지점으로 옮겨주고, 첫 번째 지점에 위치하는 데이터를 탐색해주는 기능)을<br>
가진 함수가 필수적으로 필요하다.<br>

이러한 이유로, 먼저,`LFirst`함수를 호출하여, `arr`의 첫번째 인덱스(`list -> arr[0]`)에 위치하는 구조체의 주소값을 구조체 포인터<br>
변수 `ppos`가 가리키게 한다.<br>

그리고, `ppos`가 가리키고 있는 구조체의 멤버, `xpos`의 값이 2인지 확인해주는 함수인 `PointComp`함수를 호출하여 확인한다.<br>
만약 해당 함수의 리턴값이 1로, `ppos`가 가리키고 있는 구조체의 멤버 `xpos`값이 2인경우, **해당 구조체의 삭제를 진행한다.**<br>

- #### 구조체 데이터의 삭제 : 배열 기반 리스트에서의 삭제 & Heap영역에 할당된 구조체 메모리까지 삭제 
  자, 지금 이 `LRemove`함수를 호출하는 시점이 어떤시점인가? 바로, `LFirst`함수를 통해 `List -> arr[0]`에 주소값이 저장되어 있는<br>
  구조체를 `ppos`가 가리키게 하고, 이 `ppos`가 가리키고 있는 구조체의 멤버, `xpos`의 값이 2임을 `PointComp`함수를 통해 확인한<br>
  상황이다.<br>

  그리고, `list`구조체의 내부적인 상황을 보면, `LFirst`함수가 `arr`의 첫 번째 인덱스에 저장되어 있는 구조체의 주소값을 탐색해 <br>
  나가는 과정에 있어,<br>
  
  `arr`에 저장되어 있는 구조체의 주소값을 저장하여 해당 구조체를 가리키는 역할을하는 구조체 포인터 변수 `ppos`가 몇 번째 인덱스의<br> 
  데이터를 가리키고 있는지를 나태내주는 `list`구조체의 멤버변수`curPosition`은 index 0을 가르키는 정수값 0을 저장하게 된다.<br>

  이렇게, `LFirst`함수가 호출되고 난 시점에서는 `ppos`가 `arr`의 0번째 인덱스에 위치하는 데이터를 참조하고 있기 때문에, `list`의<br>
  `curPosition`값으로는 0이 저장되게 된다.<br>

  즉, `list`의 멤버변수 `curPosition`은 0을저장하고, `numOfData`는 `arr`에 저장되어 있는 데이터의 수 만큼의 정수를 저장하고 있게<br>
  되는데, 이러한 상태에서 `LRemove`함수가 호출되게 되는 것이다.<br>

  다음은 `ArrayList.c`소스파일에 정의되어 있는 `LRemove`함수이다.<br>

  ```c
  LData LRemove(List * plist) {
    int rpos = plist -> curPosition;
    int num = plist -> numOfData;
    int i;
	
    LData rdata = plist -> arr[rpos]; // 데이터를 삭제하기 전, 현재 curPosition에 존재하는 데이터를 rdata에 저장. 
	
    for(i = rpos; i < (num - 1); i++) {
      plist -> arr[i]  = plist -> arr[i + 1];
    }
	
    (plist -> curPosition)--;
    (plist -> numOfData)--;
	
    return rdata; // 삭제하기 전 데이터를 저장하고 있는 rdata를 반환
  }
  ```
  <br>
  
  해당 코드를 보면 알 수 있듯이, `LRemove`함수의 경우,`LFirst`함수가 호출되고 난 시점의 `ppos`가 가리키고 있는 데이터의 `arr`<br>
  데이터 인덱스 값을 저장하고 있는 `curPosition`값과 해당 시점의 `arr`에 저장되어 있는 모든 데이터의 수를 저장하고 있는<br>
  `numOfData`값을 각각 변수 `rpos`, `num`에 저장해 두었다.<br>

  그리고, 현재 `Curposition`값에 해당 하는 인덱스에 위치하고 있는 즉, `ppos`가 가리키고 있는 구조체의 주소값은 해당 함수의 지역<br>
  변수로 선언된 `Point`구조체 포인터 변수 `rdata`에 저장된다.<br>

  왜 삭제하고자 하는 구조체의 주소값을 따로 해당 함수의 지역변수 `rdata`에 따로 저장해 두는 것일까?<br>

  그 이유는, **Heap 영역에 할당되어 있는 해당 구조체의 메모리 공간을 소멸시키지 위해서는 해당 메모리 공간의 주소값을 알고 있어야<br>
  하기 때문이다.** <br>

  즉, **1차적으로는 `LRemove`함수를 통해, `arr`상에서 해당 구조체의 주소값을 삭제해 주고**, 또, 해당 함수를 통해 리턴받은 `rdata`에<br>
  저장되어있는 `arr`에서 삭제된 구조체의 주소값을 `ppos`에 저장하여(`ppos = LRemove(&list)`) **2차적으로는 `free(ppos)`를 통해 <br>
  Heap영역에서까지 완벽하게 삭제해 주는 것이다.** 
