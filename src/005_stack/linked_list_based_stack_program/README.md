# 💻 Stack의 연결 리스트 기반 구현
### 연결 리스트 기반 스택의 논리
Stack이란 자료구조는 어떠한 특성을 지닌 자료구조였는가? 그렇다. Last in First out, 마지막에 들어온 데이터가 먼저 나오는 '후입선출'의 자료구조라 하였었다.<br>

이러한 Stack의 특성을 연결 리스트에 적용하여, 연결 리스트를 구현해 주면 연결 리스트 기반의 스택을 구현하는 것이 가능하다. 즉, **연결 리스트가 마지막에 들어온 데이터를 제일 먼저 반환하도록 연결 리스트를 구현해 주면 되는 것이다.** <br>

이러한 Stack의 특성을 바탕으로 연결 리스트를 구현해 주기 위해서는 새로운 데이터를 연결 리스트의 `head`에  추가하는 연결 리스트를 구현하여, 연결 리스트의 데이터가 저장된(들어온) 순서의 역순으로 조회 및 삭제가 이루어 지도록 만들어 주면 된다.<br>

아래 그림처럼 말이다.<br>

![스크린샷(2)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/7fe0373b-e8fc-40d9-83fa-8e61b3da5897)<br>

> 위 메모리 구조만을 놓고 보았을 때에는 이것이 연결 리스트를 구현한 것인지, 아니면, Stack을 구현한 것인지 알 수 없다.
> 다만, 이러한 메모리 구조를 바탕으로 Stack의 push연산과 pop연산이 포함된 ADT를 정의해 준다면, 이것이 Stack이 되는 것이다.

<br>

### Stack의 연결 리스트 기반 구현 1) - ADT 정의하기
우리가 구현하고자 하는 연결 리스트는 기본적으로 head에 새로운 데이터를 추가하는 단순 연결 리스트의 구조를 가지고 있다. 그러나 이 연결 리스트에 우리가 정의하고자 하는 기능(ADT)을 추가함으로써, 해당 연결 리스트는 새로운 자료구조로 진화할 수 있다.<br>

연결 리스트를 기반으로 Stack을 구현하기 위해 정의한 ADT는 다음과 같다.<br>

![스크린샷(4)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/1cbd4943-ad94-4eca-bbb6-6bd678039b4d)

해당 ADT를 기반으로, 연결 리스트 기반 스택 프로그램의 헤더파일을 정의해 보면, 다음과 같이 정의하는 것이 가능하다.<br>
[ListBaseStack.h](https://github.com/Yoonsik-2002/data-structure-study/blob/main/src/005_stack/linked_list_based_stack_program/ListBaseStack.h)<br>
<br>




