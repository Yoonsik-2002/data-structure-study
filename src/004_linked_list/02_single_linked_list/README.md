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
‘자료형’의 정의에 ‘기능’ 혹은 ‘연산’과 관련된 내용을 명시할 수 있다.  따라서 추상 자료형이라 하여 그것에 기능 또는 연산과 관련된 내용을<br>
명시할 수 없다는 생각은 버려야 한다.<br>
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
추상 자료형에 중요한 정보라면 무엇이든 추가할 수 있으며, 그 방법에는 제한이 없다. 하지만 불필요한 것을 포함시키는 것은 바람직하지 못하다.<br>

<br><br>


# 링크드 리스트(Linked List)
### 배열의 한계
프로그래밍을 하다보면, 배열 이상의 무엇인가를 요구할 때가 생기게 된다. 예들 들어, 디렉토리 내에 있는 파일들의 목록을 소프트웨어가<br>
필요로 한다고 생각해 보자, 이때 한번 생성하면 그 크기를 변경할 수 없는 배열을 사용하게 되면, 다음과 같은 문제가 생기게 된다.<br>

디렉토리 내에 파일의 개수가 하나도 없을 수도 있고, 딱 10개가 존재할 수도 있으며, 수만, 수천개의 파일이 존재할 수도 있다.<br>
이러한 상황에서 배열을 사용한다고 생각해 보자.<br>

> 제발 디렉토리 안에 10개의 파일만 있어라.. 라고 빌면서 다음과 같이 배열을 선언하는 것은 말도 안되는 짓이다.<br>
  `char * files[10];`<br>

> 그렇다고 해서 넉넉잡아 6800개 정도면 충분하겠지? 라고 생각하면서 다음과 같이 무작정 큰 배열을 선언하는 것도 문제가 있다.<br>
  쓸데없이 큰 배열을 생성하게 될 뿐만 아니라, 해당 디렉토리의 파일 수가 6800개 이상일 수도 있기 때문이다.<br>
  `char * files[6800];`<br>

이렇게, 우리는 프로그래밍을 하면서, 데이터의 집합을 보관하는 기능을 가지고는 있지만, 한번 선언하면 <br>
그 크기를 변경할 수 없다는 한계를 가진 배열을 대신할 무언가가 필요한 상황이 생기게 된다.<br>
<br>

### 링크드 리스트의 개념
위에서 다뤄보았던 배열의 한계를 보완하면서, 데이터의 집합을 보관하는 기능을 가지고 있는 자료구조는 무엇이 있을까?<br>
바로 **`리스트(List: 목록)`** 이다.<br>

리스트는 배열처럼 데이터의 집합을 보관하는 기능을 가지면서, 배열과는 달리 유연하게 그 크기도 변경할 수 있는 자료구조이다.<br>

링크드 리스트(Linked List)는 이 리스트를 구현하는 여러가지 기법 중, 가장 간단한 방법이라고 꼽히는 자료구조로,<br>
리스트 내의 각 요소는 노드(Node)라고 하는데, 우리나라 말로 번역하면 '마디' 라는 의미를 가진다.<br>

링크드 리스트는 이 **'노드(마디)를 연결해서 만드는 리스트'** 라고 해서 붙여진 이름이다.<br>
그럼 이 노드는 어떤식으로 이루어져 있을까? 아래 그림을 한번 봐 보자.<br>

![2021-04-03-singly-linked-list-node](https://user-images.githubusercontent.com/83572199/233826489-4417d7f6-3b9d-4dd2-9ed8-fd233bcc9618.svg)<br>

노드는 다음과 같이 데이터를 저장할 수 있는 필드와 다음 노드의 주소값을 저장하는 포인터(다음 노드와 연결해주는 연결고리 역할)로 <br>
이루어져 있다.<br>

이러한 노드를 주렁주렁 엮으면 링크드 리스트 라는 자료구조가 만들어지고,<br>
이 링크드 리스트의 첫 번째 노드가 해당 링크드 리스트의 머리 즉, head가 되며, 링크드 리스트의 마지막 노드가 해당 링크드 리스트의 꼬리, tail이 된다.<br>

이러한 구조로 이루어진 링크드 리스트를 사용하게 되면, 배열과는 다르게 다뤄야할 데이터의 집합의 크기를 미리알지 못한다 해도<br>
문제가 되지 않는다.<br>

해당 링크드 리스트에 데이터를 추가하고 싶으면, 추가하고 싶은만큼 데이터가 늘어날 때마다 tail에 노드를 생성하여 붙이면 되고,<br>
링크드 리스트 중간에 새로운 노드를 끼워넣거나 삭제하고 싶으면, 해당 노드를 가리키는 포인터만 수정해주면 되기 때문이다.<br>
<br>

### 링크드 리스트의 구현
링크드 리스트는 노드가 주렁주렁 엮인 형태라고 설명하였다. 때문에, 링크드 리스트를 구현하기 위해서는 노드를 코드로 표현할 수 있어야 한다.<br>
이 노드를 C언어로 표현하면 다음과 같이 구조체 형태로 표현이 가능하다.<br>

```c
typedef struct tagNode // 구조체 태그이름 tagNode
{
  int Data; // 데이터를 저장하는 필드
  struct tagNode* NextNode; // 다음 노드의 주소값을 저장하는 포인터 (같은 구조체 타입:struct tagNode(Node) 의 노드를 연결해준다.)
} Node;
```
이렇게 선언한 `Node` 구조체는 다음과 같이 인스턴스를 생성 가능하다. 
```c
Node Mynode;
```

<br><br>


## 링크드 리스트의 연산
링크드 리스트를 구축하고, 링트드 리스트의 데이터를 활용하기 위한 주요 연산으로는 다음 5가지가 존재한다. 
- 노드의 생성/소멸
- 노드 추가
- 노드 삭제
- 노드 삽입
- 노드 탐색

노드의 생성/소멸, 추가, 삭제, 삽입은 링크드 리스트의 구축을 위한 연산이고, 노드 탐색은 구촉되어 있는 링크드 리스트의<br>
데이터를 활용하기 위한 연산이다.<br>
<br>

### 노드의 생성/소멸
노드의 생성과 소멸에 대해 이해하기 위해서는 우선적으로, C언어 프로그램의 메모리 영역에 대한 지식이 필요하다.<br>
해당 내용은 다음 링크에서 다루고 있다.<br>
[Memory Area of C Program](https://github.com/Yoonsik-2002/data-structure-study/tree/main/000_other_knowledge/001_memory_area_of_c_program)<br>

그럼, 링크드 리스트를 이루는 노드는 자동 메모리(스택 영역), 자유 메모리(힙 영역) 중 어디에 생성하는 것이 적절할까?<br>
먼저, 자동 메모리에 노드를 생성해 보겠다.<br><br>

- #### 노드를 자동메모리(스택 영역)에 생성하게 되는 경우
  다음은 새로운 노드를 자동메모리에 생성해주는 함수 `SSL_CreateNode` 이다.<br>
  
  ```c
  // 노드생성(실패 버전)
  Node* SSL_CreateNode(int new_data)
  {
    Node NewNode; // 자동 저장소(스택 영역)에 새로운 노드 생성
    
    NewNode.Data = new_data; // 인자로 받은 new_data의 값을 인스턴스의 멤버 Data에 저장
    NewNode.NextNode = Null; // 새로 생성된 노드 NewNode의 다음 노드는 존재하지 않음(Null)
    
    return &NewNode; // NewNode의 주소값 반환
  }
  ...
  Node* MyNode = SSL_CreateNode(911); // 구조체 타입의 포인터 변수 MyNode에 반환된 NewNode의 주소값 저장
  ```
  다음 코드를 실행한다면, 노드생성을 성공하게될까?<br>
  답은 '아니다' 자동 메모리는 코드 블럭을 기준을 생성과 소멸이 일어난다. 즉, 코드 블럭 안에서 생성된 것들은 선언 당시에<br>
  자동 메모리에 저장되었다가 코드블럭의 끝에서 모두 자동으로 제거된다.<br>
  
  함수도 마찬가지이다. `SSL_CreateNode`함수 안에서 생성된 노드 `NewNode`는 선언 당시에 자동 메모리에 저장되었다가,<br>
  해당 함수가 종료되면서(코드 블럭의 끝) 모두 자동으로 제거되게 된다. <br>
  
  결국에 `SSL_CreateNode` 함수가 `NewNode`의 주소값을 반환하고 종료하게 되면, 해당 함수가 종료되면서, **자동 메모리 내에 저장되어 있던<br>
  `NewNode` 는 자동으로 삭제되게 된다.**<br>
  그럼, 반환된 주소값은 `NewNode`가 존재했었던 주소값이 되는 것이다. 결국, 포인터 `MyNode`는 엉뚱한 메모리를 가리키게 된다.<br>
  이러한 이유 때문에, 노드는 자동 저장소(스택 영역)에서 생성이 불가능하다.<br><br>
  
- #### 노드를 자유 저장소(힙 영역)에 생성하게 되는 경우
  자유 저장소에 메모리를 할당하기 위해서는 `malloc()` 함수가 필요하다. 해당 함수에 관한 내용은 다음 링크를 통해 볼 수 있다.<br>
  [malloc function](https://github.com/Yoonsik-2002/data-structure-study/tree/main/000_other_knowledge/002_malloc_function)<br>
  
  `malloc()` 함수를 이용하여 heap영역에 노드를 생성하는 코드를 한번 만들어 보겠다.<br>
  (Node 를 표현하는 구조체 Node 가 선언되어 있다고 가정)<br>
  ```c
  Node * NewNode = (Node*)malloc(sizeof(Node));
  ```
  먼저, `malloc()` 함수의 인자로 들어가는 `sizeof(Node)`를 보도록 하자.<br>
  
  위의 링크에서도 설명하였듯이, `malloc()`함수는 인자로 전달받은 정수의 크기에 해당하는 바이트 크기(`인자로 전달받은 정수 값 == 바이트 크기`)<br>
  의 메모리 공간을 heap영역에 할당한다.<br>
  
  이때, `malloc()` 함수가 인자로 전달받게 되는 정수는 양의 정수만 가능한데, `sizeof()`함수의 반환형이 `unsigned int`형 이기 때문에<br>
  `Node`의 크기에 해당하는 양의 정수인 `sizeof(Node)`를 인자로 전달한다.<br>
  
  그러면, `Node`의 크기에 해당하는 바이트 크기의 메모리 공간이 heap영역에 할당되게 된다.<br>
  
  그 후,`malloc()` 함수는 `Node`의 크기만큼 heap영역에 할당된 메모리 공간을 이루는 바이트들 중, 첫 번째 바이트의 주소값을 구조체 포인터 변수 `NewNode`에 반환한다.
  <br><br>
  
  구조체 타입 `Node`로 해당 함수를 형변환 하는 이유를 살펴보자.<br>
  
  일단 `sizeof()` 함수가 실행되고 나면, `malloc()` 함수의 입장에서는 할당할 메모리의 byte 크기에 대한 숫자(양의정수) 정보밖에 알 수 없다.<br>
  당연히 `malloc()`입장에서 숫자만 보고서는, 할당하는 메모리의 용도가 `int`형인지, `double`형인지 알 수가 없다.<br>
  
  때문에 `malloc()` 함수는 일단, 기본 반환형으로, 어떤 타입이든 상관 없이 주소값을 담을 수 있는 `void 형 포인터` 형태로 주소값을 반환한다.<br>
  하지만, `void 형 포인터`를 사용하는 경우, 포인터 연산과 접근이 불가하게 된다.<br>
  > **void 형 포인터를 사용하는 경우**<br>
    `void * NewNode = malloc(sizeof(Node));`<br><br>
    `malloc()` 함수를 실행하고 반환되는 주소값은 heap 영역에 할당된 메모리 전체가 아니라, 해당 메모리를 이루는 첫 번째 바이트의 주소값임,<br>
    이 상태에서 `*NewNode` 라고 하면, 첫 번째 바이트의 주소값으로부터 어디까지를 읽어들여야 하는지 알 수가 없다. <br>
    때문에 포인터 연산과 접근 불가.<br>
  
  이러한 이유로, 프로그래머는 기본적으로 `void`형 으로 반환되는 이 주소값을 원하는 type으로 형 변환하여 할당된 메모리 공간으로 접근이 가능할<br>
  수 있게 해야 한다.<br>
  
  우리가 원하는 type은 구조체 타입 `Node`이므로, 해당 type으로 형 변환을 해 준다.<br><br>
  
  이 과정들을 짧게 설명하면 다음과 같다.<br>
  > `malloc()` 함수는 sizeof 연산자가 측정한 노드의 크기만큼 자유 저장소에 할당한 후, 구조체 포인터 변수 `NewNode`에<br>
  > 그 메모리 주소를 저장한다.
  <br>
  
  그럼, `Node`를 heap 영역에 생성하고 만들어진 `Node`의 주소값을 반환하는 함수인 `SSL_CreateNode()` 를 완성해 보겠다.<br>
  ```c
  // 노드 생성
  Node* SSL_CreateNode(int NewData)
  {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    NewNode->Data = NewData;	// 구조체 포인터 변수 NewNode 가 가리키고 있는 구조체의 멤버 Data의 값을 NewData로 초기화
    NewNode->NextNode = Null;
    
    return NewNode;
  }
  ```
  
  다음은, heap 영역에 생성된 `Node`를 소멸하는 함수인 `SSL_DestroyNode()`를 만들어 보겠다.<br>
  ```c
  // 노드 소멸
  void SSL_DestroyNode(Node* Node)
  {
    free(Node);
  }
  ```
  <br>

### 노드 추가 
<br><br>
![D4952421-E66B-477C-A237-B8BDBFE21E1A](https://user-images.githubusercontent.com/83572199/236614680-2cf82b5f-c06d-4f62-882e-6ca7f47e25de.jpeg)<br>
<br>

위 사진은 여려개의 노드가 연결되어 이루어진 연결리스트를 그림을 통해 표현한 것이다.<br>
노드를 생성하는 법을 알아보았으니, 연결 리스트에 노드를 추가하는 방법에 대해 알아보도록 하겠다.<br>

**노드 추가** 라는 작업은 **연결 리스트가 비어있는 경우, 연결리스트의 첫 번째 노드를 가리키는 헤드 포인터에 새 노드를 추가하고 비어있지 않은 경우,<br>
연결 리스트의 테일노드 뒤에 새로운 노드를 만들어 추가하는 작업**을 의미한다.<br>

이 작업을 수행하기 위해서는 헤드 포인터에 새 노드의 주소값을 대입하거나 링크드 리스트의 테일노드의 연결고리 역할을 해주는 `NextNode` 포인터에<br>
새로 생성한 노드의 주소값을 대입해주어야 한다.<br>

해당 작업을 수행하는 노드 추가함수 `SSL_AppendNode`를 만들어 보겠다.<br>
해당 함수는 다음과 같이 사용이 가능하다.<br>

*(`SSL_CreateNode` 함수를 이용하여 heap영역에 새 노드를 생성하고, 생성한 노드를 `SSL_AppendNode` 함수를 이용하여 연결 리스트에 추가)*

```c
Node* List = Null; // 연결리스트의 헤드 포인터 - 연결리스트의 첫 번째 노드의 주소값 저장
Node* NewNode = Null;

NewNode = SSL_CreateNode(int data); // 힙 영역(자유 저장소)에 노드 생성 후, 생성된 노드의 주소값을 NewNode에 저장
SSL_AppendNode(&List, NewNode); // 생성한 노드를 연결 리스트에 추가
```
<br>

- #### 노드 추가함수 `SSL_AppendNode`
  `SSL_AppendNode` 함수가 호출되면, 해당 함수의 인자로, 연결리스트의 첫 번째 노드의 주소값을 저장하는 헤드 포인터 `List`의 주소값이<br>
  매개변수인 구조체 타입의 이중 포인터 변수 `Head`에 전달되고,<br>
  새로 만들어진 노드의 주소값을 저장하고 있는 포인터 `NewNode`가 매개변수 `NewNode`로 전달된다.<br>
  
  노드를 추가하기 위해, 해당 함수를 이용하여 `List`가 비어있으면(헤드 포인터가 아무것도 가리키고 있지 않음), 새로 생성한 첫 번째 노드의<br>
  주소값을 헤드 포인터에 추가해주고,<br>
  `List`가 비어있지 않다면, 테일노드를 찾아 해당 노드의 `NextNode` 에 `NewNode(새로 생성한 노드의 주소값)`를 대입해 주어야 한다.<br>
  
  먼저, 함수가 호출되면서, 구조체 타입의 이중포인터 `Head`는 연결리스트의 첫 번째 노드를 가리키는 구조체 타입의 포인터 변수,<br>
  헤드 포인터 `List`를 가리키게 되는데, (`Node** Head = &List`)<br>
  해당 상황을 그림으로 표현하면 다음과 같다.<br>
  
  ![55FAA663-BD3A-47D2-BE1A-BC1191E55730](https://user-images.githubusercontent.com/83572199/236591704-bb77f416-67b1-4f7b-a05d-2318f7096e55.jpeg)<br>


  > `List` - heap 영역에 생성된 첫 번째 노드의 주소값 저장(없을 시, Null값 저장)<br>
  > `*List` - 저장된 주소값에 해당되는 노드<br><br>
  > `Head` - 구조체 포인터`List`의 주소값(`&List`)<br>
  > `*Head` - `List`가 저장하고 있는 첫 번째 노드의 주소값(`List`)<br>
  > `**Head` - `List`가 저장하고 있는 노드의 주소값에 해당하는 첫 번째 노드(`*List`)<br>
  
  
  <br>
  
  다음은 새 노드를 추가해주는 `SSL_AppendNode` 함수이다.<br>
 
  ```c
  void SSL_AppendNode(Node** Head, Node* NewNode) 
  {
    if((*Head) == Null) // List(*Head)가 Null인 경우 - 헤드 포인터 List가 첫 번째 노드의 주소값을 저장하고 있지 않은 경우, 즉 List가 비어있는 경우
    {
      *Head = NewNode; // List에 새로운 첫 번째 노드의 주소값 저장
    }
    
    else // List가 비어있지 않은 경우 - Tail 노드를 찾아 해당 노드의 NextNode에 NewNode를 대입
    {
      Node* Tail = (*Head);
      while(Tail->NextNode != Null) // 탐색을 반복하여, 구조체 포인터 변수 Tail이 마지막 노드의 주소값을 저장(마지막 노드 바로 이전 노드의 포인터 멤버변수 NextNode 값 저장) - 마지막 노드를 Tail이 가리키게 됨
      { 
        Tail = Tail->NextNode; 
      }
      Tail->NextNode = NewNode // 마지막 노드를 Tail이 가리키고 있는 상태에서 저장값이 Null인 해당 노드의 포인터 멤버변수 NextNode에 새로 생성한 노드의 주소값 NewNode 저장!
    }
  }
  ```
  이때 나는 개인적으로, 해당함수를 보고 다음과 같은 의문점이 생겼다.<br>
  
  *'왜 매개변수를 이중포인터로 두어서 `List`의 주소값을 인자로 전달받지? 그냥 `List`를 인자로 전달하고<br>
  `Node* Head`로 받아도 문제 없는거 아닌가?'*<br>
  
  해당 의문에 대한 답은 직접 해당 함수가 작동하는 과정을 풀어봄으로써 찾아볼 수 있었다.<br>
  
  먼저, `SSL_AppendNode`함수는 연결리스트의 첫 번째 노드의 주소값을 저장하는 헤드 포인터 `List`에 새로운 첫번째 노드의 주소값을<br>
  추가하거나,
  헤드 포인터가 가리키고 있는 첫 번째 노드로부터 시작되어 이어져 있는 연결리스트의 테일노드에 새로 생성된 노드를<br>
  이어 붙여주는 동작을 하는 함수이다.<br>
  
  **때문에, 해당 함수가 동작하고 난 뒤에, 헤드포인터 `List`는 연결리스트의 첫 번째 노드를 반드시 가리키고 있어야 한다!!**<br>
  
  이 점을 기억하고, `SSL_AppendNode`함수의 동작과정을 살펴보도록 하겠다.<br><br>
  
  #### Step1
  ```c
  Node* List = Null;
  Node* NewNode = Null;
  
  NewNode = SSL_CreateNode(911);
  ```
  먼저, 연결리스트의 첫 번째 노드를 가리키는 헤드 포인터 `List`가 선언된다.<br>
  해당 시점에서는 아직 노드가 생성되기 전이기 때문에 아무것도 가리키고 있지 않은 상태 이므로, `Null` 값으로 초기화 하였다.<br>
  
  그리고, `SSL_CreateNode` 함수를 통해 새롭게 생성된 노드의 주소값을 저장하는 구조체 포인터 변수 `NewNode`도 선언된다.<br>
  마찬가지로, 아직 새 노드를 생성하지 않은 상태이기 때문에 아무것도 가리키고 있지 않아, `Null` 값으로 초기화 하였다.<br>
  
  이렇게, 헤드 포인터`List`와 새 노드를 저장할 구조체 포인터 변수`NewNode`도 생성하였으니, `SSL_CreateNode` 함수를 통해 <br>
  `119`이라는 int형 데이터를 저장하고 있는 첫 번째 노드를 heap영역에 생성한 뒤, 해당 노드의 주소값을 `NewNode`에 저장해 보았다.<br>
  
  다음 과정을 실행시키면 C언어 프로그램의 메모리 공간, Stack영역과 Heap영역에는 아래와 같은 변화가 생긴다.<br>
  
  ![FACB1658-9586-4586-A5F6-76D1A0B74947](https://user-images.githubusercontent.com/83572199/236665563-5d6ab495-9c28-4625-befc-e9a762bc8cc0.jpeg)<br>
  
  > 지역변수와 함수의 매개변수가 저장되는 Stack영역에 `List`와 `NewNode`가 생성되고, `SSL_CreateNode`함수를 통해 `119`라는 int형 값을<br>
  저장하고 있는 새 노드가 Heap영역에 생성되고, 반환된 해당 노드의 주소값을 `NewNode`가 저장하여, 가리키는 형태를 띄게 된다.<br>
  <br>
  
  #### Step2
  ```c
  SSL_AppendNode(&List, NewNode); // void SSL_AppendNode(Node** Head, Node* NewNode);
  ```
  **`Step1`** 에서 Heap영역에 새 노드를 생성하고, 해당 노드의 주소값을 포인터 `NewNode`에 저장해 보았다.<br>
  이제, 이렇게 새로 생성된 첫 번째 노드를 비어있는 연결리스트의 헤드 포인터 `List`가 가리킬 수 있도록, `SSL_AppendNode` 함수를<br>
  사용해 보도록 하겠다.<br>
  
  위 과정을 실행시키면 Stack영역과 Heap영역에는 아래와 같은 변화가 생긴다.<br>
  
  ![158C8109-F7BA-48AB-8B72-FA2DB12D1791](https://user-images.githubusercontent.com/83572199/236665615-760e4e1b-4566-47d3-991c-b59b0cd01504.jpeg)<br>
  <br><br>
  ![37BDCD1B-61A3-4EC4-A09B-7D11DE230F35](https://user-images.githubusercontent.com/83572199/236665664-db730e98-5ead-44ac-995c-def871b051db.jpeg)<br>

  
  > `SSL_AppendNode`함수를 호출하면 지역변수와 함수의 매개변수가 저장되는 Stack영역에는 위와 같이 `SSL_AppendNode`함수의 매개변수인<br>
  `Node** Head`와 `Node* NewNode`가 추가로 생성된다.<br><br>
  이때, 포인터 변수의 주소값을 저장하는 이중포인터 `Head`는 헤드 포인터 `List`의 주소값을 인자로 전달받기 때문에, `List`를 가리키게 된다.<br>
  (`Node** Head = &List`)<br>
  그리고, `NewNode`에 저장되어 있는 새 노드의 주소값은 복사되어 매개변수 `NewNode`에 전달되어 매개변수 `NewNode`도 Heap영역의 노드를<br>
  가리키게 된다.<br><br>
  또, `Node** Head = &List`의 경우, `*Head`는 `List`가 저장하고 있는 주소값인 `Null(List)`을 의미하게 되는데,<br>
  `SSL_AppendNode` 함수에서 `*Head == Null`인 경우 즉, 헤드 포인터 `List`가 비어있는 경우, `NewNode`를 `List`에 저장하게 하기 때문에<br>
  `*Head = NewNode`가 동작하여 헤드 포인터 `List`도 Heap영역의 노드를 가리키게 된다.<br><br>
  여기서 내 의문에 대한 해답이 나온다.<br><br>
  **`SSL_AppendNode`함수의 매개변수를 이중 포인터(`**`)로 선언해야, 헤드 포인터 `List`의 주소값을 인자로서 전달할 수 있게 되고,<br>
  이중 포인터 `Head`는 이 `List`의 주소값을 이용하여, 헤드 포인터 `List`가 새로 생성된 첫 번째 노드를 가리킬 수 있게 하는 것이다!!**<br><br>
  마지막으로, SSL_AppendNode 함수가 종료되면서, 해당 함수의 매개변수인 Head와 NewNode는 자동으로 Stack 영역에서 제거되게 되고,<br>
  결국 나머지  구조체 포인터 변수 NewNode와 헤드 포인터 List는 그대로 Heap영역에 생성된 새 노드를 가리키고 있는 채로 남아있게 된다.<br><br>
  반대로, 내가 생각한대로 `Node* Head`에 `List`를 인자로 전달하게 되면, `List`는 가지고 있는 주소값인 `Null`을 복사하여 `Head`에 전달하고<br>
  `Head`는 `Null`값을 저장하고 있기 때문에 `Head = NewNode`가 작동하여, Heap영역의 노드를 가리키게 되지만,<br>
  자신이 가지고 있는 주소값을 복사하여 전달하기만 한 `List`는 그대로 `Null`값만 저장하고 있을 뿐, 아무것도 가리키고 있지 않은 상태가 된다.<br>
  또, 최종적으로, `SSL_AppendNode`가 작동이 끝나면, 해당 함수의 매개변수인 `Head`와 `NewNode`는 자동으로 Stack영역에서 삭제되어,<br>
  결국엔 처음 함수를 호출하기 전과 똑같은 상황으로 되돌아가게 된다!<br>
<br>
  
### 노드 탐색
유연한 크기변경, 자유로운 노드 추가, 삭제 등 배열과 비교했을때 모든면이 뛰어날 것 같던 링크드 리스트의 유일한 약점은 바로 이 탐색 연산이다.<br>
배열에는 인덱스라는 개념이 존재하여, 배열 내의 `n`번째 데이터를 취하고 싶을땐 `n-1`에 해당하는 인덱스를 이용하면 쉽게 구할 수 있었다.<br>

하지만, 링크드 리스트의 경우, 헤드부터 시작해서 원하는 노드까지 하나하나 세어나가야지만 해당 요소에 접근이 가능하다.<br> 
이러한 탐색 연산을 수행하는 함수, `SSL_GetNodeAt`은 아래와 같이 사용이 가능하다.<br>

```c
Node* List = Null;
Node* MyNode = Null;

// 첫 번째 노드 생성 후, 헤드 포인터에 추가
SSL_AppendNode(&List, SSL_CreateNode(117));
// 두 번째 노드 생성 후, 첫 번째 노드 뒤에 이어붙임
SSL_AppendNode(&List, SSL_CreateNode(119));
// 세 번째 노드 생성 후, 두 번째 노드 뒤에 이어붙임
SSL_AppendNode(&List, SSL_CreateNode(121));

// 노드 탐색(탐색한 노드의 주소값 반환)
MyNode = SSL_GetNodeAt(List, 1);

// 탐색한 노드의 멤버변수 Data를 출력
printf("%d"\n", MyNode->Data);
```
이제, 원하는 링크드 리스트에서 원하는 노드를 탐색하여 해당 노드의 주소를 반환해주는 `SSL_GetNodeAt` 함수를 구현해 보겠다.<br>
<br>

- #### 노드 탐색함수 `SSL_GetNodeAt`
  이 노드 탐색함수가 동작하는 원리는 다음과 같다. **전체 범위 *'노드의 Head 부터 마지막 노드 까지'* 내 에서, 순차적으로 반복하여 <br>
  원하는 노드의 위치까지 세어가며 탐색하고 탐색한 노드의 주소값을 반환한다.**<br>
  
  이때, 주의할 점은 탐색의 시작점이 첫 번째 노드를 가리키고 있는 헤드 포인터이기 때문에, `n`번째 노드를 탐색하고 싶으면 반복 횟수를 결정하는<br>
  해당 함수의 두번째 매개변수에 `n-1` 값을 대입해 주어야 한다.<br>
  (첫 번째 노드를 탐색하고자 하는 경우에는 이미 시작점인 헤드 포인터가 가리키고 있기 때문에 탐색할 필요가 없음)<br>
  
  이러한 반복 조건을 코드로 나타내면 다음과 같을 것이다.<br>
  ```c
  while([헤드 포인터] != Null && (--[n-1에 해당하는 값]) >=0))
  ```
  <br> 
  
  이를 토대로, 노드 탐색함수 `SSL_GetNodeAt` 함수를 완성해 보도록 하겠다.<br>
  
  ```c
  Node* SSL_GetNodeAt(Node* Head, int Location)
  {
    Node* Current = Head;
    Location -= 1; // Location값에서 1을 빼주는 기능을 더해, 두번째 노드를 탐색하고 싶은 경우, 그냥 헷갈리지 않게 1이 아닌 2를 인자로 전달할 수 있게 함.
    
    while(Current != Null && (--Location) >= 0)
    {
      Current = Current->NextNode;
    }
    return Current;
  }
  ```
  먼저, 해당 코드를 보면, 링크드 리스트의 첫 번째 노드의 주소값을 저장하고 있는 구조체 포인터 변수 `List`의 값이 복사되어<br>
  해당 함수의 매개변수 `Head`에 저장되게 된다.<br>

  또, 현재 노드의 주소값을 저장하는 해당 함수의 지역변수 `Current`에 `List(첫 번째 노드의 주소값 저장)`의 값을 복사하여<br>
  저장한 `Head`의 값이 저장된다.<br>

  이러한 함수의 매개변수, 지역변수는 해당 함수가 종료되면, Stack 메모리에서 자동으로 소멸되게 된다.<br>

  결국, `while`문을 통해서, 찾고자 하는 위치의 노드를 탐색하고, 해당 노드의 주소값을 `Current`에 저장하여 `return`하고<br>
  이 `SSL_GetNodeAt`함수는 종료되게 되는데,<br>

  해당 함수가 종료되고 나면, 위에서 설명하였듯이, 매개변수 `Head`와 `Location`, 지역변수 `Current`는 메모리(Stack)에서<br>
  삭제되게 된다. 그리고, 값을 복사하여 전달해 준, `List`는 초기 상태 그대로, 첫 번째 노드를 가리키고 있는 상태가 된다.<br>
  (`SSL_GetNodeAt` 함수의 매개변수 `Head`에 값을 복사하여 전달해준(Call by address) `List`는 해당 함수의 동작과는<br>
  별개로, 첫 번째 노드를 가리키고 있던 초기 상태를 유지함. 결과적으로는 탐색하고자 했던 Node의 주소값이 return 되고,<br>
  해당 함수의 매개변수 지역변수는 모두 제거 되고, 값을 복사하여 전달한 `List`는 초기 상태 그대로 첫 번째 노드를 가리키고<br>
  있는 상태가 됨)<br>

  노드탐색 함수는 보기엔 간단하지만, 배열과는 달리 탐색하고 싶은 노드까지 하나하나 순차적으로 탐색해나가야 한다는<br>
  비효율성을 품고 있다.<br>
<br>

### 링크드 리스트 내부의 노드 삭제
노드 삭제연산은 링크드 리스트 내부의 임의의 노드를 삭제하는 연산이다. 해당 작업은 삭제하고자 하는 노드의 이전 노드의 `Nextnode`값에 삭제하고자<br>
하는 노드의 다음 노드의 주소값을 대입하여 연결하는 방식으로 구현이 가능하다.<br>
(삭제하고자 하는 노드를 건너 뛰어서 이전 노드와 다음 노드를 연결하는 방식이다.)<br>

해당 함수를 설계하는데 있어, 구현해 내야 할 아래와 같은 두 가지 경우의 수가 존재한다.<br>
1) 헤드 포인터가 가리키고 있는 첫 번째 노드를 링크드 리스트 상에서 삭제하는 경우<br>
2) 그 외의 노드를 링크드 리스트 상에서 삭제하는 경우<br>

이러한 두 가지 경우를 기억하고, 링크드 리스트 내부의 노드를 삭제해 주는 `SSL_RemoveNode`함수를 구현해 보도록 하겠다.<br>
<br>

- #### 링크드 리스트 내에서의 노드 삭제 함수 `SSL_RemoveNode`
  해당 함수가 동작하는 방식은 다음과 같다.<br>

  먼저, 링크드 리스트의 첫 번째 노드를 가리키는 헤더 포인터 `List`의 주소값을 구조체 이중포인터 `Head`라는 매개변수에게<br>
  전달해주고, 링크드 리스트 내에서 삭제하고자 하는 노드의 주소값을 매개변수 `Reamove`에 전달해 준다.<br>

  ```c
  // 함수 호출
  SSL_RemoveNode(&List, Target);
  ```
  ```c
  void SSL_RemoveNode(Node** Head, Node* Remove) {
   ...
  }
  ```

  자, 그럼 이제 첫 번째 경우에서의 코드를 짜보도록 하겠다.<br>
  헤드 포인터가 가리키고 있는 첫 번째 노드를 링크드 리스트 상에서 삭제하기 위해서는 먼저, 조건을 다음과 같이 주어야 할 것이다.<br>
  
  ```c
  if(*Head == Reamove) // 헤더 포인터가 가리키고 있는 첫 번째 노드의 주소값과 삭제하고자 하는 노드의 주소값이 일치하는 경우
  ```

  그리고, 해당 조건이 만족하는 경우, 링크드 리스트의 첫 번째 노드를 삭제해 주기 위해서는 헤드 포인터가 자신이 가리키고 있는<br>
  기존의 첫 번째 노드인 `Remove`의 다음 노드(`Remove -> NextNode`)를 가리키게 해야 할 것이다.<br>
  해당 작업을 코드로 나타내면 다음과 같다.<br>

  ```c
  (*Head) = Remove -> NextNode;
  ```

  이렇게 간단하게 링크드 리스트의 첫 번째 노드를 삭제할 수 있는 코드를 구현해 보았다.<br>
  
  이번엔 그 이외의 노드를 링크드 리스트 내에서 삭제하는 코드를 짜 보도록 하겠다.<br>
  첫 번째 노드를 제외한 그 이외의 노드를 링크드 리스트에서 삭제하기 위해서는 첫 번째 노드에서부터 순차적으로 삭제하고자 하는 노드<br>
  의 이전 노드를 탐색하여, 해당 노드의 `NextNode`값을 삭제하고자 하는 노드의 `NextNode`값으로 지정해주어야 한다.<br>

  이러한 작업을 통해 삭제하고자 하는 노드 이전 노드가 삭제하고자 하는 노드를 건너뛰어, 그 다음노드와 연결되게 할 수 있다.<br>

  자, 먼저, 다음 코드와 같이 탐색한 노드의 주소값을 저장하고 이를 `Remove`와 비교하는데 쓰일 구조체 포인터 변수 `Current`를<br>
  선언해 보도록 하겠다.<br>

  삭제하고자 하는 노드 이전 노드의 탐색은 당연히 첫 번째 노드부터 순차적으로 이루어지기 때문에, 첫 번째 노드의 주소값을 저장하고<br>
  있는 `(*Head)`의 값을 `Current`에 대입하였다. 이로써 탐색의 시작은 첫 번째 노드가 된다!<br>

  ```c
  else {
    Node* Current = (*Head);
    ...
  }
  ```

  탐색의 시작을 정했으니, 해당 탐색의 반복조건을 담당하는 코드를 만들어 보도록 하겠다.<br>
  이 반복조건을 구성하는 조건으로, 두 가지 조건을 생각해 보았다.<br>
  1) 첫 번째 노드부터 마지막(`Current == Null`) 까지 탐색하여도 삭제하고자 하는 노드의 이전 노드를 찾지 못한 경우<br>
  2) 삭제하고자 하는 노드의 이전 노드를 탐색해낸 경우<br>
 
  자, 그럼 이제 해당 조건을 토대로 탐색의 반복을 제어해줄 `while`문을 작성해 보도록 하겠다.<br>

  ```c
  else {
    Node* Current = (*Head);

    while(Current != Null && Current -> NextNode != Remove) {
      Current = Current -> NextNode;
    }
    ...
  }
  ```

  이렇게 첫 번째 노드부터 마지막까지 탐색해도 삭제하고자 하는 노드의 이전 노드를 찾지 못하면 반복을 종료하고, 삭제하고자 하는 <br>
  노드의 이전 노드를 찾아내면 반복을 종료하는 `while`문을 완성해내 보았다.<br>

  이제, 남은 건 삭제하고자 하는 노드의 이전 노드를 찾은 경우, 해당 노드의 `NextNode`에 `Remove`의 `NextNode`를 대입해, 삭제<br>
  하고자 하는 노드를 건너 뛰어, 삭제하고자 하는 노드의 이전 노드와 다음 노드를 연결해주는 작업을 해내는 코드를 작성하는 것이다.<br>

  바로 만들어 보도록 하겠다.<br>

  ```c
  else {
    Node* Current = (*Head);

    while(Current != Null && Current -> NextNode != Remove) {
      Current = Current -> NextNode;
    }

    if(Current != Null) { // 탐색 해서 Remove 이전 노드를 찾았으면
      Current -> NextNode = Remove -> NextNode;
    }
  }
  ```

  이렇게 링크드 리스트 내에서 첫 번째 노드를 삭제하는 경우와 그 이외의 경우에 대한 동작을 담은 함수 `SSL_RemoveNode`를 완성해<br>
  보았다.<br>

  다음은 해당 함수의 전체 코드이다.<br>

  ```c
  void SSL_RemoveNode(Node** Head, Node* Remove) {
    if(*Head == Remove) {
      (*Head) = Remove -> NextNode;
    }

    else {
      Node* Current = (*Head);

      while(Current != Null && Current -> NextNode != Remove) {
        Current = Current -> NextNode;
      }

      if(Current != Null) {
        Current -> NextNode = Remove -> NextNode;
      }
  }
  ```
  <br>

### Heap 영역에서의 노드 삭제
이렇게 링크드 리스트 내에서 삭제시킨 노드는 달리 쓸 곳이 없다면 바로 파괴시키는 것이 좋다. 해당 작업은 이전에 만든 생성한 노드를 Heap영역에서 <br>
소멸시키는 `SSL_DestroyNode`함수를 이용하면 된다.<br>

이렇게 링크드 리스트 내에서 노드를 삭제시키는 `SSL_RemoveNode`는 다음과 같이 사용이 가능하다.<br>

```c
Node* List = Null;
Node* MyNode = Null;

// 첫 번째 노드 생성 후, 헤드 포인터에 추가
SSL_AppendNode(&List, SSL_CreateNode(117));
// 두 번째 노드 생성 후, 첫 번째 노드 뒤에 이어붙임
SSL_AppendNode(&List, SSL_CreateNode(119));
// 세 번째 노드 생성 수, 두 번째 노드 뒤에 이어붙임
SSL_AppendNode(&List, SSL_CreateNode(121));

// 두 번째 노드를 탐색하여 해당 노드의 주소값을 구조체 포인터 변수 `MyNode`에 저장
MyNode = SSL_GetNodeAt(List, 2); // 나는 해당 함수에 `Location -= 1`을 추가하여 n번째 노드를 찾는 경우, 탐색 함수의 인자로 n을 그대로 입력할 수 있게함.(원래는 n-1 전달)

// 링크드 리스트에서 노드 삭제
SSL_RemoveNode(&List, MyNode);

// 링크드 리스트에서 제거한 노드를 Heap영역에서 완전히 삭제
SSL_DestroyNode(MyNode);
```
이제, 링크드 리스트 내부의 임의의 노드를 삭제하는 함수 `SSL_RemoveNode`함수를 구현해 보도록 하겠다.<br>
<br>

- #### Heap 영역에서의 노드 삭제함수 `SSL_RemoveNode`
  노드 삭제함수 `SSL_RemoveNode`가 동작하는 원리는 다음과 같다. **삭제하고자 하는 노드(`Target`)가 헤드 포인터가 가리키고 있는 노드 <br>
  즉, 링크드 리스트의 첫 번째 노드인 경우, 바로 헤드 포인터가 두번째 노드를 가리키도록 헤드 포인터에 첫 번째 노드의 `NextNode`값을 저장해 준다.**<br>
  ```c
  *Head = Target->Nextnode;
  ```
  <br>
  
  **그리고, 삭제하고자 하는 노드가 첫 번째 노드가 아닌경우, 삭제하고자 하는 노드의 이전 노드와 삭제하고자 하는 노드를 이어준다. 해당 작업은 <br>
  삭제하고자 하는 노드의 바로 이전 노드를 탐색한 뒤, 해당 노드의 `NextNode`에 삭제하고자 하는 노드의 `NextNode`값을 대입해주면 된다!**<br>
  ```c
  Node* Current = *Head;
  
  while(Current != Null && Current->NextNode != Target)
  {
    Current = Current->NextNode;
  }
  
  if(Current != Null)
    Current->NextNode = Target->NextNode;
  ```
  <br>
  
  이를 토대로 노드 삭제함수 `SSL_RemoveNode` 함수를 완성해보도록 하겠다.<br>
  ```c
  void SSL_RemoveNode(Node** Head, Node* Target)
  {
    if((*Head) == Target)
    {
      *Head = Target->NextNode;
    }
    
    else
    {
      Node* Current = *Head;
      
      while(Current != Null && Current->NextNode != Target)
      {
        Current = Current->NextNode;
      }
      
      if(Current != Null)
      Current->NextNode = Target->NextNode;
    }
  }
  ```
<br>


### 노드 삽입
노드와 노드 사이에 새 노드를 끼워넣는 노드 삽입은 구현이 간단하다. 앞 노드의 `NextNode` 포인터가 새 노드를 가리키게 하고, 새 노드의<br>
`NextNode` 포인터가 뒤 노드를 가리키게 하면 된다.<br>

해당 작업을 수행하는 노드 삽입함수 `SSL_InsertAfter` 함수는 다음과 같이 구현이 가능하다. <br>
<br>

- #### 양 노드 사이에 새 노드를 삽입하는 노드 삽입함수 `SSL_InsertAfter`
  ```c
  void SSL_InsertAfter(Node* Current, Node* NewNode)
  {
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
  }
  ```
  해당 함수를 구현하는데 있어 주의할 점은, `NewNode`의 `NextNode`가 `Current`의 `NextNode`를 가리키게 한 뒤에, `Current`의 <br>
  `NextNode`가 `NewNode`를 가리키게 해야 한다.<br>
  
  이유는, `Current`의 다음 노드인 `Current->NextNode`를 `NewNode`가 가리킨 다음에 `Current->NextNode`가 `NewNode`를<br>
  가리켜야지 `Current`의 다음 노드를 `NewNode`가 가리킬 수 있기 때문이다.<br>
  
  `Current->NextNode = NewNode`를 먼저 해버리면, 원래 `Current`의 다음 노드에 대한 주소값 정보가 사라져버려서 `NewNode`와<br>
  `Current` 다음의 노드를 연결 할 수가 없다!<br>
<br>

- #### 새 헤드(새 첫 번째 노드)를 삽입하는 노드 삽입함수 `SSL_InsertNewHead`
  해당 함수가 종료된 후에도, 해당 노드를 포함하는 링크드 리스트의 헤드 포인터는 새로 삽입한 첫 번째 노드를 가리키고 있어야 한다!<br>
  ```c
  void SSL_InsertNewHead(Node** Head, Node* NewNode) {
    if(*Head == Null) {
      (*Head) = NewNode;
    }

    else {
      NewNode -> NextNode = (*Head);
      (*Head) = NewNode;
    }
  }
  ```
  해당 함수를 호출할 때, 아래 코드와 같이, 인자로 링크드 리스트의 첫 번째 노드를 가리키는 헤드 포인터의 주소값과, 새로 삽입할<br>
  새 노드의 주소값을 전달한다.<br>
  ```c
  SSL_InsetNewNode(&List, NewNode);
  ```
  
  이때, 헤더 포인터 `List`의 주소값을 인자로 전달받는 해당 함수의 매개변수 `Head`를 구조체 이중 포인터 타입이 아닌, 구조체 <br>
  포인터 타입으로 하고, 해당 매개변수에 인자로서 전달되는 값도 헤더 포인터 `List`의 주소값(`&List`)이 아닌, 그냥 `List`<br>
  (헤더 포인터 `List`가 가리키고 있는 첫 번째 노드의 주소값)를 전달하면 어떻게 될까?<br>
  이러한 경우를 코드로 나타내면 다음과 같을 것이다.<br>
  
  #### 잘못된 케이스
  ```c
  // SSL_InsertNewNode 함수 정의
  void SSL_InsertNewHead(Node* Head, Node* NewNode) {
    if(Head == Null) {
      Head = NewNode;
    }

    else {
      NewNode -> NextNode = Head;
      Head = NewNode;
    }
  }
  ```
  ```c
  // SSL_InsertNewNode 함수 호출
  SSL_InsertNewNode(List, NewNode);
  ```

  이러한 경우도 위에서 설명한 `SSL_AppendNode`함수의 경우와 같은 경우라 할 수 있다.<br>
  이때도 설명하였듯이, 해당 방법을 사용하면 다음과 같은 문제가 발생한다.<br>

  #### 위 잘못된 케이스를 통해 발생되는 문제와 해당 문제가 발생하는 이유
  `Call by reference`, 주소에 의한 호출은 함수 호출 시, 인자로서 어떠한 변수의 주소값을 해당 함수의 매개변수에 전달하는 호출<br>
  방식을 의미한다.<br>
  이러한 `Call by reference` 방식을 이용하여 주소값을 매개변수에 전달한 경우, 위 상황을 예로 들면, 헤더 포인터 `List`가 가리키고<br>
  있는 첫 번째 노드의 주소값이 `SSL_InsertNewHead`함수의 매개변수, 구조체 포인터 타입인 `Head`에 전달되기 때문에,<br>
  이 `List`와 `Head`는 같은 메모리 공간 즉, 첫 번째 노드의 주소값을 공유하게 된다.<br>
  이는 "해당 함수 안에서는 `List`를 `Head`라 부르겠다" 와 같이 해당 함수 실행 중에는 `Head`는 `List`의 일종의 별명이 된다고 <br>
  생각하면 이해하기 쉬울 것이다.<br>
  (첫 번째 노드의 주소값을 칭하는 별명이 `List`와 `Head`로 다른 것이지, 본질은 같음)
  그렇다면 당연히 이러한 함수를 실행하고 나면, 해당 함수를 통한 변경사항이 고스란히 `List`에 적용이 되어 있어야 한다. <br>
  맨 위에 명시해둔 해당 함수의 조건과 같이 말이다.<br>
  우리가 생각한 대로라면, 위 코드를 실행 하였을 시, `SSL_InsertNewHead` 함수를 실행시킨뒤 해당 함수가 종료되고 나면,<br>
  다음과 같은 변화가 적용되어 있어야 한다.<br>
  
  ##### 1) 해당 링크드 리스트가 비어있는 경우 (Head == Null)<br>
  헤더 포인터가 아무것도 가리키고 있지 않은, 링크드 리스트가 비어있는 경우이다. 이러한 경우, 새 노드를 헤더 포인터 `List`<br>
  의 별칭인 `Head`가 인자로 전달받은 새 노드의 주소값을 저장하고 있는 구조체 포인터 변수 `NewNode`의 값을 저장하여 새 노드<br>
  를 가리키고 해당 함수가 종료되면, `List`가 새 노드(`NewNode`)를 가키리고 있어야 한다. 

  ##### 2) 링크드 리스트가 비어있지 않은 경우<br>
  해당 링크드 리스트가 비어있지 않은 상태에서 첫 번째 노드의 위치에 새 노드를 삽입하게 되는 경우이다.<br>
  이 경우에도 `NewNode -> NextNode = Head`를 통해 새 노드의 다음 노드의 주소값을 저장하는 구조체 포인터 멤버변수 `NextNode`<br>
  에 기존 첫 번째 노드의 주소값을 대입하여, 새 노드가 첫번째 노드로, 기존 `Head`가 가리키고 있던 첫 번째 노드가 두번째 노드로<br>
  밀려나게 한뒤, `Head = NewNode`를 통해 `Head`가 새로운 첫 번째 노드인 `NewNode`의 값을 저장하여<br>
  해당 함수가 종료되면, 새 노드가 첫 번째 노드가 되고, 이 첫 번째 노드를 헤더 포인터 `List`가 가리키고 있어야 한다.<br>

  하지만, 해당 코드를 실행시키면, 해당 링크드 리스트가 비어있는 경우(`List`가 Null인 경우)에는 해당 함수가 실행된 뒤, 종료되고 나면<br>
  실제로는 이 `List`는 여전히 아무것도 가리키지 않고 있는, 함수를 호출하기 이전과 같은 Null인 상태로 남아있게 된다.<br>

  그리고 해당 링크드 리스트가 비어있지 않은 경우에는 해당 함수가 실행된 뒤, 종료되고 나면, `NewNode -> NextNode = Head`를 통한 <br>
  새 노드 -> 기존 첫번째 노드 순의 연결은 적용되어 있지만, `Head = NewNode`를 통한 헤더 포인터 `List`의 새로운 첫 번째 노드 참조<br>
  는 적용되어 있지 않고, 기존 원래 첫 번째 노드를 가리키고 있는 상태로 남아있을 것이다.<br>

  이러한 현상이 왜 일어나는 것일까?<br>

  C언어의 경우, 사실은 이러한 `Call by reference`를 지원하지 않기 때문이다.<br>
  C언어는 이러한 주소값을 **복사하여** 매개변수에 전달하는 `Call by address` 방식을 제공한다.<br>
  때문에, `SSL_InsertNewHead` 함수에서 `Head`는 `List`와 같은 메모리 공간을 공유하고 있는 `List`의 별명 같은 존재가 아닌,<br>
  `List`가 저장하고 있는 주소값을 똑같이 저장하고 있는 또 다른 구조체 포인터 변수라고 할 수 있다.<br>

  때문에, 문제가 되는 `Head = NewNode`와 같은 코드는 `List`와 같이 링크드 리스트가 비어있으면 `Null`을 가리키는 혹은<br>
  링크드 리스트가 비어있지 않다면 첫 번째 노드를 가리키는 또 다른 구조체 포인터 변수가 새 노드의 주소값을 참조하고 있는상태<br>
  라고 표현이 가능하다.<br>

  때문에, 이 `Head = NewNode`는 값을 복사하여 전달한 `List`와는 별개가 되고, 해당 코드를 통한 변화는 `List`에 적용되지 않는다.<br>
  또, 이 `Head`와 같은 매개변수는 해당 함수 호출 시, Stack 메모리에 할당되고, 해당 함수가 종료되면 자동적으로 Stack 메모리에서 <br>
  삭제되기 때문에, 결국, 이 잘못된 케이스의 경우, 함수를 호출하기 전과 다름없는 결과를 나타내게 된다. <br>
  (`Head = NewNode` 를 통해 구조체 포인터 변수 Head가 새 노드의 주소값을 참조함 하지만, 해당 함수가 종료되고 나면 이 `Head`는<br>
  자동적으로 소멸됨. 그냥 함수가 실행되는 동안에 잠깐 `NewNode`를 가리키다 해당 함수가 종료되면 소멸되고, 이러한 `Head`의 새 노드<br>
  의 주소값 참조는 값을 복사해서 전달해준 `List`와는 아무런 상관이 없음)
<br>

### 노드의 개수 세기
노드의 개수를 세는 작업을 수행하는 함수 또한 구현이 간단하다. `while`문을 이용하여 첫 번째 노드부터 마지막 노드까지 순차적으로, 노드를 <br>
가리키는 포인터 `Current`가 노드를 가리키게 하고, 해당 작업이 수행될때마다 노드의 수를 저장하는 int형 변수`count`의 값을 1씩 늘려주면 된다.<br>

링크드 리스트의 노드의 개수를 세어서 반환해주는 함수 `SSL_GetNodeCount` 함수를 구현해 보도록 하겠다.<br>
<br>

- #### 노드의 개수를 세어 반환하는 함수 `SSL_CetNodeCount`
  ```c
  int SSL_GetNodeCount(Node* Head)
  {
    int Count = 0;
    Node* Current = Head;
    
    while(Current != Null)
    {
      Current = Current->NextNode;
      Count++;
    }
    return Count;
  }
  ```
<br>

---




      

 
  
  
  
  
  

  
    



