# 🔗 양방향 연결 리스트(Doubly Linked List)
### 양방향 연결 리스트의 이해
양방향 연결 리스트란, 이름에서도 알 수 있듯이, 유효한 데이터를 지닌 노드(더미노드 포함)가 양쪽 방향으로 연결되어 있는 구조의 연결 리스트이다. 이 양방향 연결 리스트를 가리켜, 이중 연결 리스트라고 부르기도 한다.<br>

양방향 연결 리스트의 가장 기본이 되는 모델을 그림으로 나타내보면, 아래와 같다.<br>

- ###### 양방향 연결 리스트의 기본적인 모델
  ![스크린샷(1)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/241f70f7-ceee-44a8-888f-30a54c569e1a)
<br>

- ###### 양방향 연결 리스트의 노드를 나타내는 구조체
  위 그림과 같은 형태를 지니는, 양방향 연결 리스트의 노드를 구조체로 구현하면, 아래와 같은 코드로 나타내는 것이 가능하다.<br>
  
  ```c
  typedef struct _node {
    struct _node * next;
    struct _node * prev;  // 이전(왼쪽) 노드를 가리키는 멤버변수 추가
    Data data;
  } Node;
  ```
  양방향 연결 리스트의 유효한 데이터를 지닌 노드는, 이전 노드와 다음 노드에 양쪽으로 연결되기 때문에, 이전 노드를 가리키는 멤버로, 구조체 포인터 변수 `prev`가 추가 되었다.<br>
<br>

- ###### 양방향 연결 리스트를 나타내는 구조체
  양방향 연결 리스트를 나타내는 구조체는 다음과 같은 코드로 구현해 주는 것이 가능하다.<br>

  ```c
  typedef struct _dbLinkedList {
    struct _dbLinkedList * head;
    struct _dbLinkedList * cur;
    int numOfData;
  } DBLinkedList;
  ```
  해당 구조체를 보면, 연결 리스트의 데이터(노드)조회를 위해 선언된 멤버가 `cur`하나밖에 없는 것을 알 수 있다. 기존에 구현하였던 연결 리스트에는 `cur`이 가리키는 노드의 이전 노드를 가리키는 `before`이 존재하였었다.<br>

  하지만, 양방향 연결 리스트는 유효한 데이터를 지닌 노드가 양쪽 방향으로 연결되어, 이전 노드와 다음 노드를 모두 가리키는 구조이기에 `cur -> prev`를 통해 현재 참조하고 있는 노드의 이전 노드를 `before`을 따로 선언하여 사용하지 않아도 참조하는 것이 가능하다.<br>

  즉, 현재 노드를 참조하는 멤버인 구조체 포인터 변수 `cur`을 통해, 해당 노드의 다음 노드(`cur -> next`)와 이전 노드(`cur -> prev`)를 알 수 있는 것이다.<br>
  
  `cur -> next; // cur이 가리키는 노드의 다음 노드`<br>
  `cur -> prev; // cur이 가리키는 노드의 이전 노드`<br>
<br>

### 양방향 연결 리스트의 구현
이번에 구현해 볼 양방향 연결 리스트는, 맨 위에서 그림으로 표현했었던, 양방향 연결리스트의 가장 기본 모델로, 해당 연결 리스트의 ADT를 작성해 보면, 다음과 같다.<br>

![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/9717df44-3775-45d3-937d-6e6b1b00571e)<br>

이렇게 작성한 ADT를 토대로, 헤더파일을 작성하면, 아래 링크의 헤더파일과 같이 작성하는 것이 가능하다.<br>
[DBLinkedList.h](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/004_linked_list/05_doubly_linked_list/doubly_linked_list_program/DBLinkedList.h)<br>

헤더파일을 완성하였으니, 이제 본격적으로 양방향 연결 리스트를 구현해 보도록 하겠다.<br>
<br>

### 1. 양방향 연결 리스트의 초기화
###### `ListInit`함수 구현
양방향 연결 리스트를 나타내는 구조체를 구현하면, 다음과 같이 작성하는 것이 가능하였다.<br>

```c
typedef struct _dbLinkedList {
  struct _dbLinkedList * head;
  struct _dbLinkedList * cur;
  int numOfData;
} DBLinkedList;
```

이렇게 구현되는 양방향 연결 리스트를 처음 작동시키기 전에, 초기상태(값)로 초기화 해주는 기능을 담당하는 함수가 바로, 이 `LineInit`함수이다. 먼저, 이 `DBLinkedList`구조체의 멤버들을 살펴보도록 하겠다.<br>

- ###### `head`
  연결 리스트의 첫 번째 노드를 가리킨다. 초기상태에는 연결리스트에 노드가 존재하지 않기 때문에, 초기값으로, `NULL`로 초기화 해준다.<br>

- ###### `cur`
  연결 리스트의 노드(데이터)를 조회하는데 사용된다. 데이터 조회동작에 있어, 첫 번쨰 노드를 조회하는데 사용하는 `LFirst`함수의 호출과 동시에 초기화가 어차피 이루어지기 때문에, 굳이 `ListInit`함수에서 초기화 해줄 필요는 없다.<br>

- ###### `numOfData`
  연결 리스트에 저장되어 있는 데이터의 개수를 저장하는데 사용된다. 초기 상태에는 연결 리스트에 아무런 데이터(노드)도 저장하고 있지 않기 떄문에, 초기값으로 0으로 초기화 해준다.<br>
<br>

자, 이를 종합하여, `ListInit`함수를 구현해 보면, 다음과 같이 구현할 수 있다.<br>

```c
void ListInit(List * pList) {
  pList -> head = NULL;
  pList -> numOfdata = 0;
}
```


