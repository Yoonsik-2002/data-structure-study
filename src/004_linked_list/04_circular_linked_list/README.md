# 🌌 원형 연결 리스트(Circular Linked List) 
### 원형 연결 리스트의 이해 
이전에 구현하였던 단순 연결 리스트의 경우, 마지막 노드가 `NULL`을 가리켰었다.<br>

이 마지막 노드가 연결 리스트의 첫 번째 노드를 가리키게 하면, 원형 연결 리스트(Circular Linked List)가 된다. 아래 그림을 한번 보도록 하자.<br>

- ###### 기존의 Dummy Node 기반 단순 연결 리스트
  ![스크린샷(6)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/4e26148e-5278-4552-b56e-803c9580008b)<br>
  <br>

- ###### 원형 연결 리스트
  ![스크린샷(7)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/5b72399b-0005-4c44-8fcc-238f8b607e1a)<br>
  <br>
<br>

### 원형 연결 리스트의 특성 - 머리(head)와 꼬리(tail)의 구분❌

- ###### 원형 연결 리스트의 머리(head)에 새 노드를 추가하는 경우
  ![스크린샷(10)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/26097a84-1149-4f09-ae18-699f62283fab)<br>
  <br>

- ###### 원형 연결 리스트의 꼬리(tail)에 새 노드를 추가하는 경우
  ![스크린샷(9)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/b20886c6-406f-4b1b-afb6-cd8fe57a60ae)<br>
<br>

위 그림을 보면, 1을 저장하는 새 노드를 원형 연결 리스트의 머리에 추가하든, 꼬리에 추가하든 8을 저장하는 노드는 1을 저장하는 노드를 가리키고, 1을 저장하는 노드는 2를 저장하는 노드를 가리키는 것을 알 수 있다.<br>

해당 두 경우에 있어, 차이점은 구조체 포인터 변수 `head`가 어떤 노드를 가리키고 있는지를 제외하면, 존재하지 않는다.<br>

이러한 특성 때문에, 원형 연결 리스트에는 머리와 꼬리의 구분이 없다고 이야기 하기도 한다.<br>
<br><br>

### 원형 연결 리스트의 장점
이전에 구현하였던, 단순 연결 리스트의 경우, 연결 리스트의 마지막 노드를 가리키는 구조체 포인터 변수 `tail`이 있어야 효율적인 작동이 가능하였다.<br>

`tail`이 없으면, 매번 마지막 노드를 찾기 위해 리스트를 처음부터 끝까지 탐색해야 했기 때문이다.<br>

하지만, 원형 연결 리스트의 경우는 반대로 마지막 노드를 가리키는 구조체 포인터 변수 `tail`을 추가해 버리면, 원형 연결 리스트의 장점을 반감해 버리는 꼴이 되어버린다.<br>

왜냐하면 원형 연결 리스트의 장점은 다음과 같기 때문이다.<br>

> 단순 연결 리스트처럼 머리와 꼬리를 가리키는 구조체 포인터 변수를 따로 두지 않아도, 하나의 포인터 변수만 있으면, 연결 리스트의 머리와 꼬리에 노드를 간단히 추가할 수 있다.<br>

<br>

### 변형된 원형 연결 리스트
- ###### 기존의 원형 연결 리스트
  ![스크린샷(1)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/7e38312a-fb1e-4ec1-b899-4b4a398fe8cd)<br>

  위와 같이, `head`라는 포인터 변수가 연결 리스트의 첫 번째 노드를 가리키고 있는 상황에서, 연결 리스트의 꼬리에 새 노드를 추가 하기 위해서는, 현 위치인 연결 리스트의 첫 번째 노드를 시작으로, 마지막 노드를 찾아가는 과정을 매번 거쳐야 할 것이다.<br>

  해당 경우, 단순 연결 리스트에서 마지막 노드를 가리키는 구조체 포인터 변수 `tail`이 존재하지 않는 상황과 마찬가지로, 매번 첫 번째 노드에서 시작하여 마지막 노드를 탐색해 주어야 한다는 비효율성을 띄게 된다.<br>

  이러한 문제를 해결하기 위해서는 위 원형 연결 리스트를 조금 변형시켜주면 된다.<br>
<br>

- ###### 변형된 원형 연결 리스트
  ![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/39e01b70-26d9-4b77-a612-830b2477fc8b)<br>

  이전의 기존 원형 연결 리스트를 변형하여, 첫 번째 노드를 가리키던 구조체 포인터 변수 `head`대신, 마지막 노드를 가리키는 구조체 포인터 변수 `tail`을 사용하도록 만들어 주었다.<br>

  이제는 원형 연결 리스트의 꼬리에 새 노드를 추가하는데 있어, 이전 상황처럼 별도로 마지막 노드를 탐색할 필요 없이, 바로 추가해주는 것이 가능하다. 그 뿐인가? 원형 연결 리스트의 머리에도 간단히 새 노드를 추가하는 것이 가능하다. 아래를 한번 보자.<br>
  
  - 원형 연결 리스트의 꼬리를 가리키는 구조체 포인터 변수 : `tail`
  - 원형 연결 리스트의 머리를 가리키는 구조체 포인터 변수 : `tail -> next`
  
  이제, 단순 연결 리스트와 같이, 머리와 꼬리를 가리키는 구조체 포인터 변수를 각각 따로 두지 않아도, 하나의 포인터 변수만 있다면, 연결 리스트의 머리와 꼬리에 새 노드를 간단히 추가할 수 있다는 원형 연결 리스트의 장점을 살릴 수 있게 되었다.<br>
<br>

## 원형 연결 리스트의 구현
먼저, 원형 연결 리스트의 ADT를 작성해보면, 다음과 같다.<br>

![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/fdcf5faf-e7b1-4c37-99d7-3346dc091b1f)<br>

이렇게 작성한 ADT를 토대로, 헤더파일을 작성하면, 아래 링크의 헤더파일과 같이 작성하는 것이 가능하다.<br>
[CLinkedList.h](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/04_circular_linked_list/circular_linked_list_program/CLinkedList.h)<br>

헤더파일을 완성하였으니, 이제 본격적으로 변형된 원형 연결 리스트를 구현해보도록 하겠다.<br>
<br>

### 1. 원형 연결 리스트의 초기화와 노드의 삽입

###### 원형 연결 리스트의 초기화
원형 연결 리스트의 초기화 또한, 단순 연결 리스트의 초기화와 같이 간단하다. 아래와 같이, 원형 연결 리스트 구조체의 멤버들을 `NULL` 혹은 `0`과 같은 초기값으로 초기화 해주면 된다.<br>

```c
void ListInit(List * pList) {
  pList -> cur = NULL;
  pList -> before = NULL;
  pList -> tail = NULL;
  pList -> numOfData = 0;
}
```
<br>

###### 새 노드 생성 및 삽입 
```c

// ppt 자료 추가

```

먼저, 위의 자료에서, 왼편의 그림은 새 노드는 생성되었지만, 원형 연결 리스트 내에는 아직 아무런 노드도 추가되지 않았음을 나타낸다. 원형 연결 리스트에서, `tail`이 `NULL`을 가리키고 있다는 것은, 노드가 하나도 추가되지 않았음을 의미한다.<br>

이러한 상황에서 원형 연결 리스트에 첫 번째 새 노드가 삽입되면, 오른쪽과 같이 새 노드 스스로도 자기 자신을 가리키고, `tail`또한 새 노드를 가리키는 형태를 띄게 된다.<br>

그 이유는, **맨 처음 추가된 노드는 원형 연결 리스트의 꼬리이자, 머리이기 때문이다.** <br>
<br>

이렇게 빈 원형 연결리스트에 새로운 첫 번째 노드를 추가하는 경우, `LInsert`함수를 사용하든, `LInsertFront`함수를 사용하든 같은 형태의 결과가 나오기 때문에, 이 두 함수는 해당 경우에 대한 서로 공통적인 코드 내용을 가지게 된다.<br>
<br>

- ###### `LInsert`함수와 `LInsertFront`함수의 공통부분
  비어있는 원형 연결 리스트에 새로운 첫 번째 노드를 추가하는 경우에 대한 `LInsert`함수와 `LInsertFront`함수의 공통부분은 아래 코드와 같다.<br>

  ```c
  void LInser~(List * pList, Data data) {
    Node * newNode = (Node *)malloc(sizeof(Node));  // 새 노드를 생성하여, heap영역에 메모리 할당
    newNode -> data = data;  // 새 노드에 데이터 저장

    if(pList -> tail == NULL) {  // 원형 연결 리스트가 비어있는 경우, 새 노드 추가
      /* 새 노드 그 자체로 원형 연결 리스트의 꼬리이자, 머리가 됨 */
      pList -> tail = newNode;  // tail이 새 노드를 가리킴
      newNode -> next = newNode;  // 새 노드가 자기 스스로를 가리킴
    }

    else {
      /* 차이가 나는 부분 */
    }

    (pList -> numOfData)++;
  }
  ```

  비어있는 원형 연결 리스트에 `LInsert`함수나 `LInsertFront`함수를 활용하여, 첫 번째 새 노드를 추가하는 경우, 공통적으로 위 코드가 실행되어, 아래 그림과 같은 결과가 나오게 될 것이다.<br>

  ![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/e83fe85b-e8b3-4cdd-8fd7-8ba685653d8c)<br>

  다시한번 강조하지만, 비어있는 원형 연결 리스트에 첫 번째로 새롭게 추가된 노드는 그 자체로, 원형 연결 리스트의 머리이자, 꼬리이다.<br>
  <br>
  
- ###### 원형 연결 리스트가 비어있지 않은 경우, 새 노드를 원형 연결 리스트의 머리에 추가하는 경우 - `LInsertFront`
  이제, `LInsert`함수와 `LInsertFront`함수 간의 차이가 나는 부분을 작성해 보도록 하겠다.<br>

  두 함수는 원형 연결 리스트가 비어있지 않은 상황에서 새 노드를 머리에 추가하느냐, 꼬리에 추가하느냐에 대한 기능적 차이가 발생하게 된다.<br>
  
  먼저, 원형 연결 리스트가 비어있지 않은 경우, 새 노드를 원형 연결 리스트의 머리에 추가하는 경우에 대해 알아보도록 하겠다.<br>
  <br>

  아래 그림과 같이, 원형 연결 리스트에 노드 2개가 추가되어 있는 상황이라 해보자.<br>

  ![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/0b2c4d51-1994-43e7-baad-f36baaefabf0)<br>

  이러한 경우, 새 노드를 위 연결 리스트의 머리에 추가하기 위해서는 일단 우선적으로, 아래와 같이 새 노드를 생성해 주어야 할 것이다. 새롭게 추가할 노드에 들어가는 데이터는 7로 해주도록 하겠다.<br>

  ![스크린샷(3)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f5f3a4a0-084b-45c0-8aa9-5dae4b24fb47)<br>

  이렇게 데이터 7을 저장하고 있는 새 노드를 생성해 주었고, 이제, 해당 노드를 노드 2개가 추가되어 있는 원형 연결 리스트에 추가해 주도록 하겠다.<br>

  ![스크린샷(5)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/f7d189da-82ed-4b6c-b745-6360b9930f83)<br>

  ![스크린샷(6)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/241bbca3-6367-4622-8161-836bc5dc85e0)<br>

  먼저, 새 노드를 연결 리스트의 머리인 `pList -> tail -> next`를 가리키게 하여 연결 해준 뒤, 마지막 노드인 `tail`이 이렇게 머리에 연결된 새 노드를 가리키게 하여 원형 연결 리스트의 형태가 만들어질 수 있도록 하였다.<br>

  완성된, 새 노드를 원형 연결 리스트의 머리에 추가해주는 `LInsertFront` 함수는 아래와 같다.<br>

  ```c
  void LInsertFront(List * pList, Data data) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;

    if(pList -> tail == NULL) {
      pList -> tail = newNode;
      newNode -> next = newNode;
    }

    else {
      newNode -> next = pList -> tail -> next;
      pList -> tail -> next = newNode;
    }

    (pList -> numOfData)++;
  }
  ```
<br>

- ###### 원형 연결 리스트가 비어있지 않은 경우, 새 노드를 원형 연결 리스트의 꼬리에 추가하는 경우 - `LInsert`
  이번엔, 원형 연결 리스트가 비어있지 않은 경우, 새 노드를 원형 연결 리스트의 꼬리에 추가하는 경우에 대해 알아보도록 하겠다.<br>

  이번에도 마찬가지로, 아래와 같이, 원형 연결 리스트에 노드 2개가 추가되어 있는 상황이라 해보자.<br>

  ![스크린샷(4)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/88574057-ec15-49f2-b605-424506cc1d60)<br>
  
  이러한 경우, 새 노드를 머리에 추가해 주기 위해서는 어떻게 해야할까? `pList -> tail -> next = newNode`를 통해 꼬리에 새 노드를 그대로 연결해 주어야 할까?<br>

  해당 방법을 사용하면, `newNode`가 가리켜야 할 기존 첫 번째 노드에 대한 정보(`pList -> tail -> next`)가 `newNode`의 주소값으로 덮어씌어져, 사라져 버리게 된다.<br>

  결국, `newNode`를 가리키게 하기 전의 `pList -> tail -> next`의 값을 따로 임시 저장해 두어야 해당 방법으로 새 노드를 꼬리에 추가하는 것이 가능할 것이다. 하지만, 이는 비효율적이며, 불필요한 방법이다. 원형 연결 리스트는 다음과 같은 특징을 가지고 있기 때문이다.<br>

  > (변형된)원형 연결리스트에는 머리의 꼬리의 구분이 없다. 단지, 새 노드를 머리에 추가한 경우나 꼬리에 추가한 경우에, `tail`의 위치에 있어 차이가 있을 뿐이다.

  <br>

  이러한 특성을 가진 원형 연결 리스트이기에, 새 노드를 추가할 때, `LInsertFront`함수의 내용과 같이 연결 리스트의 머리에 새 노드를 추가해 주고, `tail`의 위치만 새로 추가한 노드로 변경해 주면, 원형 연결 리스트의 꼬리에 새 노드를 추가하는 것이 가능하게 된다.<br>

  이제, 기존 노드 2개가 존재하는 원형 연결 리스트의 꼬리에 새 노드를 추가하는 과정을 정리해 보도록 하겠다.<br>

  ![스크린샷(6)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/4c2bf5b1-c092-48d8-8b3b-f244cdeb573a)<br>

  먼저, 위 그림과 같이 7이라는 데이터를 저장하고 있는 새 노드를 생성해 주었다.<br>

  ![스크린샷(5)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/56a004e4-da5b-4c1e-a72d-157a2dfe25f8)<br>

  그리고, 해당 노드를 `newNode = pList -> tail -> next;`를 통해 위 그림과 같이, 원형 연결 리스트의 머리(첫 번째 노드)에 연결 시켜 주었다.<br>

  ![스크린샷(7)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/42ecf84c-41f0-4b09-a034-c232c2181fae)<br>

  그리고 나서, `pList -> tail -> next = newNode;`를 통해, `tail`이 가리키고 있는 노드가 새롭게 추가된 노드를 가리키게 해 주었다. 여기까지의 내용과 코드는 새 노드를 원형 연결 리스트의 머리에 추가하는 `LInsertFront`와 별반 다를 것이 없다.<br>

  위에서도 언급하였듯이, 원형 연결 리스트에선 머리와 꼬리의 구분이 없기 때문에 이것이 가능하다 할 수 있다. 하지만, 새 노드를 머리에 추가하였느냐, 아니면 꼬리에 추가하였느냐에 있어서는 하나의 차이점이 존재한다.<br>

  바로, 원형 연결 리스트의 꼬리(마지막 노드)를 가리키는 `tail`의 위치이다. 당연히, 새 노드를 원형 연결 리스트의 꼬리에 추가해 준 것이니, 원형 연결리스트의 꼬리를 가리키는 `tail`은 반드시 꼬리에 새롭게 추가된 해당 노드를 가리켜 주어야 할 것이다.<br>

  ![스크린샷(9)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/dafbe5fa-3928-433d-a906-6bb4c2f98271)<br>

  원형 연결 리스트의 꼬리에 새 노드를 추가해주는 경우, 위 그림과 같이, `pList -> tail = newNode;`를 통해 해당 새 노드가 원형 연결 리스트의 꼬리에 해당하는 노드임을 표시해 주어야 한다.<br>

  ![스크린샷(10)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/649ac827-1d26-4e58-87a8-81856fad34f4)<br>

  위 그림과 같이, 새롭게 추가한 7을 저장하는 노드를 원형 연결 리스트의 마지막으로 옮겨 주어도, 해당 노드들이 가리키고 있는 노드의 순서는 둘다 `7` -> `2` -> `4` -> `7`로, 동일하다. `tail`도 7을 저장하는 새 노드를 가리키고 있으므로, 두 그림은 같은 상황이라 할 수 있다.<br>

  원형 연결 리스트에 새 노드를 꼬리에 추가했을 때와 머리에 추가했을 때의 유일한 차이점은 `tail`이 가리키는 노드가 다르다는 점이다. 완성된 새 노드를 원형 연결 리스트의 꼬리에 추가해주는 `LInsert` 함수는 아래와 같다.<br>

  ```c
  void LInsert(List * pList, Data data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    if(pList -> tail == NULL) {
      pList -> tail -> next = newNode;
      newNode -> next = pList -> tail;
    }

    else {
      newNode -> next = pList -> tail -> next;
      pList -> tail -> next = newNode;
      pList -> tail = newNode;
    }

    (pList -> numOfData)++;
  }
  ```
  <br>

### 2. 원형 연결 리스트의 데이터 탐색 및 조회

###### 원형 연결 리스트를 나타내는 구조체 `CList`의 멤버, `cur`과 `before`
원형 연결 리스트를 나타내는 구조체인 `CList`는 다음과 같이 정의되어 있다.<br>

```c
typedef struct _CLL {
  Node * tail;
  Node * cur;
  Node * before;
  int numOfData;
} CList;
```

`CList`의 멤버인 `cur`과 `before`은 단순 연결 리스트를 구현했을 때와 마찬가지로, `cur`은 현재 노드를, `before`은 이전 노드를 가리킨다.<br>
<br>

- ###### `cur`과 `before`을 탐색의 시작 위치로 초기화 하고, 원형 연결 리스트의 첫 번째 노드의 데이터를 반환 - `LFirst`
  탐색의 시작점이자, 원형 연결 리스트의 첫 번째 노드를 탐색하여 데이터를 반환해주는 `LFirst`함수를 호출하는 경우, 아래와 같이, `cur`은 원형 연결 리스트의 첫 번째 노드를 가리키고, `before`은 이전 노드인 원형 연결 리스트의 마지막 노드를 가리키도록 초기화 되어야 한다.<br>

  ![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/7d2742d6-e884-40e3-982d-404be08bcf67)<br>

  `LFirst`함수의 호출 결과는 위와 같고, 이 상태가 원형 연결 리스트의 노드 탐색의 처음 시작 상태가 된다.<br>

  이렇게 `cur`과 `before`이 초기화 되면, `LFirst`함수는 `cur`이 가리키고 있는 원형 연결 리스트의 첫 번째 노드의 데이터를 반환한다. 이러한 `LFirst`함수는 `cur`과 `before`을 탐색의 처음 시작 위치로 초기화 시켜주고, 첫 번째 노드의 데이터를 반환하는 기능을 수행한다.<br>

  `LFirst`함수를 정의하면, 다음과 같다.<br>

  ```c
  int LFirst(List * pList , Data * pData) {
    if(pList -> tail == NULL) {
    return FALSE;
    }
  
    pList -> before = pList -> tail;
    pList -> cur = pList -> tail -> next;

    *pData -> data = pList -> cur -> data;

    return TRUE;
  }
  ```
<br>  

  
  






  

  

  
