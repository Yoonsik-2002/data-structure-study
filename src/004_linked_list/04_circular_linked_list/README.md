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




